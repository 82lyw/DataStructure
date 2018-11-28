#include <iostream>
using namespace std;

// LinkStack.h��ջ���ݽṹC++��������ʵ�֣������ࣩ

#ifndef LINKSTACK_H
#define LINKSTACK_H
#include "LinkStack.h"
#endif

//������Ҫ��һЩ����
#ifndef TEST_H
#define TEST_H
#include "test.h"
#endif

int main()
{
	MyLinkStack<int> list1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************������ջ�Ĳ���*************************" << endl << endl;

		cout << "\t 1.��ջ��ѹ��һ��������Ϊe�Ľ��" << endl;
		cout << "\t 2.����ջ�����" << endl;
		cout << "\t 3.��ջ������������" << endl;
		cout << "\t 4.�ж���ջ�Ƿ�Ϊ��" << endl;
		cout << "\t 5.����ջ�н��ĸ���" << endl;
		cout << "\t 6.��һ����ջ��ֵ����һ����ջ" << endl;
		cout << "\t 7.����ջ�ÿ�" << endl;
		cout << "\t 8.���������ջ" << endl;
		cout << "\t 9.�����е���ջ��ʼ����һ����ջ" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(list1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-9�����룺";
		cin >> choose;

		if (choose > 0 && choose <= 9)
		{
			system("cls");
			displayCurrentObject(list1);
		}

		switch (choose)
		{
		case 1:ex4_2_1(list1, continueYesNo);
			break;
		case 2:ex4_2_2(list1, continueYesNo);
			break;
		case 3:ex4_2_3(list1, continueYesNo);
			break;
		case 4:ex4_2_4(list1, continueYesNo);
			break;
		case 5:ex4_2_5(list1, continueYesNo);
			break;
		case 6:ex4_2_6(list1, continueYesNo);
			break;
		case 7:ex4_2_7(list1, continueYesNo);
			break;
		case 8:ex4_2_8(list1, continueYesNo);
			break;
		case 9:ex4_2_9(list1, continueYesNo);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}
		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}
	return 0;
}