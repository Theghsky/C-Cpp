#define  _CRT_SECURE_NO_WARNINGS

#include"contact.h"

void InitContact(Contact* ps)
{
	ps->data = ((People*)malloc(3 * sizeof(People)));
	if (ps->data == NULL)
	{
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;
}

void CheckCapacity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		//增容
		People* ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(People));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
	}
}

void  AddContact(struct Contact* ps)
{
	//检测当前通讯录的容量
	//1.如果满了就增加空间
	//2.如果没满啥事不干
	CheckCapacity(ps);
	//增加数据
	printf("请输入名字:>");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入年龄:>");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入性别:>");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入手机:>");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址:>");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;
	printf("添加成功\n");
	
}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		for (i = 0; i < ps->size; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

//找到了返回名字所在元素的下标，找不到返回-1
static int FindByName(const struct Contact* ps, char name[max_name])
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;//找到了
		}
	}
	return -1;//找不到
}

void DelContact(struct Contact* ps)
{
	char name[max_name];
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//查找要删除的人在什么位置
	int ret = FindByName(ps, name);
	if (-1 == ret)
	{
		printf("要删除的人不存在\n");
	}
	//删除
	else
	{
		//删除数据
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[max_name];
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[ret].name,
			ps->data[ret].age,
			ps->data[ret].sex,
			ps->data[ret].tele,
			ps->data[ret].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[max_name];
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int ret = FindByName(ps, name);
	if (ret == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[ret].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ret].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[ret].sex);
		printf("请输入手机:>");
		scanf("%s", ps->data[ret].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[ret].addr);

		printf("修改完成\n");
	}
}

void SortContact(struct Contact* ps)
{
	int i = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		int j = 0;
		for (j = 0; j < ps->size - 1; j++)
		{
			if (ps->data[j].age > ps->data[j + 1].age)
			{
				struct People pot = ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = pot;
			}
		}
	}
	printf("排序完成\n");
}

void Destroy(Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}