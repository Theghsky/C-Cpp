//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

//示例 1：
//输入：head = [1, 2, 3, 4, 5]
//输出：[5, 4, 3, 2, 1]
//来源：
//https ://leetcode-cn.com/problems/reverse-linked-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
    //解法二：
    struct ListNode* cur = head;
    struct ListNode* newHead = NULL;
    while (cur)
    {
        struct ListNode* next = cur->next;

        //头插
        cur->next = newHead;
        newHead = cur;
        cur = next;
    }
    return newHead;

    //解法一：
    // if(head==NULL)
    // {
    //     return NULL;
    // }
    // //初始条件
    // struct ListNode* n1=NULL,*n2=head,*n3=n2->next;
    // //结束条件
    // while(n2)
    // {
    //     //迭代过程
    //     n2->next=n1;
    //     n1=n2;
    //     n2=n3;
    //     if(n3!=NULL)
    //         n3=n3->next;
    // }
    // return n1;
}
