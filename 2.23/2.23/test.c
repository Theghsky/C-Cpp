#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

int main()
{
	char* arr1 = "abcdef";
	char* arr2 = "abczef";
	int len = my_strcmp(arr1, arr2);
	printf("ret=%d \n", len);
	return 0;
}