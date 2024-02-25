#include <xc.h>
#include "soft_i2c.h"
#include "mcc_generated_files/mcc.h"


// ==================== I2C Start =============================
void I2C_start() {
	I2C_SDA_LAT = 1;
	I2C_SDA_TRIS = 0;	// output
	I2C_SCL_LAT = 1;		// SCL high
	I2C_SCL_TRIS = 0;	// output
    __delay_us(2);
	I2C_SDA_LAT = 0;		// SDA low : start
    __delay_us(2);
	I2C_SCL_LAT = 0;		// SCL low
}

// ==================== I2C Stop ==============================
void I2C_stop() {
	I2C_SDA_LAT = 0;		// SDA low
	I2C_SDA_TRIS = 0;	// output
	I2C_SCL_LAT = 1;		// SCL high
    __delay_us(2);
	I2C_SDA_TRIS = 1;	// input(SDA high) : stop
	I2C_SCL_TRIS = 1;	// input(SCL high) : stop
}

// ==================== I2C Send ==============================
void I2C_send(unsigned char send_data) {
	unsigned char i2c_data,i;

	I2C_SDA_TRIS = 0;	// SDA output

	i2c_data = send_data;
	for (i=8 ; i>0 ; i--) {
		if  (i2c_data & 0x80) {	// ビットセット
			I2C_SDA_LAT = 1;
		} else {
			I2C_SDA_LAT = 0;
		}
		i2c_data = i2c_data << 1;	// next bit set

		I2C_SCL_LAT = 1;	// 1ビット送信
        __delay_us(4);
		I2C_SCL_LAT = 0;
        __delay_us(3);
	}
	I2C_SDA_TRIS = 1;	// SDA input
}

// ==================== I2C Recive ============================
unsigned char I2C_rcv() {
	unsigned char i2c_data,i;

	I2C_SDA_TRIS = 1;	// SDA input
	for (i=8 ; i>0 ; i--) {
        __delay_us(1);
		I2C_SCL_LAT = 1;	// １ビット受信
		i2c_data = i2c_data <<1;
		if (I2C_SDA_PORT) {
			i2c_data = i2c_data | 0x01;
		} else {
			i2c_data = i2c_data & 0xFE;
		}
		I2C_SCL_LAT = 0;
	}

	return(i2c_data);
}


// ==================== I2C ACK check =========================
unsigned char I2C_ackchk() {
	unsigned char i2c_data;

	I2C_SCL_LAT = 1;	// ACKビット受信
    __delay_us(1);
	i2c_data = I2C_SDA_PORT;
	I2C_SCL_LAT = 0;

	return(i2c_data);
}

// ==================== I2C ACK send ==========================
void I2C_acksnd() {
	I2C_SDA_LAT = 0;		// ACK
	I2C_SDA_TRIS = 0;	// SDA output
    __delay_us(1);
	I2C_SCL_LAT = 1;		// ACK送信
    __delay_us(2);
	I2C_SCL_LAT = 0;
	I2C_SDA_TRIS = 1;	// SDA input
}

// ==================== I2C NACK send =========================
void I2C_nacksnd() {
	I2C_SDA_LAT = 1;		// NACK
	I2C_SDA_TRIS = 0;	// SDA output
	I2C_SCL_LAT = 1;		// NACK送信
    __delay_us(1);
	I2C_SCL_LAT = 0;
    __delay_us(1);
	I2C_SDA_TRIS = 1;	// SDA input
}

