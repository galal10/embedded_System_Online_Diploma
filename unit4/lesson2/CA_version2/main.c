/*
 * main.c
 *
 *  Created on: Oct 31, 2022
 *      Author: galal
 */

#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	// init all the drivers
	// init IRQ "interrupts"
	// init HAL US_driver DC_driver
	// init BLOCK
	US_init();
	DC_init();
	// set states pointers for each block
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}

int main(void)
{
	volatile int d;
	setup();

	while(1)
	{
		// call state for each block
		US_state();
		CA_state();
		DC_state();
		for(d=0;d<1000;d++);
	}
	return 0;
}
