
#include "stack.h"

void test1();
void test2();
//2、用顺序栈实现整数的逆序输出。例如输入整数1，2，3，输出3，2，1.
void test1()
{
	pstack_t p = stack_init();
	printf("p: %p\n", p);

	//正数则入栈，负数就出栈 
	datatype d;
	int ret;
	while (1)
	{
		ret = scanf("%d", &d);
		if (!ret)
			break;
		push(p, d);
		display(p);
	}

	while (!pop(p, &d))
	{
		printf("%d", d);
	}
	printf("\n");
}

//3、用顺序栈、链栈实现十进制向八进制转换。例如输入123，输出0173.
void test2()
{
	pstack_t p = stack_init();
	printf("p: %p\n", p);

	int num ;
	scanf("%d", &num);

	while (num!=0)
	{
		push(p, num%8);
		num /=8;
	}
	display(p);

	printf("0");
	while (!pop(p, &num))
	{
		printf("%d", num);
	}
	printf("\n");
}

int main(void)
{

	//test1();
	test2();

	return 0;
}
