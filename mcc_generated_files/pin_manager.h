/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1575
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()              PORTAbits.RA0
#define RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()             do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()           do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode()         do { ANSELAbits.ANSA0 = 1; } while(0)
#define RA0_SetDigitalMode()        do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISAbits.TRISA2
#define LED_LAT                  LATAbits.LATA2
#define LED_PORT                 PORTAbits.RA2
#define LED_WPU                  WPUAbits.WPUA2
#define LED_OD                   ODCONAbits.ODA2
#define LED_ANS                  ANSELAbits.ANSA2
#define LED_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_GetValue()           PORTAbits.RA2
#define LED_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()              PORTAbits.RA4
#define RA4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetPullup()             do { WPUAbits.WPUA4 = 1; } while(0)
#define RA4_ResetPullup()           do { WPUAbits.WPUA4 = 0; } while(0)
#define RA4_SetAnalogMode()         do { ANSELAbits.ANSA4 = 1; } while(0)
#define RA4_SetDigitalMode()        do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set TRIG_IN aliases
#define TRIG_IN_TRIS                 TRISAbits.TRISA5
#define TRIG_IN_LAT                  LATAbits.LATA5
#define TRIG_IN_PORT                 PORTAbits.RA5
#define TRIG_IN_WPU                  WPUAbits.WPUA5
#define TRIG_IN_OD                   ODCONAbits.ODA5
#define TRIG_IN_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define TRIG_IN_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define TRIG_IN_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define TRIG_IN_GetValue()           PORTAbits.RA5
#define TRIG_IN_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define TRIG_IN_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define TRIG_IN_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define TRIG_IN_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define TRIG_IN_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define TRIG_IN_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)

// get/set I2C_SCL aliases
#define I2C_SCL_TRIS                 TRISCbits.TRISC2
#define I2C_SCL_LAT                  LATCbits.LATC2
#define I2C_SCL_PORT                 PORTCbits.RC2
#define I2C_SCL_WPU                  WPUCbits.WPUC2
#define I2C_SCL_OD                   ODCONCbits.ODC2
#define I2C_SCL_ANS                  ANSELCbits.ANSC2
#define I2C_SCL_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define I2C_SCL_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define I2C_SCL_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define I2C_SCL_GetValue()           PORTCbits.RC2
#define I2C_SCL_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define I2C_SCL_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define I2C_SCL_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define I2C_SCL_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define I2C_SCL_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define I2C_SCL_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define I2C_SCL_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define I2C_SCL_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set I2C_SDA aliases
#define I2C_SDA_TRIS                 TRISCbits.TRISC3
#define I2C_SDA_LAT                  LATCbits.LATC3
#define I2C_SDA_PORT                 PORTCbits.RC3
#define I2C_SDA_WPU                  WPUCbits.WPUC3
#define I2C_SDA_OD                   ODCONCbits.ODC3
#define I2C_SDA_ANS                  ANSELCbits.ANSC3
#define I2C_SDA_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define I2C_SDA_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define I2C_SDA_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define I2C_SDA_GetValue()           PORTCbits.RC3
#define I2C_SDA_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define I2C_SDA_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define I2C_SDA_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define I2C_SDA_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define I2C_SDA_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define I2C_SDA_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define I2C_SDA_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define I2C_SDA_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set TRIG_OUT aliases
#define TRIG_OUT_TRIS                 TRISCbits.TRISC4
#define TRIG_OUT_LAT                  LATCbits.LATC4
#define TRIG_OUT_PORT                 PORTCbits.RC4
#define TRIG_OUT_WPU                  WPUCbits.WPUC4
#define TRIG_OUT_OD                   ODCONCbits.ODC4
#define TRIG_OUT_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define TRIG_OUT_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define TRIG_OUT_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define TRIG_OUT_GetValue()           PORTCbits.RC4
#define TRIG_OUT_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define TRIG_OUT_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define TRIG_OUT_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define TRIG_OUT_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define TRIG_OUT_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define TRIG_OUT_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/