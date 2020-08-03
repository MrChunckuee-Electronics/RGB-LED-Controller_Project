/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   io_service.h
 * Author: Pedro Sanchez Ramirez (MrChunckuee)
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef IO_SERVICE_H
#define	IO_SERVICE_H

#include <xc.h> // include processor files - each processor file is guarded. 

//Correccion por codigo para error de serigrafia en el PCB.
//#define ticksRed     0
//#define ticksGreen   1
//#define ticksBlue    2
#define ticksRed     2
#define ticksGreen   1
#define ticksBlue    0

#define NUMBER_OF_COLORS 26

struct hardwareEncoder {
    // Rotary encoder position
    int16_t encoderPosition;
    int16_t encoderDirection;
    uint8_t encoderState;
    uint8_t encoderPreviousState;

    // Encoder push button
    uint8_t buttonState;
    uint8_t buttonMode;   
    uint16_t buttonTicks;
    uint16_t currentButtonState;
    uint8_t lastButtonState;  
};

extern struct hardwareEncoder rotary;
extern uint8_t PWMDutty[4];
//extern bool encoderStatus;

void PWM_Init(void);
void PWM_SetDutty(uint8_t colorRed, uint8_t colorGreen, uint8_t colorBlue);
void ENCODER_Init(void);
void ENCODER_SwitchRead(void);
void IO_ENCODERSetColors(void);
void LEDRGB_ColorDemo(void);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* IO_SERVICE_H */

