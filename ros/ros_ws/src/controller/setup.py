from setuptools import find_packages, setup

package_name = 'controller'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='dash',
    maintainer_email='dash@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "handshake = controller.handshake:main",
            "app_control = controller.app_control:main",
            "robot_status = controller.robot_status:main",
            "settings_handler = controller.settings_handler:main",
            "controller = controller.controller:main",
        ],
    },
)
