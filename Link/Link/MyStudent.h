// 学生表 数据结构C++类声明和实现（派生类）

// sqlist.h数据结构C++类声明和实现（基类）
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

	//随机学生表
	void RandomStudents();

	//输入
	void inputStudent();

	void readS(istream & in);

	void displayS(ostream & out) const;

};

template<typename ElemType>
void MyStudent<ElemType>::readS(istream & in)
{
	int i;
	cout << "请输入学生表中的学生人数：" ;
	in >> i;
		for (int i = 0; i < this->n; i++)
		{
			cout << "请输入学生表第"<<i<<"个学生的信息" << endl;
			cout << "\t学号：";
			cin >> this->elem[i].student_id;
			cout << "\t姓名：";
			cin >> this->elem[i].name;
			cout << "\t语文：";
			cin >> this->elem[i].Chinese;
			cout << "\t英语：";
			cin >> this->elem[i].English;
			cout << "\t数学：";
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
	out << "当前学生表（采用顺序表存储）有"<<this.getLength()<<"个学生" << endl << endl;
	out << "学号\t" << "姓名\t" << "语文\t" << "英语\t" << "数学\t" << "平均分\t" << "总分" << endl;
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
