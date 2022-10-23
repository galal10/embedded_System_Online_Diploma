/*
 * lifo.h
 *
 *  Created on: Oct 19, 2022
 *      Author: galal
 */

#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//types definitions
typedef struct
{
	uint32_t length;
	uint32_t count;
	uint8_t* head;
	uint8_t* base;
}LIFO_Buf_t;

typedef enum
{
	LIFO_no_error,
	LIFO_full,
	LIFO_not_full,
	LIFO_empty,
	LIFO_not_empty,
	LIFO_Null
}LIFO_status;
//APIs
LIFO_status LIFO_push_item(LIFO_Buf_t* lifo_buf,uint32_t item);
LIFO_status LIFO_pop_item(LIFO_Buf_t* lifo_buf,uint32_t* item);
LIFO_status LIFO_init(LIFO_Buf_t* lifo_buf,uint32_t* buf,uint32_t length);

#endif /* LIFO_H_ */
