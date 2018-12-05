#pragma once
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

#define random(a,b) (rand()%(b-a+1)+a);

template <typename ElemType>
class LinkQueue
{
public:
	class LinkNode
	{
	public:
		ElemType data;
		LinkNode *next;
	};
	typedef LinkNode * NodePointer;

public:
	//�ѷ�ѭ�������ÿ�
	void clear();

	//�����У�ɾ����ѭ�����Ӷ�ͷ��㣩
	Status deQueue(ElemType& e);

	//�����У��ڷ�ѭ�����Ӷ�β�����㣩
	void enQueue(ElemType e);

	//����ѭ�����Ӷ�ͷ����������
	Status getFront(ElemType& e);

	//�жϷ�ѭ�������Ƿ�Ϊ��
	bool isEmpty();

	//���ѭ�������н��ĸ���
	int getLength() const;

	//���ظ�ֵ������Ķ���
	LinkQueue<ElemType> operator=(LinkQueue<ElemType> rightQ);

	//��ѭ�����ӹ��캯��
	LinkQueue();

	//��ѭ��������������
	~LinkQueue();

	//��ѭ�����ӿ�����ʼ�����캯��
	LinkQueue(const LinkQueue<ElemType>& otherQ);

protected:
	int queueSize;
	NodePointer rear;//��βָ��
	NodePointer front;//��ͷָ��
};

//���ܣ��ѷ�ѭ�������ÿ�
template <typename ElemType>
void LinkQueue<ElemType>::clear()
{
	NodePointer q;
	NodePointer p = front;
	while (p)
	{
		q = p;
		p = p->next;
		delete q;
	}
	front = rear = NULL;
}

//���ܣ������У�ɾ����ѭ�����Ӷ�ͷ��㣩
template <typename ElemType>
Status LinkQueue<ElemType>::deQueue(ElemType& e)
{
	if (!front)
		return ERROR;
	NodePointer s = front;
	e = s->data;
	front = front->next;
	delete s;
	if (!front)
		rear = NULL;
	return OK;
}

//���ܣ������У��ڷ�ѭ�����Ӷ�β�����㣩
template <typename ElemType>
void LinkQueue<ElemType>::enQueue(ElemType e)
{
	NodePointer s;
	s = new(LinkNode);
	assert(s != 0);
	s->data = e;
	s->next = NULL;
	if (!front)
		front = rear = s;
	else
	{
		rear->next = s;
		rear = s;
	}
}

//���ܣ�����ѭ�����Ӷ�ͷ����������
template <typename ElemType>
Status LinkQueue<ElemType>::getFront(ElemType& e)
{
	if (!front)
		return ERROR;
	e = front->data;
	return OK;
}

//���ܣ��жϷ�ѭ�������Ƿ�Ϊ��
template <typename ElemType>
bool LinkQueue<ElemType>::isEmpty()
{
	return (!front ? true : false);
}

//���ܣ����ѭ�������н��ĸ���
template <typename ElemType>
int LinkQueue<ElemType>::getLength() const
{
	int length = 0;
	NodePointer p = front;
	while (p)
	{
		++length;
		p = p->next;
	}
	return length;
}

//���ܣ����ظ�ֵ������Ķ���
template <typename ElemType>
LinkQueue<ElemType> LinkQueue<ElemType>::operator=(LinkQueue<ElemType> rightQ)
{
	NodePointer s;
	NodePointer rp = rightQ.front;
	if (this != &rightQ)
	{
		clear();
		while (rp)
		{
			s = new(LinkNode);
			assert(s != 0);
			s->data = rp->data;
			s->next = NULL;
			if (!front)
				front = rear = s;
			else
			{
				rear->next = s;
				rear = s;
			}
			rp = rp->next;
		}
	}
	return *this;
}

//���ܣ���ѭ�����ӹ��캯��
template <typename ElemType>
LinkQueue<ElemType>::LinkQueue()
{
	front = rear = NULL;
}

//���ܣ���ѭ��������������
template <typename ElemType>
LinkQueue<ElemType>::~LinkQueue()
{
	clear();
}

//���ܣ���ѭ�����ӿ�����ʼ�����캯��
template <typename ElemType>
LinkQueue<ElemType>::LinkQueue(const LinkQueue<ElemType>& otherQ)
{
	NodePointer s;
	NodePointer op = otherQ.front;
	rear = front = NULL;
	while (op)
	{
		s = new(LinkNode);
		assert(s != 0);
		s->data = op->data;
		s->next = NULL;
		if (!front)
			front = rear = s;
		else
		{
			rear->next = s;
			rear = s;
		}
		op = op->next;
	}
}


template <typename ElemType>
class MyLinkQueue :public LinkQueue<ElemType>
{
public:
	//�����ѭ������
	void read(istream& in);
	//�����ѭ������
	void display(ostream& out) const;
	//������ɷ�ѭ������
	void RandLinkQ();
};

//���ܣ������ѭ������
template <typename ElemType>
void MyLinkQueue<ElemType>::read(istream& in)
{
	typename LinkQueue<ElemType>::NodePointer p, s;
	p = this->rear = NULL;
	int n;
	cout << "�������ѭ�������еĽ�������" << endl;
	cin >> n;
	cout << "�������ѭ������ÿ������������" << endl;
	for (int i = 1; i <= n; ++i)
	{
		s = new typename LinkQueue<ElemType>::LinkNode;
		assert(s != 0);
		cin >> s->data;
		if (i == 1)
		{
			p = s;
			this->front = this->rear = p;
		}
		else
		{
			p->next = s;
			p = p->next;
		}
	}
	p->next = NULL;
}

//���ܣ�������ɷ�ѭ������
template <typename ElemType>
void MyLinkQueue<ElemType>::RandLinkQ()
{
	cout << endl << "��ǰ��ѭ������Ϊ��" << endl;
	int i;
	typename LinkQueue<ElemType>::NodePointer s;
	this->rear = this->front = NULL;
	i = random(3,6);
	for (int j = 0; j < i; ++j)
	{
		s = new typename LinkQueue<ElemType>::LinkNode;
		assert(s != 0);
		s->data = random(1,99);
		cout<<s->data<<"  ";
		s->next = NULL;
		if (!this->front)
			this->front = this->rear = s;
		else
		{
			this->rear->next = s;
			this->rear = s;
		}
	}
	cout << endl;
}

//���ܣ���������������Ķ���
template <typename ElemType>
istream& operator>>(istream& in, MyLinkQueue<ElemType>& iD)
{
	iD.read(in);
	return in;
}

//���ܣ������ѭ������
template<typename ElemType>
void MyLinkQueue<ElemType>::display(ostream& out) const
{
	typename LinkQueue<ElemType>::NodePointer t = this->front;
	int len = typename LinkQueue<ElemType>::getLength();
	if (!this->front)
	{
		cout << "��ǰ��ѭ������Ϊ�գ�" << endl;
		return;
	}
	out << "\t";
	while (t != this->rear)
	{
		out << setw(2) << t->data << "->";
		t = t->next;
	}
	if (this->rear == t)
		out << setw(2) << t->data;
	out << endl;

	out << "\t";
	out << "��" << setw(4 * (len - 1)) << "��" << endl;
	out << "\t";
	out << "front" << setw(4 * (len - 1)) << "rear" << endl;
}

//���ܣ��������������Ķ���
template <typename ElemType>
ostream& operator <<(ostream& out, const MyLinkQueue<ElemType>& oD)
{
	oD.display(out);
	return out;
}