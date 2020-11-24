/*
 * File:   io_service.c
 * Author: Pedro Sánchez Ramírez (MrChunckuee)
 *
 * Created on 1 de agosto de 2020, 12:33 AM
 */

#include "main.h"

struct hardwareEncoder rotary;

uint8_t PWMDutty[4]; // Red, Green, Blue
uint8_t levelColor;
uint8_t color = 0;
uint16_t ticksRGB = 0;
uint8_t count_sw = 0;

unsigned char colors[NUMBER_OF_COLORS][3] = {
        //{0,     0,      0},     //Black
        {255,   255,    255},   //Blanco
        {255,   0,      0},     //Rojo
        {223,   32,     0},
        {191,   64,     0},
        {159,   96,     0},
        {128,   128,    0},
        {96,    159,    0},
        {64,    191,    0},
        {32,    223,    0},
        {0,     255,    0},     //Verde
        {0,     223,    32},
        {0,     191,    64},
        {0,     159,    96},
        {0,     128,    128},
        {0,     96,     159},
        {0,     64,     191},
        {0,     32,     223},
        {0,     0,      255},   //Azul
        {32,    0,      223},
        {64,    0,      191},
        {96,    0,      159},
        {128,   0,      128},
        {159,   0,      96},
        {191,   0,      64},
        {223,   0,      32}
        };

/*******************************************************************************
 * Function:        void PWM_Init(void)
 * Description:     Configurarion del TMR0 para PWM de los LEDs
 * Precondition:    None
 * Parameters:      None
 * Return Values:   None
 * Remarks:         TMR0 = 39us
 * ****************************************************************************/
void PWM_Init(void){
    T0CONbits.TMR0ON = 1; //TMR0 On
    T0CONbits.T08BIT = 1; //8 bits
    T0CONbits.T0CS = 0;
    T0CONbits.T0SE = 0;
    T0CONbits.PSA = 0;
    T0CONbits.T0PS = 0b000; // Prescaler = 2
    TMR0H = 0x00;
    TMR0L = 0xB2;
    INTCONbits.TMR0IF = 0; //Clear the INT0 external interrupt
    INTCONbits.TMR0IE = 1; //Enables the INT0 external interrupt 
    INTCON2bits.TMR0IP = 1; // TMR0 Overflow Interrupt High Priority
}

/*******************************************************************************
 * Function:        void PWM_SetDutty( uint8_t colorRed, 
 *                                     uint8_t colorGreen, 
 *                                     uint8_t colorBlue   )
 * Description:     Esta funcion carga los valores RGB al PWM Dutty.
 * Precondition:    None
 * Parameters:      uint8_t colorRed - Valor del dutty Red
 *                  uint8_t colorGreen - Valor del dutty Green
 *                  uint8_t colorBlue - Valor del dutty Blue
 * Return Values:   None
 * Remarks:         None
 * ****************************************************************************/
void PWM_SetDutty(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue){
    PWMDutty[ticksRed] = colorRed;
    PWMDutty[ticksGreen] = colorGreen;
    PWMDutty[ticksBlue] = colorBlue;
}

/*******************************************************************************
 * Function:        void ENCODER_Init(void)
 * Description:     Cofig PORT change interrupt (RB4 & RB5)
 * Precondition:    None
 * Parameters:      None
 * Return Values:   None
 * Remarks:         None
 * ****************************************************************************/
void ENCODER_Init(void){  
    INTCON2bits.RBPU = 1;   //Disables Pull-Ups
//    WPUBbits.WPUB4 = 0;     //RB4
//    WPUBbits.WPUB5 = 0;     //RB5
    INTCON2bits.RBIP = 1;   //High priority
    INTCONbits.RBIF = 0;    //Clear flag PORT change interrupt 
    INTCONbits.RBIE = 1;    //Enables PORT change interrupt
    IOCBbits.IOCB4 = 1;
    IOCBbits.IOCB5 = 1;
}

/*******************************************************************************
 * Function:        void ENCODER_SwitchRead(void)
 * Description:     Funcion para leer el estado del switch del encoder.
 * Precondition:    None
 * Parameters:      None
 * Return Values:   None
 * Remarks:         None
 * ****************************************************************************/
void ENCODER_SwitchRead(void){
    if(encoderTerminalSW == 0){
        __delay_ms(300);
        count_sw++;
        switch(count_sw){
            case 1:
                ctrlBarra1 = 1;
                ctrlBarra2 = 1;
                ctrlBarra3 = 1;
                ctrlBarra4 = 0;
                break;
            case 2:
                ctrlBarra1 = 1;
                ctrlBarra2 = 1;
                ctrlBarra3 = 0;
                ctrlBarra4 = 0;
                break;
            case 3:
                ctrlBarra1 = 1;
                ctrlBarra2 = 0;
                ctrlBarra3 = 0;
                ctrlBarra4 = 0;
                break;
            case 4:
                ctrlBarra1 = 0;
                ctrlBarra2 = 0;
                ctrlBarra3 = 0;
                ctrlBarra4 = 0;
                break;
            case 5:
                ctrlBarra1 = 1;
                ctrlBarra2 = 1;
                ctrlBarra3 = 1;
                ctrlBarra4 = 1;
                count_sw = 0;
                break;
            default:
                break;
        }
    }
}

/*******************************************************************************
 * Function:        void ENCODER_SetColors(void)
 * Description:     Funcion para cargar el dutty de cada color, dependiendo de 
 *                  la pocicion del encoder.
 * Precondition:    None
 * Parameters:      None
 * Return Values:   None
 * Remarks:         None
 * ****************************************************************************/
void ENCODER_SetColors(void){       
    uint16_t currentLedNumber = rotary.encoderPosition;
    PWM_SetDutty(colors[currentLedNumber][ticksRed],    \
                 colors[currentLedNumber][ticksGreen],  \
                 colors[currentLedNumber][ticksBlue]);
}

/*******************************************************************************
 * Function:        void LEDRGB_ColorDemo(void)
 * Description:     Funcion demo, barrido de colores y variacion de dutty.
 * Precondition:    None
 * Parameters:      None
 * Return Values:   None
 * Remarks:         None
 * ****************************************************************************/
void LEDRGB_ColorDemo(void){
    switch (color){
        case 0:
            ++ticksRGB;
            if (ticksRGB == 256) {
                color = 1;
                ticksRGB = 0;
            }
            PWM_SetDutty(ticksRGB,0,0);
            break;
        case 1:
            ++ticksRGB;
            if (ticksRGB == 256) {
                color = 2;
                ticksRGB = 0;
            }
            PWM_SetDutty(0,ticksRGB,0);
            break;
        case 2:
            ++ticksRGB;
            if (ticksRGB == 256) {
                color = 3;
                ticksRGB = 0;
            }
            PWM_SetDutty(0,0,ticksRGB);
            break;
        case 3:
            for(levelColor=0; levelColor<25; levelColor++){
                PWM_SetDutty(colors[levelColor][0], colors[levelColor][1], colors[levelColor][2]);
                __delay_ms(1000);
            }
            color=0;
            break;
        default:
            color = 0;
            ticksRGB = 0;
            break;
    }
    __delay_ms(30);
}
