/*
 * main.c
 *
 *  Created on: Feb 4, 2022
 *      Author: galal
 */


#include "stdio.h"

int main(void)
{
	int n,i;
	float sum=0.0 ,num[100];
	printf("Enter the number of the data: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	while(n>100 || n<=0)
	{
		printf("Error this is an invalid range it should be from 0 to 100\n");
		printf("Enter the number again: ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&n);
	}
	for(i=0;i<n;i++)
	{
		printf("%d Enter number: ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%f",&num[i]);
		sum+=num[i];
	}
	printf("Average = %.2f",sum/n);
	return 0;
}
