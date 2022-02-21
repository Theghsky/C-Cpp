#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//char* my_strcpy(char* dest,const char* src)
////函数指针  
////函数指针数组
//
//char* (*pf)(char*,const char*)=my_strcpy
//
//char* (*pff[4])(char*,const char*)=my_strcpy
//
//(   *  (void (*)()  0   )();
////0被强制类型转换为函数指针类型，0就是一个函数的地址，
////调用0地址处的该函数
//
//void（* signal(int, void(*)(int))）(int);
////signal是一个函数，该函数有两个变量，一个为int 类型，另一个为函数指针类型
////                                           该指针指向的函数的返回值为void，参数为int型
////signal函数的返回类型也为函数指针类型，该指针指向的函数的返回值为void，参数为int型
////简写：
//typedef void(*pfun_t)(int);
//pfun_t signal(int, pfen_t);
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	int (*pa)(int, int) = Add;
//	printf("%d\n", pa(2, 3));
//	printf("%d\n", (*pa)(2, 3));
//	//*号不做解释，有*号方便理解
//	return 0;
//}

//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int* arr[5];
//	int (*pa)(int, int) = Add;//函数指针
//	int (*paa[4])(int, int) = { Add,Sub,Mul,Div };//函数指针数组
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", paa[i](2, 3));
//	}
//	return 0;
//}

//计算器
//用函数指针数组来实现
//
//void menu()
//{
//	printf("*************************\n");
//	printf("  1:add            2:sub \n");
//	printf("  3:mul            4:div \n");
//	printf("******    0:exit  *******\n");
//}
//int main()
//{
//	int x , y ;
//	int input = 1;
//	int ret = 0;
//	int(*pa[5])(int x, int y) = { 0,Add,Sub,Mul,Div };
//	while (input)
//	{
//		menu();
//		printf("请选择：");
//		scanf("%d", &input);
//		if ((input >= 1 && input <= 4))
//		{
//			printf("输入操作数:");
//			scanf("%d %d", &x, &y);
//			ret = (*pa[input])(x, y);
//			printf("ret=%d\n", ret);
//		}
//		else if (input == 0)
//			{
//			printf("退出");
//			}
//			else
//			{
//				printf("输入有误");
//			}
//	}
//	return 0;
//}

void print(char* str)
{
	printf("hehe:%s",str);
}
void test(void (*p)(char*))
{
	printf("test\n");
	p("bit");
}
int main()
{
	test(print);
	return 0;
}