#include"List.h"

void TestList1()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListPushFront(plist, 0);
	ListPushFront(plist, -1);
	ListPrint(plist);

	ListPopFront(plist);
	ListPrint(plist);

	ListPopBack(plist);
	ListPrint(plist);

	ListDestory(plist);

}


void TestList2()
{
	ListNode* plist = ListInit();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListNode* pos = ListFind(plist, 3);
	if (pos)
	{
		// 查找，附带着修改的作用
		pos->data *= 10;
		printf("找到了，并且节点的值乘以10\n");
	}
	else
	{
		printf("没有找到\n");
	}

	ListPrint(plist);

	ListInsert(pos, 300);
	ListPrint(plist);

	ListErase(pos);
	ListPrint(plist);
}

int main()
{
	TestList1();
	printf("\n");
	TestList2();

	return 0;
}