#include"quence.h"

int main()
{
	Quence t;
	t.insertData(1, 0);
	t.insertData(2, 1);
	t.insertData(3, 2);
	t.insertData(4, 2);

	t.remove(2);
	t.remove(0);

	t.PrintData();

	return 0;
}