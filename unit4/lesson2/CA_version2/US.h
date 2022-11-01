/*
 * US.h
 *
 *  Created on: Oct 31, 2022
 *      Author: galal
 */

#ifndef US_H_
#define US_H_

#include "state.h"
// Define states

enum
{
	US_busy,
}US_state_id;

void US_init();

extern void (*US_state) ();

STATE_define(US_busy);

#endif /* US_H_ */
