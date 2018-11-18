//CircularLinkList.h 循环单链表数据结构C++类定义（基类）

//myhead.h
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

#define random(a,b) (rand()%(b-a+1)+a)

//循环单链表数据结构C++类声明
template <typename ElemType>
class CircularLinkList
{
public:
	//循环单链表结点的C++类声明
	class LinkNode
	{
	public:
		ElemType data;  //结点的数据域
		LinkNode *next;  //指向下一个结点的指针域
	};
	//指向结点的指针类型声明
	typedef LinkNode *NodePointer;

public:
	//把循环单链表置空
	void clear();

	//删除第i个结点，头指针移至其下一个结点
	Status deleteElem(int i, ElemType & e);

	//取循环单链表第一个结点的数据域
	Status getHeadElem(ElemType & e);

	//判断循环单链表是否为空
	bool isEmpty();

	//获取循环单链表的长度
	int getLength();

	//把循环单链表的头指针后移至第i个结点
	Status moveHead(int i);

	//重载赋值运算符的定义
	CircularLinkList<ElemType> operator = (CircularLinkList<ElemType>rightL);

	//循环单链表的构造函数
	CircularLinkList();

	//循环单链表的析构函数
	~CircularLinkList();

	//循环单链表的拷贝初始化构造函数
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
