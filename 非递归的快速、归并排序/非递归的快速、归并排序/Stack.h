#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
typedef int STDataType;

//#define MAX 10000
//struct Stack
//{
//	STDataType a[MAX];
//	int top;
//};

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);
// »Î’ª
void StackPush(ST* ps, STDataType x);
// ≥ˆ’ª
void StackPop(ST* ps);
STDataType StackTop(ST* ps);

int StackSize(ST* ps);
bool StackEmpty(ST* ps);