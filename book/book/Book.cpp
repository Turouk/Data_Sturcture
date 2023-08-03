#define _CRT_SECURE_NO_WARNINGS 1
#include"Book.h"



void meue()
{
	cout << "*******************************************************" << endl;
	cout << "********       1.Find     2.Insert    *****************" << endl;
	cout << "********       3.Delete   4.Revise    *****************" << endl;
	cout << "********       5.Sort     6.Count     *****************" << endl;
	cout << "********       7.Print    0.Exit      *****************" << endl;
	cout << "*******************************************************" << endl;
}

void meue1()
{
	cout << "*******************************************************" << endl;
	cout << "********          1.按IBSN查找        *****************" << endl;
	cout << "********        2.按书名查找查找      *****************" << endl;
	cout << "********          3.按价格查找        *****************" << endl;
	cout << "********             0.退出           *****************" << endl;
	cout << "*******************************************************" << endl;
}

void meue2()
{
	cout << "*******************************************************" << endl;
	cout << "********           1.修改IBSN         *****************" << endl;
	cout << "********           2.修改书名         *****************" << endl;
	cout << "********           3.修改价格         *****************" << endl;
	cout << "********             0.退出           *****************" << endl;
	cout << "*******************************************************" << endl;
}

void meue3()
{
	cout << "*******************************************************" << endl;
	cout << "********       1.根据IBSN排序         *****************" << endl;
	cout << "********       2.根据书名排序         *****************" << endl;
	cout << "********       3.根据价格排序         *****************" << endl;
	cout << "********           0.退出             *****************" << endl;
	cout << "*******************************************************" << endl;
}



void printList(LinkList L) {
	LinkList p = L->next;
	printf("\n");
	while (p != NULL)
	{
		cout << left << setw(20) << p->data.id << left << setw(20) << p->data.name << left << setw(5) << p->data.price << endl;
		p = p->next;
	}
}

LinkList CreatBook(int n)
{
	LinkList L = new LNode;
	LinkList p;
	LinkList r;

	r = L;
	for (int i = 0; i < n; ++i)
	{
		p = new LNode;
		cin >> p->data.id;
		cin >> p->data.name;
		cin >> p->data.price;
		p->next = NULL;
		r->next = p;
		r = p;
	}

	return L;
}


void FindBook(LinkList L)
{
	
	LinkList r;
	meue1();
	int input = 0;

	do
	{
		cout << "请选择查找方式：>";
		cin >> input;
		switch (input)
		{
		case IBSN:	
			cout << "请输入IBSN：>";
			char Ibsn;
			cin >> Ibsn;
			r=Find_by_IBSN(L, Ibsn);
			cout <<left<<setw(20)<< r->data.id <<left<<setw(20)<< r->data.name <<left<<setw(5)<< r->data.price <<endl;
			break;
		case Name:
			cout << "请输入书名：>";
			char NAME;
			cin >> NAME;
			r = Find_by_NAME(L, NAME);
			cout << left << setw(20) << r->data.id << left << setw(20) << r->data.name << left << setw(5) << r->data.price <<endl;
			break;
		case Price:
			cout << "请输入价格：>";
			int PRICE;
			cin >> PRICE;
			r = Find_by_PRICE(L, PRICE);
			cout << left << setw(20) << r->data.id << left << setw(20) << r->data.name << left << setw(5) << r->data.price<<endl;
			break;
		case EXIT:
			cout << "退出\n";
			break;
		default:
			cout << "操作错误，请重新选择\n";
			break;
		}
		cin.clear();
		cin.ignore(9999,'\n');
	} while (input);
}

void InsertBook(LinkList& L)
{
	int input = 0;
	cout << "请选择在第几行插入书籍信息\n";
	cin >> input;
	Insert_Book(L, input);

}

void DeleteBook(LinkList& L)
{
	int input = 0;
	cout << "请选择删除第几行的书籍信息\n";
	cin >> input;
	Delete_Book(L, input);

}

void ReviseBook(LinkList& L)
{
	meue2();
	int input = 0;

	do
	{
		cout << "请选择修改方式：>";
		cin >> input;
		switch (input)
		{
		case IBSN:
			cout << "请输入要修改的IBSN：>";
			char Ibsn;
			cin >> Ibsn;
			Revise_Book_IBSN(L, Ibsn);
			break;
		case Name:
			cout << "请输入要修改的书名：>";
			char NAME;
			cin >> NAME;
		    Revise_Book_NAME(L, NAME);
			break;
		case Price:
			cout << "请输入要修改的价格：>";
			int PRICE;
			cin >> PRICE;
			Revise_Book_PRICE(L, PRICE);
			break;
		case EXIT:
			cout << "退出\n";
			break;
		default:
			cout << "操作错误，请重新选择\n";
			break;
		}
		cin.clear();
		cin.ignore(9999, '\n');
	} while (input);
}


void CountBook(LinkList L)
{
	int count = Count_Book(L);
	cout << "链表元素个数为：>" << count << endl;
}

void SortBook(LinkList L)
{
	meue3();
	int input = 0;

	do
	{
		cout << "请选择排序方式：>";
		cin >> input;
		switch (input)
		{
		case IBSN:
			Sort_Book_IBSN(L);
			break;
		case Name:
			Sort_Book_NAME(L);
			break;
		case Price:
			Sort_Book_PRICE(L);
			break;
		case EXIT:
			cout << "退出\n";
			break;
		default:
			cout << "操作错误，请重新选择\n";
			break;
		}
	} while (input);
}