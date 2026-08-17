#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

#include <chrono>
#include <memory>

#include "robot_pose_msgs/msg/robot_pose_msg.hpp"
using namespace std::chrono_literals;

int main(int argc, char **argv)
{

  float x = 0.0f;
  float y = 0.0f;
  float z = 0.0f;

  float angle0 = 0.0f;
  float angle1 = 0.0f;
  float angle2 = 0.0f;
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>("hello_ros_pub_node");

  auto publisher =
      node->create_publisher<robot_pose_msgs::msg::RobotPoseMsg>(
          "robot_pose", 10);

  auto timer = node->create_wall_timer(
      1000ms,
      [publisher, &x, &y, &z, &angle0, &angle1, &angle2]() 
      {
        robot_pose_msgs::msg::RobotPoseMsg message;

        message.x = x;
        message.y = y;
        message.z = z;

        message.angles.data = {
            angle0,
            angle1,
            angle2};
        publisher->publish(message);
        x += 0.1f;
        y += 0.1f;
        z += 0.1f;

        angle0 += 0.1f;
        angle1 += 0.1f;
        angle2 += 0.1f;
      });

  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}
