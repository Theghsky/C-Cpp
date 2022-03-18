#pragma once

#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef int LTDataType;

//带头双向链表结构，任意位置插入删除数据都是0（1）
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;

//链表初始化
ListNode* ListInit();

//销毁
void ListDestory(ListNode* phead);
//打印
void ListPrint(ListNode* phead);
//尾插
void ListPushBack(ListNode* phead, LTDataType x);
//头插
void ListPushFront(ListNode* phead, LTDataType x);
//头删
void ListPopFront(ListNode* phead);
//尾删
void ListPopBack(ListNode* phead);
//查找
ListNode* ListFind(ListNode* phead, LTDataType x);
// pos 位置之气插入 x
void ListInsert(ListNode* pos, LTDataType x);
//删除 pos 位置的值
void ListErase(ListNode* pos);