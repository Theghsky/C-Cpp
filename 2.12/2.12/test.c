#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	char ch = 'w';
//	char* pc = &ch;
//	*pc = 'w';
//	return 0;
//}

//int main()
//{
//	char str1[] = "hello bit";
//	char str2[] = "hello bit";
//	const char* str3 = "hello bit";
//	const char* str4 = "hello bit";
//
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are not same\n");
//
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are not same\n");
//
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	printf("arr = %p\n", arr);
//	printf("arr = %p\n", &arr);
//
//	printf("arr+1 = %p\n", arr + 1);
//	printf("&arr+1= %p\n", &arr + 1);
//	return 0;
//}

void print_arr1(int (*arr)[5], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//printf("%d ", arr[i][j]);
			//printf("%d ", *(*(arr+ i)+j));
			printf("%d ", (*(arr + i))[j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
	print_arr1(arr, 3, 5);
	return 0;
}