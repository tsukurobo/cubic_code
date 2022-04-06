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
// 回転方向：0か1, Duty比(%)：0～100
uint8_t buf[16];

ros::NodeHandle nh;

pwm::pwm order0;
pwm::pwm order1;
pwm::pwm order2;
pwm::pwm order3;
pwm::pwm order4;
pwm::pwm order5;
pwm::pwm order6;
pwm::pwm order7;

void get_order0(const pwm::pwm& order0) {
  buf[0] = order0.dire;
  buf[1] = order0.duty;
}

void get_order1(const pwm::pwm& order1) {
  buf[2] = order1.dire;
  buf[3] = order1.duty;
}

void get_order2(const pwm::pwm& order2) {
  buf[4] = order2.dire;
  buf[5] = order2.duty;
}

void get_order3(const pwm::pwm& order3) {
  buf[6] = order3.dire;
  buf[7] = order3.duty;
}

void get_order4(const pwm::pwm& order4) {
  buf[8] = order4.dire;
  buf[9] = order4.duty;
}

void get_order5(const pwm::pwm& order5) {
  buf[10] = order5.dire;
  buf[11] = order5.duty;
}

void get_order6(const pwm::pwm& order6) {
  buf[12] = order6.dire;
  buf[13] = order6.duty;
}

void get_order7(const pwm::pwm& order7) {
  buf[14] = order7.dire;
  buf[15] = order7.duty;
}

ros::Subscriber<pwm::pwm> sub_order0("motor0", get_order0);
ros::Subscriber<pwm::pwm> sub_order1("motor1", get_order1);
ros::Subscriber<pwm::pwm> sub_order2("motor2", get_order2);
ros::Subscriber<pwm::pwm> sub_order3("motor3", get_order3);
ros::Subscriber<pwm::pwm> sub_order4("motor4", get_order4);
ros::Subscriber<pwm::pwm> sub_order5("motor5", get_order5);
ros::Subscriber<pwm::pwm> sub_order6("motor6", get_order6);
ros::Subscriber<pwm::pwm> sub_order7("motor7", get_order7);

void setup() {
  digitalWrite(ENABLE_PIN, HIGH); // 動作開始
  
  //nh.getHardware()->setBaud(115200);
  nh.initNode();

  nh.subscribe(sub_order0);
  nh.subscribe(sub_order1);
  nh.subscribe(sub_order2);
  nh.subscribe(sub_order3);
  nh.subscribe(sub_order4);
  nh.subscribe(sub_order5);
  nh.subscribe(sub_order6);
  nh.subscribe(sub_order7);
  
  SPI.begin(); //SPI通信開始
  SPI.setClockDivider(SPI_CLOCK_DIV8); // SPI通信速度を1MHzに設定
  pinMode(SS,OUTPUT); // SSピンを出力用に設定
  digitalWrite(SS,HIGH); //通信状態を非アクティブに
}

void loop() {
  nh.spinOnce();
  
  //digitalWrite(SS,LOW); //通信状態をアクティブに
  for (int i = 0; i < 16; i++) {
    digitalWrite(SS,LOW); //通信状態をアクティブに
    SPI.transfer(buf[i]);
    digitalWrite(SS,HIGH); //通信状態を非アクティブに
  }
  //digitalWrite(SS,HIGH); //通信状態を非アクティブに

  //ある程度遅延を入れないと安定しない。
  delay(10);
}
