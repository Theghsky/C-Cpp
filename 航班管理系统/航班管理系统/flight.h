#ifndef _FLIGHT_H
#define _FLIGHT_H

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#define M 18
#define D 12
#define T 8

enum Option
{
	quit,
	add,
	show,
    search,
    del
};

typedef struct flight {
    char number[M];    //航班号    
    char staddress[M];   //起点站    
    char arraddress[M];   //终点站    
    char DATE[D];       //班期    
    char TYPE[T];       //机型    
    int stime;          //起飞时间    
    int atime;          //到达时间    
    int value;           //票价
}flight;

typedef flight datatype;

typedef struct link {
	datatype data;
	struct link* prev;
	struct link* next;
}link_t,*plink_t;

//添加航班数据
void  Addflight(plink_t pf);
//打印航班
void  Printflight(plink_t pf);
//初始化
void link_init(plink_t* p);
//添加航班
void link_add_tail(plink_t p);
//打印航班信息
void display(plink_t p);
// 一个节点node插在p的前面
static void insert_forward(plink_t p, plink_t node);
//一个节点node插在p的后面
static void insert_behind(plink_t p, plink_t node);
//插入航班
void sortflight(plink_t p, plink_t newnode);
//查找航班
plink_t flightFind(plink_t p);
//剪切
static void cut_node(plink_t node);
//删除
void link_del(plink_t p);

#endif 