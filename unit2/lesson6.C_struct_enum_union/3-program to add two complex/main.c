/*
 * main.c
 *
 *  Created on: Jun 29, 2022
 *      Author: galal
 */


#include <stdio.h>


struct Complex
{
	float real;
	float img;
};


void add_complex(struct Complex ,struct Complex);

int main(void)
{
	struct Complex n1,n2;
	printf("for 1st complex number\n");
	printf("Enter real and imaginary : ");
	fflush(stdin); fflush(stdout);
	scanf("%f%f",&n1.real,&n1.img);

	printf("\nfor 2nd complex number\n");
	printf("Enter real and imaginary : ");
	fflush(stdin); fflush(stdout);
	scanf("%f%f",&n2.real,&n2.img);

	add_complex(n1,n2);
	return 0;
}

void add_complex(struct Complex num1,struct Complex num2)
{
	struct Complex sum;
	sum.real=num1.real+num2.real;
	sum.img=num1.img+num2.img;

	printf("Sum=%.1f+%.1fj",sum.real,sum.img);
}
