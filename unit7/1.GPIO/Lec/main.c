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

#include "platform_types.h"

// RCC reg
#define RCC_BASE 	0x40021000
#define GPIOA_BASE 	0x40010800
#define GPIOB_BASE	0x40010C00

// APB2 peripheral clock enable register
#define RCC_APB2ENP *(vuint32_t *)(RCC_BASE+0x18)

// GPIOA register
#define GPIOA_CRH 	*(vuint32_t *)(GPIOA_BASE+0x04)
#define GPIOA_CRL 	*(vuint32_t *)(GPIOA_BASE+0x00)
#define GPIOA_ODR	*(vuint32_t *)(GPIOA_BASE+0x0C)
#define GPIOA_IDR	*(vunit32_t *)(GPIOA_BASE+0x08)

// GPIOB register
#define GPIOB_CRH 	*(vuint32_t *)(GPIOB_BASE+0x04)
#define GPIOB_CRL 	*(vuint32_t *)(GPIOB_BASE+0x00)
#define GPIOB_ODR	*(vuint32_t *)(GPIOB_BASE+0x0C)
#define GPIOB_IDR	*(vunit32_t *)(GPIOB_BASE+0x08)

//bit field
#define RCC_IOPAEN   2
#define RCC_IOPBEN	 3

void clock_init()
{
	// Enable clock GPIOA
	RCC_APB2ENP |= (1<<RCC_IOPAEN);

	// Enable clock GPIOB
	RCC_APB2ENP |= (1<<RCC_IOPBEN);
}

void GPIOA_init()
{
	GPIOA_CRL = 0;
	GPIOB_CRL = 0;

	// A1 floating input mode

	//	MODEy[1:0] 00: Input mode (reset state)
	GPIOA_CRL &= ~(0b11 << 4);

	// 01: Floating input (reset state)
	GPIOA_CRL |= (0b01 << 6);

	/* ################################### */

	// B1 push pull output mode

	// 01: Output mode, max speed 10 MHz
	GPIOB_CRL |= (0b01 << 4);

	// 00: General purpose output push-pull
	GPIOB_CRL &= ~(0b11 << 6);

	/* ################################### */

	// A13 floating input mode

	//	MODEy[1:0] 00: Input mode (reset state)
	GPIOA_CRH &= ~(0b11 << 20);

	// 01: Floating input (reset state)
	GPIOA_CRH |= (0b01 << 22);

	/* ################################### */

	// B13 push pull output mode

	// 01: Output mode, max speed 10 MHz
	GPIOB_CRH |= (0b01 << 20);

	// 00: General purpose output push-pull
	GPIOB_CRH &= ~(0b11 << 22);

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
	GPIOA_init();

	while(1)
	{
		if ( ((GPIOA_IDR & (1 << 1)) >> 1) == 0 ) // single pressing
		{
			GPIOB_ODR ^= (1 << 1);

			while ( ((GPIOA_IDR & (1 << 1)) >> 1) == 0 );
		}

		if( ( (GPIOA_IDR & (1 << 13)) >> 13) == 1 ) // multi pressing
		{
			GPIOB_ODR ^= (1 << 13);
		}

		my_delay(1);
	}
}
