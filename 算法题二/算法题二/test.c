//
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-element
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//
//示例 1：
//输入：nums = [3, 2, 2, 3], val = 3
//输出：2, nums = [2, 2]
//解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。
//例如，函数返回的新长度为 2 ，而 nums = [2, 2, 3, 3] 或 nums = [2, 2, 0, 0]，也会被视作正确答案。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/remove-element
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


int removeElement(int* nums, int numsSize, int val)
{
	int src = 0;
	int dst = 0;
	while (src<numsSize)
	{
		if (nums[src]!=val)
		{
			nums[dst++] = nums[src++];
		}
		else
		{
			++src;
		}
	}
	return dst;
}


//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，
//nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
// 
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/merge-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//
//示例 1：
//
//输入：nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
//输出：[1, 2, 2, 3, 5, 6]
//解释：需要合并[1, 2, 3] 和[2, 5, 6] 。
//合并结果是[1, 2, 2, 3, 5, 6] ，其中斜体加粗标注的为 nums1 中的元素。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/merge-sorted-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int str = m - 1;
	int dst = n - 1;
	int end = m + n - 1;
	while(str>=0 && dst>=0)
	{
		if (nums1[str] > nums2[dst])
		{
			nums1[end] = nums2[str];
			--end;
			--str;
		}
		else
		{
			nums1[end] = nums2[dst];
			--end;
			--dst;
		}
	}
	//
	while (dst>=0)
	{
		nums1[end] = nums2[dst];
		--end;
		--dst;
	}

}