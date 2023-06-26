/*
 * MemMap.h
 *
 *  Created on: Jun 21, 2023
 *      Author: galal
 */

#ifndef MEMMAP_H_
#define MEMMAP_H_

#include <stdint.h>

#define BASE			0x20

#define PORTA		*(volatile uint8_t *)(BASE + 0x1B)
#define DDRA		*(volatile uint8_t *)(BASE + 0x1A)
#define PINA		*(volatile uint8_t *)(BASE + 0x19)

#define PORTB		*(volatile uint8_t *)(BASE + 0x18)
#define DDRB		*(volatile uint8_t *)(BASE + 0x17)
#define PINB		*(volatile uint8_t *)(BASE + 0x16)

#define PORTC		*(volatile uint8_t *)(BASE + 0x15)
#define DDRC		*(volatile uint8_t *)(BASE + 0x14)
#define PINC		*(volatile uint8_t *)(BASE + 0x13)

#define PORTD		*(volatile uint8_t *)(BASE + 0x12)
#define DDRD		*(volatile uint8_t *)(BASE + 0x11)
#define PIND		*(volatile uint8_t *)(BASE + 0x10)

#endif /* MEMMAP_H_ */
