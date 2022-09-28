#include <ros.h>
#include <std_msgs/Int16MultiArray.h>
#include "Cubic1.7.h"

Cubic_motor motor0;
Cubic_motor motor1;
Cubic_motor motor2;

ros::NodeHandle nh;
std_msgs::Int16MultiArray motor_msg;
int v0,v1,v2;

void omniCb( const std_msgs::Int16MultiArray& motor_msg){
  v0 = motor_msg.data[0]*3;
  v1 = motor_msg.data[1]*3;
  v2 = motor_msg.data[2]*3;
  /*motor0.put(motor_msg.data[0]*2);
  motor1.put(motor_msg.data[1]*2);
  motor2.put(motor_msg.data[2]*2);
  motor0.send();
  Serial.print(motor_msg.data[0]*2);
  Serial.print(motor_msg.data[1]*2);
  Serial.print(motor_msg.data[2]*2);
  Serial.println();*/
}

ros::Subscriber<std_msgs::Int16MultiArray> sub("omni", &omniCb );

void setup()
{
  
  /*motor0.begin(0);//motor0をモーター0として使用
  motor1.begin(1);//motor1をモーター1として使用
  motor2.begin(2);*/
  //Serial.begin(115200);
  nh.getHardware()->setBaud(115200);
  nh.initNode();
  motor_msg.data = (int16_t*)malloc(sizeof(int16_t)*3);
  motor_msg.data_length = 3; 
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  motor0.put(v0);
  motor1.put(v1);
  motor2.put(v2);
  motor0.send();

  delay(2);
}
