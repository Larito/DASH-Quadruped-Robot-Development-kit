#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from geometry_msgs.msg import Twist
from std_srvs.srv import SetBool # Import SetBool service

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

        self.count = 0

        self.camera_on = False
        self.read_frame = True
        self.bridge = CvBridge()

        self.image_subscriber = self.create_subscription(Image,'image',self.image_callback,10)
        
        self.recognition_frame = None
        self.recognition_result_list = []

        model_path = "/home/dash/Desktop/ros_ws/src/cv_subsystem/models/face_deteector.tflite"
        base_options = python.BaseOptions(model_asset_path=model_path)
        options = vision.GestureRecognizerOptions(base_options=base_options,
                                                running_mode=vision.RunningMode.LIVE_STREAM,
                                                min_detection_confidence=0.5,
                                                min_suppression_threshold=0.5,
                                                result_callback = self.save_result)

        self.detector = vision.GestureRecognizer.create_from_options(options)

        self.curr_time = time.time_ns()
        self.prev_time = self.curr_time - 1

        self.get_logger().info("Starting gesture recognizer")

    def image_callback(self, msg):
        if not self.camera_on or not self.read_frame: return
        self.count += 1
        # print(f"{self.count} frames read, toggle:{self.camera_on}")

        self.read_frame = False
        rgb_image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        rgb_image = cv2.cvtColor(rgb_image, cv2.COLOR_BGR2RGB)
        rgb_image = cv2.rotate(rgb_image, cv2.ROTATE_180)
        mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb_image)

        self.prev_time = self.curr_time
        self.curr_time = time.time_ns()
        if self.curr_time == self.prev_time:
            return

        self.detector.recognize_async(mp_image, self.curr_time // 1_000_000)

    def save_result(self, result: vision.GestureRecognizerResult, unused_output_image: mp.Image, timestamp_ms: int):
        print(results)
        self.get_logger().info(str(results))
        self.read_frame = True
        
    def toggle_gesture_control_callback(self, request, response):
        self.camera_on = request.data
        response.success = True
        response.message = "Gesture control toggled"
        return response

def main(args=None):
    rclpy.init(args=args)

    node = GestureRecognizer()
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()
