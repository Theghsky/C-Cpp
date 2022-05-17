//从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
//
//例如:
//给定二叉树: [3, 9, 20, null, null, 15, 7] ,
//
//3
/// \
//9  20
/// \
//15   7
//返回：
//
//[3, 9, 20, 15, 7]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
#define MAX_SIZE 10001
int* levelOrder(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (root == NULL)
        return NULL;
    int* ans = (int*)calloc(MAX_SIZE, sizeof(int));
    struct TreeNode* queue[MAX_SIZE];
    memset(queue, 0, sizeof(struct TreeNode*));
    int head = 0;
    int tail = 0;
    queue[tail++] = root;

    while (head < tail)
    {
        struct TreeNode* tmp = queue[head++];
        ans[(*returnSize)++] = tmp->val;
        if (tmp->left != NULL)
        {
            queue[tail++] = tmp->left;
        }
        if (tmp->right != NULL)
        {
            queue[tail++] = tmp->right;
        }
    }
    return ans;
}
