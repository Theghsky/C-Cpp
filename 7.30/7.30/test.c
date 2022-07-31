#include<stdio.h>
int main()
{
	int x;
	for (x = 2; x <= 1000; ++x)
	{
		int sum = 0;
		for (int i = 1; i <= x - 1; ++i)
		{
			if (x % i == 0)
				sum += i;
		}
		if (sum == x)
			printf("%d ", x);
	}
	return 0;
}