# rosserialArduinoTutorials

Rae Jeong :: raychanjeong@gmail.com :: following http://wiki.ros.org/rosserial_arduino/Tutorials

catkin_ws follows the convention of all lowercase package name

## rosserialArduinoGyroSensor

Modification of the Temperture Sensor tutorial: http://wiki.ros.org/rosserial_arduino/Tutorials/Measuring%20Temperature

Used MiniIMU-9 v3(L3GD20H) instead of TMP102

L3G library:
https://github.com/pololu/l3g-arduino

## rosserial_arduino_hello_world

**NOTE**

firmware/CMakeLists.txt references chatter instead of hello (different from the wiki)

Using Arduino Uno

### Upload code to Arduino

run:

catkin_make rosserial_arduino_hello_world_firmware_hello-upload

instead of:

catkin_make helloworld_firmware_hello-upload
