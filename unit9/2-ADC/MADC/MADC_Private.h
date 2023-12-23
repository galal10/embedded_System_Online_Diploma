/*
 * MADC_Private.h
 *
 *  Created on: Dec 23, 2023
 *      Author: galal
 */

#ifndef MADC_PRIVATE_H_
#define MADC_PRIVATE_H_

/* ADC Multiplexer Selection Register */
#define ADMUX			*((volatile u8*)0x27)
/* ADMUX Bits */
#define REFS1 			7
#define REFS0 			6
#define ADLAR 			5
#define MUX4 			4
#define MUX3 			3
#define MUX2 			2
#define MUX1 			1
#define MUX0			0

/* ADC Control and Status Register A */
#define ADCSRA			*((volatile u8*)0x26)
/* ADCSRA Bits */
#define ADEN 			7
#define ADSC 			6
#define ADATE 			5
#define ADIF 			4
#define ADIE 			3
#define ADPS2 			2
#define ADPS1 			1
#define ADPS0			0

