//CircularLinkList.h ѭ�����������ݽṹC++�ඨ�壨���ࣩ

//myhead.h
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

#define random(a,b) (rand()%(b-a+1)+a)

//ѭ�����������ݽṹC++������
template <typename ElemType>
class CircularLinkList
{
public:
	//ѭ�����������C++������
	class LinkNode
	{
	public:
		ElemType data;  //����������
		LinkNode *next;  //ָ����һ������ָ����
	};
	//ָ�����ָ����������
	typedef LinkNode *NodePointer;

public:
	//��ѭ���������ÿ�
	void clear();

	//ɾ����i����㣬ͷָ����������һ�����
	Status deleteElem(int i, ElemType & e);

	//ȡѭ���������һ������������
	Status getHeadElem(ElemType & e);

	//�ж�ѭ���������Ƿ�Ϊ��
	bool isEmpty();

	//��ȡѭ��������ĳ���
	int getLength();

	//��ѭ���������ͷָ���������i�����
	Status moveHead(int i);

	//���ظ�ֵ������Ķ���
	CircularLinkList<ElemType> operator = (CircularLinkList<ElemType>rightL);

	//ѭ��������Ĺ��캯��
	CircularLinkList();

	//ѭ�����������������
	~CircularLinkList();

	//ѭ��������Ŀ�����ʼ�����캯��
	CircularLinkList(const CircularLinkList & otherL);

//protected:
public:
	NodePointer head;
	int n;
};

template <typename ElemType>
void CircularLinkList<ElemType>::clear()
{
	if (head == NULL)
		return;
	
	NodePointer p;
	while (head != head->next);
	{
		p = head->next;
		head->next = p->next;
		delete p;
	}
	delete head;
	head = NULL;
}

template <typename ElemType>
Status CircularLinkList<ElemType>::deleteElem(int i, ElemType & e)
{
	int j = 1;
	NodePointer r=NULL;
	NodePointer p = head;

	if (!head)
		return ERROR;

	while (j < i)
	{
		r = p;
		p = p->next;
		++j;
	}
	e = p->data;

	if (p == p->next)
		head = NULL;
	else
		head = r->next = p ->next;

	delete p;
	return OK;
}

template <typename ElemType>
Status CircularLinkList<ElemType>::getHeadElem(ElemType & e)
{
	if (!head)
		return ERROR;
	e = head->data;
	return OK;
}

template <typename ElemType>
bool CircularLinkList<ElemType>::isEmpty()
{
	return (head ? false : true);
}

template <typename ElemType>
int CircularLinkList<ElemType>::getLength()
{
	NodePointer p = head;
	int i = 1;
	if (!head)
	{
		n=0;
	}
	else
	{
		while (p->next != head)
		{
			i++;
			p->next;
		}
		n = i;
	}
	return n;
}

template <typename ElemType>
Status CircularLinkList<ElemType>::moveHead(int i)
{
	int j = 1;

	if (!head)
		return ERROR;

	while (j < i)
	{
		head = head->next;
		++j;
	}

	return OK;
}

template <typename ElemType>
CircularLinkList<ElemType> CircularLinkList<ElemType>::operator=(CircularLinkList<ElemType> rightL)
{
	NodePointer p = NULL;
	NodePointer rp = rightL.head;
	NodePointer s;

	if (this != &rightL)
	{
		clear();

		while (rp->next != rightL.head)
		{
			s = new(LinkNode);
			assert(s != 0);

			s->data = rp->data;

			if (!head)
				head = s;
			else
				p->next = s;

			p = s;
			rp = rp->next;
		}

		if (head)
			p->next = head;
	}
	return *this;
}

template <typename ElemType>
CircularLinkList<ElemType>::CircularLinkList()
{
	head = NULL;
}

template <typename ElemType>
CircularLinkList<ElemType>::~CircularLinkList()
{
	clear();
}

template <typename ElemType>
CircularLinkList<ElemType>::CircularLinkList(const CircularLinkList<ElemType> & otherL)
{
	NodePointer p;
	NodePointer op = otherL.head;

	NodePointer s;
	head = p = NULL;

	while (op)
	{
		s = new(LinkNode);
		assert(s != 0);

		s->data = op->data;

		if (!head)
			head = s;
		else
			p->next = s;

		p = s;

		op = op->next;

		if (head)
			p->next = head;
	}
}
