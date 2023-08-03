#define _CRT_SECURE_NO_WARNINGS 1
#define MAXQSIZE 100

#include <iostream>

using namespace std;

typedef struct {
	char name[20];
	char sex;
}Person;

typedef struct {
	Person* base;
	int front;
	int rear;
} SqQueue;



void Init(SqQueue& Q)
{
	Q.base = new Person[MAXQSIZE];
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return;
}

int QueueEmpty(SqQueue Q)
{//判断队列是否为空
	if (Q.front == Q.rear) 
		return 1;//队列空，返回1
	else 
		return 0;//队列不空，返回0
}

void EnQueue(SqQueue &Q, Person e)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return;
}

int DeQueue(SqQueue& Q, Person& e)
{
	if (Q.front == Q.rear)
		return 0;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return 1;
}

Person GetHead(SqQueue Q)
{
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}

void DancePartner(Person dancer[], int num)
{
	SqQueue Mdancers, Fdancers;
	Init(Mdancers);
	Init(Fdancers);
	Person p;

	for (int i = 0; i < num; i++)
	{
		p = dancer[i];
		if (p.sex == 'F')
			EnQueue(Fdancers, p);
		else
			EnQueue(Mdancers, p);
	}
	cout << "The dancing partners are:\n";
	while (!QueueEmpty(Fdancers) && !QueueEmpty(Mdancers))
	{
		DeQueue(Fdancers, p);
		cout << p.name << " ";
		DeQueue(Mdancers, p);
		cout << p.name << endl;
	}
	if (!QueueEmpty(Fdancers))
	{
		p = GetHead(Fdancers);
		cout << "The first woman to get a partner is:" << p.name << endl;
	}
	else if (!QueueEmpty(Mdancers))
	{
		p = GetHead(Mdancers);
		cout << "The first man to get a partner is:" << p.name << endl;
	}
}


int main()
{
	Person dancer[MAXQSIZE];
	int i, num;
	cout << "请输入跳舞总人数：>";
	cin >> num;
	cout << "输入各个跳舞人的性别和姓名(‘F’表示女性，‘M’表示男性)：\n";
	for (i = 0; i < num; i++)
	{
		cout << "请输入第" << i+1 << "个跳舞人的姓名和性别：>";
		cin >> dancer[i].name >> dancer[i].sex;
	}
	DancePartner(dancer,num);
	return 0;
}