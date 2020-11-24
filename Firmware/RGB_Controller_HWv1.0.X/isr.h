/* 
 * File:   isr.h
 * Author: Pedro Sanchez Ramirez (MrChunckuee)
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ISR_H
#define	ISR_H

#include <xc.h> // include processor files - each processor file is guarded.  

void INTERRUPT_Enable(void);
void INTERRUPT_Disable(void);

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* ISR_H */

