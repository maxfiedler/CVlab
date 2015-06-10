# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "rvc_utils: 2 messages, 0 services")

set(MSG_I_FLAGS "-Irvc_utils:/home/viki/WurzelWorkspace/src/rvc_utils/msg;-Istd_msgs:/opt/ros/groovy/share/std_msgs/msg;-Igeometry_msgs:/opt/ros/groovy/share/geometry_msgs/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

#better way to handle this?
set (ALL_GEN_OUTPUT_FILES_cpp "")

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(rvc_utils
  /home/viki/WurzelWorkspace/src/rvc_utils/msg/DataSetMessage.msg
  "${MSG_I_FLAGS}"
  "/opt/ros/groovy/share/std_msgs/msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rvc_utils
)
_generate_msg_cpp(rvc_utils
  /home/viki/WurzelWorkspace/src/rvc_utils/msg/ROCCurveMessage.msg
  "${MSG_I_FLAGS}"
  "/opt/ros/groovy/share/geometry_msgs/msg/Point32.msg;/opt/ros/groovy/share/std_msgs/msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rvc_utils
)

### Generating Services

### Generating Module File
_generate_module_cpp(rvc_utils
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rvc_utils
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(rvc_utils_gencpp ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(rvc_utils
  /home/viki/WurzelWorkspace/src/rvc_utils/msg/DataSetMessage.msg
  "${MSG_I_FLAGS}"
  "/opt/ros/groovy/share/std_msgs/msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rvc_utils
)
_generate_msg_lisp(rvc_utils
  /home/viki/WurzelWorkspace/src/rvc_utils/msg/ROCCurveMessage.msg
  "${MSG_I_FLAGS}"
  "/opt/ros/groovy/share/geometry_msgs/msg/Point32.msg;/opt/ros/groovy/share/std_msgs/msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rvc_utils
)

### Generating Services

### Generating Module File
_generate_module_lisp(rvc_utils
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rvc_utils
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(rvc_utils_genlisp ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(rvc_utils
  /home/viki/WurzelWorkspace/src/rvc_utils/msg/DataSetMessage.msg
  "${MSG_I_FLAGS}"
  "/opt/ros/groovy/share/std_msgs/msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rvc_utils
)
_generate_msg_py(rvc_utils
  /home/viki/WurzelWorkspace/src/rvc_utils/msg/ROCCurveMessage.msg
  "${MSG_I_FLAGS}"
  "/opt/ros/groovy/share/geometry_msgs/msg/Point32.msg;/opt/ros/groovy/share/std_msgs/msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rvc_utils
)

### Generating Services

### Generating Module File
_generate_module_py(rvc_utils
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rvc_utils
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(rvc_utils_genpy ALL
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)


debug_message(2 "rvc_utils: Iflags=${MSG_I_FLAGS}")


if(gencpp_INSTALL_DIR)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rvc_utils
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(rvc_utils_gencpp std_msgs_gencpp)
add_dependencies(rvc_utils_gencpp geometry_msgs_gencpp)

if(genlisp_INSTALL_DIR)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rvc_utils
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(rvc_utils_genlisp std_msgs_genlisp)
add_dependencies(rvc_utils_genlisp geometry_msgs_genlisp)

if(genpy_INSTALL_DIR)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rvc_utils\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rvc_utils
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(rvc_utils_genpy std_msgs_genpy)
add_dependencies(rvc_utils_genpy geometry_msgs_genpy)
