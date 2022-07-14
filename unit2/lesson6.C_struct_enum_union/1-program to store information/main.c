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


struct Student read_data();
void displaying(struct Student);

int main(void)
{
	struct Student student;
	student=read_data();
	displaying(student);
	return 0;
}

struct Student read_data()
{
	struct Student x;
	printf("Enter information of students: \n");
	printf("\nEnter name:");
	fflush(stdin); fflush(stdout);
	gets(x.name);
	printf("Enter roll number:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x.roll);
	printf("Enter marks:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&x.marks);

	return x;
}

void displaying(struct Student x)
{
	printf("\nDisplaying information:\n");
	printf("\nname: %s",x.name);
	printf("\nRoll: %d",x.roll);
	printf("\nMarks: %.2f",x.marks);
}
