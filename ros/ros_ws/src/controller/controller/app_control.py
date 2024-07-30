#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from geometry_msgs.msg import Twist

class AppControl(Node):
    def __init__(self):
        super().__init__("app_control_publisher")

        self.subscription = self.create_subscription(String,'/app_cmd_vel',self.listener_callback,10)
        self.twist_publisher = self.create_publisher(Twist, '/cmd_vel', 10)

    def listener_callback(self, msg):
        try:
            linearX, angularZ = msg.data.split('|')[0].split(':')[1], msg.data.split('|')[1].split(':')[1]
            linearX = float(linearX)
            angularZ = float(angularZ)

            twist_msg = Twist()
            twist_msg.linear.x = linearX
            twist_msg.angular.z = angularZ

            self.twist_publisher.publish(twist_msg)
            # self.get_logger().info(f"Published Twist: linearX={linearX}, angularZ={angularZ}")

        except ValueError:
            self.get_logger().error("Failed to parse command string")
            return

def main(args=None):
    rclpy.init(args=args)

    node = AppControl()
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()