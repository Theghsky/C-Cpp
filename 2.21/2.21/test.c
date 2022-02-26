#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//	int money = 0;
//	int total = 0;
//	int empty = 0;
//	scanf("%d", &money);
//	total = money;
//	empty = money;
//	while (empty >= 2)
//	{
//		total += empty / 2;
//		empty = empty / 2 + empty%2;
//	}
//	printf("total=%d\n", total);
//	return 0;
//}





//void print(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz ; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//void move(int arr[], int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left<right)
//	{
//		while ((left<right) && (arr[left] % 2 == 1))
//		{
//			left++;
//		}
//		while ((left<right) && (arr[right] % 2 == 0))
//		{
//			right--;
//		}
//		if (left < right)
//		{
//			int tmp = arr[left];
//			arr[left] = arr[right];
//			arr[right] = tmp;
//		}
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	move(arr, sz);
//	print(arr, sz);
//	return 0;
//}




//#include<string.h>
//int is_left_move(char* s1, char* s2)
//{
//	int  len1 = strlen(s1);
//	int  len2 = strlen(s2);
//	if (len1 != len2)
//		return 0;
//	int len = strlen(s1);
//	strncat(s1, s1, len);
//	char* ret = strstr(s1, s2);
//	if (ret == NULL)
//		return 0;
//	else
//		return 1;
//}
//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "cdefab";
//	int len = is_left_move(arr1, arr2);
//	if (len == 0)
//		printf("NOW");
//	else
//		printf("YES");
//	return 0;
//}





int Fillnum(int arr[][3], int k, int* row, int* col)
{
	int x = 0;
	int y = *col - 1;
	while (x<=row-1 && y>=0)
	{
		if (arr[x][y] < k)
		{
			x++;
		}
		else if (arr[x][y] > k)
		{
			y--;
		}
		else
		{
			*row = x;
			*col = y;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int arr[][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 7;
	scanf("%d", &k);
	int x = 3;
	int y = 3;
	int len = Fillnum(arr, k, &x, &y);
	if (len == 1)
	{
		printf("找到了\n");
		printf("下标是：%d %d\n",x, y);
	}
	else
		printf("找不到\n");
	return 0;
}