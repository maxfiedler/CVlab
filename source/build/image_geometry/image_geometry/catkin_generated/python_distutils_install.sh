#!/bin/sh -x

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

cd "/home/viki/WurzelWorkspace/src/image_geometry/image_geometry"

# todo --install-layout=deb per platform
# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
/usr/bin/env \
    PYTHONPATH="/home/viki/WurzelWorkspace/install/lib/python2.7/dist-packages:/home/viki/WurzelWorkspace/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/viki/WurzelWorkspace/build" \
    "/usr/bin/python" \
    "/home/viki/WurzelWorkspace/src/image_geometry/image_geometry/setup.py" \
    build --build-base "/home/viki/WurzelWorkspace/build/image_geometry/image_geometry" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix=/home/viki/WurzelWorkspace/install --install-scripts=/home/viki/WurzelWorkspace/install/bin
