#include <ros.h>
#include <std_msgs/Int16MultiArray.h>

ros::NodeHandle nh;
std_msgs::Int16MultiArray order;


#include "Cubic1.7.h"

Cubic_motor motor0;
Cubic_motor motor1;//インスタンス作成
Cubic_motor motor2;
Cubic_motor motor3;
/*Cubic_encoder enc0;
Cubic_encoder enc1;*/

Cubic_encoder enc[12]; //エンコーダ用

void rosfatal(int num, ...) {
  char buf[100];
  
  va_list va_ptr;
  va_start(va_ptr, num);
 
  for (int i = 0; i < num; i++) {
    strcat(buf, va_arg(va_ptr, int16_t));
  }
 
  va_end(va_ptr);

  nh.logfatal(buf);
}

void callback(const std_msgs::Int16MultiArray& order) {
  motor0.put(order.data[0]);
  motor1.put(order.data[1]);
  motor2.put(order.data[2]);
  motor3.put(order.data[3]);
  nh.logfatal("sub");
  //rosfatal(4, order.data[0], order.data[1], order.data[2], order.data[3]);
}

ros::Subscriber<std_msgs::Int16MultiArray> sub("omni", callback);

void setup() {
  nh.initNode();
  
  order.data = (int16_t*)malloc(sizeof(int16_t)*4);
  order.data_length = 4;

  nh.subscribe(sub);
  
  motor0.begin(0);//motor0をモーター0として使用
  motor1.begin(1);//motor1をモーター1として使用
  motor2.begin(2);
  motor3.begin(3);
  
  /*enc0.begin(0); //enc0をエンコーダ0として使用
  enc1.begin(1); //enc1をエンコーダ1として使用*/
  for(int i=0;i<12;i++){
    enc[i].begin(i); //12個のエンコーダを初期化
  }

  //Serial.begin(115200);
}

void loop() {
  nh.spinOnce();
  /*for(int i=0;i<256;i++){
    motor0.put(i);//motor0への値を配列に格納
    motor1.put(-i); //motor1への値を配列に格納
    motor1.send();//spi通信を行う
    delay(10);
    //motor1.check();
  }
  for(int i=0;i<256;i++){
    motor0.put(255-i);//motor0への値を配列に格納
    motor1.put(-255+i); //motor1への値を配列に格納
    Cubic::send();//spi通信を行う。
    //motor1.check();
    delay(10);
  }*/
  //motor0.put(100);
  //motor1.put(-100);

  motor0.send();
  //nh.logfatal("send");
  
  static int encoder[12];
  
  for(int i=0;i<12;i++){
    if(enc[i] >> encoder[i]){
      //Serial.print(encoder[i]);
      //Serial.print("  ");
    }
    else{
      //Serial.print("ERR");
      //Serial.print("  ");
    }
  }
  //Serial.println();
  delay(10);
}
