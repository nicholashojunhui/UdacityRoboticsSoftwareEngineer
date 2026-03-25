#!/bin/sh

path_catkin_ws="/home/workspace/catkin_ws"

xterm -e "cd $path_catkin_ws && source /opt/ros/kinetic/setup.bash && source devel/setup.bash && roslaunch turtlebot_gazebo turtlebot_world.launch" &
sleep 5

xterm -e "cd $path_catkin_ws && source /opt/ros/kinetic/setup.bash && source devel/setup.bash && roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$path_catkin_ws/src/map/map.yaml" &
sleep 5

xterm -e "cd $path_catkin_ws && source /opt/ros/kinetic/setup.bash && source devel/setup.bash && roslaunch turtlebot_rviz_launchers view_navigation.launch"