#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include <memory>

#include "robot_pose_msgs/msg/robot_pose_msg.hpp"

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>("hello_ros_sub_node");
  auto subscription =

      node->create_subscription<robot_pose_msgs::msg::RobotPoseMsg>(
          "robot_pose", 10, [node](robot_pose_msgs::msg::RobotPoseMsg::SharedPtr msg){
        RCLCPP_INFO(
          node->get_logger(),
          "x=%.2f, y=%.2f, z=%.2f",
          msg->x,
          msg->y,
          msg->z);
    for (size_t i = 0; i < msg->angles.data.size(); i++) {
        RCLCPP_INFO(
          node->get_logger(),
          "angles[%zu] = %.2f",
          i,
          msg->angles.data[i]);
      } });

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}