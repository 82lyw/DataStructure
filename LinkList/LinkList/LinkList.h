//LinkList.h��ѭ�����������ݽṹC++�ඨ�壨���ࣩ

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

	//��ѭ�������������
	void adverse();

	//�ѷ�ѭ���������ÿ�
	void clear();

	//ɾ����ѭ����������������Ϊe�ĵ�һ�����
	Status deleteElem(ElemType e);

	//ɾ����ѭ���������е��ظ�ֵ
	void deleteRepeat();

	//ȡ��ѭ��������ĵ�i�����
	Status getElem(int i, ElemType & e);

	//ȡ��һ������ָ��
	NodePointer getHead();

	//���ѭ����������ĸ���
	int getLength();

	//�ڵ�i�����֮ǰ����һ��������Ϊe�Ľ��
	Status insert(int i, ElemType e);

	//�Ƿ�Ϊ��
	bool isEmpty();

	//���ҵ�һ����e����compare������ϵ�Ľ��
	Status locateElem(ElemType e, Status(*compare)(ElemType, ElemType), int & i);

	//����ĳ���ǰ����������
	Status nextElem(ElemType e, ElemType & next_e);

	//����ĳ���ǰ����������
	Status priorElem(ElemType e, ElemType &prior_e);

	//�Զ����õĹ��캯��
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
		cout << "�Ҳ����ý��" << endl;
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
	//����
	void read(istream & in);
	void inputLinkList();

	//���
	void display(ostream & out);

	//�������
	void RandomLink();

	//���ظ�ֵ�����
	MyLinkList<ElemType> operator = (MyLinkList<ElemType> rightL);
};

template<typename ElemType>
void MyLinkList<ElemType>::read(istream & in)
{
	/*int n, i;
	ElemType *elem;
	typename LinkList<ElemType>::NodePointer p = this->head;
	typename LinkList<ElemType>::NodePointer s;
	cout << "�������ѭ���������н��ĸ�����";
	cin >> n;
	cout << "������������Ϊ��";
	for (i = 0; i < n; i++)
	{
		cin >> elem[i];
	}
	cout << "������ķ�ѭ��������Ϊ��" << endl;
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
			cout << " " << p->data << "��";
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
	cout << "�������ѭ���������н��ĸ�����";
	cin >> n;
	cout << "������������Ϊ��";
	for (i = 0; i < n; i++)
	{
		cin >> elem[i];
	}
	cout << "������ķ�ѭ��������Ϊ��" << endl;
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
	cout << " " << p->data << "��";
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
	cout << "��������������ɷ�ѭ��������:" << endl;
	for (i = 0; i < n; i++)
	{
		elem[i] = random(1, 100);
		cout << elem[i] << "\t";
	}
	cout << endl << endl;
	cout << "������ɵķ�ѭ��������Ϊ��" << endl;
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
	cout << " " << p->data << "��";
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
		cout << "��ǰ��ѭ��������Ϊ��" << endl<<endl;
	}
	else
	{

		//forѭ������ӡ����
		cout << "��ǰ��ѭ��������Ϊ��" << endl;
		for (int i = 1; i <= this->getLength(); i++)
			cout << "[ " << i << "] \t";
		cout << endl;
		while (p->next)
		{
			cout << " " << p->data << "->\t";
			p = p->next;
		}
		cout << " " << p->data << "��";
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