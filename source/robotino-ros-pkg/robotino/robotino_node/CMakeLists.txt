cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#uncomment if you have defined messages
#rosbuild_genmsg()
#uncomment if you have defined services
#rosbuild_gensrv()

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})

set(
  CMAKE_MODULE_PATH
  /usr/local/robotino/api2/cmake
)
find_package(RobotinoAPI2 REQUIRED)

rosbuild_add_executable(
  robotino_node
  src/robotino_node.cpp
  src/AnalogInputArrayROS.cpp
  src/BumperROS.cpp
  src/CameraROS.cpp
  src/CompactBHAROS.cpp
  src/ComROS.cpp
  src/DigitalInputArrayROS.cpp
  src/DigitalOutputArrayROS.cpp
  src/DistanceSensorArrayROS.cpp
  src/ElectricalGripperROS.cpp
  src/EncoderInputROS.cpp
  src/GrapplerROS.cpp
  src/KinectROS.cpp
  src/LaserRangeFinderROS.cpp
  src/MotorArrayROS.cpp
  src/NorthStarROS.cpp
  src/OdometryROS.cpp
  src/OmniDriveROS.cpp
  src/PowerManagementROS.cpp
  src/RobotinoNode.cpp
)

target_link_libraries(
  robotino_node
  ${REC_ROBOTINO_API2_LIBRARY}
)

rosbuild_add_executable(
  robotino_odometry_node
  src/robotino_odometry_node.cpp
  src/ComROS.cpp
  src/OdometryROS.cpp
  src/RobotinoOdometryNode.cpp
)

target_link_libraries(
  robotino_odometry_node
  ${REC_ROBOTINO_API2_LIBRARY}
)

rosbuild_add_executable(
  robotino_laserrangefinder_node
  src/robotino_laserrangefinder_node.cpp
  src/ComROS.cpp
  src/LaserRangeFinderROS.cpp
  src/RobotinoLaserRangeFinderNode.cpp
)

target_link_libraries(
  robotino_laserrangefinder_node
  ${REC_ROBOTINO_API2_LIBRARY}
)

rosbuild_add_executable(
  robotino_camera_node
  src/robotino_camera_node.cpp
  src/ComROS.cpp
  src/CameraROS.cpp
  src/RobotinoCameraNode.cpp
)

target_link_libraries(
  robotino_camera_node
  ${REC_ROBOTINO_API2_LIBRARY}
)

rosbuild_add_executable(
  robotino_mapping_node
  src/robotino_mapping_node.cpp
  src/MappingROS.cpp
  src/RobotinoMappingNode.cpp
  src/InitialPoseROS.cpp
  src/NavGoalROS.cpp
  src/ComROS.cpp
)

target_link_libraries(
  robotino_mapping_node
  ${REC_ROBOTINO_API2_LIBRARY}
)
