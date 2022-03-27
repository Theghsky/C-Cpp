#pragma once

//#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

//前置声明
struct BinaryTreeNode;

typedef struct BinaryTreeNode* QDataType;

typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

//初始化
void QueueInit(Queue* pq);
//销毁
void QueueDestory(Queue* pq);
//队尾入
void QueuePush(Queue* pq, QDataType x);
//队头出
void QueuePop(Queue* pq);
//取头值
QDataType QueueFront(Queue* pq);
//取尾值
QDataType QueueBack(Queue* pq);
//队大小
int QueueSize(Queue* pq);
//判断是否为空
bool QueueEmpty(Queue* pq);