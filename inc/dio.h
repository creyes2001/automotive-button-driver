#ifndef DIO_H
#define DIO_H

#include <stdint.h>

typedef enum
{
	DIO_OUTPUT = 0,
	DIO_INPUT
}Dio_DirectionType;

typedef enum
{
	DIO_LEVEL_LOW = 0,
	DIO_LEVEL_HIGH
} Dio_LevelType;

typedef struct
{
	volatile uint8_t *tris;
	volatile uint8_t *port;
	volatile uint8_t *lat;
	uint8_t pinMask;
	Dio_DirectionType direction;
}Dio_ChannelConfigType;

void Dio_Init(void);
Dio_LevelType Dio_ReadChannel(uint8_t channelId);
void Dio_WriteChannel(uint8_t channelId, Dio_LevelType level);

#endif
