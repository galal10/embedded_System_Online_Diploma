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

	/* Set PreScaler */
	ADCSRA &= ADC_SCALE_MASK;
	ADCSRA |= ADC_PRESCALER;

	/* Select Left or Right Adjust */
#if ADC_ADJUST == ADC_LEFT_ADJSUT
	SET_BIT(ADMUX, ADLAR);

#elif ADC_ADJUST == ADC_RIGHT_ADJSUT
	CLR_BIT(ADMUX, ADLAR);

#else
	#error "ADC adjust options is not valid"

#endif
