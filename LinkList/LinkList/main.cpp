#include <iostream>
using namespace std;

// MyExampleClass.h˳������ݽṹC++��������ʵ�֣������ࣩ
//#ifndef MyLinkList_H
//#define MyLinkList_H
//#include "MyLinkList.h"
//#endif
//
#ifndef MYPOLYNOMIALLINKLIST_H
#define MYPOLYNOMIALLINKLIST_H
#include "MyPolynomialLinkList.h"
#endif

#ifndef MYTERM_H
#define MYTERM_H
#include "MyTerm.h"
#endif

//������Ҫ��һЩ����
#ifndef TEST_H
#define TEST_H
#include "test3_2_1.h"
#endif

int main()
{
	MyLinkList<int> list1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************���Է�ѭ��������Ĳ���*************************" << endl << endl;
		cout << "\t 1.ȡ��ѭ��������ĵ�i�����" << endl;
		cout << "\t 2.�ڵ�i�����֮ǰ����һ��������Ϊe�Ľ��" << endl;
		cout << "\t 3.�жϷ�ѭ���������Ƿ�Ϊ��" << endl;
		cout << "\t 4.���ѭ���������н��ĸ���" << endl;
		cout << "\t 5.���ҵ�i����ĳԪ������compare������ϵԪ�ص����" << endl;
		cout << "\t 6.����ĳԪ�ص�ǰ����������" << endl;
		cout << "\t 7.����ĳԪ�صĺ�̵�������" << endl;
		cout << "\t 8.ɾ����ѭ�� ��������������Ϊe�ĵ�һ�����" << endl;
		cout << "\t 9.ɾ����ѭ�����������ظ���ֵ" << endl;
		cout << "\t 10.��ѭ�������������" << endl;
		cout << "\t 11.��һ����ѭ��������ֵ����һ����ѭ��������" << endl;
		cout << "\t 12.�ѷ�ѭ���������ÿ�" << endl;
		cout << "\t 13.������ɷ�ѭ��������" << endl;
		cout << "\t 14.�����еķ�ѭ���������ʼ����һ����ѭ��������" << endl;
		cout << "\t 15.�����ѭ��������" << endl;
		cout << "\t16.����ʽ�����㣨��ѭ���������Ӧ�ã�" << endl;
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
		case 1:ex3_2_1(list1, continueYesNo);
			break;
		case 2:ex3_2_2(list1, continueYesNo);
			break;
		case 3:ex3_2_3(list1, continueYesNo);
			break;
		case 4:ex3_2_4(list1, continueYesNo);
			break;
		case 5:ex3_2_5(list1, continueYesNo);
			break;
		case 6:ex3_2_6(list1, continueYesNo);
			break;
		case 7:ex3_2_7(list1, continueYesNo);
			break;
		case 8:ex3_2_8(list1, continueYesNo);
			break;
		case 9:ex3_2_9(list1, continueYesNo);
			break;
		case 10:ex3_2_10(list1, continueYesNo);
			break;
		case 11:ex3_2_11(list1, continueYesNo);
			break;
		case 12:ex3_2_12(list1, continueYesNo);
			break;
		case 13:ex3_2_13(list1, continueYesNo);
			break;
		case 14:ex3_2_14(list1, continueYesNo);
			break;
		case 15:ex3_2_15(list1, continueYesNo);
			break;
		case 16:ex3_2_16(list1, continueYesNo);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}
		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}
	return 0;
}