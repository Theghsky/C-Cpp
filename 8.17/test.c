#include <stdio.h>
		#include "mylib_2.h"

		int main(int argc,char **argv)
		{
			int n;

			printf("请输入一个自然数n:");
			scanf("%d",&n);
			printf("%d个自然数和为:%d\n",n,myfun01(n));

			return 0;
		}
