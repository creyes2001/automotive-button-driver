#ifndef DIOCFG_H
#define DIOCFG_H

#include "dio.h"

typedef enum
{
	DIO_CH_DOOR_SWITCH = 0,
	DIO_CH_COURTESY_LAMP,
	DIO_CH_TURN_SIGNAL_LAMP,
	DIO_CH_HAZARD_LAMP,

	DIO_CH_MAX
}Dio_ChannelType;

extern const Dio_ChannelConfigType Dio_ChannelConfig[DIO_CH_MAX];



#endif
