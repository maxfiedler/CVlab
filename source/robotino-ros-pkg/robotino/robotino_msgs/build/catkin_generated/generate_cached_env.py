from __future__ import print_function
import argparse
import os
import stat
import sys

try:
    from catkin.environment_cache import generate_environment_script, generate_static_environment_script
except ImportError:
    # find the import relatively to make it work before installing catkin
    sys.path.append(os.path.join('/opt/ros/groovy/share/catkin/cmake', '..', 'python'))
    from catkin.environment_cache import generate_environment_script, generate_static_environment_script


parser = argparse.ArgumentParser(description='Generate cached environment script.')
parser.add_argument('--static', action='store_true', help='The flag to skip sourcing the env script and generate a static environment')
args = parser.parse_args()

if not args.static:
    code = generate_environment_script('/home/viki/WurzelWorkspace/src/robotino-ros-pkg/robotino/robotino_msgs/build/devel/env.sh')
else:
    code = generate_static_environment_script('/home/viki/WurzelWorkspace/src/robotino-ros-pkg/robotino/robotino_msgs/build/devel', ['/home/viki/WurzelWorkspace/src/robotino-ros-pkg/robotino/robotino_msgs/build/devel', '/home/viki/WurzelWorkspace/devel', '/opt/ros/groovy'], 'lib/python2.7/dist-packages')

with open('/home/viki/WurzelWorkspace/src/robotino-ros-pkg/robotino/robotino_msgs/build/catkin_generated/env_cached.sh', 'w') as f:
    #print('Generate script for cached environment "%s"' % '/home/viki/WurzelWorkspace/src/robotino-ros-pkg/robotino/robotino_msgs/build/catkin_generated/env_cached.sh')
    f.write('\n'.join(code))

mode = os.stat('/home/viki/WurzelWorkspace/src/robotino-ros-pkg/robotino/robotino_msgs/build/catkin_generated/env_cached.sh').st_mode
os.chmod('/home/viki/WurzelWorkspace/src/robotino-ros-pkg/robotino/robotino_msgs/build/catkin_generated/env_cached.sh', mode | stat.S_IXUSR)
