#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;

#ifndef SQQUEUE_H
#define SQQUEUE_H
#include "SqQueue.h"
#endif

#ifndef MYSPORTS_H
#define MYSPORTS_H
#include "MySports.h"
#endif

//������Ҫ��һЩ����
#ifndef TEST_H
#define TEST_H
#include "test5_1.h"
#endif

int main()
{
	MySqQueue<int> Q1;
	//MySports S1;
	MySports S1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************����ѭ��˳����еĲ���*************************" << endl << endl;

		cout << "\t 1.�����У���ѭ��˳����ж�β����Ԫ�أ�" << endl;
		cout << "\t 2.�����У�ɾ��ѭ�����ж�ͷԪ�أ�" << endl;
		cout << "\t 3.��ѭ��˳����ж�ͷ��Ԫ�ص�e" << endl;
		cout << "\t 4.�ж�ѭ��˳������Ƿ�Ϊ��" << endl;
		cout << "\t 5.�ж�ѭ��˳������Ƿ���" << endl;
		cout << "\t 6.��ѭ��˳�������Ԫ�صĸ���" << endl;
		cout << "\t 7.��һ��ѭ��˳����и�ֵ����һ��ѭ��˳�����" << endl;
		cout << "\t 8.��һ��ѭ��˳������ÿ�" << endl;
		cout << "\t 9.�������ѭ��˳�����" << endl;
		cout << "\t 10.�����е�ѭ��˳����г�ʼ����һ����ѭ��˳�����" << endl;
		cout << "\t 11.�˶����������" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(Q1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-11�����룺";
		cin >> choose;

		if (choose > 0 && choose < 12)
		{
			system("cls");
			displayCurrentObject(Q1);
		}

		switch (choose)
		{
		case 1:ex5_1_1(Q1, continueYesNo);
			break;
		case 2:ex5_1_2(Q1, continueYesNo);
			break;
		case 3:ex5_1_3(Q1, continueYesNo);
			break;
		case 4:ex5_1_4(Q1, continueYesNo);
			break;
		case 5:ex5_1_5(Q1, continueYesNo);
			break;
		case 6:ex5_1_6(Q1, continueYesNo);
			break;
		case 7:ex5_1_7(Q1, continueYesNo);
			break;
		case 8:ex5_1_8(Q1, continueYesNo);
			break;
		case 9:ex5_1_9(Q1, continueYesNo);
			break;
		case 10:ex5_1_10(Q1, continueYesNo);
			break;
		case 11:ex5_1_11(S1, continueYesNo);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}