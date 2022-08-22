	#include <stdio.h>
			int myfun01(int n)
			{
				printf("这是我写的动态库!\n");
				if(n == 0)
					return 0;
				else
					return myfun01(n-1) + n ;
			}

			int myfun02(int n)
			{
				if(n == 0)
					return 1;
				else
					return myfun02(n-1) * n;
			}
