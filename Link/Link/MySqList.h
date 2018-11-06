// ���ݽṹC++��������ʵ�֣������ࣩ

// sqlist.h���ݽṹC++��������ʵ�֣����ࣩ
#ifndef SQLIST_H
#define SQLIST_H
#include "SqList.h"
#endif

template <typename ElemType>
class MySqList :public SqList<ElemType>
{
public:
	//����˳���
	void read(istream & in);

	//���˳���
	void display(ostream & out) const;
};

//˳������ݽṹC++���ʵ�֣������ࣩ

template <typename ElemType>
void MySqList<ElemType>::read(istream& in)
{
	//������� �����飩
	/*cout << "�������" << this->myNo.no << "��˳������" << endl;
	cout << "˳���ĳ�";
	in >> this->length;
	cout << "˳���Ŀ�";
	in >> this->width;*/

}

//���ܣ���������������Ķ���
//˵����ͨ���ú���������ʹ��C++��cinֱ�ӴӼ���������˳���
template <typename ElemType>
istream& operator>>(istream& in, MySqList<ElemType>& iD)
{
	iD.read(in);
	return in;
}

template <typename ElemType>
void MySqList<ElemType>::display(ostream& out) const
{
	//������� �����飩
	cout << "��ǰ˳�����" << this->n << "��Ԫ�أ��ֱ�Ϊ��" << endl;
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

//����˳���Ĳ���
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

//����˳���Ľ���
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

//����˳���Ĳ
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
