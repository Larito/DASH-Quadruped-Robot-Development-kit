import rclpy
from rclpy.node import Node
from robot_interfaces.srv import Config
import json

class SettingsHandler(Node):
    def __init__(self):
        super().__init__('handle_settings_handler')
        self.srv = self.create_service(Config, 'settings_handler', self.handle_settings_handler)
        self.config_file = '/home/dash/Desktop/config.json'

    def handle_settings_handler(self, request, response):
        if request.requesting:
            with open(self.config_file, 'r') as f:
                data = json.load(f)
            response.full_name = data['full_name']
            response.age = data['age']
            response.blood_type = data['blood_type']
            response.medical_notes = data['medical_notes']
            response.allergies = data['allergies']
            response.weight = data['weight']
            response.height = data['height']
            response.primary_language = data['primary_language']
            response.password = data['password']
        else:
            data = {
                'full_name': request.full_name,
                'age': request.age,
                'blood_type': request.blood_type,
                'medical_notes': request.medical_notes,
                'allergies': request.allergies,
                'weight': request.weight,
                'height': request.height,
                'primary_language': request.primary_language,
                'password': request.password,
            }
            with open(self.config_file, 'w') as f:
                json.dump(data, f)

            response.full_name = request.full_name
            response.age = request.age
            response.blood_type = request.blood_type
            response.medical_notes = request.medical_notes
            response.allergies = request.allergies
            response.weight = request.weight
            response.height = request.height
            response.primary_language = request.primary_language
            response.password = request.password
            
        return response

def main(args=None):
    rclpy.init(args=args)
    sh = SettingsHandler()
    rclpy.spin(sh)
    sh.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
