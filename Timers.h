/*
 * Interrupts.h
 *
 *  Created on: Feb 14, 2016
 *      Author: Hegman
 */

#ifndef TIMERS_H_
#define TIMERS_H_

typedef enum{
	TACLK,
	ACLK,
	SMCLK,
	INCLK
}ClockSrc;


typedef enum{
	STOP,
	TIMER_UP,
	CONTINUOUS,
	UP_DOWN
}Mode;


void Timer_A1_Init(ClockSrc, int, Mode);
void Timer_A1_Start(Mode);
//void Timer_A1_Stop(void);
void Timer_A1_Disable(void);
void Timer_A1_Set_Overflow(int);

unsigned int Timer_A1_Source_Select(ClockSrc);
unsigned int Timer_A1_Prescaler_Select(int);
unsigned int Timer_A1_Mode_Select(Mode);


#endif /* TIMERS_H_ */
