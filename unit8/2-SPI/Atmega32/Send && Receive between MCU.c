/*
 * main.c
 *
 *  Created on: Oct 1, 2023
 *      Author: galal
 */

#include "MCAL/MDIO/MDIO_Interface.h"
#include "MCAL/MSPI/MSPI_Interface.h"
#include "HAL/HCLCD/HCLCD_Interface.h"

#include "util/delay.h"


#define MASTER	1
#define SLAVE	0

#define SPI_Mode	MASTER


u8 x = 0;

int main(void)
{
#if SPI_Mode == MASTER

	u8 data = 'A', Buffer;
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
	/* init LCD */
	HCLCD_Vid_4Bits_Init();

	HCLCD_Vid_Write_String_4Bits("Master");

	while(1)
	{
		Buffer = MSPI_u8_Send_Receive(data);
		data++;

		if(data == 'Z'+1)
		{
			data = 'A';
		}
		HCLCD_Vid_SetPosition_4Bits(HCLCD_LINE2, 0);
		HCLCD_Vid_Write_Char_4Bits(Buffer);

		HCLCD_Vid_SetPosition_4Bits(HCLCD_LINE1, 9);
		HCLCD_Vid_Write_Number_4Bits(x);

		_delay_ms(1000);
		x++;

		if(x == 10)
		{
			x = 0;
		}
	}

#elif SPI_Mode == SLAVE

	u8 data = '0', Buffer;

	/* Set SS pin as an Input */
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN4, PIN_INPUT);
	/* Set MOSI pin as an Input */
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN5, PIN_INPUT);
	/* Set MISO pin as an Output */
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN6, PIN_OUTPUT);
	/* Set SCK pin as an Input */
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN7, PIN_INPUT);

	/* init Master SPI */
	MSPI_Vid_Slave_Init();
	/* init LCD */
	HCLCD_Vid_4Bits_Init();

	HCLCD_Vid_Write_String_4Bits("Slave");

	while(1)
	{
		Buffer = MSPI_u8_Send_Receive(data);
		data++;

		if(data == '9'+1)
		{
			data = '0';
		}
		HCLCD_Vid_SetPosition_4Bits(HCLCD_LINE2, 0);
		HCLCD_Vid_Write_Char_4Bits(Buffer);

		HCLCD_Vid_SetPosition_4Bits(HCLCD_LINE1, 9);
		HCLCD_Vid_Write_Number_4Bits(x);

		_delay_ms(200);
		x++;

		if(x == 10)
		{
			x = 0;
		}
	}
#endif

	return 0;
}
