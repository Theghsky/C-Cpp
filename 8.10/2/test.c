#include "stack.h"


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

	test3();
	return 0;
}
