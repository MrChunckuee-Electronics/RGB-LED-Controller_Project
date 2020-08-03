/*
 * File:   mcu.c
 * Author: Pedro Sánchez Ramírez (MrChunckuee)
 *
 * Created on 1 de agosto de 2020, 12:18 AM
 */

#include "main.h"

void MCU_Init(void){
    //Puertos digitales
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    
    //Configura oscilador interno a 16MHz
    OSCCONbits.IRCF=0b111; //El ciclo de instrucción es de 0.25 us
    
    //Puertos como salida
    TRISA = 0b00000000;
    TRISB = 0b00110000;
    TRISC = 0b00001000;
    
    //Clear all port
    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;
    
    ctrlBarra1 = 0;
    ctrlBarra2 = 0;
    ctrlBarra3 = 0;
    ctrlBarra4 = 0;
    
    PWMDutty[ticksRed] = 0;
    PWMDutty[ticksGreen] = 0;
    PWMDutty[ticksBlue] = 0;
    
    // Rotary encoder init values
    rotary.encoderPosition = 0;
    rotary.encoderState = 0;
    rotary.encoderPreviousState = 0xFF;
    rotary.encoderDirection = 0;
    //encoderStatus = 0; //Activamos encoder
    
    // Push button
    rotary.buttonState = 0;
    rotary.buttonTicks = 0;
    rotary.currentButtonState = 0;
    rotary.lastButtonState = 0;
    rotary.buttonMode = 0;
    //buttonEncoderStatus = 0;
    
    PWM_Init();
    ENCODER_Init();
    INTERRUPT_Enable();
}
