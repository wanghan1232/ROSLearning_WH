#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include<memory>

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>("hello_ros_sub_node");

  auto subscription =
    node->create_subscription<std_msgs::msg::String>(
      "hello_ros_pub_topic", 10,
      [node](std_msgs::msg::String::SharedPtr msg) {
        RCLCPP_INFO_STREAM(node->get_logger(), msg->data);
      });

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}