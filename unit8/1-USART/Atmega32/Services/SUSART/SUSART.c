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

/******************************* Asynchronous *******************************/
void SUSART_Vid_SendStringAsynch(u8* str)
{
	/* Set CallBack function */
	MUSART_Vid_SetCallBack(TXC_INT, Func_Tx);

	/* Enable interrupt Tx */
	MUSART_Vid_EnableInterrupt(TXC_INT);

	/* Send first Byte */
	MUSART_Vid_SendDataNoBlock(str[0]);

	/* copy the address of string to the global array */
	Asynch_Send_str = str;
}

