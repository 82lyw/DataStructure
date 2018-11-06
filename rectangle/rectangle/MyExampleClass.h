// MyExampleClass.h���������ݽṹC++��������ʵ�֣������ࣩ

// ExampleClass.h���������ݽṹC++��������ʵ�֣����ࣩ
#ifndef EXAMPLECLASS_H
#define EXAMPLECLASS_H
#include "ExampleClass.h"
#endif


template <typename ElemType>
class MyRectangle :public Rectangle<ElemType>
{
public:
	//���볤����
	void read(istream & in);

	//���������
	void display(ostream & out) const;
};

//���������ݽṹC++���ʵ�֣������ࣩ

template <typename ElemType>
void MyRectangle<ElemType>::read(istream& in)
{
	//-- this��һ��ָ����������ָ��  ���øú����Ķ����еĳ�ԱmyNo.no,length,width
	cout << "�������" << this->myNo.no << "�������ζ���" << endl;
	cout << "�����εĳ�";
	in >> this->length;
	cout << "�����εĿ�";
	in >> this->width;
}

//���ܣ���������������Ķ���
//˵����ͨ���ú���������ʹ��C++��cinֱ�ӴӼ��������볤����
template <typename ElemType>
istream& operator>>(istream& in, MyRectangle<ElemType>& iD)
{
	iD.read(in);
	return in;
}

template <typename ElemType>
void MyRectangle<ElemType>::display(ostream& out) const
{
	out << "��" << this->myNo.no << "�������ζ��� ��=" << this->length << "\t��=" << this->width << endl;
}

template <typename ElemType>
ostream & operator <<(ostream &out, const MyRectangle<ElemType>&oD)
{
	oD.display(out);
	return out;
}
