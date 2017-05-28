/*
 * Comms.h
 *
 *  Created on: Jan 24, 2016
 *      Author: Hegman
 */

#ifndef COMMS_H_
#define COMMS_H_

void UART_Init(void);
void SPI_Init(int, int, int);
void I2C_Init(void);

void Send_String_UART(const char*);
void Send_String_SPI(const char*);
void Send_String_I2C(const char*);



#endif /* COMMS_H_ */
