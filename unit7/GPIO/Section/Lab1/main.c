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

	while(1)
	{
		// led on from pin A0 to A7
		for(int i = 0; i <= 7; i++)
		{
			SET_BIT(PORTA,i);
			my_delay(100);
		}
		// led off from pin A7 to A0
		for(int i = 7; i>= 0; i--)
		{
			CLEAR_BIT(PORTA,i);
			my_delay(100);
		}
	}

	return 0;
}
