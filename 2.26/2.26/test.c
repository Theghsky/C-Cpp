#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

//int main()
//{
//	const char* p1 = "abczef";
//	const char* p2 = "abcqwer";
//	//int ret = strcmp(p1, p2);
//	int ret = strncmp(p1, p2, 4);
//	printf("%d\n ", ret);
//	return 0;
//}

//
//#include<assert.h>
//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//	char* s1 = NULL;
//	char* s2 = NULL;
//	char* cut = p1;
//	if (*p2 == '\0')
//	{
//		return p1;
//	}
//	while (*cut)
//	{
//		s1 = cut;
//		s2 = p2;
//		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2))
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cut;
//		}
//		cut++;
//	}
//	return NULL;
//}
//
//int main()
//{
//	char* p1 = "abbbcdef";
//	char* p2 = "bbc";
//	char* ret=my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("未能找到子串\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}



//#include<ctype.h>//字符分类函数头文件
//int main()
//{
//	/*char ch = 'w';
//	int ret = islower(ch);
//	printf("%d\n", ret);
//	return 0;*/
//
//	/*char ch = tolower('Q');
//	putchar(ch);
//	return 0;*/
//
//	char arr[] = "I am a Suduent";
//	int i = 0;
//	while (arr[i])
//	{
//		if (isupper(arr[i]))  //判断大小写
//		{
//			arr[i] = tolower(arr[i]);  //大小写转化
//		}
//		i++;
//	}
//	printf("%s\n", arr);
//	return 0;
//}


//int main()
//{
//	char arr1[] = "xie_hao_sky@126.com";
//	char arr2[] = "_@.";
//	char* ret = NULL;
//	for (ret = strtok(arr1, arr2); ret != NULL; ret=strtok(NULL, arr2))
//	{
//		printf("%s\n",ret);
//	}
//	return 0;
//}

//int main()
//{
//	FILE* ret=fopen("test.txt", "r");
//	if (ret != NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("打开成功\n");
//	}
//	return 0;
//}



#include<assert.h>
void* my_memcpy(void* dest, const void* str, size_t count)
{
	assert(dest);
	assert(str);
	char* p1 = (char*)dest;
	char* p2 = (char*)str;
	while (count--)
	{
		*p1 = *p2;
		p1++;
		p2++;
	}
	return p1;
}
//void* my_memcpy(void* dest, const void* str, size_t count)
//{
//	void* ret = dest;
//	assert(dest);
//	assert(str);
//	while (count--)
//	{
//		*(char*)dest = *(char*)str;
//		++(char*)dest;
//		++(char*)str;
//	}
//	return ret;
//}

struct s
{
	char name[20];
	int age;
};

int main()
{
	/*int arr1[] = { 1,2,3,4,5 };
	int arr2[5] = { 0 };*/
	struct s arr3[] = { {"张三",20},{"李四",10} };
	struct s arr4[3] = { 0 };
	my_memcpy(arr4, arr3, sizeof(arr3));
	return 0;
}