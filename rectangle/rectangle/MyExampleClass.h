// MyExampleClass.h长方形数据结构C++类声明和实现（派生类）

// ExampleClass.h长方形数据结构C++类声明和实现（基类）
#ifndef EXAMPLECLASS_H
#define EXAMPLECLASS_H
#include "ExampleClass.h"
#endif


template <typename ElemType>
class MyRectangle :public Rectangle<ElemType>
{
public:
	//输入长方形
	void read(istream & in);

	//输出长方形
	void display(ostream & out) const;
};

//长方形数据结构C++类的实现（派生类）

template <typename ElemType>
void MyRectangle<ElemType>::read(istream& in)
{
	//-- this是一个指向对象自身的指针  调用该函数的对象中的成员myNo.no,length,width
	cout << "请输入第" << this->myNo.no << "个长方形对象" << endl;
	cout << "长方形的长";
	in >> this->length;
	cout << "长方形的宽";
	in >> this->width;
}

//功能：重载输入运算符的定义
//说明：通过该函数，可以使用C++中cin直接从键盘上输入长方形
template <typename ElemType>
istream& operator>>(istream& in, MyRectangle<ElemType>& iD)
{
	iD.read(in);
	return in;
}

template <typename ElemType>
void MyRectangle<ElemType>::display(ostream& out) const
{
	out << "第" << this->myNo.no << "个长方形对象 长=" << this->length << "\t宽=" << this->width << endl;
}

template <typename ElemType>
ostream & operator <<(ostream &out, const MyRectangle<ElemType>&oD)
{
	oD.display(out);
	return out;
}
