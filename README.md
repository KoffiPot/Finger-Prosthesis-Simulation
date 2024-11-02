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
- Gazebo topics are not be visible when using `ros2 topic list` (requires Gazebo-ROS-bridge)
- To publish to a Gazebo topic use `gz topic`
    * Example: `gz topic -t "/cmd_vel" -m gz.msgs.Twist -p "linear: {x: 0.5}, angular: {z: 0.05}"`
