//3、用单向循环链表实现“数n出局”游戏（Josephu问题）。
//首先建立一个包含若干整数的单向循环链表，然后从第一个节点开始数，
//把数到3的那个节点删除，接着下一个节点开始数，
//数到3继续删除，以此类推，打印出最后剩余的那个节点。
#define  _CRT_SECURE_NO_WARNINGS
#include "link.h"


link_t* test()
{
	link_t* p = link_init();
	int num,del;
	scanf("%d %d", &num,&del);
	for (int i = 0; i < num; i++)
	{
		link_add_tail(p, i);
	}
	display(p);
	link_t* node = NULL;
	node = p->next;
	//link_t* node = NULL;
	while (node != node->next)
	{
		int count = 1;
		for (count; count < del; count++)
		{
			node= node->next;			
		}
		cut_behind(node);
		if (node == node->next)
			break;
	}
	display(p);
}

int main()
{
	test();
	return 0;
}










//4、用双向循环链表实现顺序递增存储若干自然数，
//比如输入一个整数10，则建立一个双向循环链表，
//里面的每个节点分别存放1，2，3，4，5，6，7，8，9，10，
//然后通过某些操作，将其重新排列成1，3，5，7，9，10，8，6，4，2，
//即奇数升序偶数降序，并在屏幕上打印出来。


//#include "link.h"
//
//void test()
//{
//	plink_t p = NULL;
//	plink_t newnode = NULL;
//	link_init(&p);
//	int num ;
//	scanf("%d", &num);
//	for (int i = 1; i <= 10; i++)
//	{
//		link_add_tail(p , i);
//	}
//	display(p);
//	for(num;num>1;num--)
//	{
//		if (num % 2 == 0)
//		{
//			newnode=ListFind(p, num);
//
//			link_add_tail(p, num);
//		}
//	}
//	display(p);
//}
//
//int main()
//{
//
//	test();
//
//	return 0;
//}