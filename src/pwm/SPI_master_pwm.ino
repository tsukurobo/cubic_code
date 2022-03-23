#include <SPI.h>
// SPIピンの番号
// MISO 50
// MOSI 51
// SCK 52
// SS 53

void setup() {
  SPI.begin(); //SPI通信開始
  SPI.setClockDivider(SPI_CLOCK_DIV8); // SPI通信速度を1MHzに設定
  pinMode(SS,OUTPUT); // SSピンを出力用に設定
  digitalWrite(SS,HIGH); //通信状態を非アクティブに
}

// pwm出力の有無：0で停止，1で出力　周波数(kHz)：20,30,...,60　Duty比(%)：0～100
byte buf[3] = {0,30,100};

void loop() {
  //digitalWrite(SS,LOW); //通信状態をアクティブに
  for (int i = 0; i < 3; i++) {
    digitalWrite(SS,LOW); //通信状態をアクティブに
    SPI.transfer(buf[i]);
    digitalWrite(SS,HIGH); //通信状態を非アクティブに
  }
  //digitalWrite(SS,HIGH); //通信状態を非アクティブに
  
  delay(100);
}
