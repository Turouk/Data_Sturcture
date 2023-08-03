#define _CRT_SECURE_NO_WARNINGS 1

#include"Book.h"

void Delete_Book(LinkList& L, int n)
{
	LinkList p = L;
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		if (p == NULL)
		{
			break;
		}
		p = p->next;
	}

	if (p->next == NULL)
	{
		cout << "É¾³ýÊ§°Ü\n";
		return;
	}
	else
	{
		LinkList q = p->next;
		p->next = q->next;
		free(q);
		q = NULL;
		cout << "É¾³ý³É¹¦\n";
		return;
	}
}