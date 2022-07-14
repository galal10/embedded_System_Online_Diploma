/*
 * main.c
 *
 *  Created on: Jun 29, 2022
 *      Author: galal
 */


#include <stdio.h>
#include <string.h>


struct Distance
{
	int feet;
	float inch;
};


int main(void)
{
	struct Distance x,y,sum;
	printf("Enter information of 1st distance: \n");
	printf("\nEnter feet:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&x.feet);
	printf("Enter inch:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&x.inch);


	printf("Enter information of 2nd distance: \n");
	printf("\nEnter feet:");
	fflush(stdin); fflush(stdout);
	scanf("%d",&y.feet);
	printf("Enter inch:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&y.inch);

	sum.feet=x.feet+y.feet;
	sum.inch=x.inch+y.inch;

	if(sum.inch >12.0)
	{
		sum.inch-=12.0;
		++sum.feet;
	}

	printf("\nSum of distance=%d\'-%.1f\"",sum.feet,sum.inch);

	return 0;
}
