#define _CRT_SECURE_NO_WARNINGS 1


#include "Book.h"

void Revise_Book_IBSN(LinkList L, char Ibsn)
{
	LinkList p = Find_by_IBSN(L, Ibsn);
	if (p == NULL)
	{
		cout << "�޸�ʧ�ܣ�δ�ҵ���Ԫ��\n";
		return;
	}
	cout << "�������޸ĺ��IBSN��>";
	cin.clear();		
	cin.ignore(9999,'\n');
	cin >> p->data.id;
	cout << "�޸ĳɹ�\n";
}

void Revise_Book_NAME(LinkList L, char NAME)
{
	LinkList p = Find_by_NAME(L, NAME);
	if (p == NULL)
	{
		cout << "�޸�ʧ�ܣ�δ�ҵ���Ԫ��\n";
		return;
	}
	cout << "�������޸ĺ��NAME��>";
	cin.clear();		
	cin.ignore(9999,'\n');
	cin >> p->data.name;
	cout << "�޸ĳɹ�\n";
}

void Revise_Book_PRICE(LinkList L, int PRICE)
{
	LinkList p = Find_by_PRICE(L, PRICE);
	if (p == NULL)
	{
		cout << "�޸�ʧ�ܣ�δ�ҵ���Ԫ��\n";
		return;
	}
	cout << "�������޸ĺ��PRICE��>";
	cin.clear();		
	cin.ignore(9999,'\n');
	cin >> p->data.price;
	cout << "�޸ĳɹ�\n";
}


