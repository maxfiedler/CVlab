/*
 * GrapplerCalibration.cpp
 *
 *  Created on: 25.01.2012
 *      Author: robotino
 */

#include "GrapplerCalibration.h"
#include <fstream>

GrapplerCalibration::GrapplerCalibration():
	cal_complete_(false)
{
	grappler_store_sub_ = nh_.subscribe("/grappler_store_positions", 1,
			&GrapplerCalibration::grapplerReadingsCb, this);
}

GrapplerCalibration::~GrapplerCalibration()
{
	grappler_store_sub_.shutdown();
}

void GrapplerCalibration::spin()
{
	ros::Rate lp(10);
	std::cout<<"Set the grappler in an upright position (as shown in the tutorial)"<<std::endl;
	std::cout<<"Once you have done so, press the green button."<<std::endl;
	while(nh_.ok())
	{
		ros::spinOnce();
		lp.sleep();
		if(cal_complete_)
			break;
	}
}

void GrapplerCalibration::grapplerReadingsCb( const robotino_msgs::GrapplerReadingsConstPtr &msg )
{
	std::cout<<"Calibration complete, copy the following line"<<std::endl
			<<"and replace the same line in the robotino_grappler_calibration/config/calibration_values.yaml file"
			<<std::endl<<std::endl;
	std::cout<<"grappler_angles: ["<<msg->angles[0]<<", "<<msg->angles[1]<<", "<<msg->angles[2]<<", "
			<<msg->angles[3]<<"]"<<std::endl<<std::endl;

	cal_complete_ = true;
}
