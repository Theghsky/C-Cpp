#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<errno.h>
#include<string.h>

//int main()
//{
//	FILE* pf;
//	pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//写文件
//	fputc('b', pf);
//  fputc('i', pf);
//  fputc('t', pf);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	FILE* pf;
//	pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//读文件
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* ps = fopen("test.txt", "r");
//	if (ps == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//读文件
//	fgets(buf, 1024, ps);
//	printf("%s", buf);
//	//puts(buf);
//	fgets(buf, 1024, ps);
//	printf("%s", buf);
//	//puts(buf);
//
//	fclose(ps);
//	ps = NULL;
//	return 0;
//}

//int main()
//{
//	char buf[1024] = { 0 };
//	FILE* ps = fopen("test.txt", "w");
//	if (ps == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//写文件
//	fputs("hello\n", ps);
//	fputs("world\n", ps);
//
//	fclose(ps);
//	ps = NULL;
//	return 0;
//}



//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};

//int main()
//{
//	struct S s = { 100,3.14,"abedefa" };
//	struct S tmp = { 0 };
//	char buf[1024] = { 0 };
//	//把格式化的数据传换成字符串存储到buf
//	sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
//	//printf("%s\n",buf);
//	
//	//从buf 中读取格式化的数据到tmp中
//	sscanf(buf, "%d %f %s", &(tmp.n), &(tmp.score), tmp.arr);
//	printf("%d %.2f %s\n", tmp.n, tmp.score, tmp.arr);
//
//	return 0;
//}


//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = {0};
//	fscanf(stdin, "%d %f %s", &(s.n), &(s.score), s.arr);
//	fprintf(stdout, "%d %.2f %s\n", s.n, s.score, s.arr);
//
//	return 0;
//}



//struct S
//{
//	int n;
//	float score;
//	char arr[10];
//};
//
//int main()
//{
//	struct S s = { 100,3.14,"asdfs"};
//	FILE* pf = fopen("test.txt", "w");
//	if (pf == NULL)
//	{
//		return 0;
//	}
//	//格式化的形式写文件
//	fprintf(pf, "%d %0.2f %s", s.n, s.score, s.arr);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


struct S
{
	int n;
	float score;
	char arr[10];
};

int main()
{
	struct S s = { 0 };
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		return 0;
	}
	//格式化的形式读文件
	fscanf(pf, "%d %0.2f %s", &(s.n),&(s.score),s.arr);
	printf("%d %0.2f %s\n", s.n, s.score, s.arr);
	fclose(pf);
	pf = NULL;
	return 0;
}


//int main()
//{
//	//从键盘读取一行文本信息
//	char buf[1024] = { 0 };
//	fgets(buf, 1024, stdin);//从表中输入流读取
//	fputs(buf, stdout);//从标准输出流读取
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//    FILE* pFile;
//    //打开文件
//    char ch[30] = { 0 };
//    pFile = fopen("myfile.txt", "r");
//    //文件操作放入到数组中
//    if (pFile != NULL)
//    {
//        fgets(ch,20, pFile);
//        printf("%s\n", ch);
//        //关闭文件
//        fclose(pFile);
//    }
//    return 0;
//}


//int main()
//{
//    FILE* pFile;
//    //打开文件
//    pFile = fopen("myfile.txt", "w");
//    //文件操作
//    if (pFile != NULL)
//    {
//        fputs("fopen example", pFile);
//        //关闭文件
//        fclose(pFile);
//    }
//    return 0;
//}
