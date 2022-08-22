#ifndef __STACK_H
#define __STACK_H


#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N 8

/*  顺序栈  */

typedef int datatype;

typedef struct stack {
	datatype data[N];
	int top;
} stack_t, * pstack_t;

extern pstack_t stack_init(void);
extern int push(pstack_t p, datatype d);
extern int pop(pstack_t p, datatype* d);
extern void display(pstack_t p);
#endif
