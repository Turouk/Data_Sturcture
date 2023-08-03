#pragma once

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

enum Option
{
	Exit,
	Find,
	Insert,
	Delete,
	Revise,
	Sort,
	Count,
	Print
};

enum Option1
{
	EXIT,
	IBSN,
	Name,
	Price
};

struct Book
{
	char id[20];
	char name[30];
	int price;
};

typedef struct LNode
{
	Book data;
	struct LNode* next;
}LNode, * LinkList;

void meue();
void meue1();
void meue2();
void meue3();


LinkList CreatBook(int n);

void printList(LinkList L);


void FindBook(LinkList L);
LNode* Find_by_IBSN(LinkList L,char IBSN);
LNode* Find_by_NAME(LinkList L,char NAME);
LNode* Find_by_PRICE(LinkList L,int NAME);

void InsertBook(LinkList& L);
void Insert_Book(LinkList& L, int n);

void DeleteBook(LinkList& L);
void Delete_Book(LinkList& L, int n);

void ReviseBook(LinkList &L);
void Revise_Book_IBSN(LinkList L, char IBSN);
void Revise_Book_NAME(LinkList L, char NAME);
void Revise_Book_PRICE(LinkList L,int PRICE);

void CountBook(LinkList L);
int Count_Book(LinkList L);

void SortBook(LinkList L);
void Sort_Book_IBSN(LinkList L);
void Sort_Book_NAME(LinkList L);
void Sort_Book_PRICE(LinkList L);



