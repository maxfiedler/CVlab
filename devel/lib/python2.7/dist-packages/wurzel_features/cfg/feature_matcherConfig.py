## *********************************************************
## 
## File autogenerated for the wurzel_features package 
## by the dynamic_reconfigure package.
## Please do not edit.
## 
## ********************************************************/

##**********************************************************
## Software License Agreement (BSD License)
##
##  Copyright (c) 2008, Willow Garage, Inc.
##  All rights reserved.
##
##  Redistribution and use in source and binary forms, with or without
##  modification, are permitted provided that the following conditions
##  are met:
##
##   * Redistributions of source code must retain the above copyright
##     notice, this list of conditions and the following disclaimer.
##   * Redistributions in binary form must reproduce the above
##     copyright notice, this list of conditions and the following
##     disclaimer in the documentation and/or other materials provided
##     with the distribution.
##   * Neither the name of the Willow Garage nor the names of its
##     contributors may be used to endorse or promote products derived
##     from this software without specific prior written permission.
##
##  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
##  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
##  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
##  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
##  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
##  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
##  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
##  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
##  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
##  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
##  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
##  POSSIBILITY OF SUCH DAMAGE.
##**********************************************************/

from dynamic_reconfigure.encoding import extract_params

inf = float('inf')

config_description = {'upper': 'DEFAULT', 'lower': 'groups', 'srcline': 231, 'name': 'Default', 'parent': 0, 'srcfile': '/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'cstate': 'true', 'parentname': 'Default', 'class': 'DEFAULT', 'field': 'default', 'state': True, 'parentclass': '', 'groups': [], 'parameters': [{'srcline': 260, 'description': 'A method parameter which is edited via an enum', 'max': 3, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'method', 'edit_method': "{'enum_description': 'An enum to set Method', 'enum': [{'srcline': 8, 'description': 'MOPS and basic matcher', 'srcfile': '/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg', 'cconsttype': 'const int', 'value': 0, 'ctype': 'int', 'type': 'int', 'name': 'MOPS'}, {'srcline': 9, 'description': 'BRIEF and Hamming matcher', 'srcfile': '/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg', 'cconsttype': 'const int', 'value': 1, 'ctype': 'int', 'type': 'int', 'name': 'BRIEF'}, {'srcline': 10, 'description': 'Conventional ORB', 'srcfile': '/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg', 'cconsttype': 'const int', 'value': 2, 'ctype': 'int', 'type': 'int', 'name': 'ORB'}, {'srcline': 11, 'description': 'Wurzel method', 'srcfile': '/home/viki/WurzelWorkspace/src/wurzel_features/cfg/feature_matcher.cfg', 'cconsttype': 'const int', 'value': 3, 'ctype': 'int', 'type': 'int', 'name': 'ORB_EXTEND'}]}", 'default': 3, 'level': 0, 'min': 1, 'type': 'int'}, {'srcline': 260, 'description': 'Window size of Harris Detector.', 'max': 10, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'window_size', 'edit_method': '', 'default': 3, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 260, 'description': 'A double parameter', 'max': 10000.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'threshold', 'edit_method': '', 'default': 2200.0, 'level': 0, 'min': 0.0, 'type': 'double'}, {'srcline': 260, 'description': '', 'max': 20, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'GaussBlur_Radius', 'edit_method': '', 'default': 4, 'level': 0, 'min': 0, 'type': 'int'}, {'srcline': 260, 'description': '', 'max': 5.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'GaussBlur_Sigma', 'edit_method': '', 'default': 1.3, 'level': 0, 'min': 0.1, 'type': 'double'}, {'srcline': 260, 'description': '', 'max': 500, 'cconsttype': 'const int', 'ctype': 'int', 'srcfile': '/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'number_of_keypoints', 'edit_method': '', 'default': 200, 'level': 0, 'min': 1, 'type': 'int'}, {'srcline': 260, 'description': '', 'max': True, 'cconsttype': 'const bool', 'ctype': 'bool', 'srcfile': '/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'use_ANMS', 'edit_method': '', 'default': True, 'level': 0, 'min': False, 'type': 'bool'}, {'srcline': 260, 'description': '', 'max': 100.0, 'cconsttype': 'const double', 'ctype': 'double', 'srcfile': '/opt/ros/groovy/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py', 'name': 'ANMS_Min_Dist', 'edit_method': '', 'default': 10.0, 'level': 0, 'min': 0.0, 'type': 'double'}], 'type': '', 'id': 0}

min = {}
max = {}
defaults = {}
level = {}
type = {}
all_level = 0

#def extract_params(config):
#    params = []
#    params.extend(config['parameters'])    
#    for group in config['groups']:
#        params.extend(extract_params(group))
#    return params

for param in extract_params(config_description):
    min[param['name']] = param['min']
    max[param['name']] = param['max']
    defaults[param['name']] = param['default']
    level[param['name']] = param['level']
    type[param['name']] = param['type']
    all_level = all_level | param['level']

feature_matcher_MOPS = 0
feature_matcher_BRIEF = 1
feature_matcher_ORB = 2
feature_matcher_ORB_EXTEND = 3
