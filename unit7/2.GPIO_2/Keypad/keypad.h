/*
 * keypad.h
 *
 *  Created on: Jul 8, 2023
 *      Author: galal
 */

#ifndef KEYPAD_KEYPAD_H_
#define KEYPAD_KEYPAD_H_

#include "../MemMap.h"

#define KEYPAD_PORT			PORTC
#define DATADir_KEYPAD_PORT	DDRC
#define KEYPAD_PIN			PINC

// ROWS
#define R0	0
#define R1	1
#define R2	2
#define R3	3
// Coloumns
#define C0	4
#define C1	5
#define C2	6
#define C3	7

void keypad_init();
char keypad_getChar();

#endif /* KEYPAD_KEYPAD_H_ */
