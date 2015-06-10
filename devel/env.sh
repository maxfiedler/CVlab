#!/usr/bin/env sh
# generated from catkin/cmake/templates/env.sh.in

if [ $# -eq 0 ] ; then
  /bin/echo "Entering environment at '/home/viki/WurzelWorkspace/devel', type 'exit' to leave"
  . "/home/viki/WurzelWorkspace/devel/setup.sh"
  "$SHELL" -i
  /bin/echo "Exiting environment at '/home/viki/WurzelWorkspace/devel'"
else
  . "/home/viki/WurzelWorkspace/devel/setup.sh"
  exec "$@"
fi
