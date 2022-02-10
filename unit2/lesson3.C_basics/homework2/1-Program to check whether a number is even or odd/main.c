/*
 * main.c
 *
 *  Created on: Feb 10, 2022
 *      Author: galal
 */
#include "stdio.h"

int main(void)
{
	int num;
	printf("Enter an integer you want to check: ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&num);
	if(num % 2 ==0 )
		printf("%d is even",num);
	else
		printf("%d is odd", num);

	return 0;
}
