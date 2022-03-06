#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//4.使用 free 释放动态开辟内存的一部分
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
////		return 0;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*p++ = i;
//	}
//	//回收空间
//
//	free(p);
//	p = NULL;
//	return 0;
//}



//5.对同一块动态内存的多次释放
//int main()
//{
//	int* p = (int*)malloc(40);
//	if (p == NULL)
//	{
//		return 0;
//	}
//	使用
//	释放
//	free(p);
//	p = NULL;//加这个可避免
//	free(p);
//	return 0;
//}


//6.动态开辟空间内存忘记释放(内存泄露)
//int main()
//{
//	while (1)
//	{
//		malloc(1);
//	}
//	return 0;
//}


//笔试题
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}

//改正 1
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

//改正 2
//char* GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//	return p;
//}
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}

// 返回栈空间地址的问题
//char* GetMemory(void)
//{
//	char p[] = "hello world";//局部变量  在  栈上
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//改 1
//char* GetMemory(void)
//{
//	// static 使局部变量的生命周期变长出函数后 p 数组不销毁
//	// 相当于将 p 从栈上放到 静态区
//	static char p[] = "hello world";//局部变量  在  栈上
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//动态内存泄露
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	//忘记释放动态开辟的内存，导致内存泄露
//}
//
//int main()
//{
//	Test();
//	return 0;
//}

//改 1
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}



//void Test(void)
//{
//	char* str = (char*)malloc(10);
//	strcpy(str, "hello");
//	free(str);   // free 释放 str 指向的空间后，并不会把 str 置为 NULL
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//	return 0;
//}
//
////改 1
//void Test(void)
//{
//	char* str = (char*)malloc(10);
//	strcpy(str, "hello");
//	free(str);   // free 释放 str 指向的空间后，并不会把 str 置为 NULL
//
//	str = NULL;
//
//	if (str != NULL)
//	{
//		strcpy(str, "world");
//		printf(str);
//	}
//	return 0;
//}