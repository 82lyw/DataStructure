#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
using std::cout;
using std::endl;
using std::cin;

#ifndef MYBITREE_H
#define MYBITREE_H
#include "BiTree.h"
#endif

//������Ҫ��һЩ����
#ifndef TEST_H
#define TEST_H
#include "test9.h"
#endif

int main()
{
	MyBiTree<char> BT1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************���ԣ������ߣ��������Ĳ���*************************" << endl << endl;

		cout << "\t 1.��������Ľ����" << endl;
		cout << "\t 2.���������Ҷ����" << endl;
		cout << "\t 3.�ݹ�����������" << endl;
		cout << "\t 4.���������������н�����������" << endl;
		cout << "\t 5.ǰ��ݹ����������" << endl;
		cout << "\t 6.����ݹ����������" << endl;
		cout << "\t 7.����ݹ����������" << endl;
		cout << "\t 8.�ǵݹ��������������" << endl;
		cout << "\t 9.�����˳�����������" << endl;
		cout << "\t 10.��˳��洢�ķ�ʽ��ʾ������" << endl;
		cout << "\t 11.�������Ķ�������洢ת��Ϊ˳��洢�ṹ" << endl;
		cout << "\t 12.��������˳��洢ת��Ϊ��������洢�ṹ" << endl;
		cout << "\t 13.������ɶ�����" << endl;
		cout << "\t 14.���������" << endl<<endl;

		/*
		cout << "\t 15.������������߶�����" << endl;
		cout << "\t 16.�����߶�����˳��洢ת��Ϊ��������洢" << endl;
		cout << "\t 17.�����߶���������ָ����������ǰ������" << endl;
		cout << "\t 18.������������߶�����" << endl;
		cout << "\t 19.���������߶�����" << endl;
		cout << "\t 20.������������������Ӧ�ã�" << endl;
		*/

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(BT1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-20�����룺";
		cin >> choose;

		if (choose > 0 && choose < 15)
		{
			system("cls");
			displayCurrentObject(BT1);
		}

		switch (choose)
		{
		case 1:ex9_2_1(BT1, continueYesNo);
			break;
			
		case 2:ex9_2_2(BT1, continueYesNo);
			break;
		case 3:ex9_2_3(BT1, continueYesNo);
			break;
		case 4:ex9_2_4(BT1, continueYesNo);
			break;
		case 5:ex9_2_5(BT1, continueYesNo);
			break;
		case 6:ex9_2_6(BT1, continueYesNo);
			break;
		case 7:ex9_2_7(BT1, continueYesNo);
			break;
		case 8:ex9_2_8(BT1, continueYesNo);
			break;
		case 9:ex9_2_9(BT1, continueYesNo);
			break;
		case 10:ex9_2_10(BT1, continueYesNo);
			break;
		case 11:ex9_2_11(BT1, continueYesNo);
			break;
		case 12:ex9_2_12(BT1, continueYesNo);
			break;
		case 13:ex9_2_13(BT1, continueYesNo);
			break;
		case 14:ex9_2_14(BT1, continueYesNo);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}