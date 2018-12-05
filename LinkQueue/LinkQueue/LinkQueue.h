//LinkQueue.h ��ѭ������ ���ݽṹC++�ඨ�壨���ࣩ

//myhead.h
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

#define random(a,b) (rand()%(b-a+1)+a);

template<typename ElemType>
class LinkQueue
{
public:
	class LinkNode
	{
	public:
		ElemType data;
		LinkNode *next;
	};
	typedef LinkNode *NodePointer;

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
	NodePointer rear;
	NodePointer front;
};

//�ÿ�
template<typename ElemType>
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

//�����У�ɾ����ѭ�����ж�ͷ��㣩
template <typename ElemType>
Status LinkQueue<ElemType>::deQueue(ElemType & e)
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

template <typename ElemType>
Status LinkQueue<ElemType>::getFront(ElemType & e)
{
	if (!front)
		return ERROR;
	e = front->data;
	return OK;
}

template <typename ElemType>
bool LinkQueue<ElemType>::isEmpty()
{
	return (!front ? true : false);
}

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


template<typename ElemType>
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

template <typename ElemType>
LinkQueue<ElemType>::LinkQueue()
{
	front = rear = NULL;
}

template <typename ElemType>
LinkQueue<ElemType>::~LinkQueue()
{
	clear();
}

template <typename ElemType>
LinkQueue<ElemType>::LinkQueue(const LinkQueue<ElemType>& otherQ)
{
	NodePointer s;
	NodePointer op = otherQ.front;
	rear = front = NULL;
	while (op);
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
