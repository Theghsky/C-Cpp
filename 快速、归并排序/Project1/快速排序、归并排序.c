#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void Print(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void Swap(int* p1,int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//三数取中
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

//左右指针法
int PartSort1(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int begin = left, end = right;
	int keyi = begin;

	while (begin < end)
	{
		//找小
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}

		//找大
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[begin], &a[keyi]);

	return begin;
}

int PartSort2(int* a, int left, int right)
{
	int index = GetMidIndex(a, left, right);
	Swap(&a[left], &a[index]);

	int keyi = left;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}

		++cur;
	}

	Swap(&a[keyi], &a[prev]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	//int keyIndex = PartSort1(a, left, right);
	int keyIndex = PartSort2(a, left, right);

	//小区间
	if (keyIndex - 1 - left > 10)
	{
		QuickSort(a, left, keyIndex-1);
	}
	else
	{
		InsertSort(a + left, keyIndex - 1 - left + 1);
	}

	if (right - (keyIndex + 1) > 10)
	{
		QuickSort(a, keyIndex + 1, right);
	}
	else
	{
		InsertSort(a + keyIndex + 1, right - (keyIndex + 1) + 1);
	}
}

void TestQuickSort()
{
	int a[] = { 49, 38, 65, 97, 76, 13, 27, 49, 13, 27, 49 };

	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	Print(a, sizeof(a) / sizeof(int));
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	//假设[left,mid][mid+1,right]有序，那么我们就可以归并了
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	//归并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	//拷贝回去
	for (int i = left; i <= right; ++i)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

void TestMergeSort()
{
	int a[] = { 10,6,7,1,3,9,4,2 };
	MergeSort(a, sizeof(a) / sizeof(int));
	Print(a, sizeof(a) / sizeof(int));
}

void TestOP()
{
	srand(time(0));
	const int N = 1000000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
	}

	int begin1 = clock();
	QuickSort(a1, 0, N - 1);
	int end1 = clock();

	int begin2 = clock();
	MergeSort(a2, N);
	int end2 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);

	free(a1);
	free(a2);
}

int main()
{
	TestQuickSort();
	TestMergeSort();
	TestOP();
	return 0;
}