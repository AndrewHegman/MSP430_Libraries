/*
 * Comms.c
 *
 *  Created on: Jan 24, 2016
 *      Author: Hegman
 */


#include <Comms.h>
#include <msp430.h>
#include <Interrupts.h>

void Send_Char_UART(unsigned char DATA){
	while (!(IFG2 & UCA0TXIFG));
		UCA0TXBUF = DATA;
}

void Send_String_UART(const char* STRING){
	int i;
	for(i=0; STRING[i]!='\0';i++){
		Send_Char_UART(STRING[i]);
	}
}

void Send_Char_SPI(unsigned char DATA){
	while(!(IFG2&UCA0TXIFG));
	UCA0TXBUF = DATA;
}

void Send_String_SPI(const char* STRING){
	int i;
	for(i=0; STRING[i]!='\0';i++){
		Send_Char_SPI(STRING[i]);
	}
}

void UART_Init(void){
	UCA0CTL1 = UCSWRST;
	UCA0CTL1 |= UCSSEL_2;
	UCA0BR0 = 104;			//See table 15-4, pg 424
	UCA0BR1 = 0;
	UCA0MCTL = UCBRS0;
	UCA0CTL1 &= ~UCSWRST;
}

void SPI_Init(int PHASE, int MASTER, int SYNC){
	UCA0CTL1 = UCSWRST;
	if (PHASE){
		UCA0CTL0 |= UCCKPH;
	}
	if (MASTER){
		UCA0CTL0 |= UCMST;
	}
	if (SYNC){
		UCA0CTL0 |= UCSYNC;
	}
	UCA0CTL1 |= UCSSEL_2;
	UCA0BR0 |= 0x02;
	UCA0BR1 = 0;
	UCA0MCTL = 0;
	UCA0CTL1 &= ~UCSWRST;
}

void I2C_Init(void){
}
