/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: galal
 */
#include "stdio.h"

int main(void)
{
	int n , i , sum =0;
	printf("Enter an integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);

	for(i=1 ; i<=n ; i++)
	{
		sum+=i;
	}
	printf("Sum = %d",sum);

	return 0;

}

