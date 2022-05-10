//定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
//
//示例:
//
//输入: 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/fan-zhuan-lian-biao-lcof
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode* cur = head;
    struct ListNode* pre = NULL;
    while (cur)
    {
        struct ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}