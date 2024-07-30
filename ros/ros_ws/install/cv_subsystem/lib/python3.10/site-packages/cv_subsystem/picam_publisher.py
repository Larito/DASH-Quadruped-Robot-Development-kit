import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2

class VideoPublisher(Node):
    def __init__(self):
        super().__init__('video_publisher')
        self.publisher_ = self.create_publisher(Image, 'image', 10)
        self.timer_ = self.create_timer(1.0 / 30, self.publish_frame)
        self.bridge_ = CvBridge()
        self.cap_ = cv2.VideoCapture(0)

        if not self.cap_.isOpened():
            self.get_logger().error('Error: Unable to open camera.')
            exit()

    def publish_frame(self):
        ret, frame = self.cap_.read()
        if not ret:
            self.get_logger().error('Error: Unable to capture frame.')
            return

        w,h,c = frame.shape
        frame = cv2.resize(frame, (h//3,w//3), interpolation=cv2.INTER_AREA)

        image_msg = self.bridge_.cv2_to_imgmsg(frame, 'bgr8')
        self.publisher_.publish(image_msg)

def main(args=None):
    rclpy.init(args=args)
    node = VideoPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
