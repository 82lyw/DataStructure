// ���ݽṹC++��������ʵ�֣������ࣩ

// CircularLinkList.h���ݽṹC++��������ʵ�֣����ࣩ
#ifndef CIRCULARLINKLIST_H
#define CIRCULARLINKLIST_H
#include "CircularLinkList.h"
#endif

template <typename ElemType>
class MyCircularLinkList :public CircularLinkList<ElemType>
{
public:
	//����ѭ��������
	void read(istream & in);

	//���ѭ��������
	void display(ostream & out) const;

	//�������ѭ��������
	void Randborn();
};

//ѭ�����������ݽṹC++���ʵ�֣������ࣩ

template <typename ElemType>
void MyCircularLinkList<ElemType>::read(istream& in)
{
	typename CircularLinkList<ElemType>::clear();
	int i;
	typename CircularLinkList<ElemType>::NodePointer p, s;
	p = this->head=NULL;
	//p = NULL;
	cout << "������ѭ���������н��ĸ�����";
	int n;
	in >> n;
	cout << "������ѭ���������еĽ�㣺";

	for (i = 0; i < n;i++)
	{
		s = new typename CircularLinkList<ElemType>::LinkNode;
		assert(s != 0);
		in >> s->data;
		if (!this->head)
			this->head = s;
		else
			p->next = s;
		p = s;
		if (p)
			p->next = NULL;
	}
	p->next = this->head;

	cout << "\n\t�Ѿ��ڵ�ǰѭ��������������" << n << "�����" << endl << endl;
	cout << "�����ѭ������������:" << endl;
}

//���ܣ���������������Ķ���
//˵����ͨ���ú���������ʹ��C++��cinֱ�ӴӼ���������ѭ��������
template <typename ElemType>
istream& operator>>(istream& in, MyCircularLinkList<ElemType>& iD)
{
	iD.read(in);
	return in;
}

template <typename ElemType>
void MyCircularLinkList<ElemType>::display(ostream& out) const
{
	//�������
	int n = CircularLinkList<ElemType>::getLength();
	typename CircularLinkList<ElemType>::NodePointer p = this->head;

	if (!p)
	{
		cout << "��ǰѭ��������Ϊ��" << endl << endl;
		return;
	}
	else
	{
		cout << "��ǰ��ѭ��������Ϊ��" << endl;
		for (int i = 1; i <= n; i++)
		{
			out<< "\t[" << i << "]" ;
		}
		cout << endl;
		//while (p!= this->head)
		while(p)
		{
			out<<"\t" << p->data << "->" ;
			p = p->next;
			if (p == this->head)
				break;
		}
		out << endl;
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				out<< "\t��____";
			}
			else if (i == n - 1)
			{
				out << "______|";
			}
			else
			{
				out << "________";
			}
		}
	}
	cout << endl << endl;
}

template <typename ElemType>
ostream & operator <<(ostream &out, const MyCircularLinkList<ElemType>&oD)
{
	oD.display(out);
	return out;
}

template<typename ElemType>
void MyCircularLinkList<ElemType>::Randborn()
{
	typename CircularLinkList<ElemType>::clear();
	int i;
	typename CircularLinkList<ElemType>::NodePointer p, s;
	p = this->head;
	int n;
	n = random(2, 8);
	cout << "���������������ѭ��������" << endl;
	
	for (i = 0; i < n;i++)
	{
		s = new typename CircularLinkList<ElemType>::LinkNode;
		assert(s != 0);
		s->data = random(1, 99);
		cout << s->data<<"  ";
		if (!this->head)
			this->head = s;
		else
			p->next = s;
		p = s;
		if (p)
			p->next = NULL;
	}
	p->next = this->head;
	cout << endl;

	cout << "������ɵ�ѭ������������:" << endl;
}
