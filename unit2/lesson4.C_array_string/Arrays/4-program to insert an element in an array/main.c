/*
 * main.c
 *
 *  Created on: Feb 4, 2022
 *      Author: galal
 */


#include "stdio.h"

int main(void)
{
	int arr[10],num,element,location;

	printf("Enter no of elements : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	int i;
	for(i=0; i<num; i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("Enter the element to be inserted : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&element);

	printf("Enter the location : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&location);

	for(i=num; i>=location; i--)
	{
		arr[i]=arr[i-1];
	}

	num++;
	arr[location-1]=element;

	for(i=0; i<num; i++)
	{
		printf("%d",arr[i]);
	}
	return 0;
}
