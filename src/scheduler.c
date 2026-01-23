#include "scheduler.h"

#define MAX_TASKS 5

static task_t task_list[MAX_TASKS];
static uint8_t task_count = 0;

void scheduler_init(void)
{
	uint8_t i;
	for(i = 0; i < MAX_TASKS; i++)
	{
		task_list[i].task = 0;
		task_list[i].period = 0;
		task_list[i].counter = 0;
		task_list[i].ready = 0;
	}
	task_count = 0;
}

void scheduler_add_task(task_func_t task, uint16_t period_ms)
{
	if(task_count < MAX_TASKS)
	{
		task_list[task_count].task = task;
		task_list[task_count].period = period_ms;
		task_list[task_count].counter = 0;
		task_list[task_count].ready = 0;
	}
	task_count++;
}

void scheduler_tick(void)
{
	uint8_t i;
	for(i = 0; i < task_count; i++)
	{
		task_list[i].counter++;
		if(task_list[i].counter >= task_list[i].period)
		{
			task_list[i].counter = 0;
			task_list[i].ready = 1;
		}
	}
}

void scheduler_run(void)
{
	uint8_t i;
	for(i = 0; i < task_count; i++)
	{
		if(task_list[i].ready == 1)
		{
			task_list[i].ready = 0;
			task_list[i].task();
		}
	}
}
