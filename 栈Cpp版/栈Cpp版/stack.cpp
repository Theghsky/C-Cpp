#include"stack.hpp"


//À≥–Ú’ª
//Stack::Stack()
//	:m_size(0)
//	,m_data()
//{
//}
//
//Stack::~Stack()
//{
//}
//
//int Stack::PrintStack()
//{
//	for (int i = 0; i < m_size; i++)
//	{
//		cout << m_data[i] << endl;
//	}
//	return 0;
//}
//
//bool Stack::push(int data)
//{
//	if (isFull())
//		return false;
//
//	m_data[m_size++] = data;
//}
//
//bool Stack::pop()
//{
//	if (isEmpty())
//		return false;
//	m_size--;
//	return true;
//}

//¡¥’ª
ListStack::ListStack()
	:m_size(0)
	,m_pTop(nullptr)
{
}

ListStack::~ListStack()
{
}

bool ListStack::push(int data)
{
	Node* p = new Node(data);
	if (p)
	{
		if (isEmpty())
			m_pTop = p;
		else
		{
			p->pNext = m_pTop;
			m_pTop = p;
		}
		m_size++; 
		return true;
	}
	return false;
}

bool  ListStack::pop()
{
	if (isEmpty())
		return false;
	Node* p = m_pTop->pNext;
	delete m_pTop;
	m_pTop = p;
	m_size--;
	return true;
}