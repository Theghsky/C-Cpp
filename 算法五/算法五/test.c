#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

//请必须使用时间复杂度为 O(log n) 的算法。

//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/search-insert-position
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//示例 1:
//
//输入: nums = [1, 3, 5, 6], target = 5
//输出 : 2

int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1;
    int cmp = numsSize;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] >= target)
        {
            cmp = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return cmp;
}

//二分查找原型
int searchInsert(int* nums, int numsSize, int target)
{
    int left = 0, right = numsSize - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else if(nums[mid]>target)
        {
            right = mid - 1;
        }
        else 
        {
            return mid;
        }
    }
    return 0;
}


int main()
{
    int nums[] = { 0,1,3,5,7,10,11,14 };
    int y=searchInsert(nums,8,2);
    if (y == 0)
    {
        printf("找不到\n");
    }
    else
    {
        printf("%d \n", y);
    }
	return 0;
}