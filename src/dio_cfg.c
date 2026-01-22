#include "dio_cfg.h"
#include <xc.h>

/*Hardware mapping for BCM signals*/

const Dio_ChannelConfigType Dio_ChannelConfig[DIO_CH_MAX] = 
{
	[DIO_CH_DOOR_SWITCH] = 
	{
		.tris		= &TRISB,
		.port		= &PORTB,
		.lat		= &LATB,
		.pinMask	= (1U << 0),
		.direction	= DIO_INPUT
	},

	[DIO_CH_COURTESY_LAMP] =
	{
		.tris		= &TRISC,
		.port		= &PORTC,
		.lat		= &LATC,
		.pinMask	= (1U << 0),
		.direction 	= DIO_OUTPUT
	},

	[DIO_CH_TURN_SIGNAL_LAMP] =
	{
		.tris		= &TRISC,
		.port		= &PORTC,
		.lat		= &LATC,
		.pinMask	= (1U << 1),
		.direction	= DIO_OUTPUT
	},

	[DIO_CH_HAZARD_LAMP] =
	{
		.tris		= &TRISC,
		.port		= &PORTC,
		.lat		= &LATC,
		.pinMask	= (1U << 2),
		.direction	= DIO_OUTPUT
	}
};
			
