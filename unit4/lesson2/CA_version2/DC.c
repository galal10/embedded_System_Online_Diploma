/*
 * DC.c
 *
 *  Created on: Oct 31, 2022
 *      Author: galal
 */

#include "DC.h"

int DC_speed = 0;

// State pointer ---> pointer to function
void (*DC_state) ();

void DC_init()
{
	// init PWM
	printf("DC_init \n");
}

void DC_motor(int s)
{
	DC_speed = s;
	DC_state = STATE(DC_busy);
	printf("CA ----------speed=%d-------> DC \n",DC_speed);
}

STATE_define(DC_idle)
{
	// state_name
	DC_state_id = DC_idle;

	// state_action
	// call pwm to make speed = DC_motor

	printf("DC_idle state : speed = %d \n",DC_speed);
}

STATE_define(DC_busy)
{
	// state_name
	DC_state_id = DC_busy;

	// state_action
	// call pwm to make speed = DC_motor

	DC_state = STATE(DC_idle);

	printf("DC_busy state : speed = %d \n",DC_speed);


}

