
// 请关闭中文输入法，用英文的字母和标点符号。
// 如果你想运行系统测试用例，请点击【执行代码】按钮，如果你想提交作答结果，请点击【提交】按钮，
// 注意：除答案外，请不要打印其他任何多余的字符，以免影响结果验证
// 本OJ系统是基于 OxCoder 技术开发，网址：www.oxcoder.com

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int* solution(int count, int (*arr)[2])
{
    int* result;
    // TODO: 请在此编写代码
    int n = 0;
    int car[1000] = { 0 };
    for (n; n <= count; n++)
    {
        if (arr[n][1] != 13)
        {
            int i = 0;
            i = arr[n][0] / arr[n][1];
            if ((arr[n][0] % arr[n][1]) != 0)
                i++;
            car[n] = i;
        }
        else
        {
            int j = 0;
            j = (arr[n][0]) / 12;
            if ((arr[n][0] % 12) != 0)
                j++;
            car[n] = j;
        }
    }
    result = car;
    return result;
}

int main()
{

    int num;
    int count = 0;
    int arr[1000][2];
    int n, k;
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d %d", &n, &k);
        arr[count][0] = n;
        arr[count][1] = k;
        count++;
    }


    int* result = solution(count, arr);

    for (int i = 0; i < count; i++) {
        printf("%d", result[i]);
        printf("\n");
    }

    return 0;
}