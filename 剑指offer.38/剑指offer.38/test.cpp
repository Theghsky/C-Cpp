//统计一个数字在排序数组中出现的次数。
//
//示例 1:
//
//输入: nums = [5, 7, 7, 8, 8, 10], target = 8
//输出 : 2
//示例 2 :
//
//	输入 : nums = [5, 7, 7, 8, 8, 10], target = 6
//	输出 : 0
//
//	来源：力扣（LeetCode）
//	链接：https ://leetcode.cn/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower)
    {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target))
            {
                right = mid - 1;
                ans = mid;
            }
            else
                left = mid + 1;
        }
        return ans;
    }

    int search(vector<int>& nums, int target)
    {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false) - 1;
        if (left <= right && right < nums.size() && nums[left] == target && nums[right] == target)
            return right - left + 1;
        return 0;
    }
};