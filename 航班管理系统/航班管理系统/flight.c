#include"flight.h"

/**
  ***********************************
  *@brief  初始化 (创建头节点)
  *@param  p : 头节点
  *@retval None
  ***********************************
  */
void link_init(plink_t* p)
{
	*p = (plink_t)malloc(sizeof(link_t));
	if (*p == NULL) {
		perror("malloc error");
		return;
	}

	(*p)->prev = (*p);
	(*p)->next = (*p);
}


/**
  ***********************************
  *@brief  插入排序
  *@param  p : 头节点
  *@retval None
  ***********************************
  */
void link_add_tail(plink_t p)
{
	//创建新的节点
	plink_t newnode = NULL;
	link_init(&newnode);
	if (newnode == NULL)
		return;
	//添加数据
	Addflight(newnode);
	//判断头节点是否指向自己是的话直接插入
	if (p->next == p)
		//将新的节点插在头的后面
		insert_behind(p, newnode);
	else {
		//排序
		sortflight(p, newnode);
	}
		

}


//增加数据
void  Addflight(plink_t pf)
{
	printf("请输入航班号:>");
	scanf("%s", pf->data.number);

	printf("请输入起点站 :>");
	scanf("%s", pf->data.staddress);

	printf("请输入终点站  :>");
	scanf("%s", pf->data.arraddress);

	printf("请输入班期:>");
	scanf("%s", pf->data.DATE);

	printf("请输入机型:>");
	scanf("%s", pf->data.TYPE);

	printf("请输入起飞时间:>");
	scanf("%d", &(pf->data.stime));

	printf("请输入到达时间 :>");
	scanf("%d", &(pf->data.atime));

	printf("请输入票价:>");
	scanf("%d", &(pf->data.value));

	printf("添加成功\n");

}

/**
  ***********************************
  *@brief  正序遍历
  *@param  p : 头节点
  *@retval None
  ***********************************
  */
void display(plink_t p)
{
	plink_t head = p;
	printf("航班信息：\n");
	while (p->next != head) {
		p = p->next;
		Printflight(p);
	}
	printf("\n");

}

//打印数据
void  Printflight(plink_t pf)
{
	printf("航班号:>%s\n", pf->data.number);
	printf("起点站:>%s\n", pf->data.staddress);
	printf("终点站:>%s\n", pf->data.arraddress);
	printf("班期:>%s\n", pf->data.DATE);
	printf("机型:>%s\n", pf->data.TYPE);
	printf("起飞时间:>%d\n",pf->data.stime);
	printf("到达时间:>%d\n", pf->data.atime);
	printf("票价:>%d\n",pf->data.value);
	printf("\n");
}

/**
  ***********************************
  *@brief  一个节点node插在p的前面
  *@param  p  node : 节点
  *@retval None
  ***********************************
  */

static void insert_forward(plink_t p, plink_t node)
{
	node->next = p;
	node->prev = p->prev;
	p->prev->next = node;
	p->prev = node;
}

/**
  ***********************************
  *@brief  一个节点node插在p的后面
  *@param  p  node : 节点
  *@retval None
  ***********************************
  */
static void insert_behind(plink_t p, plink_t node)
{
	node->next = p->next;
	node->prev = p;
	p->next->prev = node;
	p->next = node;
}

//插入
//void sortflight(plink_t p, plink_t newnode)
//{
//	plink_t pp = p;
//	while (1)
//	{
//		if (p->next == pp )
//		{
//			if (p->data.stime > newnode->data.stime)
//				//新结点插在原结点前面
//				insert_forward(p, newnode);
//			if (p->data.stime <= newnode->data.stime)
//				//新结点插在原结点后面
//				insert_behind(p, newnode);
//			break;
//		}
//		else
//		{
//			if (p->data.stime <= newnode->data.stime)
//			{
//				p = p->next;
//				continue;
//			}
//			if (p->data.stime > newnode->data.stime)
//			{
//				insert_forward(p, newnode);
//				break;
//			}
//		}
//	}
//	p = pp;
//	pp = NULL;
//	free(pp);
//}

//查找航班信息
plink_t flightFind(plink_t phead)
{
	assert(phead);
	int x = 0;
	char date[D];
	printf("请输入班期:>");
	scanf("%s",date);
	printf("请输入起飞时间:>");
	scanf("%d", &x);
	plink_t cut = phead->next;
	while (cut != phead)
	{
		if (cut->data.stime == x && strcmp(cut->data.DATE,date)==0)
		{
			Printflight(cut);
		}
		cut = cut->next;
	}

	return NULL;

}


//按照班期和起飞时间顺序插入
void sortflight(plink_t p, plink_t newnode)
{
	plink_t pp = p;
	p = p->next;
	while (1)
	{
		//判断是否到最后一个结点
			if (p->next == pp)
			{
				if (strcmp(p->data.DATE, newnode->data.DATE) > 0)
					//新结点插在原结点前面
					insert_forward(p, newnode);
				if (strcmp(p->data.DATE, newnode->data.DATE) == 0)
				{
					if (p->data.stime > newnode->data.stime)
						//新结点插在原结点前面
						insert_forward(p, newnode);
					if (p->data.stime <= newnode->data.stime)
						//新结点插在原结点后面
						insert_behind(p, newnode);
					break;
				}
				if (strcmp(p->data.DATE, newnode->data.DATE) < 0)
					//新结点插在原结点后面
					insert_behind(p, newnode);
				break;
			}
			else
			{
				if (strcmp(p->data.DATE, newnode->data.DATE) <0)
				{
					p = p->next;
					continue;
				}
				if (strcmp(p->data.DATE, newnode->data.DATE) == 0)
				{


					if (p->next == pp)
					{
						if (p->data.stime > newnode->data.stime)
							//新结点插在原结点前面
							insert_forward(p, newnode);
						if (p->data.stime <= newnode->data.stime)
							//新结点插在原结点后面
							insert_behind(p, newnode);
						break;
					}
					else
					{
						if (p->data.stime <= newnode->data.stime)
						{
							p = p->next;
						}
						if (p->data.stime > newnode->data.stime)
						{
							insert_forward(p, newnode);
							break;
						}
					}
				}
				if (strcmp(p->data.DATE, newnode->data.DATE) > 0)
				{
					insert_forward(p, newnode);
					break;
				}
			}
	}
	p = pp;
	pp = NULL;
	free(pp);
}

/**
  ***********************************
  *@brief  删除
  *@param  p : 头节点
  *@param  d : 需要删除的数据
  *@retval None
  ***********************************
  */
void link_del(plink_t p)
{
	plink_t head = p;

	plink_t node = NULL;

	int x = 0;
	char date[D];
	printf("请输入要删除的班期:>");
	scanf("%s", date);
	printf("请输入要删除的起飞时间:>");
	scanf("%d", &x);

	//找到该节点
	while (p->next != head) {
		node = p->next;
		if (node->data.stime == x && strcmp(node->data.DATE, date) == 0)
		{

			//剪切并删除该节点
			cut_node(node);
			node->prev = node;
			node->next = node;
			free(node);
			continue;
		}
		p = p->next;
	}
}

/**
  ***********************************
  *@brief  剪切
  *@param  node : 节点
  *@retval None
  ***********************************
  */
static void cut_node(plink_t node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
}
