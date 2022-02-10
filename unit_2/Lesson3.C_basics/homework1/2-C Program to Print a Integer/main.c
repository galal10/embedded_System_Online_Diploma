/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: galal
 */
#include "stdio.h"

int main(void)
{
	int integer;
	printf("Enter an integer : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&integer);
	printf("You entered: %d", integer);
	return 0;
}

