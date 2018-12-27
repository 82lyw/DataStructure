#include <iostream>
#include <string>
#include <assert.h>
#include <iomanip>
using namespace std;

#ifndef SEQTREE_H
#define SEQTREE_H
#include "SeqTree.h"
#endif

//������Ҫ��һЩ����
#ifndef TEST_H
#define TEST_H
#include "test9_1.h"
#endif

int main()
{
	MySeqTree<char> ST1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************���Զ�����(˳��洢)�Ĳ���*************************" << endl << endl;

		cout << "\t 1.���������" << endl;
		cout << "\t 2.�������" << endl;
		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(ST1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-2�����룺";
		cin >> choose;

		if (choose > 0 && choose < 3)
		{
			system("cls");
			displayCurrentObject(ST1);
		}

		switch (choose)
		{
		case 1:ex9_1_1(ST1, continueYesNo);
			break;

		case 2:ex9_1_2(ST1, continueYesNo);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}