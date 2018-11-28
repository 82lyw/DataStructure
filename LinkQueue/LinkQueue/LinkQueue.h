//LinkQueue.h 非循环链队 数据结构C++类定义（基类）

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
	void clear();
	Status deQueue(ElemType & e);
	void enQueue(ElemType e);
	Status getFront(ElemType & e);
	bool isEmpty();
	int getLength();
	LinkQueue<ElemType> operator=(LinkQueue<ElemType> rightQ);
	LinkQueue();
	~LinkQueue();
	LinkQueue(const LinkQueue<ElemType> & otherQ);

protected:
	NodePointer rear;
	NodePointer front;
};

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
int LinkQueue<ElemType>::getLength()
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
