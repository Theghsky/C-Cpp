#define  _CRT_SECURE_NO_WARNINGS

//题目：有5个人坐在一起，问第五个人多少岁？
//他说比第4个人大2岁。问第4个人岁数，他说比第3个人大2岁。
//问第三个人，又说比第2人大两岁。问第2个人，说比第一个人大两岁。
//最后问第一个人，他说是10岁。
//请问第五个人多大？

//#include<stdio.h>
//int fn(int age,int n)
//{
//	if (n != 1)
//		age = fn(age, n - 1)+2;
//	return age;
//}
//int main()
//{
//	int n = 5;
//	int age = 10;
//	printf("%d\n",fn(age,n));
//	return 0;
//}

//题目：给一个不多于5位的正整数，要求：一、求它是几位数，二、逆序打印出各位数字。

//#include <stdio.h>
//
//int main(void)
//{
//	int i, n, x, k;
//	int arr1[5] = { 0 };
//	int arr2[5] = { 1,10,100,1000,10000 };
//	scanf("%d", &i);
//	for (int j = 10000; j >= 1; j /= 10)
//	{
//		if (0 < i/j)
//		{
//			for (k = 0; k < 5; k++)
//			{
//				if (j == arr2[k])
//					break;
//			}
//			for (n = 0; n <= k; ++n)
//			{
//				x = i % 10;
//				arr1[n] = x;
//				i = i / 10;
//			}
//			for (int y=0; y < n;y++)
//				printf("%d ", arr1[y]);
//		}
//	}
//	printf("他是%d位数\n",n);
//	return 0;
//}




//5、分析以下代码的输出结果并解释原因。

//#include<stdio.h>
//
//char* get_memory(void);
//char* get_memory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//int main(void)
//{
//	char* str = NULL;
//	str = get_memory();
//	printf("%s\n", str);
//	return 0;
//}

#include <stdio.h>
extern void other(void);
int main()
{
    extern int a;
    int b = 0;
    static int c;
    a += 3;
    other();
    b += 3;
    other();
    return 0;
}

void other(void)
{
    int b = 3;
    static int c = 2;
    a += 5;
    b += 5;
    c += 5;
    printf("%d, %d, %d\n", a, b, c);
    c = b;
}