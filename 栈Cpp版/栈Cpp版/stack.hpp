#pragma once

#include<iostream>
using namespace std;
const int ARRAY_MAX = 10;

//À≥–Ú’ª
template <class T>
class Stack
{
public:
	Stack()
		:m_size(0)
		, m_data()
	{
	}

	~Stack()
	{
	}

	
	bool isFull()
	{
		return ARRAY_MAX == m_size;
	}

	
	bool isEmpty()
	{
		return m_size == 0;
	}

	
	T getTop()
	{
		if (isEmpty())
			return 0;
		return m_data[m_size - 1];
	}

	
	void clear()
	{
		m_size = 0;
	}

	
	 T PrintStack()
	{
		for (int i = 0; i < m_size; i++)
		{
			cout << m_data[i] << endl;
		}
		return 0;
	}

	//»Î’ª
	
	bool push(T data)
	{
		if (isFull())
			return false;

		m_data[m_size++] = data;
	}
	//≥ˆ’ª

	bool pop()
	{
		if (isEmpty())
			return false;
		m_size--;
		return true;
	}

protected:
	T m_data[ARRAY_MAX];
	int m_size;
};

//¡¥’ª

class ListStack
{
public:
	struct Node
	{
		int data;
		Node* pNext;
		Node(int v)
			:data(v),pNext(nullptr)
		{}
	};

	ListStack();
	~ListStack();

	bool isEmpty()
	{
		return m_pTop == nullptr;
	}

	Node* getTop()
	{
		
		return m_pTop;
	}

	void clear();


	//»Î’ª
	bool push(int data);
	//≥ˆ’ª
	bool pop();

protected:
	Node* m_pTop;
	int m_size;
};