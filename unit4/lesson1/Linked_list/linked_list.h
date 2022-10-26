/*
 * linked_list.h
 *
 *  Created on: Oct 23, 2022
 *      Author: galal
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define DPRINTF(...) 	{fflush(stdin); \
						 fflush(stdout); \
						 printf(__VA_ARGS__); \
						 fflush(stdin); \
						 fflush(stdout);}


struct Sdata
{
	int ID;
	char name[40];
	float height;
};

struct SStudent
{
	struct Sdata student;
	struct SStudent* PNextStudent;
};

void Add_student();
void fill_the_record(struct SStudent* newStudent);
int delete_student();
void view_students();
void delete_all();
#endif /* LINKED_LIST_H_ */
