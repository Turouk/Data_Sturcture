#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//#define OK 1
//#define ERROR 0
//#define Maxsize 100
//
//typedef int Status;
//
//typedef struct
//{
//	char* base;
//	char* top;
//	int stacksize;
//}SqStack;
//
//void Init(SqStack& s)
//{
//	s.base = new char[Maxsize];
//	if (!s.base)
//		exit(-1);
//	s.top = s.base;
//	s.stacksize = Maxsize;
//}
//
//Status Push(SqStack &s, char ch)
//{
//	if (s.top - s.base == s.stacksize)
//		return ERROR;
//	*s.top++ = ch;
//	return OK;
//}
//
//char GetTop(SqStack s)
//{
//	if (s.top != s.base)
//		return *(s.top - 1);
//}
//
//Status Pop(SqStack& s)
//{
//	if (s.top == s.base)
//		return ERROR;
// char ch;
//	ch =*(--s.top);
//	return OK;
//}
//
//Status Matching(SqStack &s,char ch[])
//{
//	int i = 0;
//	while (i < strlen(ch))
//	{
//		switch (ch[i])
//		{
//		case '(':
//		case '[':
//			Push(s, ch[i]);
//			break;
//
//		case ')':
//			if (!(s.base == s.top) && GetTop(s) == '(')
//			{
//				Pop(s);
//				break;
//			}
//			else
//				return ERROR;		
//
//		case ']':
//			if (!(s.base == s.top) && GetTop(s) == '[')
//			{
//				Pop(s);
//				break;
//			}
//			else
//				return ERROR;
//
//		}
//		i++;
//	}
//	if (s.base == s.top)
//		return OK;
//}
//
//int main()
//{
//	SqStack s;
//	Init(s);
//	cout << "ÇëÊäÈë×Ö·û£º>";
//	char ch[20];
//	cin >> ch;
//
//	if (Matching(s, ch))
//	{
//		cout << "Æ¥ÅäÕýÈ·";
//	}
//	else
//	{
//		cout << "Æ¥Åä´íÎó";
//	}
//
//	return 0;
//}

typedef struct StackNode
{
	char data;
	struct StackNode* next;
}StackNode, * LinkStack;

void Init(LinkStack& s)
{
	s = NULL;
}

int Push(LinkStack& s, char ch)
{
	LinkStack p = new StackNode;
	p->data = ch;
	p->next = s;
	s = p;
	return 1;

}

char GetTop(LinkStack s)
{
	if (s!=NULL)
		return s->data;
}

int Pop(LinkStack& s, char &ch)
{
	if (s == NULL)
		return 0;
	ch = s->data;
	LinkStack p = s;
	s = s->next;
	delete p;
	return 1;
}

int Matching(LinkStack &s,char ch[])
{
	int i = 0;
	int flag = 1;
	while (i<strlen(ch))
	{
		switch (ch[i])
		{
		case '(':
		case '[':
			Push(s, ch[i]);
			break;
		case ')':
			if (GetTop(s) == '(' && s != NULL)
			{
				Pop(s, ch[i]);
				break;
			}
			else
			{
				flag = 0;
				return 0;
			}
		case ']':
			if (GetTop(s) == '[' && s != NULL)
			{
				Pop(s, ch[i]);
				break;
			}
			else
			{
				flag = 0;
				return 0;
			}
				
		}
		i++;
	}

	if (s==NULL&&flag)
		return 1;
	else
		return 0;

}

int main()
{
	char ch[20];
	cout << "ÇëÊäÈë×Ö·û£º>";
	cin >> ch;
	LinkStack s;
	Init(s);

	if (Matching(s, ch))
	{
		cout << "Æ¥Åä³É¹¦";
	}
	else
	{
		cout << "Æ¥ÅäÊ§°Ü";
	}

	return 0;

}