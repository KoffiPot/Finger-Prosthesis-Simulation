# Prosthesis Control

TODO: description


## Get Started
1. Build node
```
colcon build --symlink-install
```
2. Source build
```
. install/setup.bash
```
3. Start node
```
ros2 run prosthesis_control prosthesis-controller
```

- You can also use the following start script to start the ROS2 node.
```
./scripts/start-ros2-controller.sh
```

- Might require adding `x` access
```
chmod +x ./scripts/start-ros2-controller.sh
```
