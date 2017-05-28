#include <msp430.h>

/*
 * main.c
 */

#include <GPIO.h>
#include <Interrupts.h>
#include <Comms.h>
#include <Analog.h>
#include <Timers.h>
#include <msp430.h>
//#include <C:\Users\Hegman\Desktop\VirtualWire\VirtualWire.h>


int main(void) {
	WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	//DCOCTL = DCO0 + MOD0;
	//BCSCTL1 |= RSEL0;
	/*
	Timer_A1_Set_Overflow(12000);
	Timer_A1_Init(ACLK, 1, TIMER_UP);
	Enable_Timer_A1_Interrupt();

	__bis_SR_register(GIE);
	TACCTL0 |= CCIE;	//Enable Interrupts on Timer
	TACCR0 = 1000;	//Number of cycles in the timer
	TACTL |= TASSEL_1;	//Use ACLK as source for timer
	TACTL |= MC_1;	//Use UP mode timer

	*/
	Set_Pin_Output(1,0);
	Set_Pin_State(1,0,HIGH);
    while(1){
    }
    //return 0;
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A0(void)
{
	P1OUT ^= BIT0;	//Toggle the LED
//When we exit the interrupt routine we return to Low Power Mode

}
