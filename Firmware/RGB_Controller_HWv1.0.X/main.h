/* 
 * File:   main.h
 * Author: Pedro Sanchez Ramirez (MrChunckuee)
 *
 * Created on 7 de mayo de 2019, 11:41 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <pic18f25k22.h>
#include "mcu.h"
#include "io_service.h"
#include "isr.h"
    
#define _XTAL_FREQ  16000000

/*********** P O R T   D E F I N I T I O N S **********************************/
#define redLedOutput        LATAbits.LATA5  
#define greenLedOutput      LATAbits.LATA7  
#define blueLedOutput       LATAbits.LATA4  
#define ctrlBarra1          LATCbits.LATC2  
#define ctrlBarra2          LATCbits.LATC1  
#define ctrlBarra3          LATCbits.LATC0  
#define ctrlBarra4          LATAbits.LATA6  
#define encoderTerminalA    PORTBbits.RB4   //Pin A del encoder 
#define encoderTerminalB    PORTBbits.RB5   //Pin B del encoder 
#define encoderTerminalSW   PORTCbits.RC3   //Switch del encoder

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

