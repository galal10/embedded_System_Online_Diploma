/*
 * fifo.h
 *
 *  Created on: Feb 6, 2023
 *      Author: galal
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define DPRINTF(...) printf(__VA_ARGS__);fflush(stdout);fflush(stdin);

typedef unsigned short 			uint16_t;
typedef unsigned int 			uint32_t;

typedef struct
{
	char FirstName[10];
	char LastName[10];
	int ID;
	float GPA;
	int CoursesRegistered[5];
}SStudentInformation;

SStudentInformation Student_Buffer[15];

typedef struct
{
	SStudentInformation* head;
	SStudentInformation* base;
	SStudentInformation* tail;
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
FIFO_Buf_status FIFO_init(FIFO_Buf_t* fifo,SStudentInformation* buf,uint32_t length);
FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo,SStudentInformation *item);
FIFO_Buf_status FIFO_dequeue(FIFO_Buf_t* fifo,SStudentInformation* item);
FIFO_Buf_status FIFO_IS_FULL(FIFO_Buf_t* fifo);
void FIFO_print(FIFO_Buf_t* fifo);

int Count_Of_Students (FIFO_Buf_t* fifo);
int Find_Student_by_First_Name (FIFO_Buf_t* fifo, SStudentInformation *p_student);
int Find_Student_by_ID (FIFO_Buf_t* fifo, SStudentInformation *p_student);
int Delete_Student_by_ID (FIFO_Buf_t* fifo, SStudentInformation *p_student);
int Update_Student (FIFO_Buf_t* fifo, SStudentInformation *p_student);


#endif /* FIFO_H_ */
