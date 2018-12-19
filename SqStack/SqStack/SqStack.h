//SqStack.h 顺序栈 数据结构 （基类）

//myhead.h
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

#define STACK_MAX_SIZE 100
#define STACKINCREMENT 10
#define random(a,b) (rand()%(b-a+1)+a);

template <typename ElemType>
class SqStack
{
public:
	void clear();

	int getLength();

	int getStackSize();

	Status getTop(ElemType & e);

	bool isEmpty();

	SqStack<ElemType> operator =(SqStack<ElemType> rightS);

	Status pop(ElemType & e);

	void push(ElemType e);

	SqStack();

	~SqStack();

	SqStack(SqStack<ElemType> & otherS);

//protected:
public:
	ElemType *base;
	ElemType *top;
	int StackSize;
};

template<typename ElemType>
void SqStack<ElemType>::clear()
{
	top = base;
}

template<typename ElemType>
int SqStack<ElemType>::getLength()
{
	return top - base;
}

template <typename ElemType>
int SqStack<ElemType>::getStackSize()
{
	return StackSize;
}

template<typename ElemType>
int SqStack<ElemType>::getTop(ElemType& e)
{
	if (isEmpty())
	{
		return ERROR;
	}
	else
	{
		e = *(top - 1);
	}
	return OK;
}

template <typename ElemType>
bool SqStack<ElemType>::isEmpty()
{
	return (top == base ? true : false);
}

template<typename ElemType>
SqStack<ElemType> SqStack<ElemType>::operator=(SqStack rightS)
{
	int length = rightS.getLength();
	if (this != &rightS)
	{
		if (StackSize < rightS.StackSize)
		{
			delete[] base;
			base = new ElemType[rightS.StackSize];
			assert(base != 0);
			StackSize = rightS.StackSize;
		}

		for (int i = 0; i < length; i++)
		{
			*(base + i) = *(rightS.base + i);
		}
		top = base + length();
	}
	return *this;
}

template<typename ElemType>
Status SqStack<ElemType>::pop(ElemType & e)
{
	if (isEmpty())
	{
		return ERROR;
	}
	else
	{
		e = *--top;
	}
	return OK;
}

template<typename ElemType>
void SqStack<ElemType>::push(ElemType e)
{
	int length = top - base;
	ElemType *newbase;
	if (top - base >= StackSize)
	{
		newbase = new ElemType[StackSize + STACKINCREMENT];
		assert(newbase != 0);
		for (int j = 0; j < length; j++)
		{
			*(newbase + j) = *(base + j);
		}
		delete[]base;

		StackSize += STACKINCREMENT;
		base = newbase;
		top = base + length;
	}
	*top = e;
	++top;
}

template <typename ElemType>
SqStack<ElemType>::SqStack()
{
	base = new ElemType[STACK_MAX_SIZE];
	assert(base != 0);
	StackSize = STACK_MAX_SIZE;
	top = base;
}

template <typename ElemType>
SqStack<ElemType>::~SqStack()
{
	if (base)
		delete[]base;
	StackSize = 0;
	top = base = NULL;
}

template<typename ElemType>
SqStack<ElemType>::SqStack( SqStack & otherS)
{
	int length;
	length = otherS.getLength();
	base = new ElemType[otherS.StackSize];
	assert(base != 0);
	StackSize = otherS.StackSize;
	for (int i = 0; i < length; i++)
	{
		*(base + i) = *(otherS.base + i);
	}
	top = base + length;
}


//顺序栈派生类 MySqStack.h
template<typename ElemType>
class MySqStack : public SqStack<ElemType>
{
public:
	MySqStack(ElemType *p, int nsize);
	MySqStack() {}
	void display(ostream & out);
	//void read();
	void randStack();
};
	                                                                             
template<typename ElemType>
void MySqStack<ElemType>::display(ostream & out)
{
	if (typename SqStack<ElemType>::isEmpty())
		cout << "当前顺序栈为空" << endl;
	else
	{
		int i;
		int length = typename SqStack<ElemType>::getLength();
		for (i = 0; i < length; i++)
			cout << " \t" << *(this->base + i) ;
		cout << endl;
		for (i = 0; i <= length; ++i)
		{
			if (i == 0)
				cout << "\t↑";
			else
				if (i == length)
					cout << "\t↑" << endl;
				else
					cout << "\t";
		}
		for (i = 0; i <= length; ++i)
		{
			if (i == 0)
				cout << "\t base";
			else if (i == length)
				cout << "\t top";
			else
				cout << "\t";
		}
		cout << endl;
	}
}

template<typename ElemType>
ostream & operator <<(ostream & out, MySqStack<ElemType> & s)
{
	s.display(out);
	return out;
}

template<typename ElemType>
MySqStack<ElemType>::MySqStack(ElemType *p, int nsize)
{
	int *next = new ElemType[100];
	assert(next != 0);
	int n = nsize;
	if (n < 0)  n = 0;
	for (int i = 0; i < n; i++)
	{
		next[i] = p[i];
	}
	for (int j = 0; j < n; ++j)
		*(this->base + j) = next[j];
	this->top = this->base + n;
}


template<typename ElemType>
void MySqStack<ElemType>::randStack()
{
	int a = random(2, 6);
	ElemType e;
	cout << "随机生成顺序栈中的一些元素如下：" << endl;
	for (int i = 0; i < a; i++)
	{
		e= random(1, 100);
		typename SqStack<ElemType>::push(e);
		cout << e << "  ";
	}
	cout << endl;
	cout << "随机生成的顺序栈（采用顺序存储）如下：" << endl;
}
