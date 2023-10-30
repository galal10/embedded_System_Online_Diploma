/*
 * MUSART_Program.c
 *
 *  Created on: Oct 22, 2023
 *      Author: galal
 */
#include "../../LIB/LBITS.h"
#include "../../LIB/LSTD_TYPES.h"
#include "MUSART_Interface.h"
#include "MUSART_Config.h"
#include "MUSART_Private.h"

void MUSART_Vid_Init(void)
{
	u8 LOC_u8Copy_UCSRC = 0;

	/* frame */
	/* select USART mode */
#if USART_MODE == USART_ASYNCHRONOUS_MODE
	CLR_BIT(LOC_u8Copy_UCSRC, UMSEL);
#elif USART_MODE == USART_SYNCHRONOUS_MODE
	SET_BIT(LOC_u8Copy_UCSRC, UMSEL);

	/* set CLK polarity -> with synch. mode only */
	#if USART_CLOCK_POLARITY == USART_RisingTx_FallingRx
		CLR_BIT(UCSRC, UCPOL);
	#elif USART_CLOCK_POLARITY == USART_FallingTx_RisingRx
		SET_BIT(UCSRC, UCPOL);
	#else
		#error "USART CLK polarity mode is not valid"
	#endif

#else
	#error "USART mode is not valid"
#endif
}
