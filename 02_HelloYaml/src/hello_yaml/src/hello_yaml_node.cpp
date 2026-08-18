#include <chrono>
#include <functional>
#include <memory>

#include "geometry_msgs/msg/point32.hpp"
#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class HelloYamlNode : public rclcpp::Node
{
private:
  void publish_callback(){
    geometry_msgs::msg::Point32 message;

    message.x = static_cast<float>(x_);
    message.y = static_cast<float>(y_);
    message.z = static_cast<float>(z_);

    publisher_->publish(message);

    RCLCPP_INFO(
        this->get_logger(),
        "x=%.2f, y=%.2f, z=%.2f",
        message.x,
        message.y,
        message.z);
  }

  double x_;
  double y_;
  double z_;

  rclcpp::Publisher<geometry_msgs::msg::Point32>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;

public:
  HelloYamlNode() : Node("hello_yaml_node"){
    x_ = this->declare_parameter<double>("x", 0.0);
    y_ = this->declare_parameter<double>("y", 0.0);
    z_ = this->declare_parameter<double>("z", 0.0);

    publisher_ =
        this->create_publisher<geometry_msgs::msg::Point32>(
            "initial_coordinate", 10);

    timer_ = this->create_wall_timer(
        1s,
        std::bind(&HelloYamlNode::publish_callback, this));
  }
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<HelloYamlNode>();

  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}
