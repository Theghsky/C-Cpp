#pragma once
#include <iostream>


using namespace std;
#define ARRAY_MAX 10

class Quence
{
public:
	Quence();
	~Quence();

	//²åÈë
	bool insertData(int data, int index);
	//É¾³ý
	bool remove(int index);

	void PrintData();
protected:
	int m_data[ARRAY_MAX];
	int m_count;

};