#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from robot_interfaces.srv import RobotStatusSrv
import json

class RobotStatus(Node):
    def __init__(self):
        super().__init__("RobotStatus_Server")
        self.server_ = self.create_service(RobotStatusSrv, "statusing", self.callback)
    
    def callback(self, request, response):
        response.battery_level = 3
        response.current_mode = 1

        self.get_logger().info("Robot sent status update to mobile device")

        return response

def main(args=None):
    rclpy.init(args=args)

    node = RobotStatus()
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()