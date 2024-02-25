#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <string.h>
#include "soft_i2c.h"
#include "lcd_i2c.h"
#include "wt901.h"

#define TIMEOUT 100

// キャリブレーション値
signed short aa1 = (0);
signed short av1 = (0);

// Angle
signed short aa[4]; // 欲しいのは aa[1] 左傾斜で＋ 右傾斜で－
// Angular Velocity
signed short av[4]; // 欲しいのは av[1]


//char buf[32];
uint8_t n_on = 0; // TRIG_ON 連続ON回数 
uint8_t n_off = 0; // TRIG_ON 連続OFF回数 
uint8_t trigger = 0; // 安定化処理後のトリガー状態
uint8_t trigger0 = 0; // 安定化処理後のトリガー状態の直前状態


// 受信データー確認
// 受信あれば1 なければ0 を返す
char check_rsv(void) {
    uint8_t n = get_rsv_size1();
    if (n < 8) {
        return 0; // 受信データーが少な過ぎる
    }
    n = get_rsv_size2();
    if (n < 8) {
        return 0; // 受信データーが少な過ぎる
    }
    return 1;
}


void set_pwm(void) {
    PWM1_DutyCycleSet(12000);
    PWM2_DutyCycleSet(9375);
    PWM1_LoadBufferSet();
    PWM2_LoadBufferSet();
    PWM1_Start();
    PWM2_Start();
}


void main(void)
{
    SYSTEM_Initialize();
    set_rsv_buf((uint8_t *)av, 8, (uint8_t *)aa, 8);
    EUSART_SetRxInterruptHandler(WT901_rsv_int);

    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    set_pwm();
    
    uint16_t t;
    
    CLRWDT();
    //__delay_ms(100);    
    CLRWDT();
    //LCD_i2c_init(8);
    
    while (1) {
        CLRWDT();

        uint8_t n = 0;
        for (t=0; t<TIMEOUT; t++) {
            if (check_rsv()) {
                break;
            }
            __delay_ms(1);
        }
        clear_rsv_size();

        //LCD_i2C_cmd(0x80);
        //sprintf(buf, "%6d %6d", aa[0], av[1]);
        //LCD_i2C_data(buf);

        if (TRIG_IN_GetValue()) {
            n_on ++;
            if (n_on > 3) {
                n_on = 3;
                trigger = 1;
            }
            n_off = 0;
        }
        else {
            n_off ++;
            if (n_off > 20) {
                n_off = 20;
                trigger = 0;
            }
            n_on = 0;
        }
        
        if (trigger) {
            LED_SetHigh();
            TRIG_OUT_SetHigh();
        }
        else {
            LED_SetLow();
            TRIG_OUT_SetLow();
            PWM1_DutyCycleSet((uint16_t)(aa[1] + 12000));
            PWM1_LoadBufferSet();
        }
    }
}
/**
 End of File
*/