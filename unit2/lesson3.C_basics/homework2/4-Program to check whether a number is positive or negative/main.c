/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: galal
 */
#include "stdio.h"

int main(void)
{
	float num;
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&num);

	if(num > 0)
		printf("%.2f is a positive",num);
	else if(num < 0)
		printf("%.2f is a negative",num);
	else
		printf("you entered zero");
	return 0;
}
