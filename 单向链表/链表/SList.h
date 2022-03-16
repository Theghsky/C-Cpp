#pragma once

#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef int SLTDataType;
struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
};

typedef struct SListNode SLTNode;
//打印,不会改变头指针，传一级指针
void SListPrint(SLTNode* phead);

//可能会改变头指针，传二级指针
//尾插
void SListPushBack(SLTNode** pphead, SLTDataType x);
//头插
void SListPushFront(SLTNode** pphead, SLTDataType x);
//头删
void SListPopFront(SLTNode** pphead);
//尾删
void SListPopBack(SLTNode** pphead);


//查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//在pos的前面插入x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//删除pos位置的值
void SListErase(SLTNode** pphead, SLTNode* pos);

