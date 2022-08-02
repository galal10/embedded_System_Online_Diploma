/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: galal
 */


#include <stdio.h>

struct employee
{
	char *name;
	int ID;
};


int main(void)
{
	struct employee emp1 = {"galal",1001},emp2={"Alex",1002},emp3={"ahmed",1003};

	struct employee (*arr[])={&emp1,&emp2,&emp3};
	struct employee (*(*pt)[3]) =&arr;

	printf("Exmployee Name : %s\n",(*(*pt+1))->name);
	printf("Employee ID : %d",(*(*pt+1))->ID);
	return 0;
}
