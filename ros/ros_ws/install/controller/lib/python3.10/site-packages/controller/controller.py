#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from geometry_msgs.msg import Twist
import serial
import threading

class AppControl(Node):
    def __init__(self):
        super().__init__("app_control_publisher")

        self.subscription = self.create_subscription(Twist, '/cmd_vel', self.listener_callback, 10)
        
        self.mega_port1 = '/dev/ttyACM0'
        self.mega_port2 = '/dev/ttyACM1'
        self.mega_port3 = '/dev/ttyACM2'
        self.baudrate = 9600
        try:
            self.mega1 = serial.Serial(self.mega_port1, self.baudrate, timeout=1)
            self.get_logger().info(f"Serial port {self.mega_port1} opened successfully.")
            
            self.mega2 = serial.Serial(self.mega_port2, self.baudrate, timeout=1)
            self.get_logger().info(f"Serial port {self.mega_port2} opened successfully.")
            
            self.mega3 = serial.Serial(self.mega_port3, self.baudrate, timeout=1)
            self.get_logger().info(f"Serial port {self.mega_port3} opened successfully.")
            
        except serial.SerialException as e:
            self.get_logger().error(f"Failed to open serial port: {e}")

    def listener_callback(self, msg):
        try:
            linearX, angularZ = msg.linear.x, msg.angular.z

            if linearX > 0:
                command = 'w'
            elif linearX < 0:
                command = 's'
            elif angularZ > 0:
                command = 'a'
            elif angularZ < 0:
                command = 'd'
            else:
                command = 'x'

            self.get_logger().info(f"Received Twist: linearX={linearX}, angularZ={angularZ}")
            
            # Create threads for each serial write operation
            thread1 = threading.Thread(target=self.write_to_serial, args=(self.mega1, command))
            thread2 = threading.Thread(target=self.write_to_serial, args=(self.mega2, command))
            thread3 = threading.Thread(target=self.write_to_serial, args=(self.mega3, command))
            
            # Start the threads
            thread1.start()
            thread2.start()
            thread3.start()
            
            # Optionally join the threads if you want to wait for them to finish
            thread1.join()
            thread2.join()
            thread3.join()

        except ValueError:
            self.get_logger().error("Failed to parse command string")
            return
        except serial.SerialException as e:
            self.get_logger().error(f"Failed to write to serial port: {e}")

    def write_to_serial(self, serial_port, command):
        try:
            serial_port.write(command.encode())
            self.get_logger().info(f"Sent command '{command}' to serial port {serial_port.port}.")
        except serial.SerialException as e:
            self.get_logger().error(f"Failed to write to serial port {serial_port.port}: {e}")

def main(args=None):
    rclpy.init(args=args)

    node = AppControl()
    rclpy.spin(node)

    rclpy.shutdown()

if __name__ == '__main__':
    main()
