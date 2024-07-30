from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    return LaunchDescription([
        ExecuteProcess(
            cmd=['ros2', 'launch', 'rosbridge_server', 'rosbridge_websocket_launch.xml', 'port:=9091'],
            output='screen'
        ),
        Node(
            package='nlp_subsystem',
            executable='voice_assistant',
            name='voice_assistant',
            output='screen'
        ),
        Node(
            package='controller',
            executable='handshake',
            name='handshake',
            output='screen'
        ),
        # Node(
        #     package='depthai_examples',
        #     executable='rgb_stereo_node',
        #     name='rgb_stereo_node',
        #     output='screen'
        # ),
        Node(
            package='cv_subsystem',
            executable='picam_publisher',
            name='picam_publisher',
            output='screen'
        ),
        Node(
            package='cv_subsystem',
            executable='capture_handler',
            name='capture_handler',
            output='screen'
        ),
        Node(
            package='cv_subsystem',
            executable='gesture_recognizer',
            name='gesture_recognizer',
            output='screen'
        ),
        Node(
            package='cv_subsystem',
            executable='face_detector',
            name='face_detector',
            output='screen'
        ),
        Node(
            package='controller',
            executable='robot_status',
            name='robot_status',
            output='screen'
        ),
        Node(
            package='controller',
            executable='app_control',
            name='app_control',
            output='screen'
        ),
        Node(
            package='controller',
            executable='settings_handler',
            name='settings_handler',
            output='screen'
        ),
        Node(
            package='controller',
            executable='controller',
            name='controller',
            output='screen'
        ),
        Node(
            package='user_interface',
            executable='flask_user_interface',
            name='flask_user_interface',
            output='screen'
        ),
    ])
