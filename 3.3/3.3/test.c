#define  _CRT_SECURE_NO_WARNINGS

//struct S
//{
//	char name[20];
//	int age;
//};
//
//int main()
//{
//
//	struct S arr[50];//50个struct S 的数据类型  （浪费）
//
//}

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

//malloc 与 free 成对使用

//int main()
//{
//	//申请10个整形的空间
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (p == NULL)
//	{
//		//打印打错原因
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		//正常使用空间
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//当动态申请空间不在使用的时候
//	//就应该还给操作系统
//	free(p);
//	p = NULL;//空间还给操作系统，但是指针p还是存着地址，因此要赋值空指针
//	return 0;
//}



//int main()
//{
//	//malloc(10*sizeof(int))
//	int* p = (int*)calloc(10, sizeof(int));  //calloc 对内存有个初始化而 malloc 没有 因此 前者效率略低于 后者
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//	//释放空间
//	//free函数是用来释放动态开辟的空间的
//	free(p);
//	p = NULL;
//	return 0;
//}


//int main()
//{
//	int* p = (int*)malloc(20);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			*(p + i) = i;
//		}
//	}
/*	就是在使用 malloc 开辟的20个字节空间
	假设这里，20个字节不能满足我们大的使用
	希望我们能够有40个字节的空间
	这里就可以使用 realloc 来调整动态开辟的空间

	realloc 使用注意事项;
	1.如果 p 指向的空间之后有足够的内存空间可以追加，则直接追加，后返回 p
	2.如果 p 指向的空间之后 没有 足够的内存空间可以追加，则 realloc 函数会重新找一个新的内存区域
		开辟一块满足需求的空间，并把原来内存中的数据拷贝回来，释放旧的内存空间
		最后返回新开辟的内存空间地址*/
	//3.要用一个新的变量来接收 realloc 函数的返回值
//	int* prt = realloc(p, 40);
//
//	if (prt != NULL)
//	{
//		p = prt;
//		int i = 0;
//		for (i = 5; i < 10; i++)
//		{
//			*(p + i) = i;
//		}
//
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d ", *(p + i));
//		}
//	}
//
//	//释放空间
//	free(p);
//	p = NULL;
//
//	return 0;
//}


int main()
{
	//1.对空指针的解引用操作
	// 
	//int* p = (int*)malloc(40);
	////万一 malloc 失败，p就被赋值为NULL
	//*p = 0;//err

	//int i = 0;
	//for (i = 0; i < 10; i++)
	//{
	//	*(p + i) = i;
	//}

	//free(p);
	//p = NULL;

	//2.对动态开辟的内存的越界访问

	//int* p = (int*)malloc(5*sizeof(int));
	//if (p == NULL)
	//{
	//	return 0;
	//}
	//else
	//{
	//	int i = 0;
	//	for (i = 0; i < 10; i++)
	//	{
	//		*(p + i) = i;
	//	}
	//}

	//free(p);
	//p = NULL;

	//3.对非动态开辟的内存释放

	/*int a = 10;
	int* p = &a;
	*p = 20;
	free(p);
	p = NULL;

	return 0;*/
}