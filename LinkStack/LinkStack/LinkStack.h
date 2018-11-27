//LinkList.h链栈数据结构C++类定义（基类）

//myhead.h
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

#define random(a,b) (rand()%(b-a+1)+a)

template<typename ElemType>
class LinkStack
{
private:
	class LinkNode
	{
	public:
		ElemType data;
		LinkNode *next;
	};
	typedef LinkNode * NodePointer;

public:
	//当前链栈置空
	void clear();

	//求链栈中结点的个数
	int getLength();

	//读栈顶结点的数据域
	Status getTop(ElemType & e);

	//判断链栈是否为空
	bool isEmpty();

	//重载赋值运算符的定义
	LinkStack<ElemType> operator =(LinkStack<ElemType>  rightS);

	//弹出栈顶结点
	Status pop(ElemType & e);

	//在栈顶压入一个数据域为e的结点
	void push(ElemType e);

	//链栈构造函数
	LinkStack();

	//链栈析构函数
	~LinkStack();

	//链栈的拷贝初始化构造函数
	LinkStack(const LinkStack<ElemType> & otherS);

protected:
	NodePointer top;
};

template<typename ElemType>
void LinkStack<ElemType>::clear()
{
	NodePointer s;
	while (top)
	{
		s = top;
		top = top->next;
		delete s;
	}
	top = NULL;
}

template<typename ElemType>
int LinkStack<ElemType>::getLength()
{
	int length = 0;
	NodePointer p = top;
	while (p)
	{
		++length;
		p = p->next;
	}
	return length;
}

template<typename ElemType>
Status LinkStack<ElemType>::getTop(ElemType & e)
{
	if (!top)
		return ERROR;
	e = top->data;
	return OK;
}

template<typename ElemType>
bool LinkStack<ElemType>::isEmpty()
{
	return (top ? false : true);
}

template<typename ElemType>
LinkStack<ElemType> LinkStack<ElemType>::operator=(LinkStack<ElemType> rightS)
{
	NodePointer p;
	NodePointer rp = rightS.top;
	NodePointer s;

	if (this != &rightS)
	{
		clear();

		while (rp)
		{
			s = new (LinkNode);
			assert(s != 0);

			s->data = rp->data;
			if (!top)
				top = s;
			else
				p->next = s;
			p = s;
			rp = rp->next;
		}
		if (p)
			p->next = NULL;
	}
	return *this;
}

template<typename ElemType>
Status LinkStack<ElemType>::pop(ElemType & e)
{
	NodePointer s = top;

	if (!top)
		return ERROR;
	e = top->data;
	top = top->next;
	delete e;
	return OK;
}

template<typename ElemType>
void LinkStack<ElemType>::push(ElemType e)
{
	NodePointer s;
	s = new(LinkNode);
	assert(s != 0);
	s->data = e;
	s->next = top;
	top = s;
}

template<typename ElemType>
LinkStack<ElemType>::LinkStack()
{
	top = NULL;
}

template<typename ElemType>
 LinkStack<ElemType>::~LinkStack()
{
	clear();
}

template<typename ElemType>
LinkStack<ElemType>::LinkStack (const LinkStack<ElemType> & otherS)
{
	NodePointer p = NULL;
	NodePointer op = otherS.top;
	NodePointer s;
	top = NULL;
	while (op)
	{
		s = new (LinkNode);
		assert(s != 0);
		s->data = op->data;
		if (!top)
			top = s;
		else
			p->next = s;
		p = s;
		op = op->next;
	}
	if (p)
		p->next = NULL;
}


//MyLinkStack.h 链栈 数据结构 派生类
template <typename ElemType>
class MyLinkStack:public LinkStack<ElemType>
{
public:
	//输入
	//void read(istream & in);

	//输出
	void display(ostream & out);

	//随机生成
	void RandStack();
};

//template<typename ElemType>
//void MyLinkStack<ElemType>::read(istream & in)
//{
//	
//}
//
//template<typename ElemType>
//istream & operator >> (istream & in, LinkStack<ElemType> & s)
//{
//	s.read(in);
//	return in;
//}

template <typename ElemType>
void MyLinkStack<ElemType>::RandStack()
{
	cout << "依次在链栈的前面插入：" << endl;
	int n,i;
	n= random(2, 5);
	int e;
	for (i = 0; i < n; n++)
	{
		e = random(1, 99);
		typename LinkStack<ElemType>::push(e);
		cout << e << "  ";
	}
	cout << endl;
	cout << "随机生成的链栈如下：" << endl;


}

template<typename ElemType>
void MyLinkStack<ElemType>::display(ostream & out)
{
	typename LinkStack<ElemType>::NodePointer p = this->top;
	int n = typename LinkStack<ElemType>::getLength();
	if (!p&&!n)
	{
		out << "当前链栈为空！";
		return;
	}
	while (p&&n)
	{
		out << "\t" << p->data << "->";
		p = p->next;
	}
	out << "\t↑" << endl;
	out << "\t top" << endl;
}

template<typename ElemType>
ostream & operator <<(ostream & out, MyLinkStack<ElemType> & s)
{
	s.display(out);
	return out;
}
