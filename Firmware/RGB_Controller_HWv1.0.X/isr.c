/*
 * File:   isr.c
 * Author: Pedro Sanchez Ramirez (MrChunckuee)
 *
 * Created on 1 de agosto de 2020, 01:12 AM
 */

#include "main.h"

uint16_t Ticks = 0;

void INTERRUPT_Enable(void){
    RCONbits.IPEN = 1; 
    INTCONbits.GIEH = 1;
    INTCONbits.GIEL = 1;
//    ei();
}

void INTERRUPT_Disable(void){
    RCONbits.IPEN = 0;
    INTCONbits.GIEH = 0;
    INTCONbits.GIEL = 0;
//    di();
}

void __interrupt(high_priority) INTERRUPT_Manager(void){
    if(INTCONbits.TMR0IE && INTCONbits.TMR0IF){
        if (Ticks == 256) 
            Ticks = 0;
        ++Ticks;
        
        if (Ticks < PWMDutty[ticksRed]) 
            redLedOutput = 1;
        else redLedOutput = 0;
        
        if (Ticks < PWMDutty[ticksGreen]) 
            greenLedOutput = 1;
        else greenLedOutput = 0;
        
        if (Ticks < PWMDutty[ticksBlue]) 
            blueLedOutput = 1;
        else blueLedOutput = 0;
        
        TMR0H = 0x00;
        TMR0L = 0xB2;
        
        INTCONbits.TMR0IF = 0; //Clear interrupt bit
    }
    
    if(INTCONbits.RBIE && INTCONbits.RBIF){// Rotary encoder
        rotary.encoderState = encoderTerminalA | encoderTerminalB << 1;
        if(rotary.encoderPreviousState != 0xFF/* && encoderStatus == 0*/){ // Check for first time
            if(rotary.encoderPreviousState == 0b01 && rotary.encoderState == 0b00){
                // Going counter-clockwise
                //rotary.encoderDirection = -1;
                rotary.encoderPosition--;
                }
            else if(rotary.encoderPreviousState == 0b00 && rotary.encoderState == 0b01){      
                // Going clockwise
                //rotary.encoderDirection = 1;
                rotary.encoderPosition++;
                }
            }
            // Save the current state
            rotary.encoderPreviousState = rotary.encoderState;
            if (rotary.encoderPosition > 25) rotary.encoderPosition = 25;
            if (rotary.encoderPosition < 0) rotary.encoderPosition = 0;  
        INTCONbits.RBIF=0; //Clear flag interrupt PORT
    }

}