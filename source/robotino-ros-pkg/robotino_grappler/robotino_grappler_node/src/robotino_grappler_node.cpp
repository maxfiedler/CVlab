#include <ros/ros.h>
#include "RobotinoGrappler.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "robotino_grappler_node");
	std::string fname(argv[1]);
	RobotinoGrappler rg(fname);
	rg.spin();
	return 0;
}

