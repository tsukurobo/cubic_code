#include <SPI.h>
// SPIピンの番号
// MISO 50
// MOSI 51
// SCK 52
// SS 53
#include <ros.h>
#include <pwm/pwm.h>

#define ENABLE_PIN 2

// PWM出力のパラメータ初期値
// pwm出力の有無：0で停止，1で出力　周波数(kHz)：20,30,...,60　Duty比(%)：0～100
byte buf[3] = {0,30,50};

ros::NodeHandle nh;

pwm::pwm order;

void get_order(const pwm::pwm& order) {
  buf[0] = order.on_off;
  buf[1] = order.freq;
  buf[2] = order.duty;
}

ros::Subscriber<pwm::pwm> sub_order("pwm", get_order);

void setup() {
  digitalWrite(ENABLE_PIN, HIGH); // 動作開始
  
  //nh.getHardware()->setBaud(115200);
  nh.initNode();

  nh.subscribe(sub_order);
  
  SPI.begin(); //SPI通信開始
  SPI.setClockDivider(SPI_CLOCK_DIV8); // SPI通信速度を1MHzに設定
  pinMode(SS,OUTPUT); // SSピンを出力用に設定
  digitalWrite(SS,HIGH); //通信状態を非アクティブに
}

void loop() {
  nh.spinOnce();
  
  //digitalWrite(SS,LOW); //通信状態をアクティブに
  for (int i = 0; i < 3; i++) {
    digitalWrite(SS,LOW); //通信状態をアクティブに
    SPI.transfer(buf[i]);
    digitalWrite(SS,HIGH); //通信状態を非アクティブに
  }
  //digitalWrite(SS,HIGH); //通信状態を非アクティブに
  
  delay(100);
}
