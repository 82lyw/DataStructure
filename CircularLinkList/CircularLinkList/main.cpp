#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//MyCircularLinkList.hѭ�����������ݽṹC++��������ʵ�֣������ࣩ
#ifndef MYCIRCULARLINKLIST_H
#define MYCIRCULARLINKLIST_H
#include "MyCircularLinkList.h"
#endif

//������Ҫ��һЩ����
#ifndef TEST_H
#define TEST_H
#include "test.h"
#endif

int main()
{
	MyCircularLinkList<int> list;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************����ѭ��������Ĳ���*************************" << endl << endl;

		cout << "\t 1.�ж�ѭ���������Ƿ�Ϊ��" << endl;
		cout << "\t 2.��ѭ���������ͷָ���������i�����" << endl;
		cout << "\t 3.ɾ����i����㣬ͷָ����������һ�����" << endl;
		cout << "\t 4.��һ��ѭ��������ֵ����һ��ѭ��������" << endl;
		cout << "\t 5.ѭ���������ÿ�" << endl;
		cout << "\t 6.�������ѭ��������" << endl;
		cout << "\t 7.�����е�ѭ���������ʼ����һ��ѭ��������" << endl;
		cout << "\t 8.����ѭ��������" << endl;
		cout << "\t 9.Լɪ��Josephus�������У�ѭ���������Ӧ�ã�" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		//displayCurrentObject(list);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-9�����룺";
		cin >> choose;

		if (choose > 0 && choose < 9)
		{
			system("cls");
			//displayCurrentObject(list);
		}

		switch (choose)
		{
		case 1:ex3_3_1(list, continueYesNo);
			break;
		case 2:ex3_3_2(list, continueYesNo);
			break;
		case 3:ex3_3_3(list, continueYesNo);
			break;
		case 4:ex3_3_4(list, continueYesNo);
			break;
		case 5:ex3_3_5(list, continueYesNo);
			break;
		case 6:ex3_3_6(list, continueYesNo);
			break;
		case 7:ex3_3_7(list, continueYesNo);
			break;
		case 8:ex3_3_8(list, continueYesNo);
			break;
		case 9:ex3_3_9(list, continueYesNo);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}