/*
 * GPIO.c
 *
 *  Created on: Jan 22, 2016
 *      Author: Hegman
 */

#include <GPIO.h>
#include <msp430.h>

void Set_P11_UART_RX(void){
	P1SEL |= BIT1;
	P1SEL2 |= BIT1;
	ADC10AE0 &= ~BIT1;
}
void Set_P11_SPI_MISO(void){
	P1SEL |= BIT1;
	P1SEL2 |= BIT1;
	ADC10AE0 &= ~BIT1;
}

void Set_P12_UART_TX(void){
	P1SEL |= BIT2;
	P1SEL2 |= BIT2;
	ADC10AE0 &= ~BIT2;
}
void Set_P12_SPI_MOSI(void){
	P1SEL |= BIT2;
	P1SEL2 |= BIT2;
	ADC10AE0 &= ~BIT2;
}

void Set_P14_SPI_CLKA(void){
	P1SEL |= BIT4;
	P1SEL2 |= BIT4;
	ADC10AE0 &= ~BIT4;
}

void Set_Pin_Output(int PORT, int PIN){
	int SwitchVar = 0x01<<PIN;
	switch(PORT){
		case 1:
			P1DIR |= SwitchVar;
			P1SEL &= ~SwitchVar;
			P1SEL2 &= ~SwitchVar;
			break;
		case 2:
			P2DIR |= SwitchVar;
			P2SEL &= ~SwitchVar;
			P2SEL2 &= ~SwitchVar;
			break;
		case 3:
			P3DIR |= SwitchVar;
			P3SEL &= ~SwitchVar;
			P3SEL2 &= ~SwitchVar;
			break;
	}
}

void Set_Pin_Input(int PORT, int PIN, PullResistor Resistor){
	int SwitchVar = 0x01<<PIN;
	switch(PORT){
	case 1:
		P1DIR &= ~SwitchVar;
		P1SEL &= ~SwitchVar;
		P1SEL2 &= ~SwitchVar;
		P1REN |= SwitchVar;

		if(Resistor == UP){				//Enable PULLUP
			P1OUT |= SwitchVar;
		}
		else if(Resistor == DOWN){			//Enable PULLDOWN
			P1OUT &= ~SwitchVar;
		}
		else if(Resistor == NONE){							//Disable resistors
			P1REN &= ~SwitchVar;
		}
		break;
	case 2:
		P2DIR &= ~SwitchVar;
		P2SEL &= ~SwitchVar;
		P2SEL2 &= ~SwitchVar;
		P2REN |= SwitchVar;

		if(Resistor == UP){				//Enable PULLUP
			P2OUT |= SwitchVar;
		}
		else if(Resistor == DOWN){			//Enable PULLDOWN
			P2OUT &= ~SwitchVar;
		}
		else if(Resistor == NONE){							//Disable resistors
			P2REN &= ~SwitchVar;
		}
		break;
	case 3:
		P3DIR &= ~SwitchVar;
		P3SEL &= ~SwitchVar;
		P3SEL2 &= ~SwitchVar;
		P3REN |= SwitchVar;

		if(Resistor == UP){				//Enable PULLUP
			P3OUT |= SwitchVar;
		}
		else if(Resistor == DOWN){			//Enable PULLDOWN
			P3OUT &= ~SwitchVar;
		}
		else if(Resistor == NONE){							//Disable resistors
			P3REN &= ~SwitchVar;
		}
		break;
	}
}

void Set_Pin_State(int PORT, int PIN, PinState STATE){
	int SwitchVar = 0x01<<PIN;
	if(STATE == LOW){
		switch(PORT){
		case 1:
			P1DIR &= ~SwitchVar;
			break;
		case 2:
			P2DIR &= ~SwitchVar;
			break;
		case 3:
			P3DIR &= ~SwitchVar;
			break;
		}
	}
	else if (STATE == HIGH){
		switch(PORT){
		case 1:
			P1DIR |= SwitchVar;
			break;
		case 2:
			P2DIR |= SwitchVar;
			break;
		case 3:
			P3DIR |= SwitchVar;
			break;
		}
	}
}

int Read_Pin_State(int PORT, int PIN){
	int SwitchVar = 0x01<<PIN;
	switch(PORT){
	case 1:
		return(P1IN&SwitchVar);
	case 2:
		return(P2IN&SwitchVar);
	case 3:
		return(P3IN&SwitchVar);
	}
	return(-1);
}
