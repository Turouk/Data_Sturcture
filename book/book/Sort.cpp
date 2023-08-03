#define _CRT_SECURE_NO_WARNINGS 1

#include "Book.h"

void Sort_Book_IBSN(LinkList L)
{
	int count = Count_Book(L);
	int i = 0;
	for (i = 0; i < count - 1; i++)
	{
		int num = count - 1 - i;
		LinkList p = L->next;
		LinkList q = p->next;
		LinkList tail = L;

		while (num--)
		{
			if (strcmp(p->data.id, q->data.id) > 0) 
			{
				p->next = q->next;
				q->next = p;
				tail->next = q;
			}
			tail = tail->next;
			p = tail->next;
			q = p->next;
		}
	}
}
void Sort_Book_NAME(LinkList L)
{
	int count = Count_Book(L);
	int i = 0;
	for (i = 0; i < count - 1; i++)
	{
		int num = count - 1 - i;
		LinkList p = L->next;
		LinkList q = p->next;
		LinkList tail = L;

		while (num--)
		{
			if (strcmp(p->data.name, q->data.name) > 0)
			{
				p->next = q->next;
				q->next = p;
				tail->next = q;
			}
			tail = tail->next;
			p = tail->next;
			q = p->next;
		}
	}
}
void Sort_Book_PRICE(LinkList L)
{

	int count = Count_Book(L);
	int i = 0;
	for (i = 0; i < count - 1; i++)
	{
		int num = count - 1 - i;
		LinkList p = L->next;
		LinkList q = p->next;
		LinkList tail = L;

		while (num--)
		{
			if (p->data.price > q->data.price)
			{
				p->next = q->next;
				q->next = p;
				tail->next = q;
			}
			tail = tail->next;
			p = tail->next;
			q = p->next;
		}
	}
}