/*
 * GPIO.h
 *
 *  Created on: Jan 27, 2016
 *      Author: Hegman
 */




#ifndef GPIO_H_
#define GPIO_H_

typedef enum {
	UP,
	DOWN,
	NONE
}PullResistor;

typedef enum {
	HIGH,
	LOW
}PinState;


void Set_P11_UART_RX(void);
void Set_P11_SPI_MISO(void);

void Set_P12_UART_TX(void);
void Set_P12_SPI_MOSI(void);

void Set_P14_SPI_CLKA(void);

void Set_Pin_Output(int, int);

void Set_Pin_Input(int, int, PullResistor);

void Set_Pin_State(int, int, PinState);

int Read_Pin_State(int, int);

#endif /* GPIO_H_ */
