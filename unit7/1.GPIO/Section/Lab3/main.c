/*
 * main.c
 *
 *  Created on: May 2, 2023
 *      Author: galal
 */

#include "MemMap.h"
#include "utils.h"
#include <util/delay.h>

#define F_CPU 8000000UL


int main(void)
{
	// port C as output
	DDRC = 0xFF;

	uint8_t i,j;
	while(1)
	{
		for(i = 0; i < 10; i++)
		{
			for(j = 0; j < 10; j++)
			{
				for(uint8_t k = 0; k < 50; k++)
				{
					PORTC = 0b1011 | (i<<4);
					_delay_ms(10);

					PORTC = 0b0111 | (j<<4);
					_delay_ms(10);
				}
			}
		}
	}

	return 0;
}
