/*
 * main.cpp
 *
 *  Created on: 25.01.2012
 *      Author: robotino
 */

#include "GrapplerCalibration.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "grappler_calibration_node");
	GrapplerCalibration gc;
	gc.spin();
	return 0;
}
