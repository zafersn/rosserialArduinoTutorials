/*
 * rosserial CMake Example
 * rosserial Arduino hello world with CMake
 * Rae Jeong :: raychanjeong@gmail.com :: following http://wiki.ros.org/rosserial_arduino/Tutorials/CMake
 */

#include <ros.h>
#include <std_msgs/String.h>

// Explicitly including a header file which contains all of Arduino functions
#include <Arduino.h> 

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";

void setup()
{
  nh.initNode();
  nh.advertise(chatter);
}

void loop()
{
  str_msg.data = hello;
  chatter.publish( &str_msg );
  nh.spinOnce();
  delay(1000);
}
