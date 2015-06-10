/*
 * main.cpp
 *
 *  Created on: 23.12.2011
 *      Author: indorewala@servicerobotics.eu
 */

#include "KinectRegistration.h"
#include <ros/ros.h>

int main( int argc, char** argv )
{
	ros::init(argc, argv, "kinect_registration_node" );
	KinectRegistration kr;
	kr.spin();
	return 0;
}
