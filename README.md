# Finger prosthesis simulation with Gazebo

- [Prerequisites](#prerequisites)
- [Starting Simulation](#starting-simulation)
- [Notes](#notes)

## Prerequisites
- [Gazebo](https://gazebosim.org/api/sim/8/index.html)

## Starting Simulation
You can start the simulation by using 
```
./scripts/start-simulation.sh
```
- Might require `chmod +x ./scripts/start-simulation.sh`

or manually type 
```
export GZ_SIM_RESOURCE_PATH=${PWD}/simulation-descriptions/models
gz sim simulation-descriptions/world.sdf
```

## Notes
- To learn more about about SDF format which is used for the description of the Gazebo simulation see [SDF Format Specification](http://sdformat.org/spec?ver=1.8&elem=sdf)

- To publish to a Gazebo topic use `gz topic`
    * Example: `gz topic -t "/cmd_vel" -m gz.msgs.Twist -p "linear: {x: 0.5}, angular: {z: 0.05}"`

- Gazebo topics are not be visible when using `ros2 topic list` (requires Gazebo-ROS-bridge)
    - See also [Bridge communication between ROS and Gazebo (Github)](https://github.com/gazebosim/ros_gz/tree/ros2/ros_gz_bridge)
    - A bridge can be started like this:
```
ros2 run ros_gz_bridge parameter_bridge --ros-args -p config_file:=./config/ros_gz.yml
```
