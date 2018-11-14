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
	//p = this->head;
	p = NULL;
	cout << "������ѭ���������н��ĸ�����";
	in >> this->n;
	cout << "������ѭ���������еĽ�㣺";

	for (i = 0; i < this->n;i++)
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
	typename CircularLinkList<ElemType>::NodePointer p = this->head;


	if (!p)
	{
		cout << "��ǰ��ѭ��������Ϊ��" << endl << endl;
	}
	else
	{
		cout << "��ǰ��ѭ��������Ϊ��" << endl;
		for (int i = 1; i <= this->n; i++)
			cout << "[ " << i << "] \t";
		cout << endl;
		while (p->next != this->head)
		{
			cout << " " << p->data << "->\t";
			p = p->next;
		}
		cout << " " << p->data<<endl;
	}
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
	//int n, i;
	int i;
	typename CircularLinkList<ElemType>::NodePointer p, s;
	p = this->head;
	this->n = random(2, 8);
	cout << "���������������ѭ����������" << endl;
	
	for (i = 0; i < this->n;i++)
	{
		s = new typename CircularLinkList<ElemType>::LinkNode;
		assert(s != 0);
		s->data = random(1, 99);
		cout << s->data;
		if (!this->head)
			this->head = s;
		else
			p->next = s;
		p = s;
		if (p)
			p->next = NULL;
	}
	p->next = this->head;
}