//输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
//
//示例 1：
//
//输入：arr = [3, 2, 1], k = 2
//输出：[1, 2] 或者[2, 1]
//示例 2：
//
//输入：arr = [0, 1, 2, 1], k = 1
//输出：[0]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> vec(k, 0);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) {
            vec[i] = arr[i];
        }
        return vec;
    }
};

作者：LeetCode - Solution
链接：https ://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/solution/zui-xiao-de-kge-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。