FILE(REMOVE_RECURSE
  "../msg_gen"
  "../srv_gen"
  "../src/robotino_msgs/msg"
  "../src/robotino_msgs/srv"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "../msg_gen/cpp/include/robotino_msgs/DigitalReadings.h"
  "../msg_gen/cpp/include/robotino_msgs/AnalogReadings.h"
  "../msg_gen/cpp/include/robotino_msgs/EncoderReadings.h"
  "../msg_gen/cpp/include/robotino_msgs/SetGrapplerAxes.h"
  "../msg_gen/cpp/include/robotino_msgs/NorthStarReadings.h"
  "../msg_gen/cpp/include/robotino_msgs/PowerReadings.h"
  "../msg_gen/cpp/include/robotino_msgs/SetGrapplerAxis.h"
  "../msg_gen/cpp/include/robotino_msgs/SetBHAPressures.h"
  "../msg_gen/cpp/include/robotino_msgs/BHAReadings.h"
  "../msg_gen/cpp/include/robotino_msgs/GripperState.h"
  "../msg_gen/cpp/include/robotino_msgs/GrapplerReadings.h"
  "../msg_gen/cpp/include/robotino_msgs/MotorReadings.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
