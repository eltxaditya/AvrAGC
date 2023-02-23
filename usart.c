/*
 * File:   usart.c
 * Author: bramhansh
 *
 * Created on February 22, 2023, 11:49 AM
 */


#include "usart.h"


void USART_Init(unsigned int ubrr)
{
/*Set baud rate */
UBRR0H = (unsigned char)(ubrr>>8);
UBRR0L = (unsigned char)ubrr;
//Enable receiver and transmitter 
UCSR0B = (1<<RXEN0)|(1<<TXEN0);
/* Set frame format: 8data, 1stop bit */
UCSR0C = (3<<UCSZ00);
}

void USART_Transmit(unsigned char data)
{
/* Wait for empty transmit buffer */
while (!(UCSR0A & (1<<UDRE0)));
/* Put data into buffer, sends the data */
UDR0 = data;
}

void USART_Send(const char *dataP){
    while(dataP[0]){
        USART_Transmit((unsigned char)dataP[0]);
        dataP++;
    }
}