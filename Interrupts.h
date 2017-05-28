/*
 * Interrupts.h
 *
 *  Created on: Jan 22, 2016
 *      Author: Hegman
 */

#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

typedef enum {
	RISING,
	FALLING
}EdgeSelect;

#define Enable_Global_Interrupts __bis_SR_register(GIE);
void Enable_Pin_Interrupt(int, int, EdgeSelect);
void Disable_Pin_Interrupt(int, int);
void Clear_Interrupt_Flag(int, int);

void Enable_Timer_A1_Interrupt(void);
void Disable_Timer_A1_Interrupt(void);
void Clear_Timer_A1_Interrupt_Flag(void);

#endif /* INTERRUPTS_H_ */
