// ѧ���� ���ݽṹC++��������ʵ�֣������ࣩ

// sqlist.h���ݽṹC++��������ʵ�֣����ࣩ
#ifndef SQLIST_H
#define SQLIST_H
#include "SqList.h"
#endif

template <typename ElemType>
class MyStudent :public SqList<ElemType>
{
public:
	double student_id;
	string name;
	ElemType Chinese;
	ElemType English;
	ElemType Math;
	float average;
	ElemType Total;

	//���ѧ����
	void RandomStudents();

	//����
	void inputStudent();

	void readS(istream & in);

	void displayS(ostream & out) const;

};

template<typename ElemType>
void MyStudent<ElemType>::readS(istream & in)
{
	int i;
	cout << "������ѧ�����е�ѧ��������" ;
	in >> i;
		for (int i = 0; i < this->n; i++)
		{
			cout << "������ѧ�����"<<i<<"��ѧ������Ϣ" << endl;
			cout << "\tѧ�ţ�";
			cin >> this->elem[i].student_id;
			cout << "\t������";
			cin >> this->elem[i].name;
			cout << "\t���ģ�";
			cin >> this->elem[i].Chinese;
			cout << "\tӢ�";
			cin >> this->elem[i].English;
			cout << "\t��ѧ��";
			cin >> this->elem[i].Math;
			//system("cls");
	        //displayCurrentObject(list_1);
			cout << "***********************************************************" << endl << endl;
			//cout<<
		}

	cout << endl;
}

template<typename ElemType>
istream & operator>>(istream & in, MyStudent<ElemType> & iS)
{
	iS.readS(in);
	return in;
}

template<typename ElemType>
void MyStudent<ElemType>::displayS(ostream & out) const
{
	int i;
	out << "��ǰѧ��������˳���洢����"<<this.getLength()<<"��ѧ��" << endl << endl;
	out << "ѧ��\t" << "����\t" << "����\t" << "Ӣ��\t" << "��ѧ\t" << "ƽ����\t" << "�ܷ�" << endl;
	for (i = 0; i < this->n; i++)
	{
		//out << elem[i].student_id << "\t" << elem[i].name; << "\t" << elem[i].Chinese << "\t" << elem[i].English;
			//<< "\t" << elem[i].Math << "\t" << elem[i].average << "\t" elem[i].Total << endl;
	}
	out << endl;
}

template <typename ElemType>
ostream & operator <<(ostream & out, const MyStudent<ElemType> & oS)
{
	oS.displayS(out);
	return out;
}
