/*
 * KinectRegistration.h
 *
 *  Created on: 23.12.2011
 *      Author: indorewala@servicerobotics.eu
 */

#ifndef KINECTREGISTRATION_H_
#define KINECTREGISTRATION_H_

#include <ros/ros.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

#include <actionlib/client/simple_action_client.h>

#include "robotino_local_move/LocalMoveAction.h"

#include "sensor_msgs/PointCloud2.h"

typedef actionlib::SimpleActionClient<robotino_local_move::LocalMoveAction> Client;

typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloud;

class KinectRegistration
{
public:
	EIGEN_MAKE_ALIGNED_OPERATOR_NEW
	KinectRegistration();
	~KinectRegistration();

private:
	ros::NodeHandle nh_;

	ros::Subscriber kinect_cloud_sub_;
	ros::Publisher registered_cloud_pub_;

	sensor_msgs::PointCloud2 cloud_msg_;

	std::string output_topic_;

	bool receive_point_cloud_, first_point_cloud_;

	double angle_rotation_, rotated_;
	int num_clouds_;

	Client client_;
	robotino_local_move::LocalMoveGoal goal_;

	PointCloud src_, tgt_;

	bool rotateRobotino();
	bool checkServer();
	void kinectCloudCallback( const sensor_msgs::PointCloud2ConstPtr &cloud );
	void transformCloud (const PointCloud &input, PointCloud &output, double degrees );
	void downsample( PointCloud &input, PointCloud &output, double leaf_size = 0.04 );
	void removeOutliers( PointCloud &input, PointCloud &output, int mean_K = 50, double std_dev = 1.0 );

public:
	void spin();
};

#endif /* KINECTREGISTRATION_H_ */
