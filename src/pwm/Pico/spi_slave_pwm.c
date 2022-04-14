#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/spi.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"

#define SIMO_PIN 0
#define SS_PIN 1
#define SCLK_PIN 2
#define SOMI_PIN 3

const unsigned int DIRE_PIN[8] = {18, 17, 15, 12, 11, 8, 7, 4};
const unsigned int DUTY_PIN[8] = {19, 16, 14, 13, 10, 9, 6, 5};

//周波数20kHz
const int Wrap = 124;
const float Clkdiv = 50;

//モータ構造体(回転方向とDuty比の値をもつ)
typedef struct { 
    uint8_t dire;
    uint8_t duty;
} motor_t;

int main() {
    //USBによる通信を開始
    stdio_init_all();
    //SPI通信の周波数を8MHzに設定
    spi_init(spi_default, 8000000);
    //スレーブでSPI通信開始
    spi_set_slave(spi_default, true);

    //各SPIピンをアクティブに
    gpio_set_function(SIMO_PIN, GPIO_FUNC_SPI);
    gpio_set_function(SS_PIN, GPIO_FUNC_SPI);
    gpio_set_function(SCLK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(SOMI_PIN, GPIO_FUNC_SPI);

    int bytesread = 0;  // 受信したデータ数

    //パリティバイトを含む
    uint8_t buf[17];

    //モータ番号0~7までの情報を格納
    motor_t motors[8];

    //PWMスライス
    uint slice_num[8];

    for (int i = 0; i < 8; i++) {
        //DIRE_PIN[i]の初期化
        gpio_init(DIRE_PIN[i]);
        //DIRE_PIN[i]をgpio出力用のピンとして設定する．
        gpio_set_dir(DIRE_PIN[i], GPIO_OUT);

        //DUTY_PIN[i]をPWM出力用のピンとして設定する．
        gpio_set_function(DUTY_PIN[i], GPIO_FUNC_PWM);

        //DUTY_PIN[i]がどのPWMスライスに接続されているかを調べる．
        slice_num[i] = pwm_gpio_to_slice_num(DUTY_PIN[i]);

        //カウンタ値を0に戻すときの値 1~65535
        pwm_set_wrap(slice_num[i], Wrap);
        //システムクロック(125MHz)を割る値 0.0~256.0未満
        pwm_set_clkdiv(slice_num[i], Clkdiv);

        //PWMの有効化
        pwm_set_enabled(slice_num[i], true);
    }

    while(true) {
        //受信
        bytesread = spi_read_blocking(spi_default, 0, buf, 17);

        //パリティバイトが格納された要素の位置を求める
        int s;
        for (int i = 0; i < bytesread; i++) {
            if (buf[i] == 255) {
                s = i;
                break;
            }
        }

        for (int i = 0; i < 8; i++) {
            s++;
            if (s > bytesread - 1) s = 0; 
            motors[i].dire = buf[s]; printf("%u ", motors[i].dire);
            s++;
            if (s > bytesread - 1) s = 0;
            motors[i].duty = buf[s]; printf("%u ", motors[i].duty);

            gpio_put(DIRE_PIN[i], motors[i].dire);

            int level = (Wrap+1) * motors[i].duty * 0.01;
            if (DUTY_PIN[i] % 2 == 0)
                pwm_set_chan_level(slice_num[i], PWM_CHAN_A, level);
            else
                pwm_set_chan_level(slice_num[i], PWM_CHAN_B, level);
            
        }
        printf("\n");
        //sleep_ms(1);
    }
}