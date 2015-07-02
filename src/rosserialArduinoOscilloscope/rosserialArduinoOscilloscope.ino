/*
 * rosserial ADC Example
 * Poor man's Oscilloscope. Sending an analog value into ROS
 * Rae Jeong :: raychanjeong@gmail.com :: following http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20Oscilloscope
 */
 
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <ros.h>
#include <rosserial_arduino/Adc.h>

ros::NodeHandle nh;

rosserial_arduino::Adc adc_msg;
ros::Publisher p("adc", &adc_msg);

void setup()
{
  pinMode(13, OUTPUT);  
  nh.initNode();
  
  nh.advertise(p);
}

// Averaging the analog reading for cleaning some noise out
int averageAnalog(int pin) {
  int v = 0;
    for(int i=0; i<4; i++) v += analogRead(pin);
    return v/4;
}

long adc_timer;

void loop()
{
  adc_msg.adc0 = averageAnalog(0);
  adc_msg.adc1 = averageAnalog(1);
  adc_msg.adc2 = averageAnalog(2);
  adc_msg.adc3 = averageAnalog(3);
  adc_msg.adc4 = averageAnalog(4);
  adc_msg.adc5 = averageAnalog(5);

  p.publish(&adc_msg);

  nh.spinOnce();
}

