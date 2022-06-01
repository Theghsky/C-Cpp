#include"Queue.hpp"

int main()
{
	Queue t;
	t.pushBack(1);
	t.pushBack(2);
	t.pushBack(3);
	t.pushBack(4);
	t.pushBack(5);
	t.pushBack(6);
	t.PrintQueue();
	t.popFront();

	t.PrintQueue();

	return 0;
}