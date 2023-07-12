/*
 * main.c
 *
 *  Created on: Jul 4, 2023
 *      Author: galal
 */

#define F_CPU 8000000UL
#include "LCD/lcd.h"
#include "Keypad/keypad.h"



int main(void)
{
	LCD_init();
	keypad_init();
	char pressed_key;
	while(1)
	{
		pressed_key = keypad_getChar();
		switch(pressed_key)
		{
			case '!' :
				LCD_ClearScreen();
				break;

			case 'N' :
				break;
			default :
				LCD_Write_Char(pressed_key);
				break;
		}
	}
}
