#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>

//int prime_num(int j)
//{
//	int n;
//	for (n = 2; n < j; n++)
//	{
//		if (j % n == 0)
//			return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	int i=0;
//	scanf("%d",&i);
//	if (1 == prime_num(i))
//		printf("%d 这个数不是素数\n", i);
//	else
//	printf("%d 这个数是素数\n",i);
//	return 0;
//}

//int leap_year(int i)
//{
//	if ((i % 4 == 0 && i % 100 == 0) || (i % 400 == 0))
//		return 1;
//	return 0;
//}
//
//int main()
//{
//	int year;
//	scanf("%d",&year);
//	if (1 == leap_year(year))
//		printf("%d 这一年是闰年\n", year);
//	else 
//		printf("%d 这一年是闰年\n", year);
//	return 0;
//}

//int dic_num(int a[],int i,int s)
//{
//	int Lift=0;
//	int Right= s-1;
//	while (Lift <= Right)
//	{
//		int mid = (Lift + Right) / 2;
//		if (a[mid] > i)
//		{
//			Right = mid - 1;
//		}
//		else if (a[mid] < i)
//		{
//			Lift = mid + 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int num[] = { 1, 2, 3, 4, 5, 6 ,7 ,8 ,9, 10 };
//	int key;
//	scanf("%d",&key);
//	int sz = sizeof(num) / sizeof(num[0]);
//	int ret = dic_num(num, key, sz);
//	if (-1 == ret)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，这个数的下标是 %d \n", ret);
//	}
//	return 0;
//}

//void add(int* i)
//{
//	(*i)++;
//}
//
//int main()
//{
//	int num = 0;
//	add(&num);
//	printf("%d",num);
//	add(&num);
//	printf("%d", num);
//	add(&num);
//	printf("%d", num);
//	add(&num);
//	printf("%d", num);
//	add(&num);
//	printf("%d", num);
//	return 0;
//}
//
//void new_line()
//{
//	printf("hehe\n");
//}
//
//void three_line()
//{
//	int i = 0;
//	for (i; i < 3; i++)
//	{
//		new_line();
//	}
//}
//
//int main()
//{
//	three_line();
//	return 0;
//}
//
//int main()
//{
//	char arr[20] = "hello";
//	int ret = strlen(strcat(arr, "bit"));
//	printf("%d\n",ret);
//	return 0;
//}

int main()
{
	printf("%d", printf("%d", printf("%d", 43)));
	return 0;
}