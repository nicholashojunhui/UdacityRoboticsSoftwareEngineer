#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"
#include <string>

ros::Publisher velocity_publisher;

bool handle_drive_request(ball_chaser::DriveToTarget::Request& req,
                          ball_chaser::DriveToTarget::Response& res)
{
    geometry_msgs::Twist velocity_cmd;

    velocity_cmd.linear.x  = req.linear_x;
    velocity_cmd.angular.z = req.angular_z;

    velocity_publisher.publish(velocity_cmd);

    res.msg_feedback = "Executed command -> linear: " +
                       std::to_string(req.linear_x) +
                       ", angular: " +
                       std::to_string(req.angular_z);

    ROS_INFO_STREAM("[Nicholas Controller] " << res.msg_feedback);

    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "nicholas_motion_controller");
    ros::NodeHandle nh;

    velocity_publisher =
        nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    ros::ServiceServer service =
        nh.advertiseService("/ball_chaser/command_robot", handle_drive_request);

    ROS_INFO("[Nicholas Controller] Motion service ready.");

    ros::spin();
    return 0;
}