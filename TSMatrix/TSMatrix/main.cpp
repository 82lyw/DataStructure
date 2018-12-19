#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;

#ifndef TSMATRIX_H
#define TSMATRIX_H
#include "TSMatrix.h"
#endif


//������Ҫ��һЩ����
#ifndef TEST_H
#define TEST_H
#include "test7_1.h"
#endif

int main()
{
	TSMatrix<int> T1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "************** ����ϡ������ת�þ���Ĳ�����������Ԫ���˳��洢��******************" << endl << endl;

		cout << "\t 1.��ϡ������ת�þ���" << endl;
		cout << "\t 2.������ϡ������ת�þ���" << endl;
		cout << "\t 3.����ϡ�������е�һ������Ԫ������Ԫ����е��±�" << endl;
		cout << "\t 4.ϡ�����ĸ�ֵ����" << endl;
		cout << "\t 5.��ϡ�����ļӷ�" << endl;
		cout << "\t 6.��ϡ�����ĳ˷�" << endl;
		cout << "\t 7.��ʾϡ��������Ԫ���ʾ" << endl;
		cout << "\t 8.�������ϡ�����" << endl;
		cout << "\t 9.�����е�ϡ������ʼ��һ���¾���" << endl;
		cout << "\t 10.����ϡ��������Ԫ���" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(T1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-10�����룺";
		cin >> choose;

		if (choose > 0 && choose < 12)
		{
			system("cls");
			displayCurrentObject(T1);
		}

		switch (choose)
		{
		case 1:ex7_1_1(T1, continueYesNo);
			break;
		case 2:ex7_1_2(T1, continueYesNo);
			break;
		case 3:ex7_1_3(T1, continueYesNo);
			break;
		case 4:ex7_1_4(T1, continueYesNo);
			break;
		case 5:ex7_1_5(T1, continueYesNo);
			break;
		case 6:ex7_1_6(T1, continueYesNo);
			break;
		case 7:ex7_1_7(T1, continueYesNo);
			break;
		case 8:ex7_1_8(T1, continueYesNo);
			break;
		case 9:ex7_1_9(T1, continueYesNo);
			break;
		case 10:ex7_1_10(T1, continueYesNo);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}