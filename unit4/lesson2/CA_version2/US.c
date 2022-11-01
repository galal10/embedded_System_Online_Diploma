/*
 * US.c
 *
 *  Created on: Oct 31, 2022
 *      Author: galal
 */

#include "US.h"


int US_distance = 0;

// State pointer ---> pointer to function
void (*US_state) ();

void US_init()
{
	// init US driver
	printf("US_init \n");
}

int US_Get_distance_random(int l, int r, int count);

STATE_define(US_busy)
{
	// state_name
	US_state_id = US_busy;

	// state_action
	US_distance = US_Get_distance_random(45,55,1);


	printf("US_waiting state : distance = %d  \n",US_distance);
	US_set_distance(US_distance);
	US_state = STATE(US_busy);
 }

int US_Get_distance_random(int l, int r, int count)
{
	int i;
	for(i = 0; i<count; i++)
	{
		int rand_num = (rand() % (r - l + 1)) + l;
		return rand_num;
	}
}
