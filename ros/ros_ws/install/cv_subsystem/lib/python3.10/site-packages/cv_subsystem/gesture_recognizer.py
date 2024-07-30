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

        self.camera_on = False
        self.read_frame = True
        self.bridge = CvBridge()

        # self.subscription = self.create_subscription(Image, '/color/video/image', self.listener_callback, 10)
        self.image_subscriber = self.create_subscription(Image,'image',self.image_callback,10)
        self.twist_publisher = self.create_publisher(Twist, '/cmd_vel', 10)

        # Create a service for toggling gesture control
        self.toggle_gesture_control_service = self.create_service(SetBool, 'toggle_gesture_control', self.toggle_gesture_control_callback)

        self.recognition_frame = None
        self.recognition_result_list = []

        model_path = "/home/dash/Desktop/ros_ws/src/cv_subsystem/models/gesture_recognizer.task"
        base_options = python.BaseOptions(model_asset_path=model_path)
        options = vision.GestureRecognizerOptions(base_options=base_options,
                                                running_mode=vision.RunningMode.LIVE_STREAM,
                                                num_hands=1,
                                                min_hand_detection_confidence=0.5,
                                                min_hand_presence_confidence=0.5,
                                                min_tracking_confidence=0.5,
                                                result_callback = self.save_result)

        self.recognizer = vision.GestureRecognizer.create_from_options(options)

        self.curr_time = time.time_ns()
        self.prev_time = self.curr_time - 1

        self.get_logger().info("Starting gesture recognizer")

    def image_callback(self, msg):
        if not self.camera_on or not self.read_frame: return

        self.read_frame = False
        rgb_image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        rgb_image = cv2.cvtColor(rgb_image, cv2.COLOR_BGR2RGB)
        mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb_image)

        self.prev_time = self.curr_time
        self.curr_time = time.time_ns()
        if self.curr_time == self.prev_time:
            return

        self.recognizer.recognize_async(mp_image, self.curr_time // 1_000_000)

        if self.recognition_result_list:
            for hand_index, hand_landmarks in enumerate(self.recognition_result_list[0].hand_landmarks):
                if self.recognition_result_list[0].gestures:
                    gesture = self.recognition_result_list[0].gestures[hand_index]
                    category_name = gesture[0].category_name

                    twist_msg = Twist()
                    if category_name == "ILoveYou":
                        twist_msg.linear.x = 0.5 # Forward
                        twist_msg.angular.z = 0.0
                    elif category_name == "Closed_Fist":
                        twist_msg.linear.x = -0.5 # Backward
                        twist_msg.angular.z = 0.0
                    elif category_name == "Pointing_Up":
                        twist_msg.linear.x = 0.0
                        twist_msg.angular.z = 0.5 # Left
                    elif category_name == "Victory":
                        twist_msg.linear.x = 0.0
                        twist_msg.angular.z = -0.5 # Right
                    elif category_name == "Open_Palm":
                        twist_msg.linear.x = 0.0
                        twist_msg.angular.z = 0.0

                    if category_name in ["ILoveYou", "Closed_Fist", "Pointing_Up", "Victory", "Open_Palm"]:
                        self.twist_publisher.publish(twist_msg)
                        self.get_logger().info(category_name)
                        print(category_name)

            self.recognition_result_list.clear()

    # def listener_callback(self, msg):
    #     if not self.camera_on or not self.read_frame: return
    #     self.count += 1
    #     print(f"{self.count} frames read, toggle:{self.camera_on}")

    #     self.read_frame = False

    #     np_image = np.frombuffer(msg.data, dtype=np.uint8).reshape(msg.height, msg.width, -1)
    #     rgb_image = cv2.cvtColor(np_image, cv2.COLOR_BGR2RGB)
    #     rgb_image = cv2.rotate(rgb_image, cv2.ROTATE_180)
    #     w,h,c = rgb_image.shape
    #     rgb_image = cv2.resize(rgb_image, (h//8,w//8), interpolation=cv2.INTER_AREA)
    #     mp_image = mp.Image(image_format=mp.ImageFormat.SRGB, data=rgb_image)

    #     self.prev_time = self.curr_time
    #     self.curr_time = time.time_ns()
    #     if self.curr_time == self.prev_time:
    #         return

    #     self.recognizer.recognize_async(mp_image, self.curr_time // 1_000_000)

    #     if self.recognition_result_list:
    #         for hand_index, hand_landmarks in enumerate(self.recognition_result_list[0].hand_landmarks):
    #             if self.recognition_result_list[0].gestures:
    #                 gesture = self.recognition_result_list[0].gestures[hand_index]
    #                 category_name = gesture[0].category_name

    #                 twist_msg = Twist()
    #                 if category_name == "ILoveYou":
    #                     twist_msg.linear.x = 0.5 # Forward
    #                     twist_msg.angular.z = 0.0
    #                 elif category_name == "Closed_Fist":
    #                     twist_msg.linear.x = -0.5 # Backward
    #                     twist_msg.angular.z = 0.0
    #                 elif category_name == "Pointing_Up":
    #                     twist_msg.linear.x = 0.0
    #                     twist_msg.angular.z = 0.5 # Left
    #                 elif category_name == "Victory":
    #                     twist_msg.linear.x = 0.0
    #                     twist_msg.angular.z = -0.5 # Right
    #                 elif category_name == "Open_Palm":
    #                     twist_msg.linear.x = 0.0
    #                     twist_msg.angular.z = 0.0

    #                 if category_name in ["ILoveYou", "Closed_Fist", "Pointing_Up", "Victory", "Open_Palm"]:
    #                     self.twist_publisher.publish(twist_msg)
    #                     self.get_logger().info(category_name)
    #                     print(category_name)

    #         self.recognition_result_list.clear()

    def save_result(self, result: vision.GestureRecognizerResult, unused_output_image: mp.Image, timestamp_ms: int):
        self.recognition_result_list.append(result)
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
