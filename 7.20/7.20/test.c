#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//14、编写一个函数Fibonacci()，要求程序输出第n项斐波那契数，n由用户输入。
//斐波那契数列：1, 1, 2, 3, 5, 8, 13, 21, … …

//int Fibonacci(int n)
//{
//	if (n == 1 || n == 2)
//		return 1;
//	else
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	printf("%d\n", Fibonacci(n));
//	return 0;
//}

//15、编写一个函数，输入一个十进制数，输出对应的十六进制数。（不能用printf的 % x格式说明符）



//2、编写一个函数，返回一个double型数组中最大和最小值的差值，并在一个简单的程序中测试这个函数。
//double cha(double arr[],int i)
//{
//	double max, min;
//	max = arr[0];
//	min = arr[0];
//	for (i = 0; i < 5; i++)
//	{
//		if (max <= arr[i])
//		{
//			min = max;
//			max = arr[i];
//		}
//	}
//	double cha;
//	cha = max - min;
//	return cha;
//}
//int main()
//{
//	double arr[5]={0};
//	int i;
//	for (i = 0; i < 5; i++)
//	{
//		scanf("%lf",&arr[i]);
//	}
//	printf("%lf\n", cha(arr,i));
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d\n",sizeof(&arr));
//	return 0;
//}