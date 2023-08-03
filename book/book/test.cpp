#define _CRT_SECURE_NO_WARNINGS 1
#include"Book.h"


int main()
{
	cout << "创建图书信息\n";
	LinkList L=CreatBook(5);
	int input = 0;
	do
	{	
		meue();
		cout << "请选择你要进行的操作：>";
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
			cout << "退出系统\n";
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			break;
		}
		cin.clear();
		cin.ignore();
	} while(input);


	return 0;
}