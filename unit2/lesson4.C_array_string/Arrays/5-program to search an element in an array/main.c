/*
 * main.c
 *
 *  Created on: Feb 14, 2022
 *      Author: galal
 */

#include "stdio.h"

int main(void)
{
	int arr[10] , num , element;

	printf("Enter no of elements : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	int i;
	for(i=0; i<num; i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("Enter the elements to be searched : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&element);
	i = 0;
	while(i<num && element != arr[i])
	{
		i++;
	}

	if(i<num)
		printf("Number found at the location = %d", i+1);
	else
		printf("not found");
	return 0;
}
