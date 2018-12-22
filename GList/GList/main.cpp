#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;

#ifndef GLIST_H
#define GLIST_H
#include "GList.h"
#endif

//������Ҫ��һЩ����
#ifndef TEST_H
#define TEST_H
#include "test8.h"
#endif

int main()
{
	GList GL1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************���Թ��������ͷβ����洢��*************************" << endl << endl;

		cout << "\t 1.����������" << endl;
		cout << "\t 2.�����ĸ�ֵ����" << endl;
		cout << "\t 3.������ĳ���" << endl;
		cout << "\t 4.�жϹ�����Ƿ�Ϊ��" << endl;
		cout << "\t 5.ȡ�����ı�ͷ" << endl;
		cout << "\t 6.ȡ�����ı�β" << endl;
		cout << "\t 7.ɾ�������ı�ͷ" << endl;
		cout << "\t 8.����һ���������Ϊ�����ı�ͷ" << endl;
		cout << "\t 9.�����еĹ�����ʼ��һ���¹����" << endl;
		cout << "\t 10.���ַ�����ʽ��������" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(GL1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-11�����룺";
		cin >> choose;

		if (choose > 0 && choose < 12)
		{
			system("cls");
			displayCurrentObject(GL1);
		}

		switch (choose)
		{
		case 1:ex8_1(GL1, continueYesNo);
			break;
		case 2:ex8_2(GL1, continueYesNo);
			break;
		case 3:ex8_3(GL1, continueYesNo);
			break;
		case 4:ex8_4(GL1, continueYesNo);
			break;
		case 5:ex8_5(GL1, continueYesNo);
			break;
		case 6:ex8_6(GL1, continueYesNo);
			break;
		case 7:ex8_7(GL1, continueYesNo);
			break;
		case 8:ex8_8(GL1, continueYesNo);
			break;
		case 9:ex8_9(GL1, continueYesNo);
			break;
		case 10:ex8_10(GL1, continueYesNo);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}