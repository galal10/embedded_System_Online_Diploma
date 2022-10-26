/*
 * linked_lish.c
 *
 *  Created on: Oct 23, 2022
 *      Author: galal
 */

#include "linked_list.h"


struct SStudent* gpFirstStudent = NULL;


void fill_the_record(struct SStudent* newStudent)
{
	char text[40];

	DPRINTF("\nEnter your id: ");
	gets(text);
	newStudent->student.ID = atoi(text);

	DPRINTF("Enter your name: ");
	gets(newStudent->student.name);

	DPRINTF("Enter your length: ");
	gets(text);
	newStudent->student.height = atof(text);

}

void Add_student()
{
	struct SStudent* pNewStudent;
	struct SStudent* pLastStudent;

	// if linked list is empty
	if(gpFirstStudent == NULL)
	{
		pNewStudent =(struct SStudent*) malloc(1*sizeof(struct SStudent));
		gpFirstStudent = pNewStudent;
	}
	else
	{
		pLastStudent = gpFirstStudent;
		while(pLastStudent->PNextStudent)
		{
			pLastStudent = pLastStudent->PNextStudent;
		}
		pNewStudent =(struct SStudent*) malloc(1*sizeof(struct SStudent));
		pLastStudent->PNextStudent = pNewStudent;
	}
	fill_the_record(pNewStudent);
	pNewStudent->PNextStudent = NULL;
}

int delete_student()
{
	char text[20];
	unsigned selected_id;
	DPRINTF("Enter the ID: ");
	gets(text);
	selected_id = atoi(text);

	//checks if it's not empty
	if(gpFirstStudent)
	{
		struct SStudent* pSelectedStusent = gpFirstStudent;
		struct SStudent* pPreviousStudent = NULL;

		while(pSelectedStusent)
		{
			if(pSelectedStusent->student.ID == selected_id)
			{
				// checks if it the first element or not
				if(pPreviousStudent) // it's not the first
				{
					pPreviousStudent->PNextStudent = pSelectedStusent->PNextStudent;
				}
				else // the first one
				{
					gpFirstStudent = pSelectedStusent->PNextStudent;
				}
				free(pSelectedStusent);
				return 1;
			}
			pPreviousStudent = pSelectedStusent;
			pSelectedStusent = pSelectedStusent->PNextStudent;
		}
	}

	DPRINTF("can't find this ID\n");
	return 0;
}

void view_students()
{
	struct SStudent* pCurrentStudent = gpFirstStudent;
	int count = 0;
	if(gpFirstStudent == NULL)
	{
		DPRINTF("Empty list\n");
	}

	while(pCurrentStudent)
	{
		DPRINTF("\n Record Number %d",count+1);
		DPRINTF("\n \t ID : %d",pCurrentStudent->student.ID);
		DPRINTF("\n \t Name : %s",pCurrentStudent->student.name);
		DPRINTF("\n \t height : %.2f\n",pCurrentStudent->student.height);
		pCurrentStudent = pCurrentStudent->PNextStudent;

		count++;
	}
}

void delete_all()
{
	struct SStudent* pCurrentStudent = gpFirstStudent;

	if(gpFirstStudent == NULL)
	{
		DPRINTF("Empty list\n");
	}

	while(pCurrentStudent)
	{
		struct SStudent* pTemp = pCurrentStudent;
		pCurrentStudent = pCurrentStudent->PNextStudent;
		free(pTemp);
	}

	gpFirstStudent = NULL;
}
