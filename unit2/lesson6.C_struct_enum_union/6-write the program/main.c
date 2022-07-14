/*
 * main.c
 *
 *  Created on: Jun 29, 2022
 *      Author: galal
 */


#include <stdio.h>



union job
{
	char name[32];
	float salary;
	int worker_no;
}u;
struct job1
{
	char name[32];
	float salary;
	int worker_no;
}s;

int main(void)
{
	printf("size of union=%d",sizeof(u));
	printf("\nsize of structure=%d",sizeof(s));
	return 0;
}
