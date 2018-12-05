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
	//把非循环链队置空
	void clear();

	//出队列（删除非循环链队对头结点）
	Status deQueue(ElemType& e);

	//进队列（在非循环链队队尾插入结点）
	void enQueue(ElemType e);

	//读非循环链队队头结点的数据域
	Status getFront(ElemType& e);

	//判断非循环链队是否为空
	bool isEmpty();

	//求非循环链队中结点的个数
	int getLength() const;

	//重载赋值运算符的定义
	LinkQueue<ElemType> operator=(LinkQueue<ElemType> rightQ);

	//非循环链队构造函数
	LinkQueue();

	//非循环链队析构函数
	~LinkQueue();

	//非循环链队拷贝初始化构造函数
	LinkQueue(const LinkQueue<ElemType>& otherQ);

protected:
	int queueSize;
	NodePointer rear;//队尾指针
	NodePointer front;//队头指针
};

//功能：把非循环链队置空
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

//功能：出队列（删除非循环链队队头结点）
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

//功能：进队列（在非循环链队队尾插入结点）
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

//功能：读非循环链队队头结点的数据域
template <typename ElemType>
Status LinkQueue<ElemType>::getFront(ElemType& e)
{
	if (!front)
		return ERROR;
	e = front->data;
	return OK;
}

//功能：判断非循环链队是否为空
template <typename ElemType>
bool LinkQueue<ElemType>::isEmpty()
{
	return (!front ? true : false);
}

//功能：求非循环链队中结点的个数
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

//功能：重载赋值运算符的定义
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

//功能：非循环链队构造函数
template <typename ElemType>
LinkQueue<ElemType>::LinkQueue()
{
	front = rear = NULL;
}

//功能：非循环链队析构函数
template <typename ElemType>
LinkQueue<ElemType>::~LinkQueue()
{
	clear();
}

//功能：非循环链队拷贝初始化构造函数
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
	//输入非循环链队
	void read(istream& in);
	//输出非循环链队
	void display(ostream& out) const;
	//随机生成非循环链队
	void RandLinkQ();
};

//功能：输入非循环链队
template <typename ElemType>
void MyLinkQueue<ElemType>::read(istream& in)
{
	typename LinkQueue<ElemType>::NodePointer p, s;
	p = this->rear = NULL;
	int n;
	cout << "请输入非循环链队中的结点个数：" << endl;
	cin >> n;
	cout << "请输入非循环链队每个结点的数据域：" << endl;
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

//功能：随机生成非循环链队
template <typename ElemType>
void MyLinkQueue<ElemType>::RandLinkQ()
{
	cout << endl << "当前非循环链队为：" << endl;
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

//功能：重载输入运算符的定义
template <typename ElemType>
istream& operator>>(istream& in, MyLinkQueue<ElemType>& iD)
{
	iD.read(in);
	return in;
}

//功能：输出非循环链队
template<typename ElemType>
void MyLinkQueue<ElemType>::display(ostream& out) const
{
	typename LinkQueue<ElemType>::NodePointer t = this->front;
	int len = typename LinkQueue<ElemType>::getLength();
	if (!this->front)
	{
		cout << "当前非循环链队为空！" << endl;
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
	out << "↑" << setw(4 * (len - 1)) << "↑" << endl;
	out << "\t";
	out << "front" << setw(4 * (len - 1)) << "rear" << endl;
}

//功能：重载输出运算符的定义
template <typename ElemType>
ostream& operator <<(ostream& out, const MyLinkQueue<ElemType>& oD)
{
	oD.display(out);
	return out;
}