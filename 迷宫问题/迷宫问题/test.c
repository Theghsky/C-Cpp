#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
typedef struct Position
{
    int row;//行
    int col;//列
}PT;
///////////////////////////////////////////////////////////
typedef PT STDataType;

typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}ST, Stack;

void StackInit(ST* ps);
void StackDestory(ST* ps);
// 入栈
void StackPush(ST* ps, STDataType x);
// 出栈
void StackPop(ST* ps);
STDataType StackTop(ST* ps);

int StackSize(ST* ps);
bool StackEmpty(ST* ps);

void StackInit(ST* ps)
{
    assert(ps);

    ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
    if (ps->a == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }

    ps->capacity = 4;
    ps->top = 0;
}

void StackDestory(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = ps->capacity = 0;
}

// 入栈
void StackPush(ST* ps, STDataType x)
{
    assert(ps);

    // 满了-》增容
    if (ps->top == ps->capacity)
    {
        STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
        if (tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        else
        {
            ps->a = tmp;
            ps->capacity *= 2;
        }
    }

    ps->a[ps->top] = x;
    ps->top++;
}

// 出栈
void StackPop(ST* ps)
{
    assert(ps);
    // 栈空了，调用Pop，直接中止程序报错
    assert(ps->top > 0);

    //ps->a[ps->top - 1] = 0;
    ps->top--;
}

STDataType StackTop(ST* ps)
{
    assert(ps);
    // 栈空了，调用Top，直接中止程序报错
    assert(ps->top > 0);

    return ps->a[ps->top - 1];
}

int StackSize(ST* ps)
{
    assert(ps);

    return ps->top;
}

bool StackEmpty(ST* ps)
{
    assert(ps);

    return ps->top == 0;
}

Stack path;
Stack minpath;
///////////////////////////////////////////////////////////

//打印迷宫
void Print(int** a, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void PrintPath(Stack* ps)
{
    //path 数据倒到rpath
    Stack rpath;
    StackInit(&rpath);
    while (!StackEmpty(&path))
    {
        StackPush(&rpath, StackTop(&path));
        StackPop(&path);
    }

    while (!StackEmpty(&rpath))
    {
        PT top = StackTop(&rpath);
        printf("(%d,%d)\n", top.row, top.col);
        StackPop(&rpath);
    }
    StackDestory(&rpath);
}

//判断能不能走
bool IsPass(int** maze, int n, int m, PT p)
{
    if (p.row >= 0 && p.row < n
        && p.col >= 0 && p.col < m
        && maze[p.row][p.col] == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//默认[0，0]，是入口，[n-1,m-1]是出口
bool GetMazePath(int** maze, int n, int m, PT cur)
{
    StackPush(&path, cur);

    //如果走到出口
    if (cur.row == n - 1 && cur.col == m - 1)
        return true;

    //探测上下左右四个方向
    PT next;
    maze[cur.row][cur.col] = 2;

    //上
    next = cur;
    next.row -= 1;
    if (IsPass(maze, n, m, next))
    {
        if (GetMazePath(maze, n, m, next))
            return true;
    }

    //下
    next = cur;
    next.row += 1;
    if (IsPass(maze, n, m, next))
    {
        if (GetMazePath(maze, n, m, next))
            return true;
    }

    //左
    next = cur;
    next.col -= 1;
    if (IsPass(maze, n, m, next))
    {
        if (GetMazePath(maze, n, m, next))
            return true;
    }

    //右
    next = cur;
    next.col += 1;
    if (IsPass(maze, n, m, next))
    {
        if (GetMazePath(maze, n, m, next))
            return true;
    }

    StackPop(&path);

    return false;
}

int main()
{
    int n = 0, m = 0;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        //创建迷宫，获取迷宫地图
        //动态开辟二维数组
        int** maze = (int**)malloc(sizeof(int*) * n);
        for (int i = 0; i < n; ++i)
        {
            maze[i] = (int*)malloc(sizeof(int) * m);
        }

        //二维数组的输入
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &maze[i][j]);
            }
        }

       // Print(maze, n, m);
        StackInit(&path);
        PT entry = { 0,0 };
        if (GetMazePath(maze, n, m, entry))
        {
            PrintPath(&path);
        }
        else
        {
            printf("找不到路");
        }

        StackDestory(&path);

        for (int i = 0; i < n; ++i)
        {
            free(maze[i]);
        }
        free(maze);
        maze = NULL;
    }
    return 0;
}