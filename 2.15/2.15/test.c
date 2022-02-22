#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student
{
	char name[20];
	int age;
};

int cmd_str_age(const void* e1, const void* e2)
{
	return ((struct student*)e1)->age - ((struct student*)e2)->age;
}

int cmd_str_name(const void* e1, const void* e2)
{
	return strcmp(((struct student*)e1)->name, ((struct student*)e2)->name);
}

int cmp_str_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void test_1()
{
	int s[10] = { 2,4,3,6,5,1,8,9,7,0 };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_str_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", s[i]);
	}
}

int cmp_str_float(const void* e1, const void* e2)
{
	/*if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 > *(float*)e2)
		return 1;
	else
		return -1;*/
	return (int)(*(float*)e1 - *(float*)e2);
}

void test_2()
{
	float s[] = { 5.0,4.0,3.0,2.0,1.0 };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_str_float);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", s[i]);
	}
}

void swop(char* e1, char* e2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}

void bubbling(void* base, int count, int width, int (*cmp)(void* e1, void* e2))
{
	int i = 0;
	for (i = 0; i < count-1 ; i++)
	{
		int j = 0;
		for (j = 0; j < count - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				swop((char*)base + j * width , (char*)base + (j + 1) * width, width);
			}
		}
	}
}

void test_3()
{
	struct student s[3] = { {"zhangsan",20}, {"lisi",10},{"xiaomin",30} };
	int sz = sizeof(s) / sizeof(s[0]);
	//bubbling(s, sz, sizeof(s[0]), cmd_str_age);
	bubbling(s, sz, sizeof(s[0]), cmd_str_name);
}

int main()
{
	//struct student s[3] = { {"zhangsan",20}, {"lisi",10},{"xiaomin",30}};
	//int sz = sizeof(s) / sizeof(s[0]);
	////qsort(s, sz, sizeof(s[0]), cmd_str_age);
	//qsort(s, sz, sizeof(s[0]), cmd_str_name);
	//test_1();
	//test_2();
	test_3();
	return 0;
}