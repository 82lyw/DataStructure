//LinkList.h非循环单链表数据结构C++类定义（基类）

//myhead.h
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

#define random(a,b) (rand()%(b-a+1)+a)

template<typename ElemType>
class LinkList
{
public:
	class LinkNode
	{
	public:
		ElemType data;
		LinkNode *next;
	};
	typedef LinkNode * NodePointer;

	//void inputLinkList();

	//void RandomLink();

	//非循环单链表的逆置
	void adverse();

	//把非循环单链表置空
	void clear();

	//删除非循环单链表中数据域为e的第一个结点
	Status deleteElem(ElemType e);

	//删除非循环单链表中的重复值
	void deleteRepeat();

	//取非循环单链表的第i个结点
	Status getElem(int i, ElemType & e);

	//取第一个结点的指针
	NodePointer getHead();

	//求非循环单链表结点的个数
	int getLength();

	//在第i个结点之前插入一个数据域为e的结点
	Status insert(int i, ElemType e);

	//是否为空
	bool isEmpty();

	//查找第一个与e满足compare（）关系的结点
	Status locateElem(ElemType e, Status(*compare)(ElemType, ElemType), int & i);

	//返回某结点前驱的数据域
	Status nextElem(ElemType e, ElemType & next_e);

	//返回某结点前驱的数据域
	Status priorElem(ElemType e, ElemType &prior_e);

	//自动调用的构造函数
	LinkList();

	~LinkList();

	LinkList(const LinkList<ElemType> & otherL);

protected:
	NodePointer head;
};

template<typename ElemType>
void LinkList<ElemType>::adverse()
{
	NodePointer r, p, q;
	if (!head)
		return;
	r = NULL, p = head, q = p->next;
	while (p)
	{
		p->next = r;

		r = p;
		p = q;
		if (q)
		{
			q = p->next;
		}
		head = r;
	}
}

template<typename ElemType>
void LinkList<ElemType>::clear()
{
	NodePointer p, q;
	p = NULL, q = head;
	while (q)
	{
		p = q;
		q = q->next;
		delete p;
	}
	head = NULL;
}

template<typename ElemType>
Status LinkList<ElemType>::deleteElem(ElemType e)
{
	NodePointer r, p;
	r = NULL, p = head;
	while (p && !equal(p->data, e))
	{
		r = p;
		p = p->next;
	}
	if (p == NULL)
		return ERROR;
	if (r == NULL)
		head = head->next;
	else
		r->next = p->next;

	free(p);
	return OK;
}

template<typename ElemType>
void LinkList<ElemType>::deleteRepeat()
{
	NodePointer r, p;
	NodePointer s;
	r = NULL, p = head;
	while (p)
	{
		s = head;
		while (s != p)
		{
			if (s->data == p->data)
			{
				r->next = p->next;
				delete  p;
				p = r;
				break;
			}
			s = s->next;
		}
		r = p;
		if (p)
			p = p->next;
	}
}

template<typename ElemType>
Status LinkList<ElemType>::getElem(int i, ElemType & e)
{
	int j = 1;
	NodePointer p = head;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;
	return OK;
}

template<typename ElemType>
typename LinkList<ElemType>::NodePointer LinkList<ElemType>:: getHead()
{
	return head;
}

template<typename ElemType>
int LinkList<ElemType>::getLength()
{
	int n = 0;
	NodePointer p = head;
	while (p)
	{
		++n;
		p = p->next;
	}
	return n;
}

template<typename ElemType>
Status LinkList<ElemType>::insert(int i, ElemType e)
{
	int j = 1;
	NodePointer p = head;
	NodePointer s;

	while (p&&j < i-1)
	{
		j++;
		p = p->next;
	}
	if (!p || j > i)
	{
		return ERROR;
	}
	s = new LinkNode;
	assert(s != 0);

	s->data = e;

	if (i == 1)
	{
		s->next = head;
		head = s;
	}
	else
	{
		s->next = p->next;
		p->next = s;
	}

	return OK;
}

template<typename ElemType>
bool LinkList<ElemType>::isEmpty()
{
	return (head ? false : true);
}

template<typename ElemType>
Status LinkList<ElemType>::locateElem(ElemType e, Status(*compare)(ElemType, ElemType), int & i)
{
	NodePointer p = head;
	i = 1;
	while (p && !(*compare)(p->data, e))
	{
		p = p->next;
		++i;
	}
	if (!p)
	{
		cout << "找不到该结点" << endl;
		return ERROR;
	}

	return OK;
}

template<typename ElemType>
Status LinkList<ElemType>::nextElem(ElemType e, ElemType & next_e)
{
	NodePointer p = head;
	while (p && !equal(p->data, e))
		p = p->next;
	if (!p || !p->next)
		return ERROR;
	next_e = p->next->data;
	return OK;
}

template<typename ElemType>
Status LinkList<ElemType>::priorElem(ElemType e, ElemType & prior_e)
{
	NodePointer r = NULL;
	NodePointer p = head;
	while (p && !equal(p->data, e))
	{
		r = p;
		p = p->next;
	}

	if (!p || !r)
	{
		return ERROR;
	}
	prior_e = r->data;
	return OK;
}

template<typename ElemType>
LinkList<ElemType>::LinkList()
{
	head = NULL;
}

template<typename ElemType>
LinkList<ElemType>::~LinkList()
{
	clear();
}

template<typename ElemType>
LinkList<ElemType>::LinkList(const LinkList & otherL)
{
	NodePointer p;
	NodePointer op = otherL.head;
	NodePointer s;
	head = p = NULL;
	while (op)
	{
		s = new LinkNode;
		assert(s != 0);
		s->data = op->data;
		if (!head)
			head = s;
		else
			p->next = s;
		p = s;
		op = op->next;
	}
	if (head)
		p->next = NULL;
}


template<typename ElemType>
class MyLinkList :public LinkList<ElemType>
{
public:
	//输入
	void read(istream & in);
	void inputLinkList();

	//输出
	void display(ostream & out);

	//随机生成
	void RandomLink();

	//重载赋值运算符
	MyLinkList<ElemType> operator = (MyLinkList<ElemType> rightL);
};

template<typename ElemType>
void MyLinkList<ElemType>::read(istream & in)
{
	/*int n, i;
	ElemType *elem;
	typename LinkList<ElemType>::NodePointer p = this->head;
	typename LinkList<ElemType>::NodePointer s;
	cout << "请输入非循环单链表中结点的个数：";
	cin >> n;
	cout << "各结点的数据域为：";
	for (i = 0; i < n; i++)
	{
		cin >> elem[i];
	}
	cout << "新输入的非循环单链表为：" << endl;
	for (i = 1; i <= n + 1; i++)
		cout << "[ " << i << "] \t";
	cout << endl;
	for (i = 0; i < n; i++)
	{
		s = new typename LinkList<ElemType>::LinkNode;
		assert(s != 0);
		s->data = elem[i];
		if (!this->head)
			this->head = s;
		else
			p->next = s;
		p = s;
		if (p)
			p->next = NULL;
	}
	p = this->head;
	while (p)
	{
		while (p->next != NULL)
		{
			cout << " " << p->data << "->";
			break;
		}
		while (p->next == NULL)
		{
			cout << " " << p->data << "∧";
			break;
		}
		p = p->next;
	}*/
	cout << endl;
}

template<typename ElemType>
void MyLinkList<ElemType>::inputLinkList()
{
	typename LinkList<ElemType>::clear();
	int n, i;
	ElemType *elem=new ElemType[100];
	typename LinkList<ElemType>::NodePointer p = this->head;
	typename LinkList<ElemType>::NodePointer s;
	cout << "请输入非循环单链表中结点的个数：";
	cin >> n;
	cout << "各结点的数据域为：";
	for (i = 0; i < n; i++)
	{
		cin >> elem[i];
	}
	cout << "新输入的非循环单链表为：" << endl;
	for (i = 1; i <= n ; i++)
		cout << "[ " << i << "] \t";
	cout << endl;
	for (i = 0; i < n; i++)
	{
		s = new typename LinkList<ElemType>::LinkNode;
		assert(s != 0);
		s->data = elem[i];
		if (!this->head)
			this->head = s;
		else
			p->next = s;
		p = s;
		if (p)
			p->next = NULL;
	}
	p = this->head;
	while (p->next)
	{
		cout << " " << p->data << "->\t";
		p = p->next;
	}
	cout << " " << p->data << "∧";
	cout << endl;
}

template <typename ElemType>
void MyLinkList<ElemType>::RandomLink()
{
	typename LinkList<ElemType>::clear();
	int i, n;
	ElemType *elem = new ElemType[100];
	typename LinkList<ElemType>::NodePointer p = this->head;
	typename LinkList<ElemType>::NodePointer s;
	n = random(4, 10);
	cout << "用如下随机数生成非循环单链表:" << endl;
	for (i = 0; i < n; i++)
	{
		elem[i] = random(1, 100);
		cout << elem[i] << "\t";
	}
	cout << endl << endl;
	cout << "随机生成的非循环单链表为：" << endl;
	for (i = 1; i <= n; i++)
		cout << "[ " << i << "] \t";
	cout << endl;
	for (i = 0; i < n; i++)
	{
		s = new typename LinkList<ElemType>::LinkNode;
		assert(s != 0);
		s->data = elem[i];
		if (!this->head)
			this->head = s;
		else
			p->next = s;
		p = s;
		if (p)
			p->next = NULL;
	}
	p = this->head;
	while (p->next)
	{
		cout << " " << p->data << "->\t";
		p = p->next;
	}
	cout << " " << p->data << "∧";
	cout << endl;
}

template<typename ElemType>
istream & operator >> (istream & in, MyLinkList<ElemType> & s)
{
	s.read(in);
	return in;
}

template<typename ElemType>
void MyLinkList<ElemType>::display(ostream & out)
{
	typename LinkList<ElemType>::NodePointer p = this->head;
	if (!p)
	{
		cout << "当前非循环单链表为空" << endl<<endl;
	}
	else
	{

		//for循环，打印链表
		cout << "当前非循环单链表为：" << endl;
		for (int i = 1; i <= this->getLength(); i++)
			cout << "[ " << i << "] \t";
		cout << endl;
		while (p->next)
		{
			cout << " " << p->data << "->\t";
			p = p->next;
		}
		cout << " " << p->data << "∧";
		cout << endl;
	}
}

template<typename ElemType>
ostream & operator <<(ostream & out, MyLinkList<ElemType> & s)
{
	s.display(out);
	return out;
}

template <typename ElemType>
MyLinkList<ElemType> MyLinkList<ElemType>::operator = (MyLinkList<ElemType>rightL)
{
	typename LinkList<ElemType>::NodePointer p = NULL;
	typename LinkList<ElemType>::NodePointer rp = rightL.getHead();
	typename LinkList<ElemType>::NodePointer s;

	if (this != &rightL)
	{
		typename LinkList<ElemType>::clear();
		while (rp)
		{
			s = new typename LinkList<ElemType>::LinkNode;
			assert(s != 0);
			s->data = rp->data;
			if (!this->head)
				this->head = s;
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