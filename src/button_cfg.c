#include "button_cfg.h"

const Button_ConfigType Button_Config[BUTTON_MAX] = 
{
	[BUTTON_0] = 
	{
		.channelId = DIO_CH_DOOR_SWITCH,
		.polarity = BUTTON_ACTIVE_LOW,
		.debounceThreshold = 3
	},

	[BUTTON_1] = 
	{
		.channelId = DIO_CH_HAZARD_SWITCH,
		.polarity = BUTTON_ACTIVE_LOW,
		.debounceThreshold = 3;
	}
};

