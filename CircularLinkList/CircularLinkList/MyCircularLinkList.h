// 数据结构C++类声明和实现（派生类）

// CircularLinkList.h数据结构C++类声明和实现（基类）
#ifndef CIRCULARLINKLIST_H
#define CIRCULARLINKLIST_H
#include "CircularLinkList.h"
#endif

template <typename ElemType>
class MyCircularLinkList :public CircularLinkList<ElemType>
{
public:
	//输入循环单链表
	void read(istream & in);

	//输出循环单链表
	void display(ostream & out) const;

	//随机生成循环单链表
	void Randborn();
};

//循环单链表数据结构C++类的实现（派生类）

template <typename ElemType>
void MyCircularLinkList<ElemType>::read(istream& in)
{
	typename CircularLinkList<ElemType>::clear();
	int i;
	typename CircularLinkList<ElemType>::NodePointer p, s;
	p = this->head;
	//p = NULL;
	cout << "请输入循环单链表中结点的个数：";
	in >> this->n;
	cout << "请输入循环单链表中的结点：";

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

//功能：重载输入运算符的定义
//说明：通过该函数，可以使用C++中cin直接从键盘上输入循环单链表
template <typename ElemType>
istream& operator>>(istream& in, MyCircularLinkList<ElemType>& iD)
{
	iD.read(in);
	return in;
}

template <typename ElemType>
void MyCircularLinkList<ElemType>::display(ostream& out) const
{
	//输出操作
	typename CircularLinkList<ElemType>::NodePointer p = this->head;

	if (!p)
	{
		cout << "当前循环单链表为空" << endl << endl;
	}
	else
	{
		cout << "当前的循环单链表为：" << endl;
		for (int i = 1; i <= this->n; i++)
		{
			std::cout << std::setiosflags(std::ios::left)<<std::setfill(' ') << std::setw(10);
			std::cout << "[ " << i << "] " << std::endl;
		}
		cout << endl;
		while (p->next != this->head)
		{
			std::cout << std::setiosflags(std::ios::left) << std::setfill(' ') << std::setw(10);
			std::cout << " " << p->data << "->" << std::endl;
			p = p->next;
		}
		std::cout << std::setiosflags(std::ios::left) << std::setfill(' ') << std::setw(10);
		std::cout << " " << p->data << std::endl;
	}
	for (int i = 0; i < this->n; i++)
	{
		if (i == 0)
		{
			std::cout << std::setiosflags(std::ios::left) << std::setfill('_') << std::setw(10);
			std::cout <<"  ↑" << std::endl;
		}
		else if(i==this->n-1)
		{
			std::cout << std::setiosflags(std::ios::right) << std::setfill('_') << std::setw(10);
			std::cout << "|" << std::endl;
		}
		else
		{
			std::cout << std::setiosflags(std::ios::left) << std::setfill('_') << std::setw(10);
			std::cout << " __" << std::endl;
		}
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
	cout << "用如下随机数生成循环单链表：" << endl;
	
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
