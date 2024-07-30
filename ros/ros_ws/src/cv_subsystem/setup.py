from setuptools import find_packages, setup

package_name = 'cv_subsystem'

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
            "gesture_recognizer = cv_subsystem.gesture_recognizer:main",
            "picam_publisher = cv_subsystem.picam_publisher:main",
            "capture_handler = cv_subsystem.capture_handler:main",
            "face_detector = cv_subsystem.face_detector:main",
        ],
    },
)
