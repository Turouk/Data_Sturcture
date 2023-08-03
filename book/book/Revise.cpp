#define _CRT_SECURE_NO_WARNINGS 1


#include "Book.h"

void Revise_Book_IBSN(LinkList L, char Ibsn)
{
	LinkList p = Find_by_IBSN(L, Ibsn);
	if (p == NULL)
	{
		cout << "修改失败，未找到该元素\n";
		return;
	}
	cout << "请输入修改后的IBSN：>";
	cin.clear();		
	cin.ignore(9999,'\n');
	cin >> p->data.id;
	cout << "修改成功\n";
}

void Revise_Book_NAME(LinkList L, char NAME)
{
	LinkList p = Find_by_NAME(L, NAME);
	if (p == NULL)
	{
		cout << "修改失败，未找到该元素\n";
		return;
	}
	cout << "请输入修改后的NAME：>";
	cin.clear();		
	cin.ignore(9999,'\n');
	cin >> p->data.name;
	cout << "修改成功\n";
}

void Revise_Book_PRICE(LinkList L, int PRICE)
{
	LinkList p = Find_by_PRICE(L, PRICE);
	if (p == NULL)
	{
		cout << "修改失败，未找到该元素\n";
		return;
	}
	cout << "请输入修改后的PRICE：>";
	cin.clear();		
	cin.ignore(9999,'\n');
	cin >> p->data.price;
	cout << "修改成功\n";
}


