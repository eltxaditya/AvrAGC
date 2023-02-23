/*
 * File:   main.c
 * Author: bramhansh
 *
 * Created on February 20, 2023, 1:19 PM
 * 
avrdude -P /dev/ttyUSB0 -c usbasp -p m328p -U efuse:w:0xFF:m
avrdude -P /dev/ttyUSB0 -c usbasp -p m328p -U hfuse:w:0xDE:m
avrdude -P /dev/ttyUSB0 -c usbasp -p m328p -U lfuse:w:0xE2:m
avrdude -P /dev/ttyUSB0 -c usbasp -p m328p -U flash:w:AvrAgcController.X.production.hex
 * 
 * Def Ard
 * (E:FD, H:DE, L:FF)
 * 
 * For 8Mhz internal
 * (E:FF, H:D9, L:E2)
 */


#include <xc.h>
#include <avr/io.h>
#include "usart.h"
#include "adc.h"
#include "timer.h"
//#pragma config WDTON = SET
//#pragma config BODLEVEL = BODLEVEL_2V7



int main(void) {
    USART_Init(MYUBRR);
//    USART_Send("Hello");
    ADC_Init();
    TIMER_init();
    while(1){
        for(unsigned int i = 0; i<65535; i++){
            for(unsigned int j = 0; j<100; j++){
                
            }
        }
//        USART_Transmit('H');
    }
    return 1;
}

