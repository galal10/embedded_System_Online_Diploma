/*
 * main.c
 *
 *  Created on: Jun 29, 2022
 *      Author: galal
 */


#include <stdio.h>
#include <string.h>

struct Student
{
	char name[50];
	int roll;
	float marks;
};


int main(void)
{
	struct Student student[10];
	int i;
	printf("Enter information of students:\n");
	for(i=0;i<10;i++)
	{
		student[i].roll=i+1;
		printf("\nfor number %d\n",student[i].roll);
		printf("Enter name:");
		fflush(stdin); fflush(stdout);
		gets(student[i].name);
		printf("\nEnter marks:");
		fflush(stdin); fflush(stdout);
		scanf("%f",&student[i].marks);
		printf("\n");
	}
	printf("Displaying information of students:\n\n");
	for(i=0;i<10;i++)
	{
		printf("\ninformation for roll number %d:\n",i+1);
		printf("name:%s",student[i].name);
		printf("marks:%.1f",student[i].marks);
	}
	return 0;
}
