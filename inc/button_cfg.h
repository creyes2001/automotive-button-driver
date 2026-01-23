#ifndef BUTTONCFG_H
#define BUTTONCFG_H

#include <stdint.h>
#include "dio.h"
#include "dio_cfg.h"

typedef enum
{
	BUTTON_0 = 0,
	BUTTON_1,

	BUTTON_MAX
}Button_IdType;

typedef enum
{
	BUTTON_ACTIVE_LOW = 0,
	BUTTON_ACTIVE_HIGH
}Button_PolarityType;

typedef struct
{
	Dio_ChannelType channelId;
	Button_PolarityType polarity;
	uint16_t 		debounceThreshold;
}Button_ConfigType;

extern const Button_ConfigType Button_Config[BUTTON_MAX];

#endif
