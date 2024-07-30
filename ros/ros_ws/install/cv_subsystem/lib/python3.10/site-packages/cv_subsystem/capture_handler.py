import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError
from robot_interfaces.srv import ImageCapture
import cv2
import base64
import numpy as np

class CaptureHandler(Node):
    def __init__(self):
        super().__init__('capture_handler')
        self.picam_sub = self.create_subscription(Image, 'image', self.callback, 10)
 
        self.bridge = CvBridge()
        self.current_image = None

        self.srv = self.create_service(ImageCapture, 'image_capture', self.handle_image_capture)

    def callback(self, msg):
        try:
            cv_image = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
            self.current_image = cv_image

        except CvBridgeError as e:
            self.get_logger().error(f'Error converting image: {e}')

    def handle_image_capture(self, request, response):
        self.get_logger().info("=========================")
        if request.command == "capture":
            if self.current_image is not None:
                _, buffer = cv2.imencode('.jpg', self.current_image)
                image_base64 = base64.b64encode(buffer).decode('utf-8')
                response.image_base64 = image_base64
            else:
                response.image_base64 = ""
        # elif request.command == "swap":
        #     self.active_camera = "back" if self.active_camera == "front" else "front"
        #     response.image_base64 = ""
            
        #     # Write camera state to camera_state.txt
        #     with open('/home/dash/Desktop/camera_state.txt', 'w') as file:
        #         file.write(f'{self.active_camera}\n')

        return response


def main(args=None):
    rclpy.init(args=args)
    node = CaptureHandler()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
