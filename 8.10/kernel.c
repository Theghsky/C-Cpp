
/* 内核链表的 增删改查操作 */
#include "kernel.h"


/**
  ***********************************
  *@brief  初始化
  *@param  p  头节点
  *@retval None
  ***********************************
  */
void kernel_init(pkernel_t *p)
{
	*p = (pkernel_t)malloc(sizeof(kernel_t));
	if(*p==NULL){
		perror("malloc error");
		return;
	}
	
	INIT_LIST_HEAD(&(*p)->list);
}



/**
  ***********************************
  *@brief  尾插
  *@param  p  头节点
  *@param  d  数据
  *@retval None
  ***********************************
  */
void kernel_add_tail(pkernel_t p,datatype d)
{
	//创建新的节点
	pkernel_t node = NULL;
	kernel_init(&node);
	if(node==NULL)
		return;
	node->data = d;
	
	//将新的节点插入到头的前面
	list_add_tail(&node->list, &p->list);
}


/**
  ***********************************
  *@brief  删除
  *@param  p  头节点
  *@param  d  数据
  *@retval None
  ***********************************
  */
void kernel_del(pkernel_t p,datatype d)
{
	struct list_head *pos = NULL;
	pkernel_t node = NULL;
	/*
		@pos  ： for循环中的中间遍历，类型为：struct list_head *
		@head ： 头节点的小结构体指针类型   ：struct list_head *
	*/
	//遍历寻找
	//for (pos = (head)->next; pos != (head); pos = pos->next)
	list_for_each(pos, &p->list)
	{
		
		/*
			@ptr  ： 外面传进来的小结构指针
			@type ： 大结构的类型
			@member：小结构在大结构体中的名字
		*/
		node = list_entry(pos,typeof(*p),list);
		if(node->data == d){
			pos = pos->prev;
			
			//将其剪切
			list_del_init(&node->list);
			free(node);
		}
	}
}



/**
  ***********************************
  *@brief  正序遍历
  *@param  p  头节点
  *@retval None
  ***********************************
  */
void display(pkernel_t p)
{
	pkernel_t pos = NULL;
	printf("正序遍历的结果为：");
	/*
		@pos  for循环中的中间遍历，类型为：大结构指针类型
		@head ： 头节点的小结构体指针类型   ：struct list_head *
		@member：小结构在大结构体中的名字
	*/
	 list_for_each_entry(pos,&p->list,list)
		 printf("%d ",pos->data);

	printf("\n");
}









