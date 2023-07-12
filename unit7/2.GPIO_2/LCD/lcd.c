/*
 * lcd.c
 *
 *  Created on: Jul 4, 2023
 *      Author: galal
 */


#include "lcd.h"

void LCD_KICK()
{
	LCD_CTRL &=~(1<<Enable_SWITCH); // enable off
	_delay_ms(50);
	LCD_CTRL |= (1<<Enable_SWITCH); // enable on
}

void LCD_ClearScreen()
{
	LCD_Write_Command(LCD_CLEAR_SCREEN);
}

void LCD_Write_Command(uint8_t command)
{
	#ifdef EIGHT_BIT_MODE
		LCD_isBusy();
		LCD_PORT = command;
		LCD_CTRL &=~(1<<RS_SWITCH | 1<<RW_SWITCH);
		LCD_KICK();
	#endif

	#ifdef FOUR_BIT_MODE
		LCD_isBusy();
		LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
		LCD_CTRL &=~(1<<RS_SWITCH | 1<<RW_SWITCH);
		LCD_KICK();

		LCD_PORT = (LCD_PORT & 0x0F) | (command <<DATA_SHIFT);
		LCD_CTRL &=~(1<<RS_SWITCH | 1<<RW_SWITCH);
		LCD_KICK();

	#endif
}

void LCD_Write_Char(uint8_t data)
{
	#ifdef EIGHT_BIT_MODE
		LCD_isBusy();
		LCD_PORT = data;
		LCD_CTRL |= (1<<RS_SWITCH);
		LCD_CTRL &=~(1<<RW_SWITCH);
		LCD_KICK();
	#endif

	#ifdef FOUR_BIT_MODE
		LCD_isBusy();
		LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
		LCD_CTRL |= (1<<RS_SWITCH);
		LCD_CTRL &=~(1<<RW_SWITCH);
		LCD_KICK();

		LCD_PORT = (LCD_PORT & 0x0F) | (data<<DATA_SHIFT );
		LCD_CTRL |= (1<<RS_SWITCH);
		LCD_CTRL &=~(1<<RW_SWITCH);
		LCD_KICK();
	#endif
}

void LCD_isBusy()
{
	#ifdef EIGHT_BIT_MODE
		DataDir_LCD_PORT = 0x00;
	#endif
	#ifdef FOUR_BIT_MODE
		DataDir_LCD_PORT &=~(0xFF << DATA_SHIFT);
	#endif
	LCD_CTRL |= (1<< RW_SWITCH); // read mode
	LCD_CTRL &=~(1<< RS_SWITCH);	// RS off
	LCD_KICK();

	DataDir_LCD_PORT = 0xFF;
	LCD_CTRL &=~(1<<RW_SWITCH); // write mode

}

void LCD_init()
{
	// wait for the hardware to initialize
	_delay_ms(20);
	LCD_isBusy();
	// directions is output
	DataDir_LCD_CTRL |=(1<<Enable_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	// CTRL as input
	LCD_CTRL &=~(1<<Enable_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	// data port as output
	DataDir_LCD_PORT = 0xFF;
	_delay_ms(15);
	LCD_ClearScreen();
	#ifdef EIGHT_BIT_MODE
		LCD_Write_Command(LCD_FUNCTION_8BIT_2LINES);
	#endif

	#ifdef FOUR_BIT_MODE
		// only for 4 bit mode
		LCD_Write_Command(0x02);
		LCD_Write_Command(LCD_FUNCTION_4BIT_2LINES);
	#endif
	LCD_Write_Command(LCD_DISP_ON_CURSOR_BLINK);
	LCD_Write_Command(LCD_ENTRY_MODE);
}

void LCD_goto_xy(int line, int position)
{
	if( line == 1 )
	{
		if( position < 16 && position >=0 )
		{
			LCD_Write_Command(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}

	else if( line == 2)
	{
		if( position < 32 && position >=0 )
		{
			LCD_Write_Command(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}

void LCD_Write_String(uint8_t* data)
{
	int count = 0;

	while( *data > 0)
	{
		count++;
		LCD_Write_Char(*data++);

		if( count == 16 )
		{
			LCD_goto_xy(2, 0);
		}

		else if( count == 32 )
		{
			LCD_ClearScreen();
			LCD_goto_xy(1, 0);
			count = 0;
		}
	}
}

