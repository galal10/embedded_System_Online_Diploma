/*
 * SUSART.c
 *
 *  Created on: Oct 26, 2023
 *      Author: galal
 */

#include "../../MCAL/MUART/MUSART_Interface.h"
#include "SUSART.h"
/******************************* Synchronous *******************************/
void SUSART_Vid_SendString(u8* P_u8_str)
{
	while(*P_u8_str)
	{
		MUSART_Vid_SendData(*P_u8_str++);
	}
}

void SUSART_Vid_ReceiveString(u8* P_u8_buffer)
{
	u8 index = 0;

	P_u8_buffer[index] = MUSART_u8_ReceiveData();

	/* ascii code of Enter */
	while(P_u8_buffer[index] != 0x0d)
	{
		index++;
		P_u8_buffer[index] = MUSART_u8_ReceiveData();
	}

	P_u8_buffer[index] = '\0';
}

