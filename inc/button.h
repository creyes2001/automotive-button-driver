#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>

typedef enum
{
	BUTTON_STATE_RELEASED = 0,
	BUTTON_STATE_PRESSED
}Button_StateType;

void Button_Init(void);
void Button_Update(void);
Button_StateType Button_GetState(uint8_t buttonId);


#endif
