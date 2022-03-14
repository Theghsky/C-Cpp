

//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//
//你可以按任意顺序返回答案。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/two-sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//难度：简单

//示例 1：
//
//输入：nums = [2, 7, 11, 15], target = 9
//输出：[0, 1]
//解释：因为 nums[0] + nums[1] == 9 ，返回[0, 1] 。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/two-sum
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    for (int i = 0; i < numsSize; ++i)
    {
        for (int j = i + 1; j < numsSize; ++j)
        {
            if ((nums[i] + nums[j]) == target)
            {
                int* arr = malloc(sizeof(int) * 2);
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2;
                return arr;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}


//给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
//
//回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/palindrome-number/

//难度：简单

//示例 1：

//输入：x = 121
//输出：true

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    if (x < 10)
    {
        return true;
    }
    int i = 0;
    int nums[10] = { 0 };
    for (i = 0; x; i++)
    {
        nums[i] = x % 10;
        x /= 10;
    }
    int left = 0, right = i - 1;
    while (left < right)
    {
        if (nums[left++] != nums[right--])
        {
            return false;
        }
    }
    return true;
}