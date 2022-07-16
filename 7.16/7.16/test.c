//题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
//1.程序分析：在10万以内判断，先将该数加上100后再开方，再将该数加上268后再开方，如果开方后的结果满足如下条件，即是结果。请看具体分析：
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	long int i;
	double x, y;
	for (i = 0; i <= 100000; ++i)
	{
		x = sqrt(i + 100);
		y = sqrt(i + 268);
		if ((x * x == i + 100) && (y * y == i + 268))
			printf("%ld\n", i);
	}
	return 0;
}

//题目：输入某年某月某日，判断这一天是这一年的第几天？
//1.程序分析：以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，
//   特殊情况，闰年且输入月份大于3时需考虑多加一天。

int main()
{
	int year, mouth, day;
	int i, count;
	scanf("%d %d %d", &year, &mouth, &day);
	int arr[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (i=0,count = 0; count < mouth; ++count)
	{
		i += arr[count];
	}
	if ((year % 400 == 0 || year % 4 == 0 && year % 100 == 0) && mouth > 3)
		i= i + day + 1;
	printf("%d\n", i);
	return 0;
}