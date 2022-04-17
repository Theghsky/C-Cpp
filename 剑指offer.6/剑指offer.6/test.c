//输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
//
//示例 1：
//
//输入：head = [1, 3, 2]
//输出：[2, 3, 1]

/**
} * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int* reversePrint(struct ListNode* head, int* returnSize)
{
    int i = 0, j = 0, k = 0;
    static int numbers[10000];
    struct ListNode* cur = head;
    while (cur != NULL)
    {
        numbers[i++] = cur->val;
        cur = cur->next;
    }
    k = i;
    int* answer = (int*)malloc(sizeof(int) * i);
    while (i > 0)
    {
        answer[j++] = numbers[i - 1];
        i--;
    }
    *returnSize = k;
    return answer;
}