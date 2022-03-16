#include"SList.h"

void TestSList1()
{
	SLTNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPushFront(&plist, 5);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist); 

	SLTNode* pos = SListFind(plist, 2);
	if (pos)
	{
		SListInsert(&plist, pos, 30);
	}
	SListPrint(plist);

	SLTNode* str = SListFind(plist, 2);
	if (str)
	{
		SListErase(&plist, str);
	}
	SListPrint(plist);

}

int main()
{
	TestSList1();
	return 0;
}