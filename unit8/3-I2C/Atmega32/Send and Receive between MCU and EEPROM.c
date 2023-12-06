/*
 * main.c
 *
 *  Created on: Oct 1, 2023
 *      Author: galal
 */

#include "LIB/LSTD_TYPES.h"
#include "MCAL/MDIO/MDIO_Interface.h"
#include "HAL/HCLCD/HCLCD_Interface.h"
#include "HAL/HEEPROM/HEEPROM_Interface.h"
#include "util/delay.h"


int main(void)
{
	u8 Rec_Pass[10] = {0};
	u8 data, i = 0;
	HCLCD_Vid_4Bits_Init();
	HEEPROM_Vid_Init();

	HEEPROM_u8_WriteByte(1, 'G');
	_delay_ms(200);

	HEEPROM_u8_WriteByte(3, 'a');
	_delay_ms(200);

	HEEPROM_u8_WriteByte(5, 'l');
	_delay_ms(200);

	HEEPROM_u8_WriteByte(7, 'a');
	_delay_ms(200);

	HEEPROM_u8_WriteByte(9, 'l');
	_delay_ms(200);

	HEEPROM_u8_ReadByte(1, &data);
	Rec_Pass[i++] = data;
	_delay_ms(200);

	HEEPROM_u8_ReadByte(3, &data);
	Rec_Pass[i++] = data;
	_delay_ms(200);

	HEEPROM_u8_ReadByte(5, &data);
	Rec_Pass[i++] = data;
	_delay_ms(200);

	HEEPROM_u8_ReadByte(7, &data);
	Rec_Pass[i++] = data;
	_delay_ms(200);

	HEEPROM_u8_ReadByte(9, &data);
	Rec_Pass[i++] = data;
	_delay_ms(200);

	HCLCD_Vid_Write_String_4Bits(Rec_Pass);
	while(1)
	{

	}
	return 0;
}
