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
