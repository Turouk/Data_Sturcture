
#define _CRT_SECURE_NO_WARNINGS 1

#include"Book.h"

int Count_Book(LinkList L)
{
	LinkList p = L->next;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}