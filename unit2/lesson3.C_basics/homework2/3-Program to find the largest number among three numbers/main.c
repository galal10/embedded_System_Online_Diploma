/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: galal
 */
#include "stdio.h"

int main(void)
{
	float x , y ,z;
	printf("Enter three numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f %f", &x , &y , &z);
	if(x>y)
	{
		if(x>z)
			printf("largest number = %f",x);
		else
			printf("largest number = %f",z);
	}
	else
	{
		if(y>z)
			printf("largest number = %f",y);
		else
			printf("largest number = %f",z);
	}
	return 0;
}

