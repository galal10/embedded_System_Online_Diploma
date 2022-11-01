/*
 * CA.c
 *
 *  Created on: Oct 31, 2022
 *      Author: galal
 */

#include "CA.h"

int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

// State pointer ---> pointer to function
void (*CA_state) ();

int US_Get_distance_random(int l, int r, int count);

STATE_define(CA_waiting)
{
	// state_name
	CA_state_id = CA_waiting;

	// state_action
	CA_speed = 0;
	// DC_motor(speed)


	// Event_check
	// US_GET_distance(CA_distance)
	CA_distance = US_Get_distance_random(45,55,1);
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));

	printf("CA_waiting state : distance = %d  speed = %d \n",CA_distance,CA_speed);
}

STATE_define(CA_driving)
{
	// state_name
	CA_state_id = CA_driving;

	// state_action
	CA_speed = 30;
	// DC_motor(speed)

	// Event_check
	// US_GET_distance(CA_distance)
	CA_distance = US_Get_distance_random(45,55,1);
	(CA_distance > CA_threshold)? (CA_state = STATE(CA_driving)) : (CA_state = STATE(CA_waiting));

	printf("CA_driving state : distance = %d  speed = %d \n",CA_distance,CA_speed);
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
