
#include "kernel.h"
void test()
{
	pkernel_t p = NULL;
	kernel_init(&p);
	int num =0;
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		kernel_add_tail(p,i);
	}
	display(p);
	for(num;num>1;num--)
	{
		if (num % 2 == 0)
		{
			kernel_del(p,num);
			kernel_add_tail(p,num);
		}
	}
	display(p);
}

int main()
{

	test();
	printf("\n");
	return 0;
}