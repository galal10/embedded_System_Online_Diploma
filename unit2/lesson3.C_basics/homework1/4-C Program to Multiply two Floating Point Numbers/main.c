/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: galal
 */
#include "stdio.h"

int main(void)
{
	float x , y;
	printf("Enter two numbers : ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&x,&y);
	printf("Product : %f",x*y);
	return 0;
}

