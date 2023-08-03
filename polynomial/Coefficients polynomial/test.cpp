#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//建立结构体，每个数据元素的数据项
typedef struct PNode
{
	float coef;
	int expn;
	struct PNode* next;
}PNode,*Polynomial;

//初始化
void CreatePolynomial(Polynomial &L, int n)
{
	L = new PNode;										//建立一个带头结点的单链表
	L->next = NULL;										
	for (int i = 0; i < n; i++)							//依次输入n个非0项
	{	
		Polynomial p;	
		Polynomial q;
		Polynomial pre;		

		p = new PNode;									//生成一个新结点p
		cin >> p->coef >> p->expn;						//输入结点数据域的值
		pre = L;										//pre保存的是q的前驱，初值为头结点
		q = L->next;									//q初始化，初值是首元结点
		
		while (q && q->expn < p->expn)					//循链向下逐个比较链表中当前链表的指数与输入项指数，找到第一个“结点指数项”>“输入指数项”的结点x
		{												//将此“输入指数项”放在此结点x之前
			pre = q;									//若没有找到，则为新结点的指针域置空做准备
			q = q->next;								//若找到了，pre为结点x的前一个结点的位置，q为结点x的位置
		}

		p->next = q;									//若找到大于“输入指数项”的结点x，则将新结点的指针域置为x的地址，将x结点前一个结点的指针域置为新结点的位置
		pre->next = p;									//若没有找到，则将新结点的指针域指控，将新结点链接到链表的最后一个结点之后。
	}
}

//多项式相加
void AddPolyn(Polynomial& Pa, Polynomial& Pb)
{
	Polynomial p1;
	Polynomial p2;
	Polynomial p3;
	Polynomial r;

	p1 = Pa->next;
	p2 = Pb->next;
	p3 = Pa;
	while (p1&&p2)
	{
		if (p1->expn == p2->expn)//若指数相等
		{
			float sum;
			sum = p1->coef + p2->coef;
			if (sum != 0)//系数相加不为0，则将p1的数据域置为sum，p3的指针域置为p1，p3移动到p1，p1移动到下个位置，p2移动到下个位置
			{
				p1->coef = sum;
				p3->next = p1;

				p3 = p1;
				p1 = p1->next;
				r = p2;
				p2 = p2->next;
				delete r;
			}
			else			//系数为0
			{
				r = p1;
				p1 = p1->next;
				delete r;
				r = p2;
				p2 = p2->next;
				delete r;
			}
		}
		else if (p1->expn < p2->expn)//若p2的指数大于p1，则将p3的指针域置为p1，p3移动到p1，p1移动到下个位置
		{
			p3->next = p1;

			p3 = p1;
			p1 = p1->next;
		}
		else						//若p1的指数大于p2，则将p3的指针域置为p2，p3移动到p2，p2移动到下个位置
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	p3->next = p1 ? p1 : p2;		//当有一个链表没有元素了，则将另外一个链表的剩余部分接在p3之后。
	delete Pb;

}

int main()
{
	Polynomial Pa;
	Polynomial Pb;
	CreatePolynomial( Pa , 4);
	CreatePolynomial( Pb , 3);

	AddPolyn(Pa, Pb);

	
}