//【程序21】
//题目：猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，
//又多吃了一个第二天早上又将剩下的桃子吃掉一半，又多吃了一个。
//以后每天早上都吃了前一天剩下的一半零一个。
//到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。

#include <stdio.h>

int main(void)
{
    int x, n = 10;
    for (x = 1; n >= 2; --n)
    {
        x = (x + 1) * 2;
    }
    printf("%d\n", x);
    return 0;
}

//
//题目：两个乒乓球队进行比赛，各出三人。甲队为a, b, c三人，乙队为x, y, z三人。
//已抽签决定比赛名单。有人向队员打听比赛的名单。
//a说他不和x比，c说他不和x, z比，请编程序找出三队赛手的名单。

#include <stdio.h>

int main(void)
{
	char i, j, k;
	for (i = 'x'; i <= 'z'; i++)
	{
		for (j = 'x'; j <= 'z'; j++)
		{
			if (i != j)
			{
				for (k = 'x'; k <= 'z'; k++)
				{
					if (i != k && j != k)
					{
						if (i != 'x' && k != 'x' && k != 'z')
							printf("a-%c b-%c c-%c\n", i, j, k);
					}
				}

			}
		}
	}
	return 0;
}


//题目：有一分数序列：2 / 1，3 / 2，5 / 3，8 / 5，13 / 8，21 / 13...求出这个数列的前20项之和。

#include <stdio.h>

int main(void)
{
	int i = 2, j = 1;
	int k = 0, x = 0;
	for (int n = 0; n <= 20; ++n)
	{
		k += i / j;
		x = i;
		i = i + j;
		j = x;
	}
	printf("%d\n", k);
	return 0;
}


//题目：求1 + 2!+ 3!+ ... + 20!的和

#include <stdio.h>

int main(void)
{
	int i, j, n;
	int x = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		int k = 1;
		for (j = 1; j <= i; j++)
		{
			k *= j;
		}
		x += k;
	}
	printf("%d\n", x);
	return 0;
}

//利用递归方法求5!。

#include <stdio.h>

int fn(int x)
{
	if (x != 1)
		return x * fn(x - 1);
	return 1;
}
int main(void)
{
	int x;
	scanf("%d", &x);
	printf("%d\n", fn(x));
	return 0;
}


//题目：利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来。

#include <stdio.h>

void fn(char* p, int sz)
{
	if (sz == 0)
	{
		printf("%c", p[sz]);
		return;
	}
	else
	{
		printf("%c", p[sz]);
		fn(p, sz - 1);
	}
}
int main(void)
{
	char arr[5] = { 0 };
	for (int i = 0; i < 5; ++i)
	{
		scanf("%c", &arr[i]);
	}
	printf("\n");
	int sz = sizeof(arr) / sizeof(arr[0]);
	fn(arr, sz);
	printf("\n");
	return 0;
}
