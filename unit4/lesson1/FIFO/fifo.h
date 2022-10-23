/*
 * fifo.h
 *
 *  Created on: Oct 19, 2022
 *      Author: galal
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

//user configuration
//select element type(char - int-...)

#define element_type uint8_t

// create width
#define width 5
element_type uart_buffer[width];

// fifo data types

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
