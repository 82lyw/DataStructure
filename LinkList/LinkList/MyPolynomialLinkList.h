
#ifndef LINKLIST_H
#define LINKLIST_H
#include "LinkList.h"
#endif

template <typename ElemType>
class MyPolynomialLinkList :public LinkList<ElemType>
{
public:
		//重载加法运算符的定义
		MyPolynomialLinkList<ElemType> operator +(MyPolynomialLinkList<ElemType> L2);

		//重载减法运算符的定义
		MyPolynomialLinkList<ElemType> operator -(MyPolynomialLinkList<ElemType> L2);

		//重新随机生成多项式
		void randomInitialFill(int display = 0);

		//输入多项式（采用非循环单链表存储）
		void read(istream & in);

		//输出多项式（采用非循环单链表存储）
		void display(ostream & out) const;
};

template <typename ElemType>
MyPolynomialLinkList<ElemType> MyPolynomialLinkList<ElemType>::operator +(MyPolynomialLinkList<ElemType> L2)
{
	typename LinkList<ElemType>::NodePointer p1 = this->head;
	typename LinkList<ElemType>::NodePointer p2 = L2.head;

	MyPolynomialLinkList<ElemType> L3;
	typename LinkList<ElemType>::NodePointer r3 = NULL, p3 = NULL;
	while (p1&&p2)
	{
		if (p1->data.expn == p2->data.expn && p1->data.coef + p2->data.coef == 0)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			p3 = new typename LinkList<ElemType>::LinkNode;
			assert(p3 != 0);

			if (p1->data.expn > p2->data.expn)
			{
				p3->data.coef = p1->data.coef;
				p3->data.expn = p1->data.expn;
				p1 = p1->next;
			}
			else if (p1->data.expn == p2->data.expn)
			{
				p3->data.coef = p1->data.coef + p2->data.coef;
				p3->data.expn = p1->data.expn;
				p1 = p1->next;
				p2 = p2->next;
			}
			else
			{
				p3->data.coef = p2->data.coef;
				p3->data.expn = p2->data.expn;
				p2 = p2->next;
			}

			if (!L3.head)
				L3.head = p3;
			else
				r3->next = p3;

			r3 = p3;
		}
	}

	while (p1)
	{
		p3 = new typename LinkList<ElemType>::LinkNode;
		assert(p3 != 0);

		p3->data.coef = p2->data.coef;
		p3->data.expn = p2->data.expn;

		p1 = p1->next;
		if (!L3.head)
			L3.head = p3;
		else
			r3->next = p3;

		r3 = p3;
	}

	while (p2)
	{
		p3 = new typename LinkList<ElemType>::LinkNode;
		assert(p3 != 0);

		p3->data.coef = p2->data.coef;
		p3->data.expn = p2->data.expn;

		p2 = p2->next;
		if (!L3.head)
			L3.head = p3;
		else
			r3->next = p3;

		r3 = p3;
	}
	if (p3)
		p3->next = NULL;
	return L3;
}

template <typename ElemType>
MyPolynomialLinkList<ElemType> MyPolynomialLinkList<ElemType>::operator -(MyPolynomialLinkList<ElemType> L2)
{
	typename LinkList<ElemType>::NodePointer p2 = L2.head;
	MyPolynomialLinkList<ElemType> L3;

	while (p2)
	{
		p2->data.coef = -p2->data.coef;
		p2 = p2->next;
	}

	L3 = (*this) + L2;
	return L3;
}

template <typename ElemType>
void MyPolynomialLinkList<ElemType>::randomInitialFill(int display)
{
	int n;
	typename LinkList<ElemType>::NodePointer r, p;
	typename LinkList<ElemType>::NodePointer s;

	typename LinkList<ElemType>::clear();

	srand((unsigned)time(NULL));

	n = rand() % 8 + 1;

	if (display)
	{
		cout << "依次生成多项式如下" << n << "个项：" << endl;
		cout << "       " ;
	}
	for (int i = 0; i < n; i++)
	{
		s = new typename LinkList<ElemType>::LinkNode;
		assert(s != 0);

		if (rand() % 2)
			s->data.coef = rand() % 100 + 1;
		else
			s->data.coef = -(rand() % 100 + 1);

		while (1)
		{
			s->data.expn = rand() % 10;
			r = NULL, p = this->head;
			while (p&&s->data.expn < p->data.expn)
			{
				r = p;
				p = p->next;
			}

			if (p&&s->data.expn == p->data.expn)
				continue;
			else
				break;
		}

		if (!r)
			this->head = s;
		else
			r->next = s;
		s->next = p;

		if (display)
		{
			if (s->data.coef != 1)
				cout << s->data.coef;
			if (s->data.expn)
				cout << "x" << s->data.expn<<"  ";
			//cout << s->data << "  ";
		}
	}

	if (display)
		cout << endl;
}

template <typename ElemType>
void MyPolynomialLinkList<ElemType>::read(istream & in)
{
	int n;
	typename LinkList<ElemType>::NodePointer r, p;
	typename LinkList<ElemType>::NodePointer s;

	typename LinkList<ElemType>::clear();

	cout << "请输入多项式的项数：";
	in >> n;

	cout<<"请输入多项式中的项"<<endl;
	for (int i = 0; i < n; i++)
	{
		cout << "\t第" << i + 1 << "项";

		s = new typename LinkList<ElemType>::LinkNode;
		assert(s != 0);

		while (1)
		{
			in >> s->data;
			r = NULL, p = this->head;
			while (p&&s->data.expn < p->data.expn)
			{
				r = p;
				p = p->next;
			}
			if (p&&s->data.expn == p->data.expn)
			{
				cout << "该指数的项已经存在，重新生成该项" << endl;
				continue;
			}
			else
				break;
		}

		if (!r)
			this->head = s;
		else
			r->next = s;

		s->next = p;
	}
	cout << "\n 已经输入了多项式的" << n << "个项" << endl;
}

template <typename ElemType>
istream & operator>>(istream & in, MyPolynomialLinkList<ElemType> &pL)
{
	pL.read(in);
	return in;
}

template <typename ElemType>
void MyPolynomialLinkList<ElemType>::display(ostream & out) const
{
	typename LinkList<ElemType>::NodePointer p;
	p= this->head;
	if (!this->head)
	{
		out << "该多项式为空！" << endl;
		return;
	}

	out << "     ";
	while (p)
	{
		if (p != this->head && p->data.coef >0)
			out << "+";
		if (p->data.coef != 1)
			out << p->data.coef;
		if (p->data.expn)
			out << "x" << p->data.expn;
		//out << p->data;

		p = p->next;
	}
	out << endl;
}

template <typename ElemType>
ostream &operator<<(ostream & out, const MyPolynomialLinkList<ElemType> & L)
{
	L.display(out);
	return out;
}