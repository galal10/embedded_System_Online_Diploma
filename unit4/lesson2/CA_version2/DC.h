/*
 * DC.h
 *
 *  Created on: Oct 31, 2022
 *      Author: galal
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"
// Define states

enum
{
	DC_idle,
	DC_busy
}DC_state_id;

void DC_init();

extern void (*DC_state) ();

STATE_define(DC_idle);
STATE_define(DC_busy);

#endif /* DC_H_ */
