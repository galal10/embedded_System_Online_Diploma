/*
 * main.c
 *
 *  Created on: May 2, 2023
 *      Author: galal
 */

#include "MemMap.h"
#include "utils.h"

#define F_CPU 8000000UL

void my_delay(uint32_t time)
{
	vuint32_t i,j;

	for(i = 0; i < time; i++)
	{
		for(j = 0; j < 255; j++);
	}
}

int main(void)
{
	// init port A as output pins
	DDRA = 0xFF;

	// init pin D0 as input
	SET_BIT(DDRD,0);

	// as a pull up
	SET_BIT(PORTD,0);

	uint8_t flag = 0;

	while(1)
	{
		if( READ_BIT(PIND,0) == 0)
		{
			if( flag > 7 )
				flag = 0;

			TOGGLE_BIT(PORTA,flag);
			flag++;
			my_delay(500);
		}
	}

	return 0;
}
