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
#include "Stm32_F103C6_USART_driver.h"


void clock_init()
{
	// Enable clock GPIOA, GBIOB, AFIO
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
}

void my_delay(uint32_t time)
{
	uint32_t i,j;

	for(i = 0; i < time; i++)
	{
		for(j = 0; j < 255; j++);
	}
}

uint16_t Byte;

int main(void)
{
	USART_Config_t USART_Config;

	clock_init();
	USART_Config.BaudRate = USART_BaudRate_115200;
	USART_Config.HwFlowCtl = USART_HwFlowCtl_NONE;
	USART_Config.Parity = USART_Parity_NONE;
	USART_Config.StopBits = USART_StopBits__1;
	USART_Config.USART_Mode = USART_Mode_Tx_Rx;
	USART_Config.PayloadLen = USART_PayloadLen_8B;
	USART_Config.IRQ_Enable = USART_IRQ_NONE;
	USART_Config.P_IRQ_CallBack = NULL;

	MCAL_USART_Init(USART1, &USART_Config);
	MCAL_USART_GPIO_Set_Pins(USART1);

	while(1)
	{
		MCAL_USART_ReceiveData(USART1, &Byte, enable);
		MCAL_USART_SendData(USART1, &Byte, enable);

	}
}
