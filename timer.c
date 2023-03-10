/*
 * File:   timer.c
 * Author: bramhansh
 *
 * Created on February 23, 2023, 1:25 PM
 */


#include "timer.h"


void TIMER_init(){
    DDRB |= 1<<PINB1;
    TCCR1A |= 1<<COM1A1 | 1<<WGM11;
    TCCR1B |= 1<<WGM13 | 1<<WGM12 |1<<CS10;
    ICR1 = 800;
    OCR1A = 260;
}