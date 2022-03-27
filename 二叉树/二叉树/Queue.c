#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = pq->tail = NULL;

}

void QueueDestory(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* nownode = (QNode*)malloc(sizeof(QNode));
	if (nownode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	nownode->data = x;
	nownode->next = NULL;

	if (pq->tail == NULL)
	{
		pq->head = pq->tail = nownode;
	}
	else
	{
		pq->tail->next = nownode;
		pq->tail = nownode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->tail->data;
}

int QueueSize(Queue* pq)
{
	assert(pq);

	int count = 0;
	QNode* cur =pq->head;
	while (cur)
	{
		++count;
		cur = cur->next;
	}
	return count;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL;
}