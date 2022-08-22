
#include "stack.h"
#include <stdlib.h>

/**
  ***********************************
  *@brief  入栈
  *@param  p : 栈顶指针
  *@param  d : 数据
  *@retval int
  *			成功返回0
  *			失败返回-1
  ***********************************
  */
int push(plink_t *p,datatype d)
{
	//创建新的节点 
	plink_t node = (plink_t)malloc(sizeof(link_t));
	if(node==NULL){
		perror("malloc error");
		return -1;
	}
	
	//数据域赋值
	node->data = d;
	
	//指针域 赋值，指向 栈顶指针
	node->next = *p;
	
	//栈顶指针 指向刚刚添加的 节点 
	*p = node;
	
	return 0;
	
}


/**
  ***********************************
  *@brief  出栈
  *@param  p : 栈顶指针
  *@param  d : 数据
  *@retval int
  *			成功返回0
  *			失败返回-1
  ***********************************
  */
int pop(plink_t *p,datatype *d)
{
	//判断是否栈空
	if(*p==NULL){
		printf("sorry!栈空\n");
		return -1;
	}
	
	//将top指向的节点的数据域 传出
	*d = (*p)->data;
	
	//将当前top指向的节点保存node
	plink_t node = *p;
	
	//栈顶指针top往后移动
	(*p) = (*p)->next;
	
	//node释放
	node->next = NULL;
	free(node);
	
	return 0;
}


/**
  ***********************************
  *@brief  遍历
  *@param  p : 栈顶指针
  *@retval int
  *			成功返回0
  *			失败返回-1
  ***********************************
  */
void display(plink_t p)
{
	printf("遍历结果为:\n");
	while(p!=NULL){
		printf("| %d |\n",p->data);
		p = p->next;
	}
	printf("\n"); 
} 
 






