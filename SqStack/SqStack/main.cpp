#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;

#ifndef MYEXPRESS_H
#define MYEXPRESS_H
#include "MyExpress.h"
#endif

//������Ҫ��һЩ����
#ifndef TEST_H
#define TEST_H
#include "test4_1.h"
#endif

int main()
{
	MySqStack<char> stack1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************����˳���Ĳ���*************************" << endl << endl;

		cout << "\t 1.��ջ��ѹ��Ԫ��" << endl;
		cout << "\t 2.����ջ����Ԫ�ص�e" << endl;
		cout << "\t 3.��ջ����Ԫ��" << endl;
		cout << "\t 4.�ж�˳��ջ�Ƿ�Ϊ��" << endl;
		cout << "\t 5.��˳��ջ��Ԫ�صĸ���" << endl;
		cout << "\t 6.��һ��˳��ջ��ֵ����һ��˳��ջ" << endl;
		cout << "\t 7.��˳��ջ�ÿ�" << endl;
		cout << "\t 8.�������˳��ջ" << endl;
		cout << "\t 9.�����е�˳��ջ��ʼ����һ���µ�˳��ջ" << endl;
		cout << "\t 10.���ʽ���" << endl;
		cout << "\t 11.�Թ����" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(stack1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-15�����룺";
		cin >> choose;

		if (choose > 0 && choose < 13)
		{
			system("cls");
			displayCurrentObject(stack1);
		}

		switch (choose)
		{
		case 1:ex4_1_1(stack1, continueYesNo);
			break;
		case 2:ex4_1_2(stack1, continueYesNo);
			break;
		case 3:ex4_1_3(stack1, continueYesNo);
			break;
		case 4:ex4_1_4(stack1, continueYesNo);
			break;
		case 5:ex4_1_5(stack1, continueYesNo);
			break;
		case 6:ex4_1_6(stack1, continueYesNo);
			break;
		case 7:ex4_1_7(stack1, continueYesNo);
			break;
		case 8:ex4_1_8(stack1, continueYesNo);
			break;
		case 9:ex4_1_9(stack1, continueYesNo);
			break;
		case 10:ex4_1_10(stack1, continueYesNo);
			break;
		case 11:ex4_1_11(stack1, continueYesNo);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}