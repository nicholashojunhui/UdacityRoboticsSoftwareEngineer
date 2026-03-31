#!/bin/sh

MAP_PATH=$(rospack find add_markers)/../map/TB3_WORLD.yaml
RVIZ_PATH=$(rospack find add_markers)/../rvizConfig/home_service_rvizConfig.rviz

xterm -e "roslaunch turtlebot3_gazebo turtlebot3_world.launch" &
sleep 5

#xterm -e "roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=$HOME/catkin_ws/src/map/TB3_WORLD.yaml" &

xterm -e "roslaunch add_markers amcl.launch map_file:=$MAP_PATH" &
sleep 5

xterm -e "roslaunch add_markers view_home_service_navigation.launch rviz_path:=$RVIZ_PATH" &
sleep 5

xterm -e "rosrun add_markers initial_pose2.py" &
sleep 5

xterm -e "rosrun add_markers add_markers" &
sleep 3

xterm -e "rosrun pick_objects pick_objects"
