// 数据结构C++类声明和实现（派生类）

// sqlist.h数据结构C++类声明和实现（基类）
#ifndef SQLIST_H
#define SQLIST_H
#include "SqList.h"
#endif

template <typename ElemType>
class MySqList :public SqList<ElemType>
{
public:
	//输入顺序表
	void read(istream & in);

	//输出顺序表
	void display(ostream & out) const;
};

//顺序表数据结构C++类的实现（派生类）

template <typename ElemType>
void MySqList<ElemType>::read(istream& in)
{
	//输入操作 （数组）
	/*cout << "请输入第" << this->myNo.no << "个顺序表对象" << endl;
	cout << "顺序表的长";
	in >> this->length;
	cout << "顺序表的宽";
	in >> this->width;*/

}

//功能：重载输入运算符的定义
//说明：通过该函数，可以使用C++中cin直接从键盘上输入顺序表
template <typename ElemType>
istream& operator>>(istream& in, MySqList<ElemType>& iD)
{
	iD.read(in);
	return in;
}

template <typename ElemType>
void MySqList<ElemType>::display(ostream& out) const
{
	//输出操作 （数组）
	cout << "当前顺序表有" << this->n << "个元素，分别为：" << endl;
	//for (int i = 1; i <= this->n; i++)
	for (int i = 1; i <= this->n; i++)
	{
		cout << "[" << i << "]\t";
	}
	cout << endl;
	for (int i = 0; i < this->n; i++)
	{
		cout << this->elem[i] << "\t";
	}
	cout << endl;
}

template <typename ElemType>
ostream & operator <<(ostream &out, const MySqList<ElemType>&oD)
{
	oD.display(out);
	return out;
}

//求两顺序表的并集
template<typename ElemType>
MySqList<ElemType> unionSet(MySqList<ElemType> firstL, MySqList<ElemType> secondL)
{
	ElemType e;
	MySqList<ElemType> thirdL(firstL);
	
	for (int i = 1; i <= secondL.getLength(); ++i)
	{
		secondL.getElem(i, e);
		if (!firstL.locateElem(e, equal))
		{
			int a = thirdL.getLength();
			thirdL.insert(++a, e);
		}
	}
	return thirdL;
}

//求两顺序表的交集
template<typename ElemType>
MySqList<ElemType> intersectionSet(MySqList<ElemType> firstL, MySqList<ElemType> secondL)
{
	int k = 0;
	ElemType e;
	MySqList<ElemType> thirdL;

	for (int i = 1; i <= firstL.getLength(); ++i)
	{
		firstL.getElem(i, e);
		if (secondL.locateElem(e, equal))
		{
			thirdL.insert(++k, e);
		}
	}
	return thirdL;
}

//求两顺序表的差集
template<typename ElemType>
MySqList<ElemType> dirfferenceSet(MySqList<ElemType> firstL, MySqList<ElemType> secondL)
{
	int k = 0;
	ElemType e;
	MySqList<ElemType> thirdL;

	for (int i=1; i <= firstL.getLength(); ++i)
	{
		firstL.getElem(i, e);
		if (!secondL.locateElem(e, equal))
		{
			thirdL.insert(++k, e);
		}
	}
	return thirdL;
}
