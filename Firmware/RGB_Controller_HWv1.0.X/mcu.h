/* 
 * File:   mcu.h
 * Author: Pedro Sanchez Ramirez (MrChunckuee)
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MCU_H
#define	MCU_H

#include <xc.h> // include processor files - each processor file is guarded.  

void MCU_Init(void);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* MCU_H */

