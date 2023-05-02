/*
 * main.c
 *
 *  Created on: May 2, 2023
 *      Author: galal
 */

#define F_CPU 8000000UL
#include "util/delay.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define BASE			0x20

#define DDRD_REG		*(volatile unsigned int *)(BASE + 0x11)
#define PORTD_REG		*(volatile unsigned int *)(BASE + 0x12)

#define MCUCR_REG		*(volatile unsigned int *)(BASE + 0x35)
#define MCUCSR_REG		*(volatile unsigned int *)(BASE + 0x34)
#define GICR_REG		*(volatile unsigned int *)(BASE + 0x3B)
#define GIFR_REG		*(volatile unsigned int *)(BASE + 0x3A)
#define SREG_REG		*(volatile unsigned int *)(BASE + 0x3F)

void EXTI_init(void)
{
	// Any logical change on INT0 ==> ISC01 = 0 , ISC00 = 1
	MCUCR_REG |= (1<<0);

	// The rising edge of INT1 ==> ISC11 = 1 , ISC10 = 1
	MCUCR_REG |= (1<<2) | (1<<3);

	// If ISC2 is written to zero, a falling edge on INT2 activates the interrupt.
	MCUCSR_REG &= ~(1<<6);

    // Setting interrupt masks in GICR
	GICR_REG |= (1<<5) | (1<<6) | (1<<7);

    // Global Interrupt Enable (SREG I-bit)
	SREG_REG |= (1<<7);
}

void GPIO_init(void)
{
    // Pins 5, 6, 7 as output for LEDS
    DDRD_REG |= (1 << 5) | (1 << 6) | (1 << 7);
}

int main(void)
{
	GPIO_init();
	EXTI_init();

	while(1);

	return 0;
}

ISR(INT0_vect)
{
	PORTD_REG |= 1<<5;
	_delay_ms(1000);
	PORTD_REG &= ~(1<<5);
	// clear interrupt request flag
	GIFR_REG |= (1<<5);
}

ISR(INT1_vect)
{
	PORTD_REG |= 1<<6;
	_delay_ms(1000);
	PORTD_REG &= ~(1<<6);
	// clear interrupt request flag
	GIFR_REG |= (1<<6);
}

ISR(INT2_vect)
{
	PORTD_REG |= 1<<7 ;
	_delay_ms(1000);
	PORTD_REG &= ~(1<<7);
	// clear interrupt request flag
	GIFR_REG |= (1<<7);
}

