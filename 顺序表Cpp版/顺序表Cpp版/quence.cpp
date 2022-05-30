#include"quence.h"




Quence::Quence()
	:m_data()
	, m_count(0)
{

}

Quence::~Quence()
{
}

bool Quence::insertData(int data, int index)
{
	if (m_count == ARRAY_MAX)
		return false;
	if (index < m_count)
	{
		//
		for (int i = m_count; index<i; --i)
		{
			m_data[i] = m_data[i - 1];
		}
		m_data[index] = data;
		m_count++;
	}
	else
	{
		//最后一个
		m_data[m_count++] = data;
	}
	return true;
}

bool Quence::remove(int index)
{
	if (index < 0 || m_count == 0)
		return false;
	if (index < m_count-1)
	{
		for (int i = index; i < m_count; i++)
		{
			m_data[i] = m_data[i + 1];
		}
		m_count--;
	}
	else
	{
		m_data[m_count--] = 0;
	}
}

void Quence::PrintData()
{
	for (auto i : m_data)
	{
		cout << i << endl;
	}
	return;
}