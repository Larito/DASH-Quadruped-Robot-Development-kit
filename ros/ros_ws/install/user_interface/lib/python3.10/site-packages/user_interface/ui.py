import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
import tkinter as tk
from PIL import Image as PILImage, ImageTk
from threading import Thread
import socket
import numpy as np
import cv2
import json
import os

CONFIG_FILE_PATH = "/home/dash/Desktop/configs.json"

class UI(Node):
    def __init__(self):
        super().__init__('ui')
        self.show_ip_address = True
        self.shutdown_flag = False
        self.current_screen = 'buttons'

        self.subscription = self.create_subscription(Image, '/color/video/image', self.listener_callback, 10)
        self.image_frame = None
        self.photo = None

        self.thread = Thread(target=self.start_tkinter_app)
        self.thread.start()

    def get_ip_address(self):
        try:
            s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            s.settimeout(0)
            s.connect(('10.254.254.254', 1))
            ip_address = s.getsockname()[0]
            s.close()
        except Exception:
            ip_address = '127.0.0.1'
        return ip_address

    def start_tkinter_app(self):
        self.root = tk.Tk()
        self.root.title("ROS 2 Tkinter App")
        self.root.attributes('-fullscreen', True)

        self.center_frame = tk.Frame(self.root)
        self.center_frame.pack(expand=True)

        if self.show_ip_address:
            self.display_ip_address()
        else:
            self.display_buttons()

        self.root.mainloop()

    def display_ip_address(self):
        self.clear_center_frame()
        self.current_screen = 'ip_address'

        ip_address = self.get_ip_address()
        self.ip_label = tk.Label(self.center_frame, text=f"{ip_address}", font=("Helvetica", 24))
        self.ip_label.pack(pady=20)

        self.continue_button = tk.Button(self.center_frame, text="Continue without phone", font=("Helvetica", 16), command=self.continue_without_phone)
        self.continue_button.pack(pady=20)

    def continue_without_phone(self):
        self.show_ip_address = False
        self.display_buttons()

    def display_buttons(self):
        self.clear_center_frame()
        self.current_screen = 'buttons'

        self.buttons_frame = tk.Frame(self.center_frame)
        self.buttons_frame.pack(expand=True)

        self.create_button("/home/dash/Desktop/ros_ws/src/user_interface/images/nav_to.png", "Navigate", 0, 0)
        self.create_button("/home/dash/Desktop/ros_ws/src/user_interface/images/create_map.png", "Create Map", 0, 1)
        self.create_button("/home/dash/Desktop/ros_ws/src/user_interface/images/connect_phone.png", "Connect Phone", 0, 2)
        self.create_button("/home/dash/Desktop/ros_ws/src/user_interface/images/take_pictures.png", "Take Pictures", 1, 0)
        self.create_button("/home/dash/Desktop/ros_ws/src/user_interface/images/settings.png", "Settings", 1, 1)
        self.create_button("/home/dash/Desktop/ros_ws/src/user_interface/images/shut_off.png", "Shutoff", 1, 2)

    def clear_center_frame(self):
        for widget in self.center_frame.winfo_children():
            widget.destroy()

    def create_button(self, image_path, text, row, column):
        img = PILImage.open(image_path).resize((100, 100), PILImage.ANTIALIAS)
        photo = ImageTk.PhotoImage(img)

        button = tk.Button(self.buttons_frame, image=photo, text=text, compound=tk.TOP, command=lambda: self.button_callback(text))
        button.image = photo  # Keep a reference to avoid garbage collection
        button.grid(row=row, column=column, padx=20, pady=20)

    def button_callback(self, text):
        self.get_logger().info(f"Button '{text}' pressed")
        if text == "Shutoff":
            self.shutdown_node()
        elif text == "Take Pictures":
            self.display_image_stream()
        elif text == "Connect Phone":
            self.display_ip_address()
        elif text == "Settings":
            self.display_settings()

    def display_image_stream(self):
        self.clear_center_frame()
        self.current_screen = 'image_stream'

        self.image_frame = tk.Label(self.center_frame)
        self.image_frame.pack(pady=20)

        self.back_button = tk.Button(self.center_frame, text="Back", font=("Helvetica", 16), command=self.display_buttons)
        self.back_button.pack(pady=20)

    def display_settings(self):
        self.clear_center_frame()
        self.current_screen = 'settings'

        settings = self.load_settings()

        form_fields = [
            ("Full Name", "name"),
            ("Age", "age"),
            ("Blood Type", "blood_type"),
            ("Medical Notes", "medical_notes"),
            ("Allergies", "allergies"),
            ("Weight", "weight"),
            ("Height", "height"),
            ("Primary Language", "primary_language"),
            ("Password", "password")
        ]

        self.entries = {}

        for label_text, field in form_fields:
            label = tk.Label(self.center_frame, text=label_text, font=("Helvetica", 14))
            label.pack(pady=5)
            entry = tk.Entry(self.center_frame, font=("Helvetica", 14))
            entry.pack(pady=5)
            entry.insert(0, settings.get(field, ""))
            self.entries[field] = entry

        self.save_button = tk.Button(self.center_frame, text="Save", font=("Helvetica", 16), command=self.save_settings)
        self.save_button.pack(pady=20)

        self.back_button = tk.Button(self.center_frame, text="Back", font=("Helvetica", 16), command=self.display_buttons)
        self.back_button.pack(pady=20)

    def load_settings(self):
        if os.path.exists(CONFIG_FILE_PATH):
            with open(CONFIG_FILE_PATH, 'r') as f:
                return json.load(f)
        return {}

    def save_settings(self):
        settings = {field: entry.get() for field, entry in self.entries.items()}

        if os.path.exists(CONFIG_FILE_PATH):
            with open(CONFIG_FILE_PATH, 'r') as f:
                data = json.load(f)
        else:
            data = {}

        data.update(settings)

        with open(CONFIG_FILE_PATH, 'w') as f:
            json.dump(data, f, indent=4)

        self.get_logger().info("Settings saved")

    def listener_callback(self, msg):
        if self.current_screen == 'image_stream':
            np_image = np.frombuffer(msg.data, dtype=np.uint8).reshape(msg.height, msg.width, -1)
            rgb_image = cv2.cvtColor(np_image, cv2.COLOR_BGR2RGB)

            pil_image = PILImage.fromarray(rgb_image)
            pil_image = pil_image.resize((640, 480), PILImage.ANTIALIAS)

            self.photo = ImageTk.PhotoImage(pil_image)

            self.image_frame.config(image=self.photo)
            self.image_frame.image = self.photo  # Keep a reference to avoid garbage collection

    def shutdown_node(self):
        self.get_logger().info("Shutting down node...")
        self.shutdown_flag = True
        self.destroy_node()
        self.root.quit()

def main(args=None):
    rclpy.init(args=args)
    tkinter_ros_app = UI()

    while rclpy.ok() and not tkinter_ros_app.shutdown_flag:
        rclpy.spin_once(tkinter_ros_app, timeout_sec=0.1)

    tkinter_ros_app.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
