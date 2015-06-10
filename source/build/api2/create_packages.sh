#!/bin/sh

chmod -R 755 /home/viki/WurzelWorkspace/src/build/api2/install/DEBIAN

mkdir -p /home/viki/WurzelWorkspace/src/build/api2/package/output
#dpkg-deb -b /home/viki/WurzelWorkspace/src/build/api2/install /home/viki/WurzelWorkspace/src/build/api2/robotino-api2-0.8.4-Linux.deb
dpkg-deb --build /home/viki/WurzelWorkspace/src/build/api2/install .
