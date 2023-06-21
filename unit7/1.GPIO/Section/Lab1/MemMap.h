/*
 * MemMap.h
 *
 *  Created on: Jun 21, 2023
 *      Author: galal
 */

#ifndef MEMMAP_H_
#define MEMMAP_H_

#include "platform_types.h"

#define BASE			0x20

#define PORTA		*(vuint8_t *)(BASE + 0x1B)
#define DDRA		*(vuint8_t *)(BASE + 0x1A)
#define PINA		*(vuint8_t *)(BASE + 0x19)

#define PORTB		*(vuint8_t *)(BASE + 0x18)
#define DDRB		*(vuint8_t *)(BASE + 0x17)
#define PINB		*(vuint8_t *)(BASE + 0x16)

#define PORTC		*(vuint8_t *)(BASE + 0x15)
#define DDRC		*(vuint8_t *)(BASE + 0x14)
#define PINC		*(vuint8_t *)(BASE + 0x13)

#define PORTD		*(vuint8_t *)(BASE + 0x12)
#define DDRD		*(vuint8_t *)(BASE + 0x11)
#define PIND		*(vuint8_t *)(BASE + 0x10)

#endif /* MEMMAP_H_ */
