/*
 * KinectRegistration.cpp
 *
 *  Created on: 23.12.2011
 *      Author: indorewala@servicerobotics.eu
 */

#include "KinectRegistration.h"

#include <pcl/registration/transforms.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/statistical_outlier_removal.h>

KinectRegistration::KinectRegistration():
	nh_("~"),
	receive_point_cloud_( true ),
	first_point_cloud_( false ),
	rotated_( 0.0 ),
	num_clouds_( 0 ),
	client_( "local_move", false)
{
	nh_.param<double>("angle_rotation", angle_rotation_, 40.0 );
	nh_.param<std::string>("output_topic", output_topic_, "registered_cloud" );

	kinect_cloud_sub_ = nh_.subscribe("/kinect", 1, &KinectRegistration::kinectCloudCallback, this );
	registered_cloud_pub_ = nh_.advertise<sensor_msgs::PointCloud2>(output_topic_, false);
}

KinectRegistration::~KinectRegistration()
{
	kinect_cloud_sub_.shutdown();
	registered_cloud_pub_.shutdown();
}

bool KinectRegistration::rotateRobotino()
{
	goal_.move_x = 0.0;
	goal_.move_y = 0.0;
	goal_.rotation = (angle_rotation_ * 3.1416) / 180 ;
	goal_.ignore_rotation = false;

	client_.sendGoal( goal_ );

	for( int i = 0; i < 40; ++i )
	{
		ros::spinOnce();
		if( client_.waitForResult( ros::Duration( 1.0 ) ) )
		{
			rotated_ += angle_rotation_;
			ROS_INFO("Robotino has rotated: %f degrees", rotated_ );
			receive_point_cloud_ = true;
			return true;
		}
	}
	ROS_ERROR("Rotation failed");
	ROS_BREAK();
	return false;
}

bool KinectRegistration::checkServer()
{
	for( int i = 0; i < 5; ++i)
	{
		ros::spinOnce();
		if( client_.waitForServer( ros::Duration( 1.0 ) ) )
		{
			ROS_INFO( "Connected to the local move server" );
			return true;
		}
		else
		{
			ROS_INFO( "Waiting for local move server" );
		}
	}

	ROS_ERROR( "local move server not running" );
	return false;
}

void KinectRegistration::spin()
{
	ros::Rate lr(50);
	if( !checkServer() )
	{
		return;
	}

	int req_num_clouds = 360 / angle_rotation_;

	while( (num_clouds_ < req_num_clouds ) )
	{
		ros::spinOnce();
		lr.sleep();
	}
	ROS_INFO("Number of point clouds received: %d", num_clouds_ );
}

void KinectRegistration::kinectCloudCallback( const sensor_msgs::PointCloud2ConstPtr &msg )
{
	if( receive_point_cloud_ )
	{
		if( !first_point_cloud_ )
		{
			ROS_INFO("First PointCloud received");
			PointCloud temp;
			pcl::fromROSMsg( *msg, temp );
			removeOutliers( temp, src_ );
			first_point_cloud_ = true;
		}
		else
		{
			ROS_INFO("PointCloud received");
			PointCloud temp, temp1;
			pcl::fromROSMsg( *msg, temp );
			removeOutliers( temp, tgt_ );

			transformCloud(tgt_, temp, num_clouds_ * 40 );
			temp1 = src_;
			temp1 += temp;

			downsample( temp1, temp );
			pcl::toROSMsg( temp, cloud_msg_ );
			registered_cloud_pub_.publish( cloud_msg_ );
			src_ = temp1;
		}
		receive_point_cloud_ = false;
		rotateRobotino();
		num_clouds_++;
	}
	else
		return;
}

void KinectRegistration::transformCloud (const PointCloud &input, PointCloud &output, double degrees )
{
	double rads = ( degrees * 3.1416 ) / 180;
	Eigen::Matrix4f transformation;
	transformation <<
			cos(rads), -1*sin(rads), 0, 0,
			sin(rads), cos(rads), 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1;

	pcl::transformPointCloud (input, output, transformation);

	ROS_INFO("PointClouds transformed.");
}

void KinectRegistration::downsample( PointCloud &input, PointCloud &output, double leaf_size )
{
	pcl::VoxelGrid<PointT> vg;
	vg.setLeafSize( leaf_size, leaf_size, leaf_size );
	vg.setInputCloud( input.makeShared() );
	vg.filter( output );
}

void KinectRegistration::removeOutliers( PointCloud &input, PointCloud &output, int mean_K, double std_dev )
{
	pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
	sor.setInputCloud ( input.makeShared() );
	sor.setMeanK (mean_K);
	sor.setStddevMulThresh (std_dev);
	sor.filter (output);
}

