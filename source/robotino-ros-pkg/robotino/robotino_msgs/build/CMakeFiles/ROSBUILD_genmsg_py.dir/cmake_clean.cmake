FILE(REMOVE_RECURSE
  "../msg_gen"
  "../srv_gen"
  "../src/robotino_msgs/msg"
  "../src/robotino_msgs/srv"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/robotino_msgs/msg/__init__.py"
  "../src/robotino_msgs/msg/_DigitalReadings.py"
  "../src/robotino_msgs/msg/_AnalogReadings.py"
  "../src/robotino_msgs/msg/_EncoderReadings.py"
  "../src/robotino_msgs/msg/_SetGrapplerAxes.py"
  "../src/robotino_msgs/msg/_NorthStarReadings.py"
  "../src/robotino_msgs/msg/_PowerReadings.py"
  "../src/robotino_msgs/msg/_SetGrapplerAxis.py"
  "../src/robotino_msgs/msg/_SetBHAPressures.py"
  "../src/robotino_msgs/msg/_BHAReadings.py"
  "../src/robotino_msgs/msg/_GripperState.py"
  "../src/robotino_msgs/msg/_GrapplerReadings.py"
  "../src/robotino_msgs/msg/_MotorReadings.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
