#ifndef __STACK_H
#define __STACK_H

#include <stdio.h>


typedef int datatype;

typedef struct link{
	datatype data;
	struct link *next;
} link_t,*plink_t;


extern int push(plink_t *p,datatype d);
extern int pop(plink_t *p,datatype *d);
extern void display(plink_t p);

#endif
