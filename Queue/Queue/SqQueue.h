//SqQueue.h 循环顺序队列数据结构C++类定义（基类）

//myhead.h包含自己设定的一些常量和类型
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

#define random(a,b) (rand()%(b-a+1)+a);

template<typename ElemType>
class SqQueue
{
public:
	//把循环顺序队列置空
	void clear();

	//出队列（删除循环顺序队列队头元素）
	Status deQueue(ElemType & e);

	//进队列（在循环顺序队列队尾插入元素）
	Status enQueue(ElemType e);

	//读循环顺序队列的队头元素
	Status getFront(ElemType & e);

	//求循环顺序队列中元素的个数
	int getLength();

	//判断循环顺序队列是否为空
	bool isEmpty();

	//判断循环顺序队列是否满
	bool isFull();

	//重载赋值运算符的定义
	SqQueue<ElemType> operator = (SqQueue<ElemType> rightQ);

	//循环顺序队列构造函数
	SqQueue(int size=10);

	//循环顺序队列析构函数
	~SqQueue();

	//循环顺序队列拷贝初始化构造函数
	SqQueue(const SqQueue<ElemType> & otherQ);

protected:
	int rear;  //队尾下标
	int front;  //队头下标
	int queueSize;  //循环顺序队列最大存储空间
	ElemType *base;  //循环顺序队列动态存储空间首地址
};

template <typename ElemType>
void SqQueue<ElemType>::clear()
{
	front = rear;
}

template <typename ElemType>
Status SqQueue<ElemType>::deQueue(ElemType & e)
{
	if (isEmpty())
		return ERROR;

	e = base[front];
	front = (front + 1) % queueSize;
	return OK;
}

template<typename ElemType>
Status SqQueue<ElemType>::enQueue(ElemType e)
{
	/*
	if (isFull())
		return ERROR;
		*/
	base[rear] = e;
	rear = (rear + 1) % queueSize;
	return OK;
}

template<typename ElemType>
Status SqQueue<ElemType>::getFront(ElemType & e)
{
	if (isEmpty())
		return ERROR;
	e = base[front];
	return OK;
}

template<typename ElemType>
int SqQueue<ElemType>::getLength()
{
	return (rear - front + queueSize) % queueSize;
}

template<typename ElemType>
bool SqQueue<ElemType>::isEmpty()
{
	return front == rear ? true : false;
}

template<typename ElemType>
bool SqQueue<ElemType>::isFull()
{
	return (rear + 1)%queueSize == front ? true : false;
}

template<typename ElemType>
SqQueue<ElemType> SqQueue<ElemType>::operator=(SqQueue<ElemType> rightQ)
{
	if (this != &rightQ)
	{
		if (queueSize != rightQ.queueSize)
		{
			delete[] base;
			base = new ElemType[rightQ.queueSize];
			assert(base != 0);
			queueSize = rightQ.queueSize;
		}
		front = rightQ.front;
		rear = rightQ.rear;
		for (int j = front; j%queueSize != rear;)
		{
			base[j] = rightQ.base[j];
			j = (j + 1) % queueSize;
		}
	}
	return *this;
}

template <typename ElemType>
SqQueue<ElemType>::SqQueue(int size)
{
	base = new ElemType[size];
	assert(base != 0);
	front = rear = 0;
	queueSize = size;
}

template <typename ElemType>
SqQueue<ElemType>::~SqQueue()
{
	delete[] base;
}

template <typename ElemType>
SqQueue<ElemType>::SqQueue(const SqQueue<ElemType> & otherQ)
{
	base = new ElemType[otherQ.queueSize];
	assert(base != 0);
	queueSize = otherQ.queueSize;
	front = otherQ.front;
	rear = otherQ.rear;
	for (int j = front; j%queueSize != rear;)
	{
		base[j] = otherQ.base[j];
		j = (j + 1) % queueSize;
	}
}

template<typename ElemType>
class MySqQueue : public SqQueue<ElemType>
{
public:
	MySqQueue(ElemType *p, int nsize, int z);
	MySqQueue() {};
	void display();
	void RandQ();
};

template<typename ElemType>
MySqQueue<ElemType>::MySqQueue(ElemType *p, int nsize, int z)
{
	int *next = new ElemType[100];
	assert(next != 0);
	int n = nsize;
	if (n < 0)  n = 0;
	for (int i = 0; i < n; i++)
	{
		next[i] = p[i];
	}
	int m = 0;
	if (z + n <= this->queueSize)
		for (int j = z; j <= z + n; ++j)
		{
			*(this->base + j) = next[m];
			m++;
		}
	else
	{
		for (int j = z; j < this->queueSize; j++)
		{
			*(this->base + j) = next[m];
			m++;
		}
		for (int j = 0; j < (z + n) % this->queueSize; j++)
		{
			*(this->base + j) = next[m];
			m++;
		}
	}
	this->front = z;
	this->rear = (this->front + n) % this->queueSize;
}

template<typename ElemType>
void MySqQueue<ElemType>::display()
{
	if (typename SqQueue<ElemType>::isEmpty())
		cout << "空" << endl;
	else
	{
		int i;
		int length = typename SqQueue<ElemType>::getLength();
		for (i = 0; i < this->queueSize; i++)
		{
			if (i < 9)
				cout << "  [ " << i + 1 << "]";
			else
				cout << "  [" << i + 1 << "]";
		}
		cout << endl;
		if (this->front < this->rear)
		{
			for (i = 0; i < this->front; i++)
				cout << "      ";
			if (this->rear < this->queueSize)
			{
				for (i = this->front; i < this->rear; i++)
				{
					if (*(this->base + i) <= 9)
						cout << "    " << *(this->base + i) << " ";
					else
						cout << "   " << *(this->base + i) << " ";
				}
				for (i = this->rear; i < this->queueSize; i++)
					cout << "      ";
			}
			else
			{
				for (i = this->rear; i < this->queueSize; i++)
				{
					if (*(this->base + i) <= 9)
						cout << "    " << *(this->base + i) << " ";
					else
						cout << "   " << *(this->base + i) << " ";
				}
			}
		}
		if (this->rear < this->front)
		{
			for (i = 0; i < this->rear; i++)
			{
				if (*(this->base + i) <= 9)
					cout << "    " << *(this->base + i) << " ";
				else
					cout << "   " << *(this->base + i) << " ";
			}
			for (i = this->rear; i < this->front; i++)
				cout << "      ";
			for (i = this->front; i < this->queueSize; i++)
			{
				if (*(this->base + i) <= 9)
					cout << "    " << *(this->base + i) << " ";
				else
					cout << "   " << *(this->base + i) << " ";
			}
		}
		cout << endl;
		for (i = 0; i < this->queueSize; ++i)
		{
			if (i == this->rear)
				cout << "   ↑ ";
			else if (i == this->front)
				cout << "   ↑ ";
			else
				cout << "      ";
		}
		cout << endl;
		for (i = 0; i < this->queueSize; ++i)
		{
			if (i == this->front)
				cout << " front";
			else if (i == this->rear)
				cout << "  rear";
			else
				cout << "      ";
		}
		cout << endl;
	}
}

template<typename ElemType>
void MySqQueue<ElemType>::RandQ()
{
	int n = random(2, 8);
	int e;
	cout << "用如下随机数生出循环顺序队列：" << endl;
	for (int i = 0; i < n; i++)
	{
		e = random(1, 99);
		cout << e << "  ";
		typename SqQueue<ElemType>::enQueue(e);
	}
	cout << endl;
	cout << "随机生成的循环顺序队列如下：" << endl;
}