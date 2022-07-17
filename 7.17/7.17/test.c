//题目：输入三个整数x, y, z，请把这三个数由小到大输出。
//1.程序分析：我们想办法把最小的数放到x上，先将x与y进行比较，如果x > y则将x与y的值进行交换，然后再用x与z进行比较，
//如果x > z则将x与z的值进行交换，这样能使x最小。








//题目：用* 号输出字母C的图案。
//1.程序分析：可先用'*'号在纸上写出字母C，再分行输出。

       /*       
             **********
            *
           *
          *
         *
        *
         *
          *
           * 
            *
             ********** 
       */

#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int i, j;//行 ‘ ’‘*’个数
    //上半C
    for (i = 0; i < 6; ++i)
    {
        for (j = i; j < 14; ++j)
            printf(" ");
        if (i == 0)
        {
            for (j = 0; j < 10; ++j)
                printf("*");
            printf("\n");
        }
        else
            printf("*\n");
    }
        //下半C
        for (i = 0; i < 5; ++i)
        {
            for (j = 4-i; j < 14; ++j)
                printf(" ");
            if (i == 4)
            {
                for (j = 0; j < 10; ++j)
                    printf("*");
            }
            else
                printf("*\n");
        }
    return 0;
}

//【程序8】
//题目：输出9 * 9口诀。
//1.程序分析：分行与列考虑，共9行9列，i控制行，j控制列。

int main()
{
    int i, j, x;
    for (i = 1; i <= 9; ++i)
    {
        for (j = 1; j <= i; ++j)
        {
            x = i * j;
            printf("%d*%d=%-3d",i,j,x);
        }
        printf("\n");
    }
    return 0;
}


//题目：要求输出国际象棋棋盘。
//1.程序分析：用i控制行，j来控制列，根据i + j的和的变化来控制输出黑方格，还是白方格。

main()
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
            if ((i + j) % 2 == 0)
                printf("%c%c", 219, 219);
            else
                printf("  ");
        printf("\n");
    }
    return 0;
}

//题目：打印楼梯，同时在楼梯上方打印两个笑脸。
//1.程序分析：用i控制行，j来控制列，j根据i的变化来控制输出黑方格的个数。

#include "stdio.h"
main()
{
    int i, j;
    printf("\1\1\n"); /*输出两个笑脸*/
    for (i = 1; i < 11; i++)
    {
        for (j = 1; j <= i; j++)
            printf("%c%c", 219, 219);
        printf("\n");
    }
    getchar();
}


//题目：古典问题：有一对兔子，从出生后第3个月起每个月都生一对兔子，
//小兔子长到第三个月后每个月又生一对兔子，
//假如兔子都不死，问每个月的兔子总数为多少？
//1.程序分析：　兔子的规律为数列1, 1, 2, 3, 5, 8, 13, 21....

int main()
{
    int tmp, nums, month;
    int count, x;
    tmp = 1, nums = 1; x = 0;
    scanf("%d", &month);
    if (month >= 3 && month > 0)
    {
        for (count = 3; count <= month; ++count)
        {
            x = nums;
            nums += tmp;
            tmp = x;
        }
        printf("%d\n", nums * 2);
    }
    else
        printf("%d", nums * 2);
    return 0;
}


//题目：判断101 - 200之间有多少个素数，并输出所有素数。
//1.程序分析：判断素数的方法：用一个数分别去除2到sqrt(这个数)，如果能被整除，则表明此数不是素数，反之是素数。
int main()
{
    int i, j;
    for (i = 101; i <= 200; ++i)
    {
        for (j = 2; j < sqrt(i); ++i)
        {
            if (i % j == 0)
                printf("%d\n", i);
            break;
        }
    }
    return 0;
}