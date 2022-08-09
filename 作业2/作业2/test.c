#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float my_power(float a, int b)
{
	float num1 = 1.0;
	float num2 = 1.0;

	if (b > 0)
	{
		for (int i = 0; i < b; i++)
		{
			num1 *= a;

		}
		return num1;
	}
	if (b == 0)
		return 0;
	if (b < 0)
	{
		for (int i = 0; i < -b; i++)
		{
			num2 *= (float)1.0 / a;

		}

		return num2;
	}

}

int main()
{
	int x;
	float N, sum;

	scanf("%f %d", &N, &x);

	sum = my_power(N, x);

	printf("%.6f\n", sum);


	return 0;
}
