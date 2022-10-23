/*
 * main.c
 *
 *  Created on: Oct 19, 2022
 *      Author: galal
 */


#include "fifo.h"

int main(void)
{
	element_type z ,temp;
	FIFO_Buf_t FIFO_UART;
	if(FIFO_init(&FIFO_UART,uart_buffer,5) == FIFO_no_error)
	{
		printf("fifo init is DONE\n");
	}

	for(z=0;z<7;z++)
	{
		printf("\tFIFO Enqueue (%x) ",z);
		if(FIFO_enqueue(&FIFO_UART,z) == FIFO_no_error)
		{
			printf("\t ===fifo enqueue is Done\n");
		}
		else
			printf("\t ==fifo enqueue is failed\n");
	}

	FIFO_print(&FIFO_UART);

	if(FIFO_dequeue(&FIFO_UART,&temp) == FIFO_no_error)
	{
		printf("fifo dequeue %x is done\n",temp);
	}

	if(FIFO_dequeue(&FIFO_UART,&temp) == FIFO_no_error)
	{
		printf("fifo dequeue %x is done\n",temp);
	}

	FIFO_print(&FIFO_UART);

	z = 8;
	if(FIFO_enqueue(&FIFO_UART,z) == FIFO_no_error)
	{
		printf("\t %d ===fifo enqueue is Done\n",z);
	}

	z = 1;

	if(FIFO_enqueue(&FIFO_UART,z) == FIFO_no_error)
	{
		printf("\t %d ===fifo enqueue is Done\n",z);
	}


	FIFO_print(&FIFO_UART);

	return 0;

}
