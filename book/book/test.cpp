#define _CRT_SECURE_NO_WARNINGS 1
#include"Book.h"


int main()
{
	cout << "����ͼ����Ϣ\n";
	LinkList L=CreatBook(5);
	int input = 0;
	do
	{	
		meue();
		cout << "��ѡ����Ҫ���еĲ�����>";
		cin >> input;
		switch (input)
		{
		case Find:
			FindBook(L);
			break;
		case Insert:
			InsertBook(L);
			break;
		case Delete:
			DeleteBook(L);
			break;
		case Revise:
			ReviseBook(L);
			break;
		case Sort:
			SortBook(L);
			break;
		case Count:
			CountBook(L);
			break;
		case Print:
			printList(L);
			break;
		case Exit:
			cout << "�˳�ϵͳ\n";
			break;
		default:
			cout << "�����������������" << endl;
			break;
		}
		cin.clear();
		cin.ignore();
	} while(input);


	return 0;
}