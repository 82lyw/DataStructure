//DoubleLinkList.h 循环双链表数据结构C++类定义（基类）

//myhead.h
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

#define random(a,b) (rand()%(b-a+1)+a)

//循环双链表数据结构C++类声明
template <typename ElemType>
class DoubleLinkList
{
public:
	//循环双链表结点的C++类声明
	class LinkNode
	{
	public:
		ElemType data;  //结点的数据域
		LinkNode *next;  //指向后继结点的指针域
		LinkNode *prior;  //指向前驱结点的指针域
	};
	//指向结点的指针类型声明
	typedef LinkNode *NodePointer;

	//循环双链表置空
	void clear();

	//删除循环双链表中数据域为e的第一个结点
	Status deleteElem(ElemType e);

	//取循环双链表第i个结点的数据域
	Status getElem(int i, ElemType & e);

	//取循环双链表的头指针
	NodePointer getHead();

	//求循环双链表中结点的个数
	int getLength();

	//在第i个结点之前插入一个数据域为e的结点
	Status insert(int i, ElemType e);

	//判断循环双链表是否为空
	bool isEmpty();

	//返回循环双链表中数据域为e的第一个结点的指针
	Status locateElem(ElemType find_e, NodePointer & r);

	//返回某结点后继的数据域
	Status nextElem(ElemType e, ElemType & next_e);

	//重载赋值运算符的定义
	DoubleLinkList<ElemType> operator = (DoubleLinkList<ElemType> rightL);

	//返回某结点前驱的数据域
	Status priorElem(ElemType e, ElemType & prior_e);

	DoubleLinkList();

	~DoubleLinkList();

	DoubleLinkList(const DoubleLinkList<ElemType> & otherL);

protected:
	NodePointer head;
};

template <typename ElemType>
void DoubleLinkList<ElemType>::clear()
{
	NodePointer r, p;

	if (!head)
		return;

	p = head->prior;
	while (p != head)
	{
		r = p->prior;
		delete p;
		p = r;
	}

	delete p;
	head = NULL;
}

template <typename ElemType>
Status DoubleLinkList<ElemType>::deleteElem(ElemType e)
{
	NodePointer p;

	if (!locateElem(e, p))
		return ERROR;

	if (head->next == head)
		head = NULL;
	else
	{
		if (p == head)
			head = p->next;

		p->prior->next = p->next;
		p->next->prior = p->prior;
	}
	delete p;
	return OK;
}

template <typename ElemType>
Status DoubleLinkList<ElemType>::getElem(int i, ElemType & e)
{
	int j = 1;
	NodePointer p = head;

	while (p&&p->next != head && j < i)
	{
		p = p->next;
		++j;
	}

	if (j == i)
	{
		e = p->data;
		return OK;
	}

	return ERROR;
}

template<typename ElemType>
typename DoubleLinkList<ElemType>::NodePointer DoubleLinkList<ElemType>::getHead()
{
	return head;
}

template<typename ElemType>
int DoubleLinkList<ElemType>::getLength()
{
	int length = 0;
	NodePointer p = head;

	while (p)
	{
		++length;
		p = p->next;
		if (p == head)
		{
			break;
		}
	}
	return length;
}

template<typename ElemType>
Status DoubleLinkList<ElemType>::insert(int i, ElemType e)
{
	int j = 1;
	NodePointer p = head;
	NodePointer s;

	while (p&&p->next != head && j < i)
	{
		p = p->next;
		++j;
	}
	if (!head&&i != 1 || j < i)
		return ERROR;

	s = new(LinkNode);
	assert(s != 0);

	s->data = e;

	if (i == 1)
	{
		if (!head)
		{
			head = s->prior = s->next = s;
			return OK;
		}
		head = s;
	}
	p->prior -> next = s;
	s->prior = p->prior;
	p->prior = s;
	s->next = p;

	return OK;
}

template<typename ElemType>
bool DoubleLinkList<ElemType>::isEmpty()
{
	return (head ? false : true);
}

template<typename ElemType>
Status DoubleLinkList<ElemType>::locateElem(ElemType e, NodePointer & r)
{
	NodePointer p = head;

	while (p&&p->next != head && p->data != e)
		p = p->next;

	if (p->data == e)
	{
		r = p;
		return OK;
	}
	else
		return ERROR;
}

template<typename ElemType>
Status DoubleLinkList<ElemType>::nextElem(ElemType e,ElemType & next_e)
{
	NodePointer p;
	if (locateElem(e, p))
	{
		next_e = p->next -> data;
		return OK;
	}
	else
		return ERROR;
}

template<typename ElemType>
DoubleLinkList<ElemType> DoubleLinkList<ElemType>::operator=(DoubleLinkList<ElemType> rightL)
{
	NodePointer p = NULL;
	NodePointer rp = rightL.getHead;
	NodePointer s;

	if (this != &rightL)
	{
		clear();

		while (rp)
		{
			s = new(LinkNode);
			assert(s != 0);

			s->data = rp->data;

			if (!head)
				head = p = s;
			p->next = s;
			p->prior = p;

			p = s;
			rp = rp->next;
			if (rp == rightL.head)
				break;
		}

		if (head)
		{
			head->prior = p;
			p->next = head;
		}
	}
	return *this;
}

template <typename ElemType>
Status DoubleLinkList<ElemType>::priorElem(ElemType e, ElemType & prior_e)
{
	NodePointer p;
	if (locateElem(e, p))
	{
		prior_e = p->prior->data;
		return OK;
	}
	else
		ERROR;
}

template <typename ElemType>
DoubleLinkList<ElemType>::DoubleLinkList()
{
	head = NULL;
}

template <typename ElemType>
DoubleLinkList<ElemType>::~DoubleLinkList()
{
	clear();
}

template <typename ElemType>
DoubleLinkList<ElemType>::DoubleLinkList(const DoubleLinkList<ElemType> & otherL)
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
			head = p = s;
		p->next = s;
		s->prior = p;

		p = s;
		op = op->next;

		if (op == otherL.head)
		{
			break;
		}
	}

	if (head)
	{
		head->prior = p;
		p->next = head;
	}
}


//DoubleLinkList.h 循环双链表数据结构C++类定义（派生类）
template <typename ElemType>
class MyDoubleLinkList :public DoubleLinkList <ElemType>
{
public:
	void read(istream & in);

	//输出循环单链表
	void display(ostream & out) const;

	//随机生成循环单链表
	void Randborn();
};

//循环单链表数据结构C++类的实现（派生类）

template <typename ElemType>
void MyDoubleLinkList<ElemType>::read(istream& in)
{
	typename DoubleLinkList<ElemType>::clear();
	int i;
	typename DoubleLinkList<ElemType>::NodePointer p, s;
	ElemType *elem;
	p = this->head;
	cout << "请输入循环双链表中结点的个数：";
	in >> this->n;
	elem = new ElemType[this->n];
	cout << "请输入循环双链表中的每个结点数据域的值：";
	for (i = 0; i < this->n; i++)
	{
		in > elem[i];
	}

	for (i = 0; i < this->n; i++)
	{
		s = new typename DoubleLinkList<ElemType>::LinkNode;
		assert(s != 0);
		s->data=elem[i];
		if (!this->head)
		{
			this->head = s;
			this->head->next = this->head->prior = this->head;
		}
		else
		{
			p->next = s;
			s->prior = p;
		}
		p = s;
		if (p)
			p->next = NULL;
	}
	p->next = this->head;
	this->head->prior = p;
}

//功能：重载输入运算符的定义
//说明：通过该函数，可以使用C++中cin直接从键盘上输入循环单链表
template <typename ElemType>
istream& operator>>(istream& in, MyDoubleLinkList<ElemType>& iD)
{
	iD.read(in);
	return in;
}

template <typename ElemType>
void MyDoubleLinkList<ElemType>::display(ostream& out) const
{
	//输出操作
	typename DoubleLinkList<ElemType>::NodePointer p = this->head;


	if (!p)
	{
		cout << "当前循环双链表为空" << endl << endl;
	}
	else
	{
		cout << "当前的循环双链表为：" << endl;
		for (int i = 1; i <= this.getLength(); i++)
			cout << "[ " << i << "] \t";
		cout << endl;
		while (p->next != this->head)
		{
			cout << " " << p->data << "->\t";
			p = p->next;
		}
		cout << " " << p->data << endl;
	}
}

template <typename ElemType>
ostream & operator <<(ostream &out, const MyDoubleLinkList<ElemType>&oD)
{
	oD.display(out);
	return out;
}

template<typename ElemType>
void MyDoubleLinkList<ElemType>::Randborn()
{
	typename DoubleLinkList<ElemType>::clear();
	int n, i;
	typename DoubleLinkList<ElemType>::NodePointer p, s;
	p = this->head;
	n = random(2, 8);
	cout << "用如下随机数生成循环双链表：" << endl;

	for (i = 0; i < n; i++)
	{
		s = new typename DoubleLinkList<ElemType>::LinkNode;
		assert(s != 0);
		s->data = random(1, 99);
		cout << s->data;
		if (!this->head)
		{
			this->head = s;
			this->head->next = this->head->prior = this->head;
		}
		else
		{
			p->next = s;
			s->prior = p;
		}
		p = s;
		if (p)
			p->next = NULL;
	}
	p->next = this->head;
	this->head->prior = p;
}
