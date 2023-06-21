/*
 * utilities.h
 *
 *  Created on: Jun 21, 2023
 *      Author: galal
 */

#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(byte,bit)		( byte |= (1 << bit) )
#define CLEAR_BIT(byte,bit)		( byte &=~(1 << bit) )
#define TOGGLE_BIT(byte,bit)	( byte ^= (1 << bit) )
#define READ_BIT(byte,bit)		((byte & (1 << bit)) >> bit )

#endif /* UTILS_H_ */
