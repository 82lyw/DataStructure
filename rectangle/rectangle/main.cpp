#include <iostream>
using namespace std;

// MyExampleClass.h���������ݽṹC++��������ʵ�֣������ࣩ
#ifndef MYEXAMPLECLASS_H
#define MYEXAMPLECLASS_H
#include "MyExampleClass.h"
#endif

#ifndef TEST_H
#define TEST_H
#include "test.h"
#endif

//int main()
//{
//	float aL = (float)8.2;
//	MyRectangle<int> d1;
//	MyRectangle<float> d2, d3;
//
//	d1.setNo(1);
//	d2.setNo(2);
//	d3.setNo(3);
//	cout << d1 << d2 << d3;
//
//	cin >> d1 >> d2;
//
//	cout << "�ѵڶ��������ζ��󸳸������������ζ���" << endl;
//	d3 = d3;
//	cout << "���õڶ��������ζ���ĳ�Ϊ" << aL << endl;
//	d2.setLength(aL);
//	cout << d1 << d2 << d3;
//	cout << "�������������෴��˳����һ�Զ��������������Ե���������" << endl;
//
//	return 0;
//}

int main()
{
	MyRectangle<float> rec;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************���Գ����εĲ���*************************" << endl << endl;

		cout << "\t 1.���ó����ε���ţ�" << endl;
		cout << "\t 2.���ó����εĳ���" << endl;
		cout << "\t 3.���ظ�ֵ������Ķ��壺" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(rec);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-3�����룺";
		cin >> choose;

		if (choose > 0 && choose < 3)
		{
			system("cls");
			displayCurrentObject(rec);
		}

		switch (choose)
		{
		case 1:ex2_1_1(rec, continueYesNo);
			break;
		case 2:ex2_1_2(rec, continueYesNo);
			break;
		case 3:ex2_1_3(rec, continueYesNo);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}
	return 0;
}