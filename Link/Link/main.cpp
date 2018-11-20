#include <iostream>
#include <string>
//using namespace std;
using std::cout;
using std::endl;
using std::cin;

// MyExampleClass.h˳������ݽṹC++��������ʵ�֣������ࣩ
#ifndef MYSQLIST_H
#define MYSQLIST_H
#include "MySqList.h"
#endif

#ifndef MYSTUDENT_H
#define MYSTUDENT_H
#include "MyStudent.h"
#endif

//������Ҫ��һЩ����
#ifndef TEST_H
#define TEST_H
#include "test.h"
#endif

int main()
{
	MySqList<int> list_1;
	MyStudent<int> list2;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************����˳���Ĳ���*************************" << endl << endl;

		cout << "\t 1.�ڵ�i��Ԫ��֮ǰ����һ��Ԫ��" << endl;
		cout << "\t 2.�ж�˳����Ƿ�Ϊ��" << endl;
		cout << "\t 3.��˳�����Ԫ�صĸ���" << endl;
		cout << "\t 4.ȡ��i��Ԫ��" << endl;
		cout << "\t 5.���ҵ�i����ĳԪ������compare������ϵԪ�ص����" << endl;
		cout << "\t 6.����ĳԪ�ص�ǰ��" << endl;
		cout << "\t 7.����ĳԪ�صĺ��" << endl;
		cout << "\t 8.ɾ����i��Ԫ��" << endl;
		cout << "\t 9.��һ��˳���ֵ����һ��˳���" << endl;
		cout << "\t 10.��˳����ÿ�" << endl;
		cout << "\t 11.�������˳���Ԫ��ֵ��0��99֮���������" << endl;
		cout << "\t 12.�����е�˳����ʼ����һ��˳���" << endl;
		cout << "\t 13.����˳���" << endl;
		cout << "\t 14.����˳���Ľ���������" << endl;
		cout << "\t 15.ѧ����Ϣ����" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(list_1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-15�����룺";
		cin >> choose;

		if (choose > 0 && choose < 13)
		{
			system("cls");
			displayCurrentObject(list_1);
		}

		switch (choose)
		{
		case 1:ex3_1_1(list_1, continueYesNo);
			break;
		case 2:ex3_1_2(list_1, continueYesNo);
			break;
		case 3:ex3_1_3(list_1, continueYesNo);
			break;
		case 4:ex3_1_4(list_1, continueYesNo);
			break;
		case 5:ex3_1_5(list_1, continueYesNo);
			break;
		case 6:ex3_1_6(list_1, continueYesNo);
			break;
		case 7:ex3_1_7(list_1, continueYesNo);
			break;
		case 8:ex3_1_8(list_1, continueYesNo);
			break;
		case 9:ex3_1_9(list_1, continueYesNo);
			break;
		case 10:ex3_1_10(list_1, continueYesNo);
			break;
		case 11:ex3_1_11(list_1, continueYesNo);
			break;
		case 12:ex3_1_12(list_1, continueYesNo);
			break;
		case 13:ex3_1_13(list_1, continueYesNo);
			break;
		case 14:ex3_1_14(list_1, continueYesNo);
			break;
		case 15:ex3_1_15(list2, continueYesNo);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}