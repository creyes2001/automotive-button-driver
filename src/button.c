#include "button.h"
#include "button_cfg.h"
#include "dio.h"

/* Last raw level read from DIO */
static Dio_LevelType Button_LastRawLevel[BUTTON_MAX];

/* Debounced counters */
static uint16_t Button_DebounceCounter[BUTTON_MAX];

/* Debounced logical state */
static Button_StateType Button_State[BUTTON_MAX];

/* local function helper */
static Button_StateType Button_InterpretLevel(uint8_t buttonId,Dio_LevelType level)
{
	if(Button_Config[buttonId].polarity == BUTTON_ACTIVE_HIGH)
	{
		return (level == DIO_LEVEL_HIGH) ? BUTTON_PRESSED : BUTTON_RELEASED;
	}
	else
	{
		return (level == DIO_LEVEL_LOW) ? BUTTON_PRESSED : BUTTON_RELEASED;
	}
}


void Button_Init(void)
{
	uint8_t i;

	for(i = 0U; i < BUTTON_MAX; i++)
	{
		Button_LastRawState[i] = Dio_ReadChannel(Button_Config[i].channelId);
		Button_DebounceCounter[i] = 0U;
		Button_State[i] = BUTTON_RELEASED;
	}

}

void Button_Update(void)
{
	uint8_t i;
	Dio_LevelType currentRaw;
	Button_State_Type interpretedState;

	for(i = 0U; i < BUTTON_MAX; i++ )
	{
		currentRaw = Dio_ReadChannel(Button_Config[i].channelId);

		if(currentRaw == Button_LastRawLevel[i])
		{
			if(Button_DebounceCounter[i] < Button_Config[i].debounceTreshold)
			{
				Button_DebounceCounter[i]++;
			}
			else
			{
				interpretedState = Button_InterpratState(i,currentRaw);
				ButtonState[i] = interpretedState;
			}
		}
		else
		{
			Button_DebounceCounter = 0U;
			Button_LastRawLevel[i] = currentRaw;
		}
	}
}

Button_StateType Button_GetState(uint8_t buttonId)
{
	return Button_State[buttonId];
}

