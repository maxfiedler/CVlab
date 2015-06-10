/*
 * RobotinoGrappler.cpp
 *
 *  Created on: 01.02.2012
 *      Author: indorewala@servicerobotics.eu
 */

#include "RobotinoGrappler.h"
#include <fstream>
#include "yaml-cpp/yaml.h"
#include <boost/bind.hpp>

RobotinoGrappler::RobotinoGrappler(const std::string& fname):
	server_(nh_, "/follow_joint_trajectory",
			boost::bind(&RobotinoGrappler::execute, this, _1), false)
{
	grappler_set_axes_pub_ = nh_.advertise<robotino_msgs::SetGrapplerAxes>("set_grappler_axes", 1, false);
	grappler_set_axis_pub_ = nh_.advertise<robotino_msgs::SetGrapplerAxis>("set_grappler_axis", 1, false);
	joint_state_pub_ = nh_.advertise<sensor_msgs::JointState> ("grappler_joint_states", 1, false );

	grappler_readings_sub_ = nh_.subscribe("grappler_readings", 1, &RobotinoGrappler::grapplerReadingsCb, this);
	grappler_gripper_sub_ = nh_.subscribe("grappler_gripper", 1, &RobotinoGrappler::grapplerGripperCb, this);

	calibration_.resize(4, 0.0);
	calibration_factor_.resize(4, 1.0);

	joint_state_msg_.name.resize(6);
	joint_state_msg_.position.resize(6, 0.0);
	joint_state_msg_.name[0] = "grappler_arm_joint";
	joint_state_msg_.name[1] = "grappler_finger02_joint";
	joint_state_msg_.name[2] = "grappler_shoulder_pan_joint";
	joint_state_msg_.name[3] = "grappler_finger01_joint";
	joint_state_msg_.name[4] = "grappler_forearm_joint";
	joint_state_msg_.name[5] = "grappler_wrist_joint";

	server_.start();

	std::ifstream fin(fname.c_str());
	if(fin.fail())
	{
		ROS_ERROR("robotino_grappler_node could not open file: %s", fname.c_str());
	}

	YAML::Parser parser(fin);
	YAML::Node doc;
	parser.GetNextDocument(doc);

	try{
		doc["grappler_angles"][0] >> calibration_[0];
		doc["grappler_angles"][1] >> calibration_[1];
		doc["grappler_angles"][2] >> calibration_[2];
		doc["grappler_angles"][3] >> calibration_[3];

		doc["grappler_correction_factor"][0] >> calibration_factor_[0];
		doc["grappler_correction_factor"][1] >> calibration_factor_[1];
		doc["grappler_correction_factor"][2] >> calibration_factor_[2];
		doc["grappler_correction_factor"][3] >> calibration_factor_[3];

		ROS_INFO("Calibration values read.");
	}
	catch (YAML::InvalidScalar)
	{
		ROS_WARN("Grappler not calibrated");
	}
}

RobotinoGrappler::~RobotinoGrappler()
{
	server_.shutdown();
	grappler_set_axes_pub_.shutdown();
	grappler_set_axis_pub_.shutdown();
	joint_state_pub_.shutdown();
	grappler_readings_sub_.shutdown();
}

void RobotinoGrappler::spin()
{
	while(nh_.ok())
	{
		ros::Rate lp(10);

		ros::spinOnce();
		lp.sleep();
	}
}

void RobotinoGrappler::grapplerReadingsCb(const robotino_msgs::GrapplerReadingsConstPtr& msg)
{
	joint_state_msg_.header.stamp = ros::Time::now();
	joint_state_msg_.position[0] =
			-(degreesToRadians(msg->angles[0] - calibration_[0])) * calibration_factor_[0];
	joint_state_msg_.position[1] = degreesToDistance(msg->angles[3] - calibration_[3]);
	joint_state_msg_.position[2] = 0.0;
	joint_state_msg_.position[3] = -joint_state_msg_.position[1];
	joint_state_msg_.position[4] =
			(degreesToRadians(msg->angles[1] - calibration_[1])) * calibration_factor_[1];
	joint_state_msg_.position[5] =
			-(degreesToRadians(msg->angles[2] - calibration_[2])) * calibration_factor_[2];

	joint_state_pub_.publish(joint_state_msg_);
}

void RobotinoGrappler::grapplerGripperCb(const robotino_grappler_msgs::GrapplerGripperConstPtr &msg)
{
	set_axis_msg_.axis = 3;
	set_axis_msg_.angle = calibration_[3] - msg->angle;
	set_axis_msg_.velocity = 4.0;
	grappler_set_axis_pub_.publish( set_axis_msg_ );
}

void RobotinoGrappler::execute( const control_msgs::FollowJointTrajectoryGoalConstPtr& goal )
{
	bool state = false;
	trajectory_msgs::JointTrajectory trj = goal->trajectory;
	trajectoryToFollow( trj, state );

	if( state )
		server_.setSucceeded();
	else
		server_.setAborted();
}

void RobotinoGrappler::trajectoryToFollow(trajectory_msgs::JointTrajectory trj, bool& state)
{
	set_axes_msg_.angles.resize(3);
	set_axes_msg_.velocities.resize(3, 3.0);

	for( unsigned int i = 0; i < trj.points.size(); ++i )
	{
		set_axes_msg_.angles[0] = radiansToDegrees( trj.points[i].positions[1] / calibration_factor_[0] );
		set_axes_msg_.angles[1] = radiansToDegrees( trj.points[i].positions[2] / calibration_factor_[1] );
		set_axes_msg_.angles[2] = radiansToDegrees( trj.points[i].positions[3] / calibration_factor_[2] );

		set_axes_msg_.angles[0] = calibration_[0] - set_axes_msg_.angles[0];
		set_axes_msg_.angles[1] = calibration_[1] + set_axes_msg_.angles[1];
		set_axes_msg_.angles[2] = calibration_[2] - set_axes_msg_.angles[2];

		grappler_set_axes_pub_.publish(set_axes_msg_);
	}
	state = true;
}

float RobotinoGrappler::degreesToRadians(float degrees)
{
	return ((degrees/180) * 3.1416);
}

float RobotinoGrappler::radiansToDegrees(float radians)
{
	return ((radians*180) / 3.1416);
}

float RobotinoGrappler::degreesToDistance(float degrees)
{
	// 20 degrees correspond to 1cm movement
	return ( ( degrees / 20 ) / 100 );
}
