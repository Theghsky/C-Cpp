//数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
//
//请写一个函数，求任意第n位对应的数字。
//
//示例 1：
//
//输入：n = 3
//输出：3
//示例 2：
//
//输入：n = 11
//输出：0
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int findNthDigit(int n)
{
    long count = 1, base = 9;
    while (n - count * base > 0)
    {
        n -= count * base;
        count++;
        base *= 10;
    }
    int num = n / count;
    int digit = n % count;
    long ans = pow(10, count - 1) + num;
    if (digit == 0)
    {
        ans -= 1;
        digit = count;
    }
    for (int i = digit; i < count; i++)
        ans /= 10;
    return ans % 10;
}