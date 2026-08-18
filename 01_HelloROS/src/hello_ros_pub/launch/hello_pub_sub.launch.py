from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription([
        Node(
            package='hello_ros_pub',
            executable='hello_ros_pub_node',
            name='hello_ros_pub_node',
            output='screen'
        ),
        Node(
            package='hello_ros_sub',
            executable='hello_ros_sub_node',
            name='hello_ros_sub_node',
            output='screen'
        )
    ])