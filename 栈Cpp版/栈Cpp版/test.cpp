#include"stack.hpp"

int main()
{
	Stack<double> t1;
	t1.push(1.0);
	t1.push(2.0);
	t1.push(3.0);
	t1.pop();
	t1.push(4.0);
	t1.push(5.0);
	t1.PrintStack();
	return 0;
}