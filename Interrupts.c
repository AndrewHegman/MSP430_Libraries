/*
 * Interrupts.c
 *
 *  Created on: Jan 22, 2016
 *      Author: Hegman
 */

#include <Interrupts.h>
#include <msp430.h>

/*
void Enable_Global_Interrupts(void){
	__bis_SR_register(GIE);
}
*/
void Enable_Timer_A1_Interrupt(void){
	TACCTL0 |= CCIE;
}
void Disable_Timer_A1_Interrupt(void){
	TACCTL0 &= ~CCIE;
}

//void Enable_USCI_Interrupt(void);
//void Disable_USCI_Interrupt(void);


void Enable_Pin_Interrupt(int PORT, int PIN, EdgeSelect EDGE){
	int SwitchVar = 0x01<<PIN;
	switch(PORT){
	case 1:
		P1IE |= SwitchVar;
		if(EDGE == RISING){							//Set as RISING edge triggered
			P1IES &= ~SwitchVar;
		}
		else if(EDGE == FALLING){
			P1IES |= SwitchVar;					//Set as FALLING edge triggered
		}
		break;
	case 2:
		P2IE |= SwitchVar;
		if(EDGE == RISING){							//Set as RISING edge triggered
			P2IES &= ~SwitchVar;
		}
		else if(EDGE == FALLING){
			P2IES |= SwitchVar;					//Set as FALLING edge triggered
		}
		break;
	}
}

void Clear_Interrupt_Flag(int PORT, int PIN){
	int SwitchVar = 0x01<<PIN;
	switch(PORT){
	case 1:
		P1IFG &= ~SwitchVar;
		break;
	case 2:
		P2IFG &= ~SwitchVar;
		break;
	}
}

void Disable_Pin_Interrupt(int PORT, int PIN){
	int SwitchVar = 0x01<<PIN;
	switch(PORT){
	case 1:
		P1IES &= ~SwitchVar;
		break;
	case 2:
		P2IES &= ~SwitchVar;
		break;
	}
}

