/*
 * rosserial Servo Control Example
 *
 * Control of hobby R/C servo using ROS and the Arduino
 *
 * Rae Jeong :: raychanjeong@gmail.com :: following http://wiki.ros.org/rosserial_arduino/Tutorials/Servo%20Controller
 */

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
   #include <WProgram.h>
#endif

#include <Servo.h>
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle nh;

Servo servo;

void servo_cb( const std_msgs::UInt16& cmd_msg) {
  servo.write(cmd_msg.data); // set servo angle, should be from 0-180
  digitalWrite(13, HIGH-digitalRead(13)); // toggle LED
}

ros::Subscriber<std_msgs::UInt16> sub("servo", servo_cb);

void setup() {
  pinMode(13, OUTPUT);
  
  nh.initNode();
  nh.subscribe(sub);
  
  servo.attach(9); // attach it to pin 9
}

void loop() {
  nh.spinOnce();
  delay(1);
}
