/*
 * main.c
 *
 *  Created on: Oct 23, 2022
 *      Author: galal
 */


#include "linked_list.h"



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
		default:
			DPRINTF("\t wrong option\n");
			break;
		}
	}
	return 0;
}

