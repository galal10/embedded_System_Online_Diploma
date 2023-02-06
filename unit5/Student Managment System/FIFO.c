/*
 * fifo.c
 *
 *  Created on: Feb 4, 2023
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
FIFO_Buf_status FIFO_enqueue(FIFO_Buf_t* fifo,SStudentInformation *item)
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

	DPRINTF("=======================\n");

	DPRINTF("\tEnter first name: ");
	scanf("%s",fifo->head->FirstName);
	
	DPRINTF("\tEnter last name: ");
	scanf("%s",fifo->head->LastName);

	DPRINTF("\tEnter The ID: ");
	scanf("%d",&fifo->head->ID);
	
	DPRINTF("\tEnter The GPA: ");
	scanf("%f",&fifo->head->GPA);
	
	DPRINTF("\tEnter The ID Of Courses Registered: ");
	int i;
	for (i = 0; i < 5; i++)
	{
		DPRINTF("\n\tEnter The ID Of Course %d : ", i+1);
		scanf("%d", &fifo->head->CoursesRegistered[i]);
	}

	DPRINTF("\n=======================\n");

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
		DPRINTF("\n=========================");
		DPRINTF("The Queue Is Empty");
		DPRINTF("\n=========================");
		return FIFO_empty;
	}

	item->ID = fifo->tail->ID;
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
		DPRINTF("\n==========================\n");
		DPRINTF("fifo is empty\n");
		DPRINTF("\n==========================\n");
		return;
	}

	int i,j;
	temp = fifo->tail;
	DPRINTF("\n=======fifo_print=====\n");
	for(i=0;i<fifo->count;i++)
	{
		DPRINTF("\tThe First Name is: %s \n", temp->FirstName);
		DPRINTF("\tThe Last Name is: %s \n", temp->LastName);
		DPRINTF("\tThe ID is: %d \n", temp->ID);
		DPRINTF("\tThe GPA is: %0.1f \n", temp->GPA);
		for (j = 0; j < 5; j++)
		{
			DPRINTF("\t The ID Of The %d Course is : %d \n", j+1, (temp->CoursesRegistered[j]));
		}
		if(temp == (fifo->base + fifo->length * sizeof(SStudentInformation)))
		{
			temp = fifo->base;
		}
		// not the end of list
		else
		{
			DPRINTF("==========================\n");
			temp++;
		}

	}
	DPRINTF("=============\n");
}

int Count_Of_Students (FIFO_Buf_t* fifo)
{
	return fifo->count;
}

int Find_Student_by_First_Name (FIFO_Buf_t* fifo, SStudentInformation *p_student)
{
	char firstName[10];
	int i = 0, j = 0;
	p_student = fifo->tail;
	DPRINTF("\nEnter The First Name of The Student You Want : ");
	scanf("%s", firstName);

	for (i = 0; i < fifo->count; i++)
	{
		if (strcmp(p_student->FirstName, firstName) == 0)
		{
			DPRINTF("===========================\n");
			DPRINTF("\tThe First Name is: %s \n", p_student->FirstName);
			DPRINTF("\tThe Last Name is: %s \n", p_student->LastName);
			DPRINTF("\tThe ID is: %d \n", p_student->ID);
			DPRINTF("\tThe GPA is: %f ", p_student->GPA);
			for (j = 0; j < 5; j++)
			{
				DPRINTF("\t The ID Of The %d Course is : %d \n", j+1, (p_student->CoursesRegistered[j]));
			}
			DPRINTF("=================================\n");
			return 0;
		}
		p_student++;
	}
	DPRINTF("\n=============================\n");
	DPRINTF("The First Name is Not Found\n");
	DPRINTF("===============================\n");

	return 0;

}

int Find_Student_by_ID (FIFO_Buf_t* fifo, SStudentInformation *p_student)
{
	int ID_Number;
	int i = 0, j = 0;
	p_student = fifo->tail;
	DPRINTF("\nEnter The ID Of The Student You Want: ");
	scanf("%d", &ID_Number);

	for (i = 0; fifo->count; i++)
	{
		if (p_student->ID == ID_Number)
		{
			DPRINTF("=================================\n");
			DPRINTF("\tThe First Name is: %s \n", p_student->FirstName);
			DPRINTF("\tThe Last Name is: %s \n", p_student->LastName);
			DPRINTF("\tThe ID is: %d \n", p_student->ID);
			DPRINTF("\tThe GPA is: %f \n", p_student->GPA);
			for (j = 0; j < 5; j++)
			{
				DPRINTF("\t The ID Of The %d Course is: %d \n", j+1, (p_student->CoursesRegistered[j]));
			}
			DPRINTF("================================\n");
			return 0;

		}
		p_student++;
	}
	DPRINTF("\n==============================\n");
	DPRINTF("This ID is Not Found \n");
	DPRINTF("================================\n");
	return 0;

}

int Delete_Student_by_ID (FIFO_Buf_t* fifo, SStudentInformation *p_student)
{
	int i, Student_ID;
	int flag = 0;
	p_student = fifo->tail;

	if (fifo->count == 0)
	{
		DPRINTF("\n=================================\n");
		DPRINTF("FIFO is Empty\n");
		DPRINTF("===================================\n");
		return 0;
	}

	SStudentInformation *pNext = (fifo->tail) + 1;

	DPRINTF("Enter ID of student that you want to delete : \n");
	scanf("%d", &Student_ID);

	for (i = 0; i < fifo->count; i++)
	{
		if (p_student->ID == Student_ID)
		{
			flag = 1;
			*p_student = *pNext;
			pNext++;
		}
		p_student++;
	}
	if (flag == 1)
	{
		DPRINTF("\n===========================\n");
		DPRINTF("Deletion has been ------> DONE");
		DPRINTF("\n===========================\n");
		fifo->count--;
		fifo->head--;
		return 0;
	}

	else
	{
		DPRINTF("This ID is Not Found in The Data base \n");
		return 0;
	}
}

int Update_Student (FIFO_Buf_t* fifo, SStudentInformation *p_student)
{
	int Student_ID;
	int i, choice, j, Course_ID;
	if (fifo->count == 0)
	{
		DPRINTF("\n=============================\n");
		DPRINTF("FIFO is Empty\n");
		DPRINTF("===============================\n");
		return 0;
	}
	DPRINTF("\n=============================\n");
	DPRINTF("Enter ID of Student you want to update: ");
	scanf("%d", &Student_ID);

	for (i = 0; i < fifo->count; i++)
	{
		if (p_student->ID == Student_ID)
		{
			DPRINTF("1. First Name \n");
			DPRINTF("2. Last Name \n");
			DPRINTF("3. ID \n");
			DPRINTF("4. GPA \n");
			DPRINTF("5. Courses \n");
			DPRINTF("Enter The Number of what you need to update: ");
			scanf("%d", &choice);

			switch (choice)
			{
			case 1:
			{
				DPRINTF("Enter The New First Name: ");
				scanf("%s", p_student->FirstName);
				break;
			}
			case 2:
			{
				DPRINTF("Enter The New Last Name: ");
				scanf("%s", p_student->LastName);
				break;
			}
			case 3:
			{
				DPRINTF("Enter The New ID: ");
				scanf("%d", &p_student->ID);
				break;
			}
			case 4:
			{
				DPRINTF("Enter The New GPA: ");
				scanf("%f", &p_student->GPA);
				break;
			}
			case 5:
			{
				DPRINTF("Enter the ID of the Course that you want to update: ");
				scanf("%d", &Course_ID);
				for (j = 0; j < 5; j++)
				{
					if (p_student->CoursesRegistered[j] == Course_ID)
					{
						DPRINTF("Enter The ID of New Course: ");
						scanf("%d", &(p_student->CoursesRegistered[j]));
					}
				}
				break;
			}
			default:
			{
				DPRINTF("Wrong choice \n");
			}

			}
			DPRINTF("\n===============================\n");
			return 0;

		}
		p_student++;
		if (p_student->ID != Student_ID)
		{
			DPRINTF("\n==================================\n");
			DPRINTF("This Course ID doesn't exist :(\n");
			DPRINTF("====================================\n");
		}
	}

	return 0;
}
