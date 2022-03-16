#include"SList.h"
//打印
void SListPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d-> ", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

//创建新节点
SLTNode* BuySListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->data = x;
	newnode->next = NULL;

	return newnode;
}

//尾插
void SListPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾节点的指针
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		//尾节点，链接新节点
		tail->next = newnode;
	}
}

//头插
void SListPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySListNode(x);

	newnode->next = *pphead;
	*pphead=newnode;
}

//头删
void SListPopFront(SLTNode** pphead)
{
	SLTNode* next = (*pphead)->next;
	free(*pphead);

	*pphead = next;
}

//尾删
void SListPopBack(SLTNode** pphead)
{
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else if (*pphead == NULL)
	{
		return;
	}
	else
	{
		SLTNode* cmp = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			cmp = tail;
			tail=tail->next;
		}
		free(tail);
		cmp->next = NULL;
	}
}

//查找
SLTNode* SListFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

//在pos的前面插入x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	if (pos == *pphead)
	{
		SListPushFront(pphead,x);
	}
	else
	{
		SLTNode* newnode = BuySListNode(x);
		SLTNode* tail = *pphead;
		while (tail->next != pos)
		{
			tail = tail->next;
		}

		tail->next = newnode;
		newnode->next = pos;

	}
}

//删除pos位置的值
void SListErase(SLTNode** pphead, SLTNode* str)
{
	if (str == *pphead)
	{
		SListPopFront(pphead);
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != str)
		{
			tail = tail->next;
		}
		tail->next = str ->next;
		free(str);
	}
}