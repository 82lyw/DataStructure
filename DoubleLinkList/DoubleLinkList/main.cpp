#include <iostream>
using namespace std;


#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H
#include "DoubleLinkList.h"
#endif

//������Ҫ��һЩ����
#ifndef TEST_H
#define TEST_H
#include "test3_4.h"
#endif

int main()
{
	MyDoubleLinkList<int> list1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************����ѭ��˫����Ĳ���*************************" << endl << endl;

		cout << "\t 1.ȡѭ��˫�����i������������" << endl;
		cout << "\t 2.�ڵ�i�����֮ǰ����һ��������Ϊe�Ľ��" << endl;
		cout << "\t 3.�ж�ѭ��˫�����Ƿ�Ϊ�գ�" << endl;
		cout << "\t 4.��ѭ��˫�����н��ĸ���" << endl;
		cout << "\t 5.����ѭ��˫������������Ϊe�ĵ�һ������ָ��" << endl;
		cout << "\t 6.����ĳ����ǰ����������" << endl;
		cout << "\t 7.����ĳ���ĺ�̵�������" << endl;
		cout << "\t 8.ɾ��ѭ��˫������������Ϊe�ĵ�һ�����" << endl;
		cout << "\t 9.��һ��ѭ��˫����ֵ����һ��ѭ��˫����" << endl;
		cout << "\t 10.��ѭ��˫�����ÿ�" << endl;
		cout << "\t 11.�������ѭ��˫����" << endl;
		cout << "\t 12.�����е�ѭ��˫�����ʼ����һ��ѭ��˫����" << endl;
		cout << "\t 13.����ѭ��˫����" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(list1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-16�����룺";
		cin >> choose;

		if (choose > 0 && choose < 16)
		{
			system("cls");
			displayCurrentObject(list1);
		}

		switch (choose)
		{
		case 1:ex3_4_1(list1, continueYesNo);
			break;
		case 2:ex3_4_2(list1, continueYesNo);
			break;
		case 3:ex3_4_3(list1, continueYesNo);
			break;
		case 4:ex3_4_4(list1, continueYesNo);
			break;
		case 5:ex3_4_5(list1, continueYesNo);
			break;
		case 6:ex3_4_6(list1, continueYesNo);
			break;
		case 7:ex3_4_7(list1, continueYesNo);
			break;
		case 8:ex3_4_8(list1, continueYesNo);
			break;
		case 9:ex3_4_9(list1, continueYesNo);
			break;
		case 10:ex3_4_10(list1, continueYesNo);
			break;
		case 11:ex3_4_11(list1, continueYesNo);
			break;
		case 12:ex3_4_12(list1, continueYesNo);
			break;
		case 13:ex3_4_13(list1, continueYesNo);
			break;
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}
		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}
	return 0;
}
