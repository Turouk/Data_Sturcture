#define _CRT_SECURE_NO_WARNINGS 1

#include "Book.h"

void Insert_Book(LinkList& L, int n)
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

	if (p == NULL)
	{
		cout << "����ʧ��\n";
	}
	else
	{
		LinkList s = new LNode;
		cout << "������Ҫ�������Ϣ��>";
		cin.clear();
		cin.ignore();
		cin >> p->data.id >> p->data.name >> p->data.price;
		s->next = p->next;
		p->next = s;
	}
}