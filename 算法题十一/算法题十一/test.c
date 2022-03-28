//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
//
//示例 1：
//
//
//输入：root = [1, null, 2, 3]
//输出：[1, 2, 3]
//示例 2：
//
//输入：root = []
//输出：[]
//示例 3：
//
//输入：root = [1]
//输出：[1]
//示例 4：
//
//
//输入：root = [1, 2]
//输出：[1, 2]
//示例 5：
//
//
//输入：root = [1, null, 2]
//输出：[1, 2]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-tree-preorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//难度：简单

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

void _prevOrder(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
        return;

    a[*pi] = root->val;
    ++(*pi);

    _prevOrder(root->left, a, pi);
    _prevOrder(root->right, a, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size = TreeSize(root);
    int* a = (int*)malloc(size * sizeof(int));
    int i = 0;
    _prevOrder(root, a, &i);

    *returnSize = size;

    return a;
}