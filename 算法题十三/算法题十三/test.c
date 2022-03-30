//
//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
//本题中，一棵高度平衡二叉树定义为：
//
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
//
//
//
//示例 1：
//
//
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出：true
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/balanced-binary-tree
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


int maxdeep(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    int leftdeep = maxdeep(root->left);
    int rightdeep = maxdeep(root->right);

    return leftdeep > rightdeep ? leftdeep + 1 : rightdeep + 1;
}


bool isBalanced(struct TreeNode* root)
{
    if (root == NULL)
        return true;

    int leftdeep = maxdeep(root->left);
    int rightdeep = maxdeep(root->right);

    return abs(leftdeep - rightdeep) < 2
        && isBalanced(root->left)
        && isBalanced(root->right);
}

//
//给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
//
//示例 1：
//
//输入：root = [1, null, 2, 3]
//输出：[1, 3, 2]
//示例 2：
//
//输入：root = []
//输出：[]
//示例 3：
//
//输入：root = [1]
//输出：[1]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-tree-inorder-traversal
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

void InOrder(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
        return;


    InOrder(root->left, a, pi);
    a[*pi] = root->val;
    ++(*pi);
    InOrder(root->right, a, pi);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size = TreeSize(root);
    int* a = (struct TreeNode*)malloc(size * sizeof(struct TreeNode));
    int i = 0;
    InOrder(root, a, &i);
    *returnSize = size;
    return a;
}



//给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
//
//示例 1：
//
//输入：root = [1, null, 2, 3]
//输出：[3, 2, 1]
//示例 2：
//
//输入：root = []
//输出：[]
//示例 3：
//
//输入：root = [1]
//输出：[1]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/binary-tree-postorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//难度：简单

int TreeSize(struct TreeNode* root)
{
    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

void PostOrder(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
        return;
    PostOrder(root->left, a, pi);
    PostOrder(root->right, a, pi);
    a[*pi] = root->val;
    ++(*pi);
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int size = TreeSize(root);
    int* a = (struct TreeNode*)malloc(size * sizeof(struct TreeNode));
    int i = 0;
    PostOrder(root, a, &i);
    *returnSize = size;
    return a;
}