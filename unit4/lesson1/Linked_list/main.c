/*
 * main.c
 *
 *  Created on: Oct 23, 2022
 *      Author: galal
 */


#include "linked_list.h"


extern struct SStudent* gpFirstStudent;

int main(void)
{
	char text[20];

	while(1)
	{
		DPRINTF("===========================================\n");
		DPRINTF("SELECT YOUR OPTION\n");
		DPRINTF("1:Add Student\n");
		DPRINTF("2:Delete Student\n");
		DPRINTF("3:View All Student\n");
		DPRINTF("4:Delete All Student\n");
		DPRINTF("5:GetNth_data \n");
		DPRINTF("6:Length_Iterative \n");
		DPRINTF("7:Length_Recursive \n");
		DPRINTF("8: Nth_End \n");
		DPRINTF("Enter option number: \n");

		gets(text);
		DPRINTF("===========================================\n");

		switch(atoi(text))
		{
		case 1:
			Add_student();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_students();
			break;
		case 4:
			delete_all();
			break;
		case 5:
			GetNth_data();
			break;
		case 6:
			iterative_length();
			break;
		case 7:
			DPRINTF("length = %d ", recursive_length(gpFirstStudent));
			break;
		case 8:
			Nth_End();
			break;
		default:
			DPRINTF("\t wrong option\n");
			break;
		}
	}
	return 0;
}

