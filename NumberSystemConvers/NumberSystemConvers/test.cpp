#define _CRT_SECURE_NO_WARNINGS 1
//将十进制数转换为八进制数
#define MAXSIZE 100;

#include <iostream>
using namespace std;

//typedef struct {
//	int* base;
//	int* top;
//	int stacksize;
//}SqStack;
//
//void InitStack(SqStack &s)
//{
//	s.base = new int[100];
//	if (!s.base)
//	{
//		return;
//	}
//
//	s.top = s.base;
//	s.stacksize = MAXSIZE;
//	return;
//}
//
//void Push(SqStack& s, int n)
//{
//	if (s.top - s.base == s.stacksize)
//		return;
//	*s.top++ = n;
//	return;
//}
//
//int Pop(SqStack& s,int i)
//{
//	if (s.top == s.base)
//	{
//		return 0;
//	}
//		
//	i = *--s.top;
//	return i;
//}
//
//void conversion(SqStack s)
//{
//	cout << "请输入一个十进制数的值：>";
//	int N = 0;
//	cin >> N;
//	while (N)
//	{
//		Push(s, N % 8);
//		N = N / 8;
//	}
//	cout << "转换后的八进制数为：>";
//	while (!(s.base==s.top))
//	{
//		int i = 0;
//		int pos = Pop(s,i);
//		cout << pos ;
//	}
//}
//
//int main()
//{
//	SqStack s ;
//	InitStack(s);
//
//	conversion(s);
//	cout << endl;
//	system("pause");
//	return 0;
//}


typedef struct StackNode
{
	int data;
	struct StackNode* next;
}StackNode,*LinkStack;

void Push(LinkStack& s, int n)
{
	LinkStack p = new StackNode;
	p->data = n;
	p->next = s;
	s = p;
}

int Pop(LinkStack& s, int n)
{
	if (s == NULL)
		return 0;
	n = s->data;
	LinkStack p = s;
	s = s->next;
	delete p;
	return n;
}

void conversion(LinkStack s)
{
	cout << "请输入一个十进制的数：>";
	int N = 0;;
	cin >> N;

	while (N)
	{
		Push(s, N % 8 );
		N = N / 8;
	}

	cout << "转换后的八进制数字为：>";
	while (!(s == NULL))
	{
		int i = 0;
		i = Pop(s, i);
		cout << i;
	}
}

int main()
{
	LinkStack s = NULL;
	
	conversion(s);
	cout << endl;

	system("pause");
	return 0;
}