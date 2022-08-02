/*
 * main.c
 *
 *  Created on: Jul 24, 2022
 *      Author: galal
 */


#include <stdio.h>


int main(void)
{
	int arr[15],size;
	int *ptr;

	printf("Input the number of elements to store in the array : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&size);

	int i;
	ptr=&arr[0];

	printf("Input %d number of elements in the array\n",size);
	for(i=0;i<size;i++)
	{
		printf("element -%d : ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",ptr);
		ptr++;
	}

	ptr = &arr[size-1];

	printf("\nThe elements of array in reverse order are :\n");
	for(i=size-1;i>=0;i--)
	{
		printf("%d\t",*ptr);
		ptr--;
	}
	return 0;
}
