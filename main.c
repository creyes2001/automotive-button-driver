#include <xc.h>
#include "interrupts.h"
#include "timer0.h"
#include "scheduler.h"
#include "button.h"
#include "config.h"
#include "dio.h"
#include "dio_cfg.h"

void __interrupt () isr (void)
{
	if(INTCONbits.TMR0IF)
	{
		timer0_reload();
		scheduler_tick();
		INTCONbits.TMR0IF = 0;
	}
}

void button_task(void)
{
	Button_Update();
}


int main()
{	
	Dio_Init();
	Button_Init();
	scheduler_init();
	timer0_init();
	timer0_start();

	enable_gi();	//enable global and peripherial inteerupts

	
	scheduler_add_task(&button_task,10);

	while(1)
	{
		scheduler_run();
	}

return 0;
}
