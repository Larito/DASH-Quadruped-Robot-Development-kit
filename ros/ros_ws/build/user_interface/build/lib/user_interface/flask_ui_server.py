import rclpy
from rclpy.node import Node
from flask import Flask, render_template_string
from flask_socketio import SocketIO, emit
import socket
import threading
import webbrowser
import base64
import json
import cv2
from sensor_msgs.msg import Image
from std_msgs.msg import Float32
from cv_bridge import CvBridge
import numpy as np

class FlaskServer(Node):
    def __init__(self):
        super().__init__('flask_server')
        self.get_logger().info('Starting Flask server...')
        self.app = Flask(__name__)
        self.socketio = SocketIO(self.app)
        self.bridge = CvBridge()

        self.setup_routes()
        self.setup_socket_events()

        self.server_thread = threading.Thread(target=self.run_flask)
        self.server_thread.start()

        self.image_subscriber = self.create_subscription(Image, 'image', self.image_callback, 10)
        self.face_detector_subscriber = self.create_subscription(Float32, 'position_in_frame', self.face_callback, 10)

    def setup_routes(self):
        @self.app.route('/')
        def index():
            html_code = """
<!DOCTYPE html>
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>DASH UI</title>
        <script src="https://cdn.socket.io/4.0.0/socket.io.min.js"></script>
        <script>            
            document.addEventListener("DOMContentLoaded", function() {
                document.getElementById('ip_address').style.display = 'flex';
                document.getElementById('eyes_div').style.display = 'none';
                document.getElementById('settings_div').style.display = 'none';
                document.getElementById('main').style.display = 'none';
                document.getElementById('camera_div').style.display = 'none';

                var socket = io();
                let timeoutId;
                let currDiv = "ip_address"

                const canvas = document.getElementById('eyesCanvas');
                const ctx = canvas.getContext('2d');
                const eyeRadius = 250; // Increased eye radius for larger eyes
                const pupilRadius = 130;  // Increased pupil radius
                const eyeSpacing = 690; // Increased eye spacing for larger eyes
                const eyeY = canvas.height / 2;
                const leftEyeX = canvas.width / 2 - eyeSpacing / 2; // Adjusted left eye X position
                const rightEyeX = canvas.width / 2 + eyeSpacing / 2; // Adjusted right eye X position
                let isBlinking = false;
                let blinkFrame = 0;
                const totalBlinkFrames = 10; // Number of frames for the blink animation
                const maxX = 200; // Maximum value of maxPupilOffset
                const minX = -200; // Minimum value of maxPupilOffset

                function drawEye(x, y, pupilOffsetX, eyeOffsetX, blinkFrame) {
                    // Draw eye
                    ctx.beginPath();
                    ctx.arc(x + eyeOffsetX, y, eyeRadius, 0, Math.PI * 2);
                    ctx.fillStyle = 'white';
                    ctx.fill();
                    ctx.strokeStyle = 'black';
                    ctx.stroke();

                    if (blinkFrame > 0) {
                        // Draw blinking eye using clip
                        const blinkHeight = (eyeRadius * 2) * (blinkFrame / totalBlinkFrames);
                        ctx.save();
                        ctx.beginPath();
                        ctx.arc(x + eyeOffsetX, y, eyeRadius, 0, Math.PI * 2);
                        ctx.clip();
                        ctx.clearRect(x + eyeOffsetX - eyeRadius, y - eyeRadius, eyeRadius * 2, blinkHeight);
                        ctx.restore();
                    } else {
                        // Draw pupil
                        ctx.beginPath();
                        ctx.arc(x + pupilOffsetX + eyeOffsetX, y, pupilRadius, 0, Math.PI * 2);
                        ctx.fillStyle = 'black';
                        ctx.fill();
                    }
                }

                function blink() {
                    isBlinking = true;
                    blinkFrame = 0;
                    const blinkInterval = setInterval(() => {
                        blinkFrame++;
                        updateEyes(canvas.width / 2); // Force a redraw during the blink
                        if (blinkFrame >= totalBlinkFrames) {
                            clearInterval(blinkInterval);
                            setTimeout(() => {
                                isBlinking = false;
                                blinkFrame = 0;
                                updateEyes(canvas.width / 2); // Force a redraw after the blink
                            }, 200); // Pause before opening the eyes
                        }
                    }, 20); // Frame duration: 20ms
                }

                function showCurrDiv() {
                    document.getElementById('eyes_div').style.display = 'none';
                    document.getElementById('ip_address').style.display = 'none';
                    document.getElementById('settings_div').style.display = 'none';
                    document.getElementById('main').style.display = 'none';
                    document.getElementById('camera_div').style.display = 'none';
                    document.getElementById(currDiv).style.display = 'flex';
                    resetTimeout();
                }

                function resetTimeout() {
                    if (timeoutId) {
                        clearTimeout(timeoutId);
                    }
                    timeoutId = setTimeout(function() {
                        document.getElementById('eyes_div').style.display = 'flex';
                        document.getElementById('ip_address').style.display = 'none';
                        document.getElementById('settings_div').style.display = 'none';
                        document.getElementById('main').style.display = 'none';
                        document.getElementById('camera_div').style.display = 'none';
                    }, 15000);
                }

                document.addEventListener('mousemove', showCurrDiv);
                document.addEventListener('click', showCurrDiv);

                socket.on("position_in_frame", function(data) {
                    ctx.clearRect(0, 0, canvas.width, canvas.height);
                    
                    var pos = data.pos

                    const normalizedLeftPupilOffsetX = pos
                    const normalizedRightPupilOffsetX = pos


                    const leftPupilOffsetX = maxX * normalizedLeftPupilOffsetX - maxX / 2; // Adjusting centering offset
                    const rightPupilOffsetX = maxX * normalizedRightPupilOffsetX - maxX / 2; // Adjusting centering offset

                    // Calculate eye offset (not normalized)
                    const maxEyeOffset = 40; // Maximum eye movement offset
                    const leftEyeOffsetX = maxEyeOffset * (leftPupilOffsetX / maxX);
                    const rightEyeOffsetX = maxEyeOffset * (rightPupilOffsetX / maxX);

                    drawEye(leftEyeX, eyeY, leftPupilOffsetX, leftEyeOffsetX, isBlinking ? blinkFrame : 0);
                    drawEye(rightEyeX, eyeY, rightPupilOffsetX, rightEyeOffsetX, isBlinking ? blinkFrame : 0);

                });

                socket.on('icons', function(data) {
                    document.getElementById(data.id).src = 'data:image/png;base64,' + data.image;
                });

                socket.on('live_stream', function(data) {
                    document.getElementById("video").src = 'data:image/png;base64,' + data.image;
                });

                socket.on('ip', function(data) {
                    document.getElementById('ip').innerHTML = 'IP Address: ' + data.ip + ':9091';
                });

                document.getElementById('phone').addEventListener('click', function() {
                    currDiv = "ip_address"
                });

                document.getElementById('camera').addEventListener('click', function() {
                    currDiv = "camera_div"
                });

                document.getElementById('settings').addEventListener('click', function() {
                    currDiv = "settings_div"

                    socket.emit('get_settings');
                    socket.on('settings', function(data) {
                        data = JSON.parse(data);
                        document.getElementById('full_name').value = data.full_name;
                        document.getElementById('age').value = data.age;
                        document.getElementById('blood_type').value = data.blood_type;
                        document.getElementById('medical_notes').value = data.medical_notes;
                        document.getElementById('allergies').value = data.allergies;
                        document.getElementById('weight').value = data.weight;
                        document.getElementById('height').value = data.height;
                        document.getElementById('primary_language').value = data.primary_language;
                        document.getElementById('password').value = data.password;
                    });
                });

                document.getElementById('connect_without_phone').addEventListener('click', function() {
                    currDiv = "main"
                });

                document.getElementById('shutoff').addEventListener('click', function() {
                    socket.emit('shutoff');
                });

                document.getElementById('back').addEventListener('click', function() {
                    currDiv = "main"
                });

                document.getElementById('save_settings').addEventListener('click', function() {
                    socket.emit('save_settings', {
                        full_name: document.getElementById('full_name').value,
                        age: document.getElementById('age').value,
                        blood_type: document.getElementById('blood_type').value,
                        medical_notes: document.getElementById('medical_notes').value,
                        allergies: document.getElementById('allergies').value,
                        weight: document.getElementById('weight').value,
                        height: document.getElementById('height').value,
                        primary_language: document.getElementById('primary_language').value,
                        password: document.getElementById('password').value
                    }); 
                    currDiv = "main"
                });

                document.getElementById('camera_back').addEventListener('click', function() {
                    currDiv = "main"
                });
            });
        </script>
    </head>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Rajdhani:wght@300;400;500;600;700&display=swap" rel="stylesheet">
    <style>
        body{
            margin: 0;
            background-color: #69d2b5;
            color: white;
            font-family: "Rajdhani", sans-serif;
            user-select: none;
        }
        body *{
            margin: auto;
        }
        #main{
            display: flex;
            justify-content: center;
            flex-direction: column;
            align-items: center;
            height: 900px;
            width: 100%
        }
        .item{
            background-color: #1e1a33;
            border-radius: 20px;
            width: 350px;
            height: 350px;
            padding: 10px;
            display: flex;
            justify-content: center;
            flex-direction: column;
            cursor: pointer;
        }
        .item *{
            margin: auto;
            text-align: center;
        }
        .heading{
            font-size: 85px;
            text-align: center;
            font-weight: bold;
        }
        .row{
            display: flex;
            justify-content: center;
            align-items: center;
            width: 85%;
            height: 40%;
        }
        img{
            width: 75%;
            height: 75%;
            border-radius: 20px;
        }

        #settings_div{
            display: flex;
            flex-direction: column;
            justify-content: center;
            height: 900px;
            width: 60%;
            margin-top: 50px;
        }

        #settings_scroller{
            height: 700px;
            width: 100%;
            overflow-y: scroll;
            text-align: center;
        }

        input{
            width: 90%;
            height: 50px;
            border-radius: 10px;
            border: none;
            padding: 5px;
            font-size: 30px;
        }

        button{
            width: 97%;
            height: 50px;
            font-size: 30px;
            margin: 10px;
            border-radius: 10px;
            border: none;
            padding: 5px;
            background-color: #1e1a33;
            color: white;
            cursor: pointer;
        }

        h1{
            font-size: 65px;
            text-align: center;
        }
        h2{
            font-size: 40px;
            text-align: center;
        }

        p{
            font-size:27px;
            font-weight:bold;
        }

        #ip_address, #camera_div{
            display: flex;
            justify-content: center;
            flex-direction: column;
            align-items: center;
            height: 900px;
        }
    </style>
    <body>
        <div id = "eyes_div">
            <canvas id="eyesCanvas" width="1200" height="600"></canvas>
        </div>

        <div id="settings_div">
            <h1>Settings</h1>
            <div id="settings_scroller">
                <h2>User Details</h2>
                <p>Name</p>
                <input type="text" id="full_name" placeholder="Full Name" autocomplete="off"/><br><br>

                <p>Age</p>
                <input type="number" id="age" placeholder="Age" autocomplete="off"/><br><br>

                <p>Blood Type</p>
                <input type="text" id="blood_type" placeholder="Blood Type" autocomplete="off"/><br><br>

                <p>Medical Notes</p>
                <input type="text" id="medical_notes" placeholder="Medical Notes" autocomplete="off"/><br><br>

                <p>Allergies</p>
                <input type="text" id="allergies" placeholder="Allergies" autocomplete="off"/><br><br>

                <p>Weight</p>
                <input type="number" id="weight" placeholder="Weight" autocomplete="off"/><br><br>

                <p>Height</p>
                <input type="text" id="height" placeholder="Height" autocomplete="off"/><br><br>

                <p>Primary Language</p>
                <input type="text" id="primary_language" placeholder="Primary Language" autocomplete="off"/><br><br>

                <br>

                <h2>Account Information</h2>
                <p>Password</p>
                <input type="password" id="password" placeholder="Password"  /><br><br>
            </div>
            <button id="save_settings">Save</button>
            <button id="back">Back</button>
        </div>

        <div id="ip_address">
            <h1 id="ip">IP Address: </h1>
            <button id="connect_without_phone">Continue Without Phone</button>
        </div>

        <div id="camera_div">
            <img id="video" style="height: 80%; width: 50%;"/>
            <button id="camera_back">Back</button>
        </div>

        <div id="main">
            <div class="row">
                <!-- <div class="item" id="eyes">
                    <img id="navigate_img"/>
                    <h2>Eyes</h2>
                </div>
                <div class="item" id="map">
                    <img id="create_map_img"/>
                    <h2>Utils</h2>
                </div> -->

                <div class="item" id="camera">
                    <img id="camera_img"/>
                    <h2>Take Pictures</h2>
                </div>
                <div class="item" id="phone">
                    <img id="phone_img"/>
                    <h2>Connect Phone</h2>
                </div>
            </div>
            <div class="row">
                <!-- <div class="item" id="camera">
                    <img id="camera_img"/>
                    <h2>Take Pictures</h2>
                </div> -->
                <div class="item" id="settings">
                    <img id="settings_img"/>
                    <h2>Settings</h2>
                </div>
                <div class="item" id="shutoff" style="background-color:red">
                    <img id="shutoff_img"/>
                    <h2>Shutoff</h2>
                </div>
            </div>
        </div>
    </body>
</html>
            """
            return render_template_string(html_code)

    def setup_socket_events(self):
        @self.socketio.on('connect')
        def handle_connect():
            self.send_images()
            self.send_ip()

        @self.socketio.on('save_settings')
        def handle_save_settings(data):
            self.save_settings(data)

        @self.socketio.on('button_click')
        def handle_button_click(data):
            self.get_logger().info('Button was clicked on the webpage!')

        @self.socketio.on('get_settings')
        def handle_get_settings():
            self.get_settings()

    def run_flask(self):
        self.socketio.run(self.app, host='0.0.0.0', port=5000, allow_unsafe_werkzeug=True)

    def get_settings(self):
        with open('/home/dash/Desktop/config.json', 'r') as f:
            config = f.read()
        emit('settings', config)

    def save_settings(self, data):
        with open('/home/dash/Desktop/config.json', 'w') as f:
            f.write(json.dumps(data))  

    def send_ip(self):
        ip_address = ''
        try:
            s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
            s.settimeout(0)
            s.connect(('10.254.254.254', 1))
            ip_address = s.getsockname()[0]
            s.close()
        except Exception:
            ip_address = '127.0.0.1'
        
        emit("ip", {"ip":ip_address})

    # def image_callback(self, msg):
    #     np_image = np.frombuffer(msg.data, dtype=np.uint8).reshape(msg.height, msg.width, -1)
    #     rgb_image = cv2.cvtColor(np_image, cv2.COLOR_BGR2RGB)
    #     rgb_image = cv2.rotate(rgb_image, cv2.ROTATE_180)
    #     img_base64 = base64.b64encode(rgb_image).decode('utf-8')
        
    #     node.get_logger().info(len(img_base64))

        # self.socketio.emit('live_stream', {'image': img_base64})
        
    def face_callback(self, msg):
        self.socketio.emit('position_in_frame', {'pos': msg.data})

    def image_callback(self, msg):
        # try:
        frame = self.bridge.imgmsg_to_cv2(msg, 'bgr8')
        # rgb_image = cv2.rotate(frame, cv2.ROTATE_180)
        
        _, buffer = cv2.imencode('.jpg', frame)
        img_base64 = base64.b64encode(buffer).decode('utf-8')

        self.socketio.emit('live_stream', {'image': img_base64})
        # except:
        #     self.get_logger().error(f'Error in imaging')

    def send_images(self):
        images = {
            # 'navigate_img': '/home/dash/Desktop/ros_ws/src/user_interface/user_interface/static/images/navigate.png',
            # 'create_map_img': '/home/dash/Desktop/ros_ws/src/user_interface/user_interface/static/images/create_map.png',
            'phone_img': '/home/dash/Desktop/ros_ws/src/user_interface/user_interface/static/images/phone.png',
            'camera_img': '/home/dash/Desktop/ros_ws/src/user_interface/user_interface/static/images/camera.png',
            'settings_img': '/home/dash/Desktop/ros_ws/src/user_interface/user_interface/static/images/settings.png',
            'shutoff_img': '/home/dash/Desktop/ros_ws/src/user_interface/user_interface/static/images/shutoff.png'
        }
        
        for img_id, img_path in images.items():
            with open(img_path, "rb") as img_file:
                b64_string = base64.b64encode(img_file.read()).decode('utf-8')
                self.socketio.emit('icons', {'id': img_id, 'image': b64_string})

def open_browser():
    webbrowser.open('http://127.0.0.1:5000')

def main(args=None):
    rclpy.init(args=args)
    node = FlaskServer()
    threading.Timer(1.5, open_browser).start()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Shutting down Flask server...')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()


