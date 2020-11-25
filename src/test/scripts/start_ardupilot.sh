#!/bin/bash
echo "Attempting to start gazebo...."
cd '/home/karthikdharmarajan/Documents/ardupilot/Tools/autotest' 
sim_vehicle.py -v ArduCopter -f gazebo-iris  -m --mav10 --map --console -I0
