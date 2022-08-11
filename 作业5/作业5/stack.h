#ifndef __STACK_H
#define __STACK_H


#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//#define N 8
//
///*  À≥–Ú’ª  */
//
//typedef int datatype;
//
//typedef struct stack {
//	datatype data[N];
//	int top;
//} stack_t, * pstack_t;
//
//extern pstack_t stack_init(void);
//extern int push(pstack_t p, datatype d);
//extern int pop(pstack_t p, datatype* d);
//extern void display(pstack_t p);


typedef int datatype;

typedef struct link {
	datatype data;
	struct link* next;
} link_t, * plink_t;


extern int push(plink_t* p, datatype d);
extern int pop(plink_t* p, datatype* d);
extern void display(plink_t p);



#endif