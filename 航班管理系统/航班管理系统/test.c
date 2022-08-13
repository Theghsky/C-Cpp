#include"flight.h"


void menu()
{
	printf("*********  航班信息  **********\n");
	printf("*******1.添加     2.显示*******\n");
	printf("*******3.查询     4.删除*******\n");
	printf("*********   0.退出   **********\n");
	printf("*******************************\n");
}

int main()
{
	int input = 0;
	//初始化
	plink_t p = NULL;
	link_init(&p);
	if (p == NULL)
		return -1;
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			link_add_tail(p);
			break;
		case show:
			display(p);
			break;
		case search:
			flightFind(p);
			break;
		case del:
			link_del(p);
			break;
		case quit:
			printf("退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);

	return 0;
}