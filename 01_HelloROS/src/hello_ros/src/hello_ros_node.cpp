#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include <chrono>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>("hello_ros_node");

  auto publisher =
    node->create_publisher<std_msgs::msg::String>(
      "hello_ros_topic", 10);

  auto timer = node->create_wall_timer(
    1000ms,
    [node, publisher]()
    {
      std_msgs::msg::String message;
      message.data = "ros";

        message.data.c_str();

      publisher->publish(message);
    });

  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}
