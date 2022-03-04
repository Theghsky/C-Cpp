#pragma once
#define  _CRT_SECURE_NO_WARNINGS

#define max 100

#define max_name 20
#define max_sex 5
#define max_tele 12
#define max_addr 30

#include<stdio.h>
#include<string.h>

enum Option
{
	exit,
	add,
	del,
	search,
	modify,
	show,
	sort
};

struct People
{
	char name[max_name];
	int age;
	char  sex[max_sex];
	char tele[max_tele];
	char addr[max_addr];
};

//通讯录类型
struct Contact
{
	struct People data[max];//存放一个信息
	int size;//记录当前已经有的个数
};

//函数声明
//初始化
void InitContact(struct Contact* ps);
//增加
void AddContact(struct Contact* ps);
//显示
void ShowContact(const struct Contact* ps);
//删除指定的联系人
void DelContact(struct Contact* ps);
//查找指定人信息
void SearchContact(const struct Contact* ps);
//修改指定联系人
void ModifyContact(struct Contact* ps);
//排序
void SortContact(struct Contact* ps);