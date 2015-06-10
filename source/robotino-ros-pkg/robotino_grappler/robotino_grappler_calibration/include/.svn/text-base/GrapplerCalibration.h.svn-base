/*
 * GrapplerCalibration.h
 *
 *  Created on: 25.01.2012
 *      Author: robotino
 */

#ifndef GRAPPLERCALIBRATION_H_
#define GRAPPLERCALIBRATION_H_

#include <ros/ros.h>
#include <robotino_msgs/GrapplerReadings.h>

class GrapplerCalibration
{
public:
	GrapplerCalibration();
	~GrapplerCalibration();

private:
	ros::NodeHandle nh_;

	ros::Subscriber grappler_store_sub_;
	bool cal_complete_;

public:
	void spin();
	void grapplerReadingsCb( const robotino_msgs::GrapplerReadingsConstPtr &msg );

};

#endif /* GRAPPLERCALIBRATION_H_ */
