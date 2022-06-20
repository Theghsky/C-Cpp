//写一个函数，求两个整数之和，要求在函数体内不得使用 “ + ”、“ - ”、“ * ”、“ / ” 四则运算符号。
//
//示例:
//
//输入: a = 1, b = 1
//输出 : 2
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int add(int a, int b)
    {
        return b == 0 ? a : add(a ^ b, (unsigned int)(a & b) << 1);
    }
};
