/*
 * main.c
 *
 *  Created on: Aug 27, 2023
 *      Author: galal
 */

#include "MCAL/MDIO/MDIO_Interface.h"
#include "HAL/HCLCD/HCLCD_Interface.h"

int main(void)
{
	HCLCD_Vid_4Bits_Init();
	HCLCD_Vid_Write_String_4Bits((u8*)"Learn in Depth");
	while(1)
	{

	}
	return 0;
}
