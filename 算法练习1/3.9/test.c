#define  _CRT_SECURE_NO_WARNINGS

//数组nums包含从0到n的所有整数，但其中缺了一个。
//请编写代码找出那个缺失的整数。
//你有办法在O(n)时间内完成吗？
// 
//题目一：消失的数字  难度简单

int missingNumber(int* nums, int numsSize)
{
    int x = 0;
    int i = 0;
    int j = 0;
    //先跟数组中的值异或
    for (i = 0; i < numsSize; i++)
    {
        x ^= nums[i];
    }
    //在跟[0-N]的值异或
    for (j = 0; j < numsSize + 1; j++)
    {
        x ^= j;
    }
    return x;
}


//给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
//题目二：难度中等
void inversion(int* nums, int left, int right)
{
    while (left < right)
    {
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        ++left;
        --right;
    }
}


void rotate(int* nums, int numsSize, int k)
{
    if (k >= numsSize)
    {
        k %= numsSize;
    }

    inversion(nums, 0, numsSize - k - 1);
    inversion(nums, numsSize - k, numsSize - 1);
    inversion(nums, 0, numsSize - 1);

}