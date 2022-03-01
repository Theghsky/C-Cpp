#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>

//void* my_memmove(void* dest, const void* str, size_t num)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(str != NULL);
//
//	if (dest<str || dest>(char*)str + num)
//	{
//		//前向后
//		while (num--)
//				{
//					*(char*)dest = *(char*)str;
//					++(char*)dest;
//					++(char*)str;
//				}
//	}
//	else
//	{
//		//后向前
//		while (num--)
//		{
//			*((char*)dest + num) = *((char*)str + num);
//		}
//	}

	//if (dest < str)
	//{
	//	//前向后
	//	while (num--)
	//	{
	//		*(char*)dest = *(char*)str;
	//		++(char*)dest;
	//		++(char*)str;
	//	}
	//}
	//else
	//{
	//	//后向前
	//	while (num--)
	//	{
	//		*((char*)dest + num) = *((char*)str + num);
	//	}
	//}
//	return ret;
//}
//
//int main()
//{
//	int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr3 + 2, arr3, 20);
//
//	return 0;
//}


//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,5,4,3 };
//	int ret=memcmp(arr1, arr2, 9);
//	printf("%d\n", ret);
//	return 0;
//}


//int main()
//{
//	int arr[10] = { 0 };
//	memset(arr, 1, 10);
//	return 0;
//}


////声明一个结构体变量
//声明一个学生类型，是想通过学生类型来创学生变量（对象）
//描述学生：属性--名字+电话+性别
//struct Stu
//{
//	char name[20];
//	char rele[12];
//	char sex[10];
//	int age;
//};
//
//int main()
//{
//	//创建结构体变量
//	struct Stu s1;
//	struct Stu s2;
//	return 0;
//}

//匿名结构体变量
//struct
//{
//	int a;
//	char c;
//}sa;
//
//int main()
//{
//	return 0;
//}
//


//结构体的自引用
//struct Node
//{
//	int data;
//	struct Node* next;
//};
//
//int main()
//{
//	return 0;
//}


//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node;
//
//int main()
//{
//	struct Node n1;
//	Node n2;
//	return 0;
//}


//struct T
//{
//	double a;
//	int b;
//};
//
//struct S
//{
//	char c;
//	struct T st;
//	int a;
//	double d;
//	char arr[20];
//};
//
//int main()
//{
//	//struct S s = { 'c',100,3.14,"hellow bit" };
//	struct S s = { 'c',{55.6,30},100,3.14,"hellow bit" };
//	printf("%c %d %lf %s\n", s.c, s.a, s.d, s.arr);
//	printf("%lf\n", s.st.a);
//}


//struct S1
//{
//	char c1;
//	int a;  
//	char c2;
//};
//
//struct S2
//{
//	char c1;
//	char c2;
//	int a;
//};
//
//struct S3
//{
//	double a;
//	char b;
//	int c;
//};
//
//struct S4
//{
//	double a;
//	struct S3 f;
//	int c;
//};
//
//int main()
//{
//	struct S1 s1 = { 0 };
//	printf("%d\n", sizeof(s1));
//	struct S2 s2 = { 0 };
//	printf("%d\n", sizeof(s2));
//	struct S3 s3 = { 0 };
//	printf("%d\n", sizeof(s3)); 
//	struct S4 s4 = { 0 };
//	printf("%d\n", sizeof(s4));
//}


//设置默认对齐数为4
//#pragma pack(4)
//struct S
//{
//	char c1;
//	double d;
//};
//#pragma pack() //取消设置默认对齐数
//int main()
//{
//	struct S s;
//	printf("%d\n", sizeof(s));
//}

//#include<stddef.h>
//struct S
//{
//	char c;
//	int i;
//	double d;
//}; 
//
//int main()
//{
//	//offsetof();
//	printf("%d\n", offsetof(struct S, c));
//	printf("%d\n", offsetof(struct S, i));
//	printf("%d\n", offsetof(struct S, d));
//	return 0;
//}