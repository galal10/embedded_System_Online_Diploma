/*
 * lifo.c
 *
 *  Created on: Oct 19, 2022
 *      Author: galal
 */

#include "lifo.h"


LIFO_status LIFO_push_item(LIFO_Buf_t* lifo_buf,uint32_t item)
{
	// check if it's valid
	if(!lifo_buf->head || !lifo_buf->base)
	{
		return LIFO_Null;
	}
	// check if it's full
	if(lifo_buf->count == lifo_buf->length)
	{
		return LIFO_full;
	}

	*(lifo_buf->head) = item;
	lifo_buf->head ++;
	lifo_buf->count++;
	return LIFO_no_error;
}
LIFO_status LIFO_pop_item(LIFO_Buf_t* lifo_buf,uint32_t* item)
{
	// check if it's valid
	if(!lifo_buf->head || !lifo_buf->base)
	{
		return LIFO_Null;
	}

	//check if it's empty
	if(lifo_buf->count == 0)
	{
		return LIFO_empty;
	}
	lifo_buf->head--;
	*item = *(lifo_buf->head);
	lifo_buf->count--;
	return LIFO_no_error;
}
LIFO_status LIFO_init(LIFO_Buf_t* lifo_buf,uint32_t* buf,uint32_t length)
{
	if(buf == NULL)
	{
		return LIFO_Null;
	}

	lifo_buf->base = buf;
	lifo_buf->head = buf;
	lifo_buf->length = length;
	lifo_buf->count = 0;

	return LIFO_no_error;
}

