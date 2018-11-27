//LinkList.h��ջ���ݽṹC++�ඨ�壨���ࣩ

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
	//��ǰ��ջ�ÿ�
	void clear();

	//����ջ�н��ĸ���
	int getLength();

	//��ջ������������
	Status getTop(ElemType & e);

	//�ж���ջ�Ƿ�Ϊ��
	bool isEmpty();

	//���ظ�ֵ������Ķ���
	LinkStack<ElemType> operator =(LinkStack<ElemType>  rightS);

	//����ջ�����
	Status pop(ElemType & e);

	//��ջ��ѹ��һ��������Ϊe�Ľ��
	void push(ElemType e);

	//��ջ���캯��
	LinkStack();

	//��ջ��������
	~LinkStack();

	//��ջ�Ŀ�����ʼ�����캯��
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


//MyLinkStack.h ��ջ ���ݽṹ ������
template <typename ElemType>
class MyLinkStack:public LinkStack<ElemType>
{
public:
	//����
	//void read(istream & in);

	//���
	void display(ostream & out);

	//�������
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
	cout << "��������ջ��ǰ����룺" << endl;
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
	cout << "������ɵ���ջ���£�" << endl;


}

template<typename ElemType>
void MyLinkStack<ElemType>::display(ostream & out)
{
	typename LinkStack<ElemType>::NodePointer p = this->top;
	int n = typename LinkStack<ElemType>::getLength();
	if (!p&&!n)
	{
		out << "��ǰ��ջΪ�գ�";
		return;
	}
	while (p&&n)
	{
		out << "\t" << p->data << "->";
		p = p->next;
	}
	out << "\t��" << endl;
	out << "\t top" << endl;
}

template<typename ElemType>
ostream & operator <<(ostream & out, MyLinkStack<ElemType> & s)
{
	s.display(out);
	return out;
}
