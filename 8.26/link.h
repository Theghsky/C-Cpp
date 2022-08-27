#ifndef __LINK_H
#define __LINK_H

#include <stdio.h>

typedef int datatype;

typedef struct link{
	datatype data;
	struct link *prev;
	struct link *next;
} link_t,*plink_t;

//      int a,b;   ---> int a;int b;
//		int a,*b;  ---> int a;int *b;
//      typedef int a;  
//		typedef int a,b;  ---> typedef int a; typedef int b;
//		typedef int a,*b; ---> typedef int a; typedef int *b;
//      typedef struct link a,*b;  ---> typedef struct link a; 
//										typedef struct link *b;

extern void link_init(plink_t *p);
extern void link_add_head(plink_t p,datatype d);
extern void link_add_tail(plink_t p,datatype d);
extern void link_del(plink_t p,datatype d);
extern void link_update(plink_t p,datatype old,datatype new);
extern void display(plink_t p);
extern void pre_display(plink_t p);

#endif