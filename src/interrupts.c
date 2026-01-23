#include <xc.h>
#include "interrupts.h"

void enable_gi(void)
{
	INTCONbits.GIE = 1;
	INTCONbits.PEIE = 1;
}

void disable_gi(void)
{
	INTCONbits.GIE = 0;
	INTCONbits.PEIE = 0;
}


