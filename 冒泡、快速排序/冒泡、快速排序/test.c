#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 时间复杂度：O（N*N）
// 最好情况:O(N)
void BubbleSort(int* a, int n)
{
	for (int j = 0; j < n; ++j)
	{
		int exchange = 0;
		for (int i = 1; i < n - j; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		if (exchange == 0)
		{
			break;
		}
	}
}

void TestBubbleSort()
{
	int a[] = { 9, 3, 5, 2, 7, 8, 6, 4, 0 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

//挖坑法
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int begin = left;
	int end = right;
	int pivot = begin;
	int key = a[begin];
	while (begin < end)
	{
		//右边找小，放到左边
		while (begin < end && a[end] >= key)
			--end;
		//小的放到左边的坑里，自己形成新的坑位
		a[pivot] = a[end];
		pivot = end;
		//左边找大
		while (begin < end && a[begin] <= key)
			++begin;
		//大的放到左边的坑里，自己形成新的坑位
		a[pivot] = a[begin];
		pivot = begin;
	}

	pivot = begin;
	a[pivot] = key;

	QuickSort(a, left, pivot-1);
	QuickSort(a, pivot + 1, right);
}

void TestQuickSort()
{
	int a[] = { 9, 3, 5, 2, 7, 8, 6, 4, 0 };
	QuickSort(a, 0, sizeof(a) / sizeof(int)-1);
	Print(a, sizeof(a) / sizeof(int));
}

// 测试排序的性能对比
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
	
		a5[i] = rand();
		a6[i] = a5[i];
		
	}

	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();

	int begin6 = clock();
	BubbleSort(a6, N);
	int end6 = clock();

	printf("BubbleSort:%d\n", end6 - begin6);
	printf("QuickSort:%d\n", end5 - begin5);

	free(a5);
	free(a6);

}

int main()
{
	TestBubbleSort();
	TestQuickSort();
	TestOP();
	return 0;
}
