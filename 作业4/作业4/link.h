#ifndef __LINK_H
#define __LINK_H

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>


typedef int datatype;

typedef struct link {
	datatype data;			//Êı¾İÓò
	struct link* next;		//Ö¸ÕëÓò
} link_t;


link_t* link_init(void);

void display(link_t* p);

link_t* cut_behind(link_t* p);

void link_add_tail(link_t* p, datatype d);

static void insert_behind(link_t* p, link_t* node);


//typedef int datatype;
//
//typedef struct link {
//	datatype data;
//	struct link* prev;
//	struct link* next;
//} link_t, * plink_t;
//
//void link_init(plink_t* p);
//void link_add_head(plink_t p, datatype d);
//void link_add_tail(plink_t p, datatype d);
//void link_del(plink_t p, datatype d);
//void link_update(plink_t p, datatype old, datatype new);
//void display(plink_t p);
//void pre_display(plink_t p);
//plink_t ListFind(plink_t p, datatype d);


#endif









