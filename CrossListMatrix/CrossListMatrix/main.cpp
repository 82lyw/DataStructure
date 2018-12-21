#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;

#ifndef CROSSLISTMATRIX_H
#define CROSSLISTMATRIX_H
#include "CrossListMatrix.h"
#endif


//������Ҫ��һЩ����
#ifndef TEST_H
#define TEST_H
#include "test7_2.h"
#endif

int main()
{
	CrossListMatrix<int> T1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "************** ����ϡ������ת�þ���Ĳ���������ʮ������洢��******************" << endl << endl;

		cout << "\t 1.ϡ�����ĸ�ֵ����" << endl;
		cout << "\t 2.��ϡ�����ļӷ�" << endl;
		cout << "\t 3.�������ϡ�����" << endl;
		cout << "\t 4.�����е�ϡ������ʼ��һ���¾���" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(T1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-4�����룺";
		cin >> choose;

		if (choose > 0 && choose < 5)
		{
			system("cls");
			displayCurrentObject(T1);
		}

		switch (choose)
		{
		case 1:ex7_2_1(T1, continueYesNo);
			break;
		case 2:ex7_2_2(T1, continueYesNo);
			break;
		case 3:ex7_2_3(T1, continueYesNo);
			break;
		case 4:ex7_2_4(T1, continueYesNo);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}