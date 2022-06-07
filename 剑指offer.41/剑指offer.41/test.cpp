//输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
//
//示例 1:
//
//给定二叉树[3, 9, 20, null, null, 15, 7]
//
//     3
//    / \
//   9  20
//      / \
//    15   7
//返回 true 。
//
//示例 2:
//
//给定二叉树[1, 2, 2, 3, 3, null, null, 4, 4]
//
//       1
//      / \
//     2   2
//    / \
//   3   3
//  / \
// 4   4
//返回 false 。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/ping-heng-er-cha-shu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int hight(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int lefthight = hight(root->left);
        int righthight = hight(root->right);
        if (lefthight == -1 || righthight == -1 || abs(lefthight - righthight) > 1)
            return -1;
        else
            return max(lefthight, righthight) + 1;
    }

    bool isBalanced(TreeNode* root)
    {
        return hight(root) >= 0;
    }
};