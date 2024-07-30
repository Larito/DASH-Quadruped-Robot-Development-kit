#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from robot_interfaces.srv import LMChat

def main(args=None):
    rclpy.init(args=args)
    node = Node("lm_test")

    client = node.create_client(LMChat, "chat")
    while not client.wait_for_service(1.0):
        node.get_logger().warn("Waiting for server")

    request = LMChat.Request()
    request.in_msg = "Hi! How are you?"

    future = client.call_async(request)
    rclpy.spin_until_future_complete(node, future)

    try:
        response = future.result()
        node.get_logger().info(str(response.out_msg))
    except Exception as e:
        node.get_logger().info(e)

    rclpy.shutdown()

if __name__ == '__main__':
    main()