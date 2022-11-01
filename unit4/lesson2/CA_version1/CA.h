/*
 * CA.h
 *
 *  Created on: Oct 31, 2022
 *      Author: galal
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"
// Define states

enum
{
	CA_waiting,
	CA_driving
}CA_state_id;

extern void (*CA_state) ();

STATE_define(CA_waiting);
STATE_define(CA_driving);

#endif /* CA_H_ */
