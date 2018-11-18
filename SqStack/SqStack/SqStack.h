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

protected:
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


template <typename ElemType>
class MySqStack :public SqStack<ElemType>
{
public:
	void read();
	void display();
};
























