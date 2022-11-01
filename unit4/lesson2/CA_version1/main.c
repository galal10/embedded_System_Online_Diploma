/*
 * main.c
 *
 *  Created on: Oct 31, 2022
 *      Author: galal
 */

#include "CA.h"

void setup()
{
	// init all the drivers
	// init IRQ "interrupts"
	// init HAL US_driver DC_driver
	// init BLOCK
	// set states pointers for each block
	CA_state = STATE(CA_waiting);
}

int main(void)
{
	volatile int d;
	setup();

	while(1)
	{
		// call state for each block
		CA_state();
		for(d=0;d<1000;d++);
	}
	return 0;
}
