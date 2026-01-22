#include "dio.h"
#include "dio_cfg.h"

void Dio_Init(void)
{
	uint8_t i;

	for(i = 0; i < DIO_CH_MAX; i++)
	{
		if(Dio_ChannelConfig[i].direction == DIO_INPUT)
		{
			*(Dio_ChannelConfig[i].tris) |= Dio_ChannelConfig[i].pinMask;
		}
		else
		{
			*(Dio_ChannelConfig[i].tris) &= ~Dio_ChannelConfig[i].pinMask;
		}
	}
}

Dio_LevelType Dio_ReadChannel(uint8_t channelId)
{
	if(*(Dio_ChannelConfig[channelId].port) & Dio_ChannelConfig[channelId].pinMask)
	{
		return DIO_LEVEL_HIGH;
	}
	else
	{
		return DIO_LEVEL_LOW;
	}
}

void Dio_WriteChannel(uint8_t channelId, Dio_LevelType level)
{
	if(level == DIO_LEVEL_HIGH)
	{
		*(Dio_ChannelConfig[channelId].lat) |= Dio_ChannelConfig[channelId].pinMask;
	}
	else
	{
		*(Dio_ChannelConfig[channelId].lat) &= ~Dio_ChannelConfig[channelId].pinMask;
	}
}
