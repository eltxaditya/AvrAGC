/*
 * File:   adc.c
 * Author: bramhansh
 *
 * Created on February 22, 2023, 4:33 PM
 */


#include "adc.h"
#include "usart.h"
#include <avr/interrupt.h>
#include <string.h>


volatile uint16_t adVal;
volatile char printData[20];
//void itoa(int iData, char *pData){
//    int local8bitCounter = 0, upCounter = 0;
//    char temp[5] = "\0";
//    do{
//        temp[local8bitCounter] = (iData % 10) + 48;
//        iData /= 10;
//        local8bitCounter++;
//    }while(iData);
//    while(local8bitCounter--){
//        pData[upCounter++] = temp[local8bitCounter];
//    }
//}
void itoa(uint16_t iData, char *pData){
    uint8_t local8bitCounter = 0, upCounter = 0;
    char temp = 0;
    do{
        pData[0] = (iData % 10) + 48;
        iData /= 10;
        pData++;
        local8bitCounter++;
    }while(iData);
    pData -= local8bitCounter;
    
//    printf("Data= %s\n",pData);
//    printf("l = %i\n",local8bitCounter);
    while(upCounter <= (local8bitCounter/2)){
        local8bitCounter--;
        temp = pData[upCounter];    
//        printf("t = %c\n",temp);
        pData[upCounter] = pData[local8bitCounter];    
//        printf("pD = %c\n",pData[upCounter]);
//    printf("Data= %s\n",pData);
        upCounter++;
        pData[local8bitCounter] = temp;    
//        printf("pDL = %c\n\n",pData[local8bitCounter]);
    }
}

ISR(ADC_vect){
    adVal = ADCL | ADCH<<8;
    memset((char *)printData,'\0', strlen((char *)printData));
    itoa(adVal,(char *)printData);
    USART_Send("0,");
    USART_Send((char *)printData);
    USART_Send(",1023\n");
}

void ADC_Init(){
    ADMUX |= 1<<REFS0 | 1<<REFS1 ;
    DIDR0  = 0xFF;
    SREG |= 1<<7;
    ADCSRA |= 1<<ADEN | 1<<ADATE | 1<<ADIE | 1<<ADSC | 1<<ADPS0 | 1<<ADPS1 | 1<<ADPS2;
//    ADCSRA |= 1<<ADEN | 1<<ADATE | 1<<ADIE | 1<<ADSC ;
}
    

