#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int a = sizeof(arr);
	int b = sizeof(arr[0]);
	printf("%d\n",a);
	printf("%d\n",b);
	printf("%d\n",sizeof(arr[0]));

	return 0;
}