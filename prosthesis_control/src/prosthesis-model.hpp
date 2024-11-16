#ifndef PROSTHESIS_MODEL_NODE_H
#define PROSTHESIS_MODEL_NODE_H

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float64.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

#include <Eigen/Dense>

using namespace std;
using Eigen::MatrixXd;

// Adapted from Blana et al. 2017
namespace prosthesis_controller
{
  // TODO read from config?
  const int NUMBER_OF_ANGLES = 2;
  const int NUMBER_OF_TODO = 2;
  
  class Dynamics
  {
    private:
      MatrixXd mass = MatrixXd(NUMBER_OF_TODO,NUMBER_OF_ANGLES);
      // double coefficient_matrix[NUMBER_OF_TODO][NUMBER_OF_ANGLES];
      // double angles[NUMBER_OF_ANGLES];
      // double force_effects[NUMBER_OF_ANGLES];
      // double joint_moments[NUMBER_OF_ANGLES];
      // double passive_equilibrium_posture[NUMBER_OF_ANGLES] = { [0 .. NUMBER_OF_ANGLES-1] = 0.1 }; //in Nm/rad

      int muscle_activation_time = 15; //in ms
      int muscle_deactivation_time = 50; //in ms

    public:
      static void print_julia();
  };
}

#endif
