/*******************************************************************************
 *
 *      RGB_Lamp: Iluminacion de escritorio con tiras LED RGB
 *
 *******************************************************************************
 * FileName:        main.c
 * Processor:       PIC18F25K22
 * Complier:        XC8 v2.20 & MPLAB X IDE v5.35
 * Author:          Pedro Sanchez (MrChunckuee)
 * Blog:            http://mrchunckuee.blogspot.com/
 * Email:           mrchunckuee.psr@gmail.com
 * Description:     Proyecto controlador de tiras LED RGB usadas para la iluminacion
 *                  de mi escritorio.
 *******************************************************************************
 *          Revision history
 * Rev.         Date            Comment
 *  v0.0.1      07/05/2019      - Creacion del proyecto, pruebas  basicas del FW.
 *  v1.0.0      02/08/2020      - Pruebas con la controladora RGB v1.0 y remapeo 
 *                                de pines.
 *                              - Se agrego funciones para encoder rotativo y demo 
 *                                la de colores.
 *  v1.0.1      18/11/2020      - Documentacion de funciones.
 *                              - Se habilito la funcion para leer el switch del 
 *                                encoder, se encienden las barras dependiendo 
 *                                del numero de veces pulsado (falta mejorar rutina).
 ******************************************************************************/

#include <xc.h>
#include "FUSES_Config.h"
#include "main.h"

void main(void) {
    MCU_Init();
    while(1){
        ENCODER_SwitchRead();
        ENCODER_SetColors();
//        LEDRGB_ColorDemo(); //Descomentar para ver el demo.
    }
}



