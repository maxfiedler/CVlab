FILE(REMOVE_RECURSE
  "../msg_gen"
  "../srv_gen"
  "../src/robotino_msgs/msg"
  "../src/robotino_msgs/srv"
  "CMakeFiles/ROSBUILD_gensrv_py"
  "../src/robotino_msgs/srv/__init__.py"
  "../src/robotino_msgs/srv/_SetGripperState.py"
  "../src/robotino_msgs/srv/_SetEncoderPosition.py"
  "../src/robotino_msgs/srv/_ResetOdometry.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gensrv_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
