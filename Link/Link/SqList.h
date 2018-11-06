//SqList.h 顺序表数据结构C++类定义（基类）

//myhead.h包含自己设定的一些常量和类型
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\data\head.h"
#endif

#define LIST_MAX_SIZE 100
#define LISTINCREMENT 10
#define random(a,b) (rand()%(b-a+1)+a)

//顺序表数据结构C++类声明（基类）

template <typename ElemType>
class SqList
{
public:
	//随机生成顺序表（0-99之间的整数）
	void RandomBorn();

	//输入
	void inputList();

	//有序顺序表折半查找
	int bin_Search(ElemType key);

	//顺序表置空
	void clear();

	//删除第i个元素
	Status deleteElem(int i, ElemType & e);

	//取第i个元素
	Status getElem(int i, ElemType & e);

	//取顺序表存储空间的个数
	int getLength();

	//取顺序表存储空间的大小
	int getListSize();

	//在第i个元素之前插入一个元素
	Status insert(int i, ElemType e);

	//判断顺序表是否为空
	bool isEmpty();

	//查找第i个与e满足compare()关系的序号
	int locateElem(ElemType e, Status(*compare)(ElemType, ElemType));

	//返回某元素的后继
	Status nextElem(ElemType e, ElemType & next_e);

	//重载赋值运算符
	SqList<ElemType> operator = (SqList<ElemType> rightL);

	//返回某元素的前驱
	Status priorElem(ElemType e, ElemType & prior_e);

	//在顺序表中顺序查找某元素
	int sequentialSearch(ElemType e);

	//构造函数及析构函数
	SqList();
	~SqList();
	SqList(const SqList<ElemType>& otherL);

protected:
	ElemType *elem;  //顺序表动态存储空间的首地址
	int listSize;  //顺序表当前已分配的存储空间
	int n;  //顺序表当前的个数
};

template <typename ElemType>
void SqList<ElemType>::inputList()
{
	int j;
	cout << "请输入顺序表中元素的个数：";
	cin >> j;
	n = j;
	for (int i = 0; i < n; i++)
	{
		cin >> elem[i];
	}
}

template <typename ElemType>
void SqList<ElemType>::RandomBorn()
{
	/*delete[] elem;
	listsize = 10;
	elem = new elemtype[listsize];
	assert(elem != 0);*/
	int i;
	n = 10;
	cout << "用以下随机数作为当前顺序表的元素：" << endl;
	for (i = 0; i < 10; i++)
	{
		elem[i] = random(1, 99);
		cout << elem[i] << "\t";
	}
	cout << endl;
}

template <typename ElemType>
int SqList<ElemType>::bin_Search(ElemType key)
{
	int low, mid, high;
	low = 0, high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (elem[mid] == key)
			return mid + 1;
		else if (elem[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return 0;
}

template<typename ElemType>
void SqList<ElemType>::clear()
{
	n = 0;
}

template<typename ElemType>
Status SqList<ElemType>::deleteElem(int i, ElemType & e)
{
	if (i<1 || i>n) return ERROR;
	e = elem[i - 1];
	for (int j = i + 1; j <= n; ++j)
	{
		elem[j - 2] = elem[j - 1];
	}
	--n;
	return OK;
}

template<typename ElemType>
Status SqList<ElemType>::getElem(int i, ElemType & e)
{
	if (i<1 || i>n) return ERROR;
	e = elem[i - 1];
	return OK;
}

template<typename ElemType>
int SqList<ElemType>::getLength()
{
	return n;
}

template<typename ElemType>
int SqList<ElemType>::getListSize()
{
	return listSize;
}

template<typename ElemType>
Status SqList<ElemType>::insert(int i, ElemType e)
{
	ElemType *newbase;
	if (i<1 || i>n + 1) return ERROR;
	if (n >= listSize)
	{
		newbase = new ElemType[listSize + LISTINCREMENT];
		assert(newbase != 0);
		for (int j = 1; j <= n; ++j)
		{
			newbase[j - 1] = elem[j - 1];
		}
		delete[] elem;
		elem = newbase;
		listSize += LISTINCREMENT;
	}
	for (int j = n; j >= i; --j)
	{
		elem[j] = elem[j - 1];
	}
	elem[i - 1] = e;
	++n;
	return OK;
}

template<typename ElemType>
bool SqList<ElemType>::isEmpty()
{
	return n ? false : true;
}

template<typename ElemType>
int SqList<ElemType>::locateElem(ElemType e, Status(*compare)(ElemType, ElemType))
{
	int i;
	for (i = 1; i <= n && !(*compare)(elem[i - 1], e); ++i);
	if (i <= n)
		return i;
	else
		return 0;
}

template<typename ElemType>
Status SqList<ElemType>::nextElem(ElemType e, ElemType & next_e)
{
	int i = locateElem(e, equal);
	if (i < 1 || i == n)
		return ERROR;
	else
		getElem(i + 1, next_e);
	return OK;
}

template<typename ElemType>
SqList<ElemType> SqList<ElemType>::operator=(SqList<ElemType>rightL)
{
	if (this != &rightL)
	{
		if (listSize < rightL.listSize)
		{
			delete[] elem;
			elem = new ElemType[rightL.listSize];
			assert(elem != 0);
			listSize = rightL.listSize;
		}
		n = rightL.n;
		for (int i = 1; i <= n; ++i)
			elem[i - 1] = rightL.elem[i - 1];
	}
	return *this;
}

template<typename ElemType>
Status SqList<ElemType>::priorElem(ElemType e, ElemType & prior_e)
{
	int i = locateElem(e, equal);
	if (i <= 1)
		return ERROR;
	else
		getElem(i - 1, prior_e);
	return OK;
}

template<typename ElemType>
int SqList<ElemType>::sequentialSearch(ElemType key)
{
	int i;
	for (i = 1; i < n&&key != elem[i - 1]; ++1);
	if (i <= n)
		return i;
	else
		return 0;
}

template<typename ElemType>
SqList<ElemType>::SqList()
{
	elem = new ElemType[LIST_MAX_SIZE];
	assert(elem != 0);
	listSize = LIST_MAX_SIZE;
	n = 0;
}

template<typename ElemType>
SqList<ElemType>::SqList(const SqList<ElemType> & otherL)
{
	elem = new ElemType[otherL.listSize];
	assert(elem != 0);
	listSize = otherL.listSize;
	n = otherL.n;
	for (int i = 1; i <= n; ++i)
	{
		elem[i - 1] = otherL.elem[i - 1];
	}
}

template <typename ElemType>
SqList<ElemType>::~SqList()
{
	delete[] elem;
}