//在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
//
//示例 1：
//
//输入：nums = [3, 4, 3, 3]
//输出：4
//示例 2：
//
//输入：nums = [9, 1, 7, 9, 7, 9, 7]
//输出：1
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-ii-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1)
            return nums[0];
        for (int i = 0; i < n; i += 3)
        {
            if (i == n - 1)
                return nums[n - 1];
            if (nums[i] == nums[i + 2])
                continue;
            else
                return nums[i];
        }
        return 0;
    }
};