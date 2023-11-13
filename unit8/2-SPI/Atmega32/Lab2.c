/*
 * main.c
 *
 *  Created on: Oct 1, 2023
 *      Author: galal
 */

#include "MCAL/MDIO/MDIO_Interface.h"
#include "MCAL/MSPI/MSPI_Interface.h"

#include "util/delay.h"

void execute(u8 cmd, u8 data)
{
	/* Set SS value as Low */
	MDIO_Error_state_SetPinValue(MDIO_PORTB, PIN4, PIN_LOW);
	/* send the command */
	MSPI_u8_Send_Receive(cmd);
	/* send the data */
	MSPI_u8_Send_Receive(data);
	/* Set SS value as High */
	MDIO_Error_state_SetPinValue(MDIO_PORTB, PIN4, PIN_HIGH);
}

int main(void)
{
	/* Set SS pin as an Output */
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN4, PIN_OUTPUT);
	/* Set MOSI pin as an Output */
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN5, PIN_OUTPUT);
	/* Set MISO pin as an Input */
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN6, PIN_INPUT);
	/* Set SCK pin as an Output */
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN7, PIN_OUTPUT);

	/* init Master SPI */
	MSPI_Vid_Master_Init();

	/* Decode all display */
	execute(0x09, 0xFF);
	/* Scan limit Display digits from 0 to 7 */
	execute(0x0B, 0x07);
	/* Intensity */
	execute(0x0A, 0x0F);
	/* Turn on display */
	execute(0x0C, 0x01);

	u8 index_display, counter = 0;

	while(1)
	{
		for(index_display = 1; index_display < 9; index_display++)
		{
			execute(index_display, counter++);
		}
		_delay_ms(1000);
	}

	return 0;
}
