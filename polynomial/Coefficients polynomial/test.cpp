#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//�����ṹ�壬ÿ������Ԫ�ص�������
typedef struct PNode
{
	float coef;
	int expn;
	struct PNode* next;
}PNode,*Polynomial;

//��ʼ��
void CreatePolynomial(Polynomial &L, int n)
{
	L = new PNode;										//����һ����ͷ���ĵ�����
	L->next = NULL;										
	for (int i = 0; i < n; i++)							//��������n����0��
	{	
		Polynomial p;	
		Polynomial q;
		Polynomial pre;		

		p = new PNode;									//����һ���½��p
		cin >> p->coef >> p->expn;						//�������������ֵ
		pre = L;										//pre�������q��ǰ������ֵΪͷ���
		q = L->next;									//q��ʼ������ֵ����Ԫ���
		
		while (q && q->expn < p->expn)					//ѭ����������Ƚ������е�ǰ�����ָ����������ָ�����ҵ���һ�������ָ���>������ָ����Ľ��x
		{												//���ˡ�����ָ������ڴ˽��x֮ǰ
			pre = q;									//��û���ҵ�����Ϊ�½���ָ�����ÿ���׼��
			q = q->next;								//���ҵ��ˣ�preΪ���x��ǰһ������λ�ã�qΪ���x��λ��
		}

		p->next = q;									//���ҵ����ڡ�����ָ����Ľ��x�����½���ָ������Ϊx�ĵ�ַ����x���ǰһ������ָ������Ϊ�½���λ��
		pre->next = p;									//��û���ҵ������½���ָ����ָ�أ����½�����ӵ���������һ�����֮��
	}
}

//����ʽ���
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
		if (p1->expn == p2->expn)//��ָ�����
		{
			float sum;
			sum = p1->coef + p2->coef;
			if (sum != 0)//ϵ����Ӳ�Ϊ0����p1����������Ϊsum��p3��ָ������Ϊp1��p3�ƶ���p1��p1�ƶ����¸�λ�ã�p2�ƶ����¸�λ��
			{
				p1->coef = sum;
				p3->next = p1;

				p3 = p1;
				p1 = p1->next;
				r = p2;
				p2 = p2->next;
				delete r;
			}
			else			//ϵ��Ϊ0
			{
				r = p1;
				p1 = p1->next;
				delete r;
				r = p2;
				p2 = p2->next;
				delete r;
			}
		}
		else if (p1->expn < p2->expn)//��p2��ָ������p1����p3��ָ������Ϊp1��p3�ƶ���p1��p1�ƶ����¸�λ��
		{
			p3->next = p1;

			p3 = p1;
			p1 = p1->next;
		}
		else						//��p1��ָ������p2����p3��ָ������Ϊp2��p3�ƶ���p2��p2�ƶ����¸�λ��
		{
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	p3->next = p1 ? p1 : p2;		//����һ������û��Ԫ���ˣ�������һ�������ʣ�ಿ�ֽ���p3֮��
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