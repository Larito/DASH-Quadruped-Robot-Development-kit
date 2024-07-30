#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from robot_interfaces.srv import Handshake
import json

class HandShakeService(Node):
    def __init__(self):
        super().__init__("handshake_Server")

        self.config_file_path = '/home/dash/Desktop/config.json'
        self.server_ = self.create_service(Handshake, "handshaking", self.callback_handshake)
    
    def callback_handshake(self, request, response):
        password = request.password
        correct_password = "1234"
        
        with open(self.config_file_path, 'r') as file:
            config_data = json.load(file)
            correct_password = config_data["password"]

        response.correct = password == correct_password
        self.get_logger().info("Password is correct: " + str(response.correct))

        return response

def main(args=None):
    rclpy.init(args=args)

    node = HandShakeService()
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()