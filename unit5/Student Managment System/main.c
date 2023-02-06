/*
 * main.c
 *
 *  Created on: Feb 4, 2023
 *      Author: Galal
 */

#include "FIFO.h"


int main (void)
{
	FIFO_Buf_t student;
	int temp;
	SStudentInformation test;

	if (FIFO_init(&student, Student_Buffer, 15) == FIFO_no_error)
	{
		DPRINTF("==========================\n");
		DPRINTF("FIFO has been Initialized ------> DONE");
		DPRINTF("\n====================================");
	}

	DPRINTF("\nWelcome to the Student Management System \n");
	while (1)
	{
		DPRINTF("=======================================\n");
		DPRINTF("Choose the task that you want to perform\n");
		DPRINTF("\n1. Add a Student details manually: ");
		DPRINTF("\n2. View students information: ");
		DPRINTF("\n3. Dequeue a student: ");
		DPRINTF("\n4. to Count the students: ");
		DPRINTF("\n5. Find a student by ID: ");
		DPRINTF("\n6. Find a student by First Name: ");
		DPRINTF("\n7. Delete a student by ID: ");
		DPRINTF("\n8. Update a student information: ");
		DPRINTF("\n9. End the program: ");

		scanf("%d", &temp);

		switch (temp)
		{
		case 1:
		{
			if (FIFO_enqueue(&student,&test) == FIFO_no_error)
			{
				DPRINTF("==================================\n");
				DPRINTF("\t FIFO ENQUEUE ------> DONE ");
				DPRINTF("\n==================================\n");
			}

			else if (FIFO_enqueue(&student, Student_Buffer) == FIFO_full)
			{
				DPRINTF("\n=================================\n");
				DPRINTF("FIFO IS FULL\n");
				DPRINTF("===================================\n");
			}

			else
			{
				DPRINTF("\t FIFO ENQUEUE -------> FAILED \n");
			}

			break;
		}
		case 2:
		{
			FIFO_print(&student);
			break;
		}
		case 3:
		{
			if (FIFO_dequeue(&student, &test) == FIFO_no_error)
			{
				DPRINTF("\n=======Dequeue is done========\n");
			}
			break;
		}
		case 4:
		{
			DPRINTF("\n======================================\n");
			DPRINTF("Number of students is %d \n", Count_Of_Students(&student));
			DPRINTF("========================================\n");
			break;
		}
		case 5:
		{
			Find_Student_by_ID(&student, Student_Buffer);
			break;
		}
		case 6:
		{
			Find_Student_by_First_Name(&student, Student_Buffer);
			break;
		}
		case 7:
		{
			Delete_Student_by_ID(&student, Student_Buffer);
			break;
		}
		case 8:
		{
			Update_Student(&student, Student_Buffer);
			break;
		}
		case 9:
		{
			return 0;
		}

		} // switch

	} // while

	return 0;
}
