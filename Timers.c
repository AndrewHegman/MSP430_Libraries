/*
 * Timers.c
 *
 *  Created on: Feb 14, 2016
 *      Author: Hegman
 */

#include <Timers.h>
#include <msp430.h>

void Timer_A1_Init(ClockSrc CLOCK, int PRESCALE, Mode MODE_SEL){
	TACTL = Timer_A1_Source_Select(CLOCK) + Timer_A1_Prescaler_Select(PRESCALE) + Timer_A1_Mode_Select(MODE_SEL);
}

void Timer_A1_Set_Overflow(int OVERFLOW){
	TACCR0 = OVERFLOW;
}

void Timer_A1_Start(Mode MODE_SEL){
	TACTL = Timer_A1_Mode_Select(MODE_SEL);
}

unsigned int Timer_A1_Source_Select(ClockSrc CLOCK){
	switch(CLOCK){
	case TACLK:
		return TASSEL_0;
	case ACLK:
		return TASSEL_1;
	case SMCLK:
		return TASSEL_2;
	case INCLK:
		return TASSEL_3;
	}
	return TASSEL_1;
}

unsigned int Timer_A1_Prescaler_Select(int PRESCALE){
	switch(PRESCALE){
	case 1:
		return ID_0;
	case 2:
		return ID_1;
	case 4:
		return ID_2;
	case 8:
		return ID_2;
	}
	return ID_0;
}

unsigned int Timer_A1_Mode_Select(Mode MODE_SEL){
	switch(MODE_SEL){
	case STOP:
		return MC_0;
	case TIMER_UP:
		return MC_1;
	case CONTINUOUS:
		return MC_2;
	case UP_DOWN:
		return MC_3;
	}
	return MC_0;
}
void Timer_A1_Disable(void);
