/*
 * Analog.c
 *
 *  Created on: Jan 27, 2016
 *      Author: Hegman
 */

#include <msp430.h>
#include <Interrupts.h>

#define CLOCK_DIV ADC10DIV_0

void Analog_INIT(void){
	//ADC10CTL0 = SREF_0 + ADC10SHT_3 + ADC10IE;
	ADC10CTL1 |= CONSEQ1;
	ADC10CTL0 |= ADC10SHT_2 + ADC10ON + MSC;

}

void Start_Converstion(void){
	//ADC10CTL0 |= ADC10ON;
	ADC10CTL0 |= ADC10SC + ENC;
}

void Stop_Conversion(void){
	ADC10CTL0 &= ~ADC10ON;
}

/*
void Set_P10_Analog_Input(void){
	//P1SEL |= BIT0;
	//ADC10AE0 |= BIT0;
	ADC10AE0 |= 1;
	//ADC10CTL1 = INCH_0 + CLOCK_DIV;
}

void Set_P11_Analog_Input(void){
	P1SEL |= BIT1;
	ADC10AE0 |= BIT1;
	ADC10CTL1 = INCH_1 + CLOCK_DIV;
}

void Set_P12_Analog_Input(void){
	P1SEL |= BIT2;
	ADC10AE0 |= BIT2;
	ADC10CTL1 = INCH_2 + CLOCK_DIV;
}

void Set_P13_Analog_Input(void){
	P1SEL |= BIT3;
	ADC10AE0 |= BIT3;
	ADC10CTL1 = INCH_3 + CLOCK_DIV;
}

void Set_P14_Analog_Input(void){
	P1SEL |= BIT4;
	ADC10AE0 |= BIT4;
	ADC10CTL1 = INCH_4 + CLOCK_DIV;
}

void Set_P15_Analog_Input(void){
	P1SEL |= BIT5;
	ADC10AE0 |= BIT5;
	ADC10CTL1 = INCH_5 + CLOCK_DIV;
}

void Set_P16_Analog_Input(void){
	P1SEL |= BIT6;
	ADC10AE0 |= BIT6;
	ADC10CTL1 = INCH_6 + CLOCK_DIV;
}

void Set_P17_Analog_Input(void){
	P1SEL |= BIT7;
	ADC10AE0 |= BIT7;
	ADC10CTL1 = INCH_7 + CLOCK_DIV;
}
*/
void Set_Pin_Analog_Input(int PIN){
	int SwitchVar = 0x01<<PIN;
	P1SEL |= SwitchVar;
	ADC10AE0 |= BIT7;
	//Need to figure out what INCH_X actually is
}
