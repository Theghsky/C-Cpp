#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>



char* my_strcpy(char* dest,const char* str)
{
	assert(dest != NULL);
	assert(str != NULL);
	char* ret = dest;
	while (*dest++ = *str++)
	{
		;
	}
	return ret;
}

//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "bit";
//	my_strcpy(arr1,arr2);
//	printf("%s\n", arr1);
//    return 0;
//}



int my_strlen_1(const char* str)
{
	assert(str != NULL);
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int my_strlen_2(const char* str)
{
	assert(str != NULL);
	if (*str == '\0')
		return 0;
	else
		return 1 + my_strlen_2(++str);
}

//int main()
//{
//	char arr1[] = "abcedf";
//	//int len=my_strlen1(arr1);
//	//printf("%d ",len);
//	printf("%d\n", my_strlen_2(arr1));
//	return 0;
//}





char* my_strcat(char* dest, const char* str)
{
	char* ret = dest;  //arr1 的首字符地址放到指针 ret 里面，使其返回 arr1 的首地址开始打印
	assert(dest != NULL);
	assert(str != NULL);
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *str++)
	{
		;
	}
	return ret;
}

//int main()
//{
//	char arr1[30] = "abcdef";
//	char arr2[] = "bit";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

