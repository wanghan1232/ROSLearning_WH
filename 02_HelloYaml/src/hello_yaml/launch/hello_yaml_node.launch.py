import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    package_share_directory =get_package_share_directory("hello_yaml")

    parameter_file = os.path.join(
      package_share_directory,
      "config",
      "hello_yaml_node.yaml")

    return LaunchDescription([
      Node(
        package="hello_yaml",
        executable="hello_yaml_node",
        name="hello_yaml_node",
        output="screen",
        parameters=[parameter_file])
    ])
