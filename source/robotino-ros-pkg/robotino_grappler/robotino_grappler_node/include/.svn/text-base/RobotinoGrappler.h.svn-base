/*
 * RobotinoGrappler.h
 *
 *  Created on: 01.02.2012
 *      Author: indorewala@servicerobotics.eu
 */

#ifndef ROBOTINOGRAPPLER_H_
#define ROBOTINOGRAPPLER_H_

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>

#include <sensor_msgs/JointState.h>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include "robotino_msgs/SetGrapplerAxes.h"
#include "robotino_msgs/SetGrapplerAxis.h"
#include "robotino_msgs/GrapplerReadings.h"
#include "robotino_grappler_msgs/GrapplerGripper.h"

typedef actionlib::SimpleActionServer<control_msgs::FollowJointTrajectoryAction> FJTServer;

class RobotinoGrappler
{
public:
	RobotinoGrappler(const std::string& fname);
	~RobotinoGrappler();
	void spin();

private:
	ros::NodeHandle nh_;

	ros::Publisher grappler_set_axes_pub_;
	ros::Publisher grappler_set_axis_pub_;
	ros::Publisher joint_state_pub_;
	ros::Publisher joint_path_pub_;

	ros::Subscriber grappler_readings_sub_;
	ros::Subscriber grappler_gripper_sub_;

	robotino_msgs::SetGrapplerAxes set_axes_msg_;
	robotino_msgs::SetGrapplerAxis set_axis_msg_;
	sensor_msgs::JointState joint_state_msg_;

	FJTServer server_;
	std::vector<float> calibration_;
	std::vector<float> calibration_factor_;

	void grapplerReadingsCb(const robotino_msgs::GrapplerReadingsConstPtr& msg);
	void grapplerGripperCb(const robotino_grappler_msgs::GrapplerGripperConstPtr &msg);
	void execute( const control_msgs::FollowJointTrajectoryGoalConstPtr& goal );
	void trajectoryToFollow(trajectory_msgs::JointTrajectory trj, bool& state);
	float degreesToRadians(float degrees);
	float radiansToDegrees(float radians);
	float degreesToDistance(float degrees);
};

#endif /* ROBOTINOGRAPPLER_H_ */
