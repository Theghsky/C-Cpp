/* 双向循环链表 的  增删改查  */
#include "link.h"
#include <stdlib.h>

/**
  ***********************************
  *@brief  一个节点node插在p的后面
  *@param  p  node : 节点
  *@retval None
  ***********************************
  */
static void insert_behind(plink_t p,plink_t node)
{
	node->next = p->next;
	node->prev = p;
	p->next->prev = node;
	p->next = node;
}

/**
  ***********************************
  *@brief  一个节点node插在p的前面
  *@param  p  node : 节点
  *@retval None
  ***********************************
  */
static void insert_forward(plink_t p,plink_t node)
{
	node->next = p;
	node->prev = p->prev;
	p->prev->next = node;
	p->prev = node;
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

/**
  ***********************************
  *@brief  new替换old
  *@param  old new 节点
  *@retval None
  ***********************************
  */
static void replace(plink_t old,plink_t new)
{
	new->next = old->next;
	new->prev = old->prev;
	new->next->prev = new;
	new->prev->next = new;
}



/**
  ***********************************
  *@brief  初始化 (创建头节点)
  *@param  p : 头节点
  *@retval None
  ***********************************
  */
void link_init(plink_t *p)
{
	*p=(plink_t)malloc(sizeof(link_t));
	if(*p==NULL){
		perror("malloc error");
		return;
	}
	
	(*p)->prev = (*p);
	(*p)->next = (*p);
}  

/**
  ***********************************
  *@brief  头插
  *@param  p : 头节点
  *@retval None
  ***********************************
  */
void link_add_head(plink_t p,datatype d)
{
	//创建新的节点
	plink_t node = NULL;
	link_init(&node);
	if(node==NULL)
		return;
	node->data = d;
	
	//将新的节点插在头的后面
	insert_behind(p,node);
}

/**
  ***********************************
  *@brief  尾插
  *@param  p : 头节点
  *@retval None
  ***********************************
  */
void link_add_tail(plink_t p,datatype d)
{
	//创建新的节点
	plink_t node = NULL;
	link_init(&node);
	if(node==NULL)
		return;
	node->data = d;

	//将新的节点插在头的前面
	insert_forward(p,node);
}


/**
  ***********************************
  *@brief  删除
  *@param  p : 头节点
  *@param  d : 需要删除的数据
  *@retval None
  ***********************************
  */
void link_del(plink_t p,datatype d)
{
	plink_t head = p;
	
	plink_t node = NULL;
	
	//找到该节点
	while(p->next!=head){
		node = p->next;
		if(node->data == d){
			
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
  *@brief  替换
  *@param  p : 头节点
  *@param  d : 需要删除的数据
  *@retval None
  ***********************************
  */
void link_update(plink_t p,datatype old,datatype new)
{
	plink_t head = p;
	plink_t node = NULL;
	plink_t new_node = NULL;
	
	//遍历寻找old
	while(p->next!=head){
		node = p->next;
		if(node->data == old){
			
			//找到后，创建新的节点new
			link_init(&new_node);
			if(new_node==NULL)
				return;
			new_node->data = new;
			
			//新的节点替换old
			replace(node,new_node);
			
			//释放old
			node->prev = node;
			node->next = node;
			free(node);
		}
		
		p = p->next;
	}
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
	
	printf("正序遍历结果为：");
	while(p->next!=head){
		p = p->next;
		printf("%d ",p->data);
	}
	printf("\n");
	
}


/**
  ***********************************
  *@brief  逆序遍历
  *@param  p : 头节点
  *@retval None
  ***********************************
  */
void pre_display(plink_t p)
{
	plink_t head = p;
	
	printf("逆序遍历结果为：");
	while(p->prev!=head){
		p = p->prev;
		printf("%d ",p->data);
	}
	printf("\n");
	
}





