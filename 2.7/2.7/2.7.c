//#define  _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
////int main()
////{
////	int i = 0;
////	for (i = 0; i < 100; i++)
////	{
////		printf("%d ",i);
////	}
////	system("pause");
////	return 0;
////}
////
////int main()
////{
////	{
////		int rmp = 0;
////		printf("tmp = %d\n", rmp);
////	}
////	int arr[10] = { 0 };
////	int i = 0;
////	for (i = 0; i < 10; i++)
////	{
////		arr[i] = i;
////	}
////	
////	return 0;
////}
////
////int main()
////{
////	int i = 0;
////	int sum = 0;
////	int n = 0;
////	scanf("%d",&n);
////	for (i = 1; i <= n; i++)
////	{
////		int j = 0;
////		int ret = 1;
////		for (j = 1; j <= i; j++)
////		{
////			ret *= j;
////		}
////		sum += ret;
////	}
////	printf("%d\n",sum);
////	return 0;
////}
//
//void test()
//{
//	int a = 10;
//	int b = 20;
//	int c = a + b;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = i + 1;
//	}
//
//	for (i = 1; i < sz; i++)
//	{
//		test();
//		printf("%d\n",arr[i]);
//	}
//	return 0;
//}
//
//void test2()
//{
//	printf("hehe\n");
//}
//void test1()
//{
//	test2();
//}
//void test()
//{
//	test1();
//}
//int main()
//{
//	test();
//	return 0;
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		arr[i] = i + 1;
//	}
//
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d",&n);//3
//	//1! + 2�� + 3!
//	//1    2     6 = 9
//	//1*2*....*	n
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//	int j = 0;
//	for (j = 1; j <= n; j++)
//	{
//		ret = 1;
//		for (i = 1; i <= j; i++)
//		{
//			ret *= i;
//		}
//		sum += ret;
//	}
//	printf("%d\n",sum);
//	return 0;
//}
//
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	//0-9
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hehe\n");
//	}
//	//�������н����ʲô��
//
//	return 0;
//}
//
//Ԥ����������
//ͨ������ļ��ɣ����ٴ���
//
//ģ��ʵ��strcpy
//strcpy - �ַ�������
//
//#include<string.h>
//
//д����
//void my_srtcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src;
//}
//
//void my_strcpy(char* dest, char* src)
//{
//	while (*src != '\0')
//	{
//		*dest++ = *src++;
//	}
//	*dest = *src;
//}
//
//void my_strcpy(char* dest, char* src)
//{
//	while (*dest++ = *src++)
//	{
//		;
//	}
//}
//
//int main()
//{
//	char arr1[20] = "xxxxxxxxxxx";
//	char arr2[] = "hello";
//	my_srtcpy(NULL, arr2);
//
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}