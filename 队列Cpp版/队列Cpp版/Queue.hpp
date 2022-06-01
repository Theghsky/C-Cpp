#pragma once

#include<iostream>
using namespace std;

class Queue
{
public:

	struct Node
	{
		int data;
		Node* pNext;
		Node(int v)
			:data(v)
			, pNext(nullptr)
		{}
	};

	Queue();
	~Queue();

	bool isEmpty()
	{
		return m_pFirst == nullptr;
	}

	//入队列
	bool pushBack(int data);
	//读取第一个
	int getFront();
	//出队列
	bool popFront();
	bool clear();

	int PrintQueue();

protected:
	Node* m_pFirst, * m_Back;
	int m_size;
};