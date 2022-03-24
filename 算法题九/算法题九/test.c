
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//
//有效字符串需满足：
//
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/valid-parentheses
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

//难度：简单

//示例 1：
//
//输入：s = "()"
//输出：true
//示例 2：
//
//输入：s = "()[]{}"
//输出：true
//示例 3：
//
//输入：s = "(]"
//输出：false
//示例 4：
//
//输入：s = "([)]"
//输出：false
//示例 5：
//
//输入：s = "{[]}"
//输出：true

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;

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

bool isValid(char* s)
{
	ST st;
	StackInit(&st);
	while (*s != '\0')
	{
		switch (*s)
		{
		case '{':
		case '[':
		case '(':
		{
			StackPush(&st, *s);
			++s;
			break;
		}
		case '}':
		case ']':
		case ')':
		{
			if (StackEmpty(&st))
			{
				StackDestory(&st);
				return false;
			}

			char top = StackTop(&st);
			StackPop(&st);

			//不匹配
			if ((*s == '}' && top != '{')
				|| (*s == ']' && top != '[')
				|| (*s == ')' && top != '('))
			{
				StackDestory(&st);
				return false;
			}
			else//匹配
			{
				++s;
			}
			break;
		}
		default:
			break;
		}
	}

	bool ret = StackEmpty(&st);
	StackDestory(&st);
	return ret;
}
