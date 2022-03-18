#include"List.h"

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
}

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void ListDestory(ListNode* phead)
{
	assert(phead);

	ListNode* cut = phead->next;
	while (cut != phead)
	{
		ListNode* next = cut->next;
		free(cut);
		cut = next;
	}

	free(phead);
	phead = NULL;
}

void ListPrint(ListNode* phead)
{
	assert(phead);

	ListNode* cut = phead->next;
	while (cut != phead)
	{
		printf("%d ", cut->data);
		cut = cut->next;
	}
	printf("\n");
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;

	//ListInsert(phead,x);  
}

void ListPushFront(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* First = phead->next;
	ListNode* newnode = BuyListNode(x);

	newnode->prev = phead;
	phead->next = newnode;
	newnode->next = First;
	First->prev = newnode;

	//ListInsert(phead->next, x);
}

void ListPopFront(ListNode* phead)
{
	//assert(phead);
	assert(phead->next != phead);

	ListNode* First = phead->next;
	ListNode* Second = First->next;

	phead->next = Second;
	Second->prev = phead;

	free(First);
	First = NULL;

	//ListInsert(phead->next, x);
}

void ListPopBack(ListNode* phead)
{
	//assert(phead);
	assert(phead->next != phead);

	ListNode* tail = phead->prev;
	ListNode* up = tail->prev;

	up->next = phead;
	phead->prev = up;

	free(tail);
	tail = NULL;

	//ListErase(phead->prev);
}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);

	ListNode* cut = phead->next;
	while (cut != phead)
	{
		if (cut->data == x)
		{
			return cut;
		}
		cut = cut->next;
	}
	return NULL;

}

void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* up = pos->prev;
	ListNode* newnode = BuyListNode(x);

	up->next = newnode;
	newnode->prev = up;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(ListNode* pos)
{
	assert(pos);

	ListNode* up = pos->prev;
	ListNode* down = pos->next;

	up->next = down;
	down->prev = up;

	free(pos);
	pos = NULL;
}


//在短时间内写出一个带头双向循环链表的方法
// 1.初始化链表、添加结点、
// 2.函数实现只需写出（ pos 位置之前的插入 x ） 与 （删除 pos 位置的值）  （打印链表函数）
// 3.其它的功能只需对上面俩个函数进行复用 