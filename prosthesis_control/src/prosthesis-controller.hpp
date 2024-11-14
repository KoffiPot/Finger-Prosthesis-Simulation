#ifndef PROSTHESIS_NODE_H
#define PROSTHESIS_NODE_H

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

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

  class MinimalSubscriber : public rclcpp::Node
  {
  public:
    MinimalSubscriber(std::string node_name, std::string topic_name);

  private:
    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_;
  };
}

#endif
