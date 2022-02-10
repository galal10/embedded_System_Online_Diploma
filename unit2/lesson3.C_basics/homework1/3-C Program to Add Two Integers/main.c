/*
 * main.c
 *
 *  Created on: Feb 9, 2022
 *      Author: galal
 */
#include "stdio.h"

int main(void)
{
	int x , y;
	printf("enter two integers : ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&x,&y);
	printf("Sum : %d",x+y);
	return 0;
}

