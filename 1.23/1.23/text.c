#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void bubble_sort(int arr[],int sz)
{
	int i;
	int j;
	for (i = 0; i <= sz; i++)
	{
		int temple = 1;
		for (j = 0;j <= sz-1-i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int a = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = a;

				temple =0;
			}
		}
		if (temple == 1)
		{
			break;
		}
	}
}

int main()
{
	int i;
	int arr[] = {0,9,8,7,6,5,4,3,2,1};
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr,sz);
	for (i=0;i<sz;i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}