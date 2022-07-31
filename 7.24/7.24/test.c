#include<stdio.h>

//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr+1);
//	printf("%p\n", &arr[0] );
//	printf("%p\n", &arr[0]+1);
//	return 0;
//}

//int main()
//{
//	int arr[2][3] = { {1,2,3},{4,5,6}};
//	printf("%p\n", arr);
//	printf("%p\n", arr + 1);
//	printf("%p\n", &arr);
//	printf("%p\n", &arr + 1);
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0] + 1);
//	return 0;
//}

void fun(char* w, int m)
{
	char s, * p1, * p2;
	p1 = w; p2 = w + m - 1;
	while (p1 < p2)
	{
		s = *p1++; 
		*p1 = *p2--; 
		*p2 = s;
	}
}

int main()
{
	char a[] = "ABCDEFG";
	fun(a, strlen(a));
	puts(a);
}