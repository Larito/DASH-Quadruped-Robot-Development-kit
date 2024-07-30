#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist
from std_msgs.msg import Float32

import mediapipe as mp
from mediapipe.tasks import python
from mediapipe.tasks.python import vision
from mediapipe.framework.formats import landmark_pb2

import blobconverter
import cv2
import numpy as np
import time
from cv_bridge import CvBridge

class GestureRecognizer(Node):
    def __init__(self):
        super().__init__("gesture_recognizer_node")

        self.camera_on = False
        self.read_frame = True
        self.bridge = CvBridge()

        self.image_subscriber = self.create_subscription(Image,'image',self.image_callback,10)
        self.position_publisher = self.create_publisher(Float32, 'position_in_frame', 10)
        
        self.recognition_frame = None
        self.recognition_result_list = []

        model_path = "/home/dash/Desktop/ros_ws/src/cv_subsystem/models/face_detector.tflite"
        base_options = python.BaseOptions(model_asset_path=model_path)
        options = vision.FaceDetectorOptions(base_options=base_options,
                                                running_mode=vision.RunningMode.LIVE_STREAM,
                                                min_detection_confidence=0.5,
                                                min_suppression_threshold=0.5,
                                                result_callback = self.save_result)

        self.detector = vision.FaceDetector.create_from_options(options)

        self.curr_time = time.time_ns()
        self.prev_time = self.curr_time - 1

        self.get_logger().info("Starting Face Detector")

        self.img_w = None

    def image_callback(self, msg):
        if not self.read_frame: return
    
        self.read_frame = False
        rgb_image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        rgb_image = cv2.cvtColor(rgb_image, cv2.COLOR_BGR2RGB)
        mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb_image)

        w,h,c = rgb_image.shape
        self.img_w = w

        self.prev_time = self.curr_time
        self.curr_time = time.time_ns()
        if self.curr_time == self.prev_time:
            return

        self.detector.detect_async(mp_image, self.curr_time // 1_000_000)

    def save_result(self, result: vision.GestureRecognizerResult, unused_output_image: mp.Image, timestamp_ms: int):
        if len(result.detections) != 0: 
            position_in_frame = (self.img_w - result.detections[0].bounding_box.origin_x)/self.img_w

            position_msg = Float32()
            position_msg.data = position_in_frame
            self.position_publisher.publish(position_msg)

        self.read_frame = True

def main(args=None):
    rclpy.init(args=args)

    node = GestureRecognizer()
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()
