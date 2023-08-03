#define _CRT_SECURE_NO_WARNINGS 1
#include "Book.h"

LNode* Find_by_IBSN(LinkList L,char ISBN)
{
	LinkList p;
	p = L->next;
	while (p && *p->data.id != ISBN)
	{
		p = p->next;
	}
	return p;
}

LNode* Find_by_NAME(LinkList L,char NAME)
{
	LinkList p;
	p = L->next;
	while (p && *p->data.name != NAME)
	{
		p = p->next;
	}
	return p;
}

LNode* Find_by_PRICE(LinkList L, int PRICE)
{
	LinkList p;
	p = L->next;
	while (p && p->data.price != PRICE)
	{
		p = p->next;
	}
	return p;
}