#include "prosthesis-controller.hpp"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  rclcpp::executors::MultiThreadedExecutor executor;

  std::variant<std::shared_ptr<prosthesis_controller::MinimalPublisher>> base_lower_node = 
    std::make_shared<prosthesis_controller::MinimalPublisher>("base_lower_publisher", "/gz/finger/joint/base_lower_joint/cmd_vel");
  std::variant<std::shared_ptr<prosthesis_controller::MinimalPublisher>> mid_upper_node = 
    std::make_shared<prosthesis_controller::MinimalPublisher>("mid_upper_publisher", "/gz/finger/joint/mid_upper_joint/cmd_vel");
  std::variant<std::shared_ptr<prosthesis_controller::MinimalSubscriber>> mid_upper_state_node = 
    std::make_shared<prosthesis_controller::MinimalSubscriber>("mid_upper_subscriber", "/gz/finger/joint/mid_upper_joint/joint_state");
  std::visit([&executor](auto&& arg) { executor.add_node(arg); }, base_lower_node);
  std::visit([&executor](auto&& arg) { executor.add_node(arg); }, mid_upper_node);
  std::visit([&executor](auto&& arg) { executor.add_node(arg); }, mid_upper_state_node);
  
  executor.spin();
  rclcpp::shutdown();
  return 0;
}
