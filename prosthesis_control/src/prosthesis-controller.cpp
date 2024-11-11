#include <cstdlib>
#include "prosthesis-controller.hpp"

using namespace std::chrono_literals;

namespace prosthesis_controller
{
  MinimalPublisher::MinimalPublisher (std::string node_name, std::string topic_name)
  : Node(node_name), count_(0)
  {  
      publisher_ = this->create_publisher<std_msgs::msg::Float64>(topic_name, 10);
      timer_ = this->create_wall_timer(
        2000ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

  void MinimalPublisher::timer_callback()
  {
      auto message = std_msgs::msg::Float64();
      //float vel = ((std::rand() % 41) - 20.f) / 10;
      float vel_diff = ((std::rand() % 21) - 10.f) / 10;
      //message.data = count_++;
      message.data = 1.f + vel_diff;
      RCLCPP_INFO(this->get_logger(), "Publishing: '%f'", message.data);
      publisher_->publish(message);
  }
}
