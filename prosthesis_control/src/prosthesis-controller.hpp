#ifndef PROSTHESIS_NODE_H
#define PROSTHESIS_NODE_H

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"

namespace prosthesis_controller
{
  class MinimalPublisher : public rclcpp::Node
  {
  public:
    MinimalPublisher(std::string node_name, std::string topic_name);

  private:
    void timer_callback();
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Float64>::SharedPtr publisher_;
    size_t count_;
  };
}

#endif
