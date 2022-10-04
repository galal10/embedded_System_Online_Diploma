/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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

// register
#define RCC_BASE 	0x40021000
#define PORTA_BASE 	0x40010800


#define RCC_APB2ENP *(vuint32_t *)(RCC_BASE+0x18)
#define GPIOA_CRH 	*(vuint32_t *)(PORTA_BASE+0x04)
#define GPIOA_ODR	*(vuint32_t *)(PORTA_BASE+0x0C)

//bit field
#define RCC_IOPAEN   2
#define GPIOA_CRHEN  21
#define GPIOA13  	 13

//void NMI_Handler(void) {}
//void H_fault_Handler(void) {}

int main(void)
{
	RCC_APB2ENP |=(1<<RCC_IOPAEN);
	GPIOA_CRH &=0xff0fffff;
	GPIOA_CRH |=(1<<GPIOA_CRHEN);
    /* Loop forever */
	while(1)
	{
		GPIOA_ODR |=(1<<GPIOA13);
		for(int i=0;i<9000;i++);
		GPIOA_ODR &=~(1<<GPIOA13);
		for(int i=0;i<9000;i++);
	}
}
