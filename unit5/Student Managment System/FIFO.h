/*
 * fifo.h
 *
 *  Created on: Dec 31, 2022
 *      Author: galal
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "platforn_types.h"

//user configuration
//select element type(char - int-...)
#define element_type uint8_t

typedef struct
{
	element_type* head;
	element_type* base;
	element_type* tail;
	uint32_t length;
	uint32_t count;
}FIFO_Buf_t;

typedef enum
{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_Null
}FIFO_Buf_status;

//APIs
FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo,element_type* buf,uint32_t length);
FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo,element_type item);
FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo,element_type* item);
FIFO_Buf_status FIFO_IS_FULL(FIFO_Buf_t* fifo);
void FIFO_print(FIFO_Buf_t* fifo);


#endif /* FIFO_H_ */
