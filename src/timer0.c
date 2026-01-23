#include <xc.h>
#include "timer0.h"

#define TIMER0_RELOAD 0xFB1E

void timer0_init(void)
{
	T0CON = 0x00;			//stop timer
	T0CONbits.T08BIT = 0;	//16 bits
	T0CONbits.T0CS = 0;		//FOSC/4
	T0CONbits.PSA = 0;		//prescaler enable
	T0CONbits.T0PS = 0b001;	//prescaler 1:4
							
	timer0_reload();

	INTCONbits.TMR0IF = 0;
	INTCONbits.TMR0IE = 1;
}

void timer0_start(void)
{
	T0CONbits.TMR0ON = 1;
}

void timer0_stop(void)
{
	T0CONbits.TMR0ON = 0;
}

void timer0_reload(void)
{
	TMR0H = (TIMER0_RELOAD >> 8) & 0xFF;
	TMR0L = TIMER0_RELOAD & 0xFF;
}

