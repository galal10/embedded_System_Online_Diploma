/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: galal
 */
#include "stdio.h"

int main(void)
{
	int n , i , fact = 1;
	printf("Enter an integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);

	if(n > 0)
	{
		for(i=1 ; i<= n ; i++)
		{
			fact*=i;
		}
	}

	else if(n == 0)
	{
		fact = 1;
	}

	else
	{
		printf("Error!!! factorial of negative number dosen't exist");
		return 1;
	}

	printf("factorial = %d",fact);
	return 0;
}
