/* 
 * rosserial Gyro Sensor
 * Gyro sensor (L3GD20H 3-axis gyro on MiniIMU v3) interface using I2C to ROS
 * Rae Jeong :: raychanjeong@gmail.com :: Credit http://wiki.ros.org/rosserial_arduino/Tutorials/Measuring%20Temperature https://github.com/pololu/l3g-arduino
 */ 
 
 #include <Wire.h>
 #include <L3G.h>      // Gyroscope library from https://github.com/pololu/l3g-arduino
 #include <ros.h>
 #include <std_msgs/String.h>
 
 // Set up the ros node and publisher
 std_msgs::String gyro_msg;
 ros::Publisher pub_gyro("gyro", &gyro_msg);
 ros::NodeHandle nh;
 
 // Set up the Gyroscope
 L3G gyro;
 
 void setup()
 {
   Wire.begin();      // Join I2C bus
   
   if(!gyro.init())   // Check if the gyroscope is available
   {
     Serial.println("Failed to autodetect gyro type!");
     while(1);
   }
  //I did not work directly with this code but it worked successfully when I added the following line 
   gyro.enableDefault();
   nh.initNode();
   nh.advertise(pub_gyro);
 }
 
 void loop()
 {
   gyro.read();     // Read data from gyro
   
   String gyro_string = String("X: " + String((int)gyro.g.x, DEC));   // Formatting output msg (There must be a better way to do this)
   gyro_string = String(gyro_string + " Y: ");
   gyro_string = String(gyro_string + String((int)gyro.g.y, DEC));
   gyro_string = String(gyro_string + " Z: ");
   gyro_string = String(gyro_string + String((int)gyro.g.z, DEC));
   const char *gyro_char = gyro_string.c_str();
   
   gyro_msg.data = gyro_char;
   
   pub_gyro.publish(&gyro_msg);     // Publish the data wiht pub_gyro
   
   nh.spinOnce();
   
   delay(100);
 }
 
 
 
