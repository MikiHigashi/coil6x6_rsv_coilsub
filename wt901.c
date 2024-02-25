#include <xc.h>
#include "wt901.h"
#include "mcc_generated_files/mcc.h"


#define TEMP_BUF_SIZE 16
static uint8_t temp_buf[TEMP_BUF_SIZE];
uint8_t* tempbuf = temp_buf;

static uint8_t rsv_mode; // 受信モード 
// 0 to 79 次にデーター部の (1 to 80) バイト目を受信するはず
// 101 次にヘッダー0x55を受信するはず
// 102 次にコマンドを受信するはず
// 105 次にチェックサムを受信するはず
static uint8_t rsv_n; // 受信バイト数 
static uint8_t rsv_size1; // 受信バッファに格納されたバイト数 
static uint8_t rsv_size2; // 受信バッファに格納されたバイト数 
static uint8_t rsv_cmd; // 受信コマンド 
static uint8_t rsv_csum; // チェックサム 
static uint8_t *rsv_buf1; // 受信バッファアドレス
static uint8_t rsv_buf1_size; // 受信バッファサイズ
static uint8_t *rsv_buf2; // 受信バッファアドレス
static uint8_t rsv_buf2_size; // 受信バッファサイズ


// 受信バッファとそのサイズを設定する
// buf1: Angular Velocity Output
// buf2: Angle Output
void set_rsv_buf(uint8_t *buf1, uint8_t size1, uint8_t *buf2, uint8_t size2) {
    rsv_buf1 = buf1;
    rsv_buf1_size = size1;
    rsv_buf2 = buf2;
    rsv_buf2_size = size2;
    rsv_size1 = 0;
    rsv_size2 = 0;
    rsv_mode = 101; // ヘッダー待ち
}


// 受信バイト数を取得
// 0 でなければ、受信データーが存在すると分かる
uint8_t get_rsv_size1(void) {
    return rsv_size1;
}
uint8_t get_rsv_size2(void) {
    return rsv_size2;
}


// 受信バイト数をクリア
// 受信バッファを参照後にこれを呼ぶことで、受信バッファの更新を知ることができるようになる
void clear_rsv_size(void) {
    rsv_size1 = 0;
    rsv_size2 = 0;
}



// バイナリモード受信　割り込みハンドラ
// 先に set_rsv_buf() で受信バッファを登録しておくこと
void WT901_rsv_int(void) {
    // ↓この部分は機種依存なので EUSART_Receive_ISR() から複写すること
    if (RCSTAbits.OERR == 1) { // バッファーオーバーフロー
        RCSTAbits.CREN = 0;
        RCSTAbits.CREN = 1;
        return;
    }
    uint8_t c = RCREG;
    // ↑この部分は機種依存なので EUSART_Receive_ISR() から複写すること

    switch (rsv_mode) {
        case 101: // 次にヘッダー0x55を受信するはず
            if (c != 0x55) return;
            rsv_mode = 102;
            break;
        case 102: // 次にコマンドを受信するはず
            if ((c == 0x52) || (c == 0x53)) {
                rsv_cmd = c;
                rsv_n = 8;
                rsv_csum = 0x55 + c;
                rsv_mode = 0;
            }
            else {
                rsv_mode = 101;
            }
            break;
        case 105: // 次にチェックサムを受信するはず
            if (c == rsv_csum) {
                if (rsv_cmd == 0x52) {
                    if (rsv_n > rsv_buf1_size) {
                        rsv_n = rsv_buf1_size; 
                    }
                    for (c=0; c<rsv_n; c++) {
                        rsv_buf1[c] = temp_buf[c];
                    }
                    rsv_size1 = rsv_n;
                }
                else if (rsv_cmd == 0x53) {
                    if (rsv_n > rsv_buf2_size) {
                        rsv_n = rsv_buf2_size; 
                    }
                    for (c=0; c<rsv_n; c++) {
                        rsv_buf2[c] = temp_buf[c];
                    }
                    rsv_size2 = rsv_n;
                }
            }
            rsv_mode = 101;
            break;
        default: // データー部受信
            rsv_csum += c;
            if (rsv_mode < TEMP_BUF_SIZE) {
                temp_buf[rsv_mode] = c;
            }
            rsv_mode ++;
            if (rsv_mode >= rsv_n) {
                rsv_mode = 105;
            }
            break;
    }
}
