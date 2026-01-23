#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

typedef void (*task_func_t)(void);

typedef struct {
	task_func_t task;	//task function
	uint16_t period;	//period in ms
	volatile uint16_t counter;	//time accumulator
	volatile uint8_t ready;		//task ready flag
}task_t;

void scheduler_init(void);
void scheduler_add_task(task_func_t task, uint16_t period_ms);
void scheduler_tick(void);
void scheduler_run(void);

#endif
