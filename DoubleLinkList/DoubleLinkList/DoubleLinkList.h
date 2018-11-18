//DoubleLinkList.h ѭ��˫�������ݽṹC++�ඨ�壨���ࣩ

//myhead.h
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

#define random(a,b) (rand()%(b-a+1)+a)

//ѭ��˫�������ݽṹC++������
template <typename ElemType>
class DoubleLinkList
{
public:
	//ѭ��˫�������C++������
	class LinkNode
	{
	public:
		ElemType data;  //����������
		LinkNode *next;  //ָ���̽���ָ����
		LinkNode *prior;  //ָ��ǰ������ָ����
	};
	//ָ�����ָ����������
	typedef LinkNode *NodePointer;

	//ѭ��˫�����ÿ�
	void clear();

	//ɾ��ѭ��˫������������Ϊe�ĵ�һ�����
	Status deleteElem(ElemType e);

	//ȡѭ��˫�����i������������
	Status getElem(int i, ElemType & e);

	//ȡѭ��˫�����ͷָ��
	NodePointer getHead();

	//��ѭ��˫�����н��ĸ���
	int getLength();

	//�ڵ�i�����֮ǰ����һ��������Ϊe�Ľ��
	Status insert(int i, ElemType e);

	//�ж�ѭ��˫�����Ƿ�Ϊ��
	bool isEmpty();

	//����ѭ��˫������������Ϊe�ĵ�һ������ָ��
	Status locateElem(ElemType find_e, NodePointer & r);

	//����ĳ����̵�������
	Status nextElem(ElemType e, ElemType & next_e);

	//���ظ�ֵ������Ķ���
	DoubleLinkList<ElemType> operator = (DoubleLinkList<ElemType> rightL);

	//����ĳ���ǰ����������
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


//DoubleLinkList.h ѭ��˫�������ݽṹC++�ඨ�壨�����ࣩ
template <typename ElemType>
class MyDoubleLinkList :public DoubleLinkList <ElemType>
{
public:
	void read(istream & in);

	//���ѭ��������
	void display(ostream & out) const;

	//�������ѭ��������
	void Randborn();
};

//ѭ�����������ݽṹC++���ʵ�֣������ࣩ

template <typename ElemType>
void MyDoubleLinkList<ElemType>::read(istream& in)
{
	typename DoubleLinkList<ElemType>::clear();
	int i;
	typename DoubleLinkList<ElemType>::NodePointer p, s;
	ElemType *elem;
	p = this->head;
	cout << "������ѭ��˫�����н��ĸ�����";
	in >> this->n;
	elem = new ElemType[this->n];
	cout << "������ѭ��˫�����е�ÿ������������ֵ��";
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

//���ܣ���������������Ķ���
//˵����ͨ���ú���������ʹ��C++��cinֱ�ӴӼ���������ѭ��������
template <typename ElemType>
istream& operator>>(istream& in, MyDoubleLinkList<ElemType>& iD)
{
	iD.read(in);
	return in;
}

template <typename ElemType>
void MyDoubleLinkList<ElemType>::display(ostream& out) const
{
	//�������
	typename DoubleLinkList<ElemType>::NodePointer p = this->head;


	if (!p)
	{
		cout << "��ǰѭ��˫����Ϊ��" << endl << endl;
	}
	else
	{
		cout << "��ǰ��ѭ��˫����Ϊ��" << endl;
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
	cout << "���������������ѭ��˫����" << endl;

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
