/*
 * main.c
 *
 *  Created on: Feb 15, 2022
 *      Author: galal
 */

#include "stdio.h"

int fact(int n);

int main(void)
{
	int num;
	printf("Enter a positive integer: ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&num);
	printf("Factorial of %d = %d",num,fact(num));
	return 0;
}

int fact(int n)
{
	if(n<=1)
		return 1;
	else
		return n*fact(n-1);

}
