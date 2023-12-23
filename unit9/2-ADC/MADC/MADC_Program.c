/*
 * MADC_Program.c
 *
 *  Created on: Dec 23, 2023
 *      Author: galal
 */

#include "../../LIB/LBITS.h"
#include "../../LIB/LSTD_TYPES.h"
#include "MADC_Private.h"
#include "MADC_Config.h"

/* ADC Initialization */
void MADC_Vid_Init(void)
{
	/* Cleared voltage reference bits */
	ADMUX &= ADC_VREF_MASK;
	/* Select V-Ref */
	ADMUX |= ADC_REF_VOLT << REFS0;

