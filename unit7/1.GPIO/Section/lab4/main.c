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
	// port D0 as output
	CLEAR_BIT(DDRD,0);

	SET_BIT(DDRD,4);


	while(1)
	{
		if( READ_BIT(PIND,0) == 1 )
		{
			SET_BIT(PORTD,4);
			my_delay(500);
			CLEAR_BIT(PORTD,4);
			my_delay(500);
		}
	}

	return 0;

}
