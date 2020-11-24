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

#define NUMBER_OF_COLORS 25 //26

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
void ENCODER_SetColors(void);
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

