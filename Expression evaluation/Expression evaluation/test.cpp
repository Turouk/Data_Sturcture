#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>

using namespace std;

typedef struct StackNode
{
	char data;
	struct StackNode* next;
}StackNode, * LinkStack;

int In(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/'|| ch == '(' || ch == ')' || ch == '#' )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char Precede(char a, char b)
{
	char f = 0;
	if (a == '+' || a == '-')
	{
		if (b == '+' || b == '-' || b == ')' || b == '#')
			f = '>';
		else if (b == '*' || b == '/' || b == '(')
			f = '<';
	}
	else if (a == '*' || a == '/')
	{
		if (b == '+' || b == '-' || b == '*' || b == '/' || b == ')' || b == '#')
			f = '>';
		else if (b == '(')
			f = '<';
	}
	else if (a == '(')
	{
		if (b == '+' || b == '-' || b == '*' || b == '/' || b == '(')
			f = '<';
		else if (b == ')')
			f = '=';
	}
	else if (a == ')')
	{
		if (b == '+' || b == '-' || b == '*' || b == '/' || b == ')' || b == '#')
			f = '>';
	}
	else if (a == '#')
	{
		if (b == '+' || b == '-' || b == '*' || b == '/' || b == '(')
			f = '<';
		else if (b == '#')
			f = '=';
	}
	return f;
}

char Operate(char a, char theta, char b)
{
	char c = 0;
	a = a - '0';
	b = b - '0';
	if (theta == '+')
		c = a + b + '0';
	else if (theta == '-')
		c = a - b + '0';
	else if (theta == '*')
		c = a * b + '0';
	else if (theta == '/')
		c = a / b + '0';
	return c;
}

void Init(LinkStack& S)
{
	S = NULL;
}

void Push(LinkStack& s, char ch)
{
	LinkStack p = new StackNode;
	p->data = ch;
	p->next = s;
	s = p;
}

char Pop(LinkStack& s)
{
	if (s == NULL)
		return 0;
	char theta = s->data;
	LinkStack p = s;
	s = s->next;
	delete p;
	return theta;
}

char GetTop(LinkStack s)
{
	if (s != NULL)
		return s->data;
}

int EvaluateExpression()
{
	LinkStack OPND;
	LinkStack OPTR;

	Init(OPND);
	Init(OPTR);

	Push(OPTR, '#');

	char ch, theta, a, b, x;
	cin >> ch;

	while (ch!='#'||GetTop(OPTR)!='#')
	{
		if (!In(ch))
		{
			Push(OPND, ch);
			cin >> ch;
		}
		else
		{
			switch (Precede(GetTop(OPTR),ch))
			{
			case '<':
				Push(OPTR, ch);
				cin >> ch;
				break;
			case '>':
				theta = Pop(OPTR);
				a = Pop(OPND);
				b = Pop(OPND);
				Push(OPND, Operate(b, theta, a));
				break;
			case '=':
				x = Pop(OPTR);
				cin >> ch;
				break;
			}
		}
	}
	return GetTop(OPND)-'0';
}



int main()
{
	cout << "请输入表达式的值，以‘#’结束\n";
	cout << "例如：\t5*(4-3)\t\n";
	cout << "运行结果是：>" << EvaluateExpression();

	return 0;
}