#include"Queue.hpp"

Queue::Queue()
	:m_pFirst(nullptr)
	,m_Back(nullptr)
	,m_size(0)
{
}

Queue::~Queue()
{}

bool Queue::pushBack(int data)
{
	Node* pNew = new Node(data);
	if (isEmpty())
		m_pFirst = pNew;
	else
		m_Back->pNext = pNew;
	m_Back = pNew;
	m_size++;
	return true;
}

int Queue::getFront()
{
	if (isEmpty())
		//return 0;
	{
		throw 0;
	}
	return m_pFirst->data;
}

bool Queue::popFront()
{
	if (isEmpty())
		return false;
	Node* p = m_pFirst->pNext;
	delete m_pFirst;
	m_pFirst = p;
	if (p == nullptr)
		m_Back = nullptr;
	m_size--;
	return true;
}

bool Queue::clear()
{
	while (popFront());
	return true;
}

int  Queue::PrintQueue()
{
	Node* s = m_pFirst;
	for (int i = 0; i < m_size; i++)
	{
		cout << s->data <<" ";
		s = s->pNext;
	}
	cout << "\n" << endl;
	return 0;
}