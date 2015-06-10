#!/usr/bin/env sh
# generated from catkin/cmake/templates/env.sh.in

if [ $# -eq 0 ] ; then
  /bin/echo "Entering environment at '/home/viki/WurzelWorkspace/install', type 'exit' to leave"
  . "/home/viki/WurzelWorkspace/install/setup.sh"
  "$SHELL" -i
  /bin/echo "Exiting environment at '/home/viki/WurzelWorkspace/install'"
else
  . "/home/viki/WurzelWorkspace/install/setup.sh"
  exec "$@"
fi
