/*
 * main.c
 *
 *  Created on: Feb 4, 2022
 *      Author: galal
 */


#include "stdio.h"

int main(void)
{
	int a[10][10],b[10][10];
	int r,c,i,j;
	printf("Enter row and column of matrix: ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&r,&c);

	printf("Enter elements of matrix\n");

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter elements a%d %d: ",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%d",&a[i][j]);
		}
	}

	printf("Entered matrix:\n");

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			b[j][i]=a[i][j];
		}
	}

	printf("transpose of matrix:\n");

	for(i=0;i<c;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
