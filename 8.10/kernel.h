#ifndef __KERNEL_H
#define __KERNEL_H


#include "list.h"
#include <stdlib.h>
#include <stdio.h>



/*
	struct list_head{
			struct list_head *next,*prev;
	};
*/

typedef int datatype;

typedef struct kernel{
	datatype data;
	struct list_head list;
} kernel_t,*pkernel_t;


extern void kernel_init(pkernel_t *p);

extern void kernel_add_tail(pkernel_t p,datatype d);
extern void kernel_del(pkernel_t p,datatype d);

extern void display(pkernel_t p);

#endif