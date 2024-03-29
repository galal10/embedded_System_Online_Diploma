/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103x6.h"
#include "Stm32_F103C6_gpio_driver.h"
#include "lcd.h"
#include "keypad.h"


#define ZERO	0x40
#define ONE		0x79
#define TWO		0x24
#define THREE	0x30
#define FOUR	0x19
#define FIVE	0x12
#define SIX		0x02
#define SEVEN	0x78
#define EIGHT	0x00
#define NINE	0x18


void clock_init()
{
	// Enable clock GPIOA
	RCC_GPIOA_CLK_EN();

	// Enable clock GPIOB
	RCC_GPIOB_CLK_EN();
}

void GPIO_7segment_init()
{
	GPIO_PinConfig_t pin;

	pin.GPIO_mode = GPIO_OUTPUT_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	pin.GPIO_PinNUmber = GPIO_PIN_9;
	MCAL_GPIO_init(GPIOB, &pin);

	pin.GPIO_mode = GPIO_OUTPUT_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	pin.GPIO_PinNUmber = GPIO_PIN_10;
	MCAL_GPIO_init(GPIOB, &pin);

	pin.GPIO_mode = GPIO_OUTPUT_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	pin.GPIO_PinNUmber = GPIO_PIN_11;
	MCAL_GPIO_init(GPIOB, &pin);

	pin.GPIO_mode = GPIO_OUTPUT_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	pin.GPIO_PinNUmber = GPIO_PIN_12;
	MCAL_GPIO_init(GPIOB, &pin);

	pin.GPIO_mode = GPIO_OUTPUT_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	pin.GPIO_PinNUmber = GPIO_PIN_13;
	MCAL_GPIO_init(GPIOB, &pin);

	pin.GPIO_mode = GPIO_OUTPUT_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	pin.GPIO_PinNUmber = GPIO_PIN_14;
	MCAL_GPIO_init(GPIOB, &pin);

	pin.GPIO_mode = GPIO_OUTPUT_PP_MODE;
	pin.GPIO_OutputSpeed = GPIO_SPEED_10M;
	pin.GPIO_PinNUmber = GPIO_PIN_15;
	MCAL_GPIO_init(GPIOB, &pin);
}

void my_delay(uint32_t time)
{
	uint32_t i,j;

	for(i = 0; i < time; i++)
	{
		for(j = 0; j < 255; j++);
	}
}

int main(void)
{
	clock_init();
	// GPIO_init();
	LCD_init();

	GPIO_7segment_init();

	LCD_Write_String("Galal Nasser");
	my_delay(500);
	LCD_ClearScreen();

	char pressed_key;

	unsigned char seg[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, ZERO};
	unsigned char lcd[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

	for(unsigned char i = 0; i < 11; i++)
	{
		LCD_Write_Char(lcd[i]);
		MCAL_GPIO_WritePort(GPIOB, seg[i] << 9);

		my_delay(100);
	}
	// turn off 7 seg
	MCAL_GPIO_WritePort(GPIOB, 0xFF << 9);

	keypad_init();

	LCD_ClearScreen();
	LCD_Write_String("Keypad is ready");
	LCD_ClearScreen();

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
