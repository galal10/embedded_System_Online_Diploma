/*
 * state.h
 *
 *  Created on: Oct 31, 2022
 *      Author: galal
 */

#ifndef STATE_H_
#define STATE_H_


#include <stdio.h>
#include <stdlib.h>

// Automatic state functions generate

#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

// states connection
void US_set_distance(int d);
void DC_motor(int s);
#endif /* STATE_H_ */
