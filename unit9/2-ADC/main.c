/*
 * main.c
 *
 *  Created on: Oct 1, 2023
 *      Author: galal
 */

#include "MCAL/MADC/MADC_Interface.h"
#include "HAL/HCLCD/HCLCD_Interface.h"
#include <util/delay.h>


int main(void)
{
	MDIO_Error_state_SetPortDirection(MDIO_PORTB, PORT_OUTPUT);
	MDIO_Error_state_SetPortValue(MDIO_PORTB, 0);

	u16 digitVal = 0, AnalogVal = 0;
	u16 AnalogOldVal = 0;
	HCLCD_Vid_4Bits_Init();
	HCLCD_Vid_Write_String_4Bits((u8*)"Welcome....");
	_delay_ms(1000);
	HCLCD_Vid_Write_Command_4Bits(HCLCD_DISPLAY_CLEAR);

	MADC_Vid_Init();
	while(1)
	{
		digitVal = MADC_u16_StartConversion(CHANNEL_0);
		AnalogVal = (digitVal * 5000UL) / 1024;
		if(AnalogVal != AnalogOldVal)
		{
			AnalogOldVal = AnalogVal;
			HCLCD_Vid_Write_Command_4Bits(HCLCD_DISPLAY_CLEAR);
			HCLCD_Vid_Write_String_4Bits((u8*)"Digital = ");
			HCLCD_Vid_Write_Number_4Bits(digitVal);
			HCLCD_Vid_SetPosition_4Bits(HCLCD_LINE2, 0);
			HCLCD_Vid_Write_String_4Bits((u8*)"volt = ");
			HCLCD_Vid_Write_Number_4Bits(AnalogVal);
			HCLCD_Vid_Write_String_4Bits((u8*)"mV");
		}
	}
	return 0;
}
