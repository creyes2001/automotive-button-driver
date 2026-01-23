#ifndef DIOCFG_H
#define DIOCFG_H

#include <stdint.h>

typedef enum
{
	DIO_CH_DOOR_SWITCH = 0,
	DIO_CH_COURTESY_LAMP,
	DIO_CH_TURN_SIGNAL_LAMP,
	DIO_CH_HAZARD_LAMP,
	DIO_CH_HAZARD_SWITCH,

	DIO_CH_MAX
}Dio_ChannelType;

typedef enum
{
	DIO_OUTPUT = 0,
	DIO_INPUT
}Dio_DirectionType;

typedef struct
{
	volatile uint8_t *tris;
	volatile uint8_t *port;
	volatile uint8_t *lat;
	uint8_t pinMask;
	Dio_DirectionType direction;
}Dio_ChannelConfigType;

extern const Dio_ChannelConfigType Dio_ChannelConfig[DIO_CH_MAX];

#endif
