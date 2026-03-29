#!/bin/sh

xterm -e "roslaunch turtlebot3_gazebo turtlebot3_world.launch" &
sleep 5

xterm -e "roslaunch add_markers amcl.launch map_file:=$HOME/catkin_ws/src/map/TB3_WORLD.yaml" &
sleep 5

xterm -e "roslaunch add_markers view_home_service_navigation.launch rviz_path:=$HOME/catkin_ws/src/rvizConfig/home_service_rvizConfig.rviz" &
sleep 5

xterm -e "rosrun add_markers initial_pose2.py"
