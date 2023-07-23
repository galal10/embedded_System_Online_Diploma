/*
 * keypad.c
 *
 *  Created on: Jul 8, 2023
 *      Author: galal
 */

#include "keypad.h"

int keypad_rows[] = {R0, R1, R2, R3};
int keypad_cols[] = {C0, C1, C2, C3};

void keypad_init()
{
	pin.GPIO_PinNUmber = R0;
	pin.GPIO_mode = GPIO_OUTPUT_AF_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	MCAL_GPIO_init(KEYPAD_PORT, &pin);

	pin.GPIO_PinNUmber = R1;
	pin.GPIO_mode = GPIO_OUTPUT_AF_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	MCAL_GPIO_init(KEYPAD_PORT, &pin);

	pin.GPIO_PinNUmber = R2;
	pin.GPIO_mode = GPIO_OUTPUT_AF_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	MCAL_GPIO_init(KEYPAD_PORT, &pin);

	pin.GPIO_PinNUmber = R3;
	pin.GPIO_mode = GPIO_OUTPUT_AF_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	MCAL_GPIO_init(KEYPAD_PORT, &pin);

	pin.GPIO_PinNUmber = C0;
	pin.GPIO_mode = GPIO_OUTPUT_AF_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	MCAL_GPIO_init(KEYPAD_PORT, &pin);

	pin.GPIO_PinNUmber = C1;
	pin.GPIO_mode = GPIO_OUTPUT_AF_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	MCAL_GPIO_init(KEYPAD_PORT, &pin);

	pin.GPIO_PinNUmber = C2;
	pin.GPIO_mode = GPIO_OUTPUT_AF_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	MCAL_GPIO_init(KEYPAD_PORT, &pin);

	pin.GPIO_PinNUmber = C3;
	pin.GPIO_mode = GPIO_OUTPUT_AF_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	MCAL_GPIO_init(KEYPAD_PORT, &pin);

//	KEYPAD_PORT = 0xFF;
	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);
}

char keypad_getChar()
{
	int i, j;

	for(i = 0; i < 4; i++)
	{
		KEYPAD_PORT |= ( (1<<keypad_cols[0]) | (1<<keypad_cols[1]) | (1<<keypad_cols[2]) | (1<<keypad_cols[3]) );
		// make one pin with 0
		KEYPAD_PORT &=~(1 <<keypad_cols[i]);

		for(j = 0; j < 4; j++)
		{
			if( !(KEYPAD_PIN & (1<<keypad_rows[j])) )
			{
				while( !(KEYPAD_PIN & (1<<keypad_rows[j])) );
				switch(i)
				{
					case(0):
						if( j == 0) return '7';
						else if( j == 1) return '4';
						else if( j == 2) return '1';
						else if( j == 3) return '!';
						break;
					case(1):
						if( j == 0) return '8';
						else if( j == 1) return '5';
						else if( j == 2) return '2';
						else if( j == 3) return '0';
						break;
					case(2):
						if( j == 0) return '9';
						else if( j == 1) return '6';
						else if( j == 2) return '3';
						else if( j == 3) return '=';
						break;
					case(3):
						if( j == 0) return '/';
						else if( j == 1) return '*';
						else if( j == 2) return '-';
						else if( j == 3) return '+';
						break;
				}
			}
		}
	}
	// if it is not pressed
	return 'N';
}
