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
	cout << "********          1.��IBSN����        *****************" << endl;
	cout << "********        2.���������Ҳ���      *****************" << endl;
	cout << "********          3.���۸����        *****************" << endl;
	cout << "********             0.�˳�           *****************" << endl;
	cout << "*******************************************************" << endl;
}

void meue2()
{
	cout << "*******************************************************" << endl;
	cout << "********           1.�޸�IBSN         *****************" << endl;
	cout << "********           2.�޸�����         *****************" << endl;
	cout << "********           3.�޸ļ۸�         *****************" << endl;
	cout << "********             0.�˳�           *****************" << endl;
	cout << "*******************************************************" << endl;
}

void meue3()
{
	cout << "*******************************************************" << endl;
	cout << "********       1.����IBSN����         *****************" << endl;
	cout << "********       2.������������         *****************" << endl;
	cout << "********       3.���ݼ۸�����         *****************" << endl;
	cout << "********           0.�˳�             *****************" << endl;
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
		cout << "��ѡ����ҷ�ʽ��>";
		cin >> input;
		switch (input)
		{
		case IBSN:	
			cout << "������IBSN��>";
			char Ibsn;
			cin >> Ibsn;
			r=Find_by_IBSN(L, Ibsn);
			cout <<left<<setw(20)<< r->data.id <<left<<setw(20)<< r->data.name <<left<<setw(5)<< r->data.price <<endl;
			break;
		case Name:
			cout << "������������>";
			char NAME;
			cin >> NAME;
			r = Find_by_NAME(L, NAME);
			cout << left << setw(20) << r->data.id << left << setw(20) << r->data.name << left << setw(5) << r->data.price <<endl;
			break;
		case Price:
			cout << "������۸�>";
			int PRICE;
			cin >> PRICE;
			r = Find_by_PRICE(L, PRICE);
			cout << left << setw(20) << r->data.id << left << setw(20) << r->data.name << left << setw(5) << r->data.price<<endl;
			break;
		case EXIT:
			cout << "�˳�\n";
			break;
		default:
			cout << "��������������ѡ��\n";
			break;
		}
		cin.clear();
		cin.ignore(9999,'\n');
	} while (input);
}

void InsertBook(LinkList& L)
{
	int input = 0;
	cout << "��ѡ���ڵڼ��в����鼮��Ϣ\n";
	cin >> input;
	Insert_Book(L, input);

}

void DeleteBook(LinkList& L)
{
	int input = 0;
	cout << "��ѡ��ɾ���ڼ��е��鼮��Ϣ\n";
	cin >> input;
	Delete_Book(L, input);

}

void ReviseBook(LinkList& L)
{
	meue2();
	int input = 0;

	do
	{
		cout << "��ѡ���޸ķ�ʽ��>";
		cin >> input;
		switch (input)
		{
		case IBSN:
			cout << "������Ҫ�޸ĵ�IBSN��>";
			char Ibsn;
			cin >> Ibsn;
			Revise_Book_IBSN(L, Ibsn);
			break;
		case Name:
			cout << "������Ҫ�޸ĵ�������>";
			char NAME;
			cin >> NAME;
		    Revise_Book_NAME(L, NAME);
			break;
		case Price:
			cout << "������Ҫ�޸ĵļ۸�>";
			int PRICE;
			cin >> PRICE;
			Revise_Book_PRICE(L, PRICE);
			break;
		case EXIT:
			cout << "�˳�\n";
			break;
		default:
			cout << "��������������ѡ��\n";
			break;
		}
		cin.clear();
		cin.ignore(9999, '\n');
	} while (input);
}


void CountBook(LinkList L)
{
	int count = Count_Book(L);
	cout << "����Ԫ�ظ���Ϊ��>" << count << endl;
}

void SortBook(LinkList L)
{
	meue3();
	int input = 0;

	do
	{
		cout << "��ѡ������ʽ��>";
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
			cout << "�˳�\n";
			break;
		default:
			cout << "��������������ѡ��\n";
			break;
		}
	} while (input);
}