
#include "stack.h"
#include <stdlib.h>

/**
  ***********************************
  *@brief  初始化
  *@param  None
  *@retval None
  ***********************************
  */
pstack_t stack_init(void)
{
	pstack_t p = (pstack_t)malloc(sizeof(stack_t));
	if (p == NULL) {
		perror("malloc error");
		return NULL;
	}

	p->top = -1;
	return p;
}

/**
  ***********************************
  *@brief  入栈
  *@param  p : 栈
  *@param  d : 数据
  *@retval int
  *			成功返回0
  *			失败返回-1
  ***********************************
  */
int push(pstack_t p, datatype d)
{
	//判断是否 栈满
	if (p->top == N - 1) {
		printf("sorry!满客！\n");
		return -1;
	}

	p->top++;
	p->data[p->top] = d;
	return 0;
}

/**
  ***********************************
  *@brief  出栈
  *@param  p : 栈
  *@param  d : 数据的地址
  *@retval int
  *			成功返回0
  *			失败返回-1
  ***********************************
  */
int pop(pstack_t p, datatype* d)
{
	//判断是否 栈空
	if (p->top == -1) {
		printf("sorry!,没客！\n");
		return -1;
	}

	*d = p->data[p->top];
	p->top--;
	return 0;
}


/**
  ***********************************
  *@brief  遍历
  *@param  p : 栈
  *@retval None
  ***********************************
  */
void display(pstack_t p)
{
	int i;
	printf("遍历结果为：\n");
	for (i = p->top; i >= 0; i--)
		printf("| %d |\n", p->data[i]);
	printf("\n");
}




