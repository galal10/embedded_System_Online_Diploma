/*
 * main.c
 *
 *  Created on: Oct 19, 2022
 *      Author: galal
 */

#include "lifo.h"
uint32_t buffer1[5];

int main(void)
{
	uint8_t i ,temp=0;
	LIFO_Buf_t uart_lifo,I2C_lifo;
	LIFO_init(&uart_lifo,buffer1,5);

	uint32_t* buffer2 = (uint32_t*)malloc(5 * sizeof(uint32_t));
	LIFO_init(&I2C_lifo,buffer2,5);

	for(i=0;i<5;i++)
	{
		if(LIFO_push_item(&uart_lifo,i) == LIFO_no_error)
		{
			printf("-%d: UART_LIFO add :%d \n",i+1,i);
		}
	}
	for(i=0;i<5;i++)
	{
		if(LIFO_pop_item(&uart_lifo,&temp) == LIFO_no_error)
		{
			printf("-%d: UART_LIFO poped :%d\n",i+1,temp);
		}
	}
	return 0;
}
