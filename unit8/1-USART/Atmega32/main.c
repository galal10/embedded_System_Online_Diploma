/*
 * main.c
 *
 *  Created on: Oct 1, 2023
 *      Author: galal
 */

#include "MCAL/MGIE/MGIE_Interface.h"
#include "MCAL/MUART/MUSART_Interface.h"
#include "Services/SUSART/SUSART.h"
#include "HAL/HCLCD/HCLCD_Interface.h"
#include "util/delay.h"


int main(void)
{
	/* Set Tx pin as input pin */
	MDIO_Error_state_SetPinDirection(MDIO_PORTD, PIN1, PIN_INPUT);
	/* Set Rx pin as input pin */
	MDIO_Error_state_SetPinDirection(MDIO_PORTD, PIN0, PIN_INPUT);
	/* init LCD */
	HCLCD_Vid_4Bits_Init();
	/* init UART */
	MUSART_Vid_Init();
	/* Enable global interrupt */
	MGIE_Vid_Enable();

	u8 num = 0, str[100] = "Receive until Enter", Buffer[100] = {0};

	SUSART_Vid_ReceiveStringAsynch(Buffer);

	while(1)
	{
		SUSART_Vid_SendString_NoCodeInt(str);

		HCLCD_Vid_SetPosition_4Bits(2, 0);
		HCLCD_Vid_Write_String_4Bits(Buffer);

		HCLCD_Vid_SetPosition_4Bits(1, 0);
		HCLCD_Vid_Write_Number_4Bits(num);
		num++;
		_delay_ms(300);

		if(num == 10) { num = 0; }
	}

	return 0;
}
