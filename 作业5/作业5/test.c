#include "stack.h"

//2、用顺序栈实现整数的逆序输出。例如输入整数1，2，3，输出3，2，1.
//void test1()
//{
//	pstack_t p = stack_init();
//	if (p == NULL)
//		return -1;
//	printf("p: %p\n", p);
//
//	//正数则入栈，负数就出栈 
//	datatype d;
//	int ret;
//	while (1)
//	{
//		ret = scanf("%d", &d);
//		if (!ret)
//			break;
//		push(p, d);
//		display(p);
//	}
//
//	while (!pop(p, &d))
//	{
//		printf("%d", d);
//	}
//	printf("\n");
//}

//3、用顺序栈、链栈实现十进制向八进制转换。例如输入123，输出0173.
//void test2()
//{
//	pstack_t p = stack_init();
//	if (p == NULL)
//		return -1;
//	printf("p: %p\n", p);
//
//	int num ;
//	scanf("%d", &num);
//
//	while (num!=0)
//	{
//		push(p, num%8);
//		num /=8;
//	}
//	display(p);
//
//	printf("0");
//	while (!pop(p, &num))
//	{
//		printf("%d", num);
//	}
//	printf("\n");
//}


void test3()
{
	plink_t top = NULL;
	printf("p: %p\n", top);

	int num;
	scanf("%d", &num);

	while (num != 0)
	{
		push(&top, num % 8);
		num /= 8;
	}
	display(top);

	printf("0");
	while (!pop(&top, &num))
	{
		printf("%d", num);
	}
	printf("\n");
}

int main(void)
{

	//test1();
	//test2();
	test3();
	return 0;
}