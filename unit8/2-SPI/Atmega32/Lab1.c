/* Master 7-Segment */
/*
 * main.c
 *
 *  Created on: Oct 1, 2023
 *      Author: galal
 */

#include "MCAL/MDIO/MDIO_Interface.h"
#include "MCAL/MSPI/MSPI_Interface.h"

#include "util/delay.h"

int main(void)
{
	/* Set SS pin as an Output */
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN4, PIN_OUTPUT);
	/* Set MOSI pin as an Output */
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN5, PIN_OUTPUT);
	/* Set MISO pin as input pin */
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN6, PIN_INPUT);
	/* Set SCK pin as an Output */
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN7, PIN_OUTPUT);

	/* init Master SPI */
	MSPI_Vid_Master_Init();

	MDIO_Error_state_SetPortDirection(MDIO_PORTA, PORT_OUTPUT);

	u8 data;

	for(data = 0; data < 255; data++)
	{
		_delay_ms(1000);
		MDIO_Error_state_SetPortValue(MDIO_PORTA, MSPI_u8_Send_Receive(data));
	}
	return 0;
}

/* Slave 7-Segment */
/*
 * main.c
 *
 *  Created on: Oct 1, 2023
 *      Author: galal
 */
/*
#include "MCAL/MDIO/MDIO_Interface.h"
#include "MCAL/MSPI/MSPI_Interface.h"

#include "util/delay.h"

int main(void)
{
	// Set SS pin as an Input
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN4, PIN_INPUT);
	// Set MOSI pin as an Input
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN5, PIN_INPUT);
	// Set MISO pin as an Output
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN6, PIN_OUTPUT);
	// Set SCK pin as an Input
	MDIO_Error_state_SetPinDirection(MDIO_PORTB, PIN7, PIN_INPUT);

	// init Master SPI 
	MSPI_Vid_Slave_Init();

	MDIO_Error_state_SetPortDirection(MDIO_PORTA, PORT_OUTPUT);

	u8 data;

	for(data = 255; data >= 0; data--)
	{
		_delay_ms(1000);
		MDIO_Error_state_SetPortValue(MDIO_PORTA,MSPI_u8_Send_Receive(data));
	}
	return 0;
}
*/