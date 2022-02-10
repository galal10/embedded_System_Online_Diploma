/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: galal
 */
#include "stdio.h"

int main(void)
{
	float a , b , x;
	printf("Enter value of a: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&b);
	x = b;
	b = a;
	a = x;
	printf("After swapping, value of a = %.2f\n",a);
	printf("After swapping, value of b = %.2f",b);
	return 0;
}

