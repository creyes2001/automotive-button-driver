#include <xc.h>
#include "interrupts.h"
#include "timer0.h"
#include "scheduler.h"
#include "button.h"
#include "config.h"
#include "dio.h"
#include "button_cfg.h"

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

void test_task(void)
{
	if(Button_GetState(BUTTON_0) == BUTTON_PRESSED)
	{
		Dio_WriteChannel(DIO_CH_COURTESY_LAMP,DIO_LEVEL_HIGH);
	}
	else
	{
		Dio_WriteChannel(DIO_CH_COURTESY_LAMP,DIO_LEVEL_LOW);
	}

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
	scheduler_add_task(&test_task,5);

	while(1)
	{
		scheduler_run();
	}

return 0;
}
