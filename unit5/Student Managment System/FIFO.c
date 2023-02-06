/*
 * fifo.c
 *
 *  Created on: Feb 6, 2023
 *      Author: galal
 */

#include "FiFo.h"


FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo,SStudentInformation* buf,uint32_t length)
{
	if(buf == NULL)
	{
		return FIFO_Null;
	}
	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;
	fifo->count = 0;
	fifo->length = length;

	return FIFO_no_error;
}
FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo,SStudentInformation item)
{
	//null
	if(!fifo->head || !fifo->base || !fifo->tail)
	{
		return FIFO_Null;
	}

	//full
	if(FIFO_IS_FULL(fifo) == FIFO_full)
	{
		return FIFO_full;
	}

	*(fifo->head) = item;
	fifo->count++;

	//circular fifo

	if(fifo->head == (fifo->base + fifo->length * sizeof(SStudentInformation)))
	{
		fifo->head = fifo->base;
	}
	// not the end of list
	else
	{
		fifo->head++;
	}
	return FIFO_no_error;
}
FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo,SStudentInformation* item)
{
	//null
	if(!fifo->head || !fifo->base || !fifo->tail)
	{
		return FIFO_Null;
	}

	//empty
	if(fifo->count == 0)
	{
		return FIFO_empty;
	}

	*item = *(fifo->tail);
	fifo->count--;

	//circular
	if(fifo->tail == (fifo->base + fifo->length * sizeof(SStudentInformation)))
	{
		fifo->tail = fifo->base;
	}

	else
	{
		fifo->tail++;
	}
	return FIFO_no_error;
}
FIFO_Buf_status FIFO_IS_FULL(FIFO_Buf_t* fifo)
{
	//null
	if(!fifo->head || !fifo->base || !fifo->tail)
	{
		return FIFO_Null;
	}
	//full
	if(fifo->count == fifo->length)
	{
		return FIFO_full;
	}
	return FIFO_no_error;
}
void FIFO_print(FIFO_Buf_t* fifo)
{
	SStudentInformation* temp;

	if(fifo->count ==0)
	{
		printf("fifo is empty\n");
		return;
	}

	int i;
	temp = fifo->tail;
	printf("\n=======fifo_print=====\n");
	for(i=0;i<fifo->count;i++)
	{
		printf("\t=== %d ===\n",*temp);
		if(temp == (fifo->base + fifo->length * sizeof(SStudentInformation)))
		{
			temp = fifo->base;
		}
		// not the end of list
		else
		{
			temp++;
		}

	}
	printf("=============\n");
}
