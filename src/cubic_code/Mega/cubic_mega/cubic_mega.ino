#include <SPI.h>
// SPIピンの番号
// MISO 50
// MOSI 51
// SCK 52
// SS 53

SPISettings mySPISettings = SPISettings(4000000, MSBFIRST, SPI_MODE0);

#include <ros.h>
#include <std_msgs/UInt8MultiArray.h>

#define ENABLE_PIN 2

// PWM出力のパラメータ初期値
// 回転方向：0か1, Duty比(%)：0～254
uint8_t buf[16];

ros::NodeHandle nh;

std_msgs::UInt8MultiArray order0, order1, order2, order3, order4, order5, order6, order7;

void get_order0(const std_msgs::UInt8MultiArray& order0) {
  buf[0] = order0.data[0];
  buf[1] = order0.data[1];
}

void get_order1(const std_msgs::UInt8MultiArray& order1) {
  buf[2] = order1.data[0];
  buf[3] = order1.data[1];
}

void get_order2(const std_msgs::UInt8MultiArray& order2) {
  buf[4] = order2.data[0];
  buf[5] = order2.data[1];
}

void get_order3(const std_msgs::UInt8MultiArray& order3) {
  buf[6] = order3.data[0];
  buf[7] = order3.data[1];
}

void get_order4(const std_msgs::UInt8MultiArray& order4) {
  buf[8] = order4.data[0];
  buf[9] = order4.data[1];
}

void get_order5(const std_msgs::UInt8MultiArray& order5) {
  buf[10] = order5.data[0];
  buf[11] = order5.data[1];
}

void get_order6(const std_msgs::UInt8MultiArray& order6) {
  buf[12] = order6.data[0];
  buf[13] = order6.data[1];
}

void get_order7(const std_msgs::UInt8MultiArray& order7) {
  buf[14] = order7.data[0];
  buf[15] = order7.data[1];
}

ros::Subscriber<std_msgs::UInt8MultiArray> sub_order0("motor0", get_order0);
ros::Subscriber<std_msgs::UInt8MultiArray> sub_order1("motor1", get_order1);
ros::Subscriber<std_msgs::UInt8MultiArray> sub_order2("motor2", get_order2);
ros::Subscriber<std_msgs::UInt8MultiArray> sub_order3("motor3", get_order3);
ros::Subscriber<std_msgs::UInt8MultiArray> sub_order4("motor4", get_order4);
ros::Subscriber<std_msgs::UInt8MultiArray> sub_order5("motor5", get_order5);
ros::Subscriber<std_msgs::UInt8MultiArray> sub_order6("motor6", get_order6);
ros::Subscriber<std_msgs::UInt8MultiArray> sub_order7("motor7", get_order7);

void setup() {
  digitalWrite(ENABLE_PIN, HIGH); // 動作開始
  
  //nh.getHardware()->setBaud(115200);
  nh.initNode();

  order0.data = (uint8_t*)malloc(sizeof(uint8_t)*2);
  order1.data = (uint8_t*)malloc(sizeof(uint8_t)*2);
  order2.data = (uint8_t*)malloc(sizeof(uint8_t)*2);
  order3.data = (uint8_t*)malloc(sizeof(uint8_t)*2);
  order4.data = (uint8_t*)malloc(sizeof(uint8_t)*2);
  order5.data = (uint8_t*)malloc(sizeof(uint8_t)*2);
  order6.data = (uint8_t*)malloc(sizeof(uint8_t)*2);
  order7.data = (uint8_t*)malloc(sizeof(uint8_t)*2);

  order0.data_length = 2;
  order1.data_length = 2;
  order2.data_length = 2;
  order3.data_length = 2;
  order4.data_length = 2;
  order5.data_length = 2;
  order6.data_length = 2;
  order7.data_length = 2;

  nh.subscribe(sub_order0);
  nh.subscribe(sub_order1);
  nh.subscribe(sub_order2);
  nh.subscribe(sub_order3);
  nh.subscribe(sub_order4);
  nh.subscribe(sub_order5);
  nh.subscribe(sub_order6);
  nh.subscribe(sub_order7);
  
  SPI.begin(); //SPI通信開始
  //SPI.setClockDivider(SPI_CLOCK_DIV2); // SPI通信速度を8MHzに設定
  pinMode(SS,OUTPUT); // SSピンを出力用に設定
  digitalWrite(SS,HIGH); //通信状態を非アクティブに
}

void loop() {
  nh.spinOnce();
  
  SPI.beginTransaction(mySPISettings);

  // パリティバイトとして255を送る。
  digitalWrite(SS,LOW); //通信状態をアクティブに
  SPI.transfer(255);
  digitalWrite(SS,HIGH); //通信状態を非アクティブに
  
  for (int i = 0; i < 16; i++) {
    digitalWrite(SS,LOW); //通信状態をアクティブに
    SPI.transfer(buf[i]);
    digitalWrite(SS,HIGH); //通信状態を非アクティブに
  }
  
  SPI.endTransaction();

  delay(2);
}
