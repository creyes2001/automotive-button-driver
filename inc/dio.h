#ifndef DIO_H
#define DIO_H

#include "dio_cfg.h"


typedef enum
{
	DIO_LEVEL_LOW = 0,
	DIO_LEVEL_HIGH
} Dio_LevelType;


void Dio_Init(void);
Dio_LevelType Dio_ReadChannel(Dio_ChannelType channelId);
void Dio_WriteChannel(Dio_ChannelType channelId, Dio_LevelType level);

#endif
