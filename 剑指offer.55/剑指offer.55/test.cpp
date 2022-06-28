//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
//
//示例 1：
//
//输入：matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
//输出：[1, 2, 3, 6, 9, 8, 7, 4, 5]
//示例 2：
//
//输入：matrix = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]
//输出：[1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};
        vector<int> answer;
        int rows = matrix.size(), cols = matrix[0].size();
        int top = 0, low = rows - 1, left = 0, right = cols - 1;
        while (top <= low && left <= right)
        {
            for (int col = left; col <= right; col++)
            {
                answer.push_back(matrix[top][col]);
            }
            for (int row = top + 1; row <= low; row++)
            {
                answer.push_back(matrix[row][right]);
            }
            if (top < low&& left < right)
            {
                for (int col = right - 1; col > left; col--)
                {
                    answer.push_back(matrix[low][col]);
                }
                for (int row = low; row > top; row--)
                {
                    answer.push_back(matrix[row][left]);
                }
            }
            top++;
            right--;
            left++;
            low--;
        }
        return answer;
    }
};



