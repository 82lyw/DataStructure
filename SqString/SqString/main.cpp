#include <iostream>
#include <string>
//using namespace std;
using std::cout;
using std::endl;
using std::cin;

// MyExampleClass.h˳�����ݽṹC++��������ʵ�֣������ࣩ
#ifndef SQSTRING_H
#define SQSTRING_H
#include "SqString.h"
#endif

//������Ҫ��һЩ����
#ifndef TEST_H
#define TEST_H
#include "test6.h"
#endif

int main()
{
	SqString str1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************����˳�򴮵Ĳ���*************************" << endl << endl;

		cout << "\t 1.��˳�򴮵ĳ���" << endl;
		cout << "\t 2.�ж�˳���Ƿ�Ϊ��" << endl;
		cout << "\t 3.ȡ˳�򴮵��Ӵ�" << endl;
		cout << "\t 4.�ڵ�i���ַ�ǰ������һ��˳��" << endl;
		cout << "\t 5.ɾ���ӵ�i���ַ��𳤶�Ϊlen���Ӵ�" << endl;
		cout << "\t 6.�ж��Ƿ����  SqString˳��==C++String˳��" << endl;
		cout << "\t 7.�ж��Ƿ����  SqString˳��==SqString˳��" << endl;
		cout << "\t 8.�ӷ����� SqString˳�� + C++String˳��" << endl;
		cout << "\t 9.�ӷ����� SqString˳�� + SqString˳��" << endl;
		cout << "\t 10.��������ƥ�䣨�л��ݲ��ң�" << endl;
		cout << "\t 11.��ģʽ����next����" << endl;
		cout << "\t 12.ģʽƥ�䣨�޻���KMP�������ң�" << endl;
		cout << "\t 13.��ֵ����  SqString˳��=C++String˳��" << endl;
		cout << "\t 14.��ֵ����  SqString˳��=SqString˳��" << endl;
		cout << "\t 15.��˳���ÿ�" << endl;
		cout << "\t 16.�������˳��" << endl;
		cout << "\t 17.��C++String˳�򴮳�ʼ��һ��˳�򴮣����ÿ�����ʼ�����캯����" << endl;
		cout << "\t 18.����һ��SqString˳�򴮳�ʼ��" << endl;
		cout << "\t 19.����˳��" << endl;
		cout << "\t 20.�򵥵��ı��༭����˳�򴮵�Ӧ�ã�" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(str1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-20�����룺";
		cin >> choose;

		if (choose > 0 && choose < 20)
		{
			system("cls");
			displayCurrentObject(str1);
		}

		switch (choose)
		{
		case 1:ex6_1_1(str1, continueYesNo);
			break;
		case 2:ex6_1_2(str1, continueYesNo);
			break;
		case 3:ex6_1_3(str1, continueYesNo);
			break;
		case 4:ex6_1_4(str1, continueYesNo);
			break;
		case 5:ex6_1_5(str1, continueYesNo);
			break;
		case 6:ex6_1_6(str1, continueYesNo);
			break;
		case 7:ex6_1_7(str1, continueYesNo);
			break;
		case 8:ex6_1_8(str1, continueYesNo);
			break;
		case 9:ex6_1_9(str1, continueYesNo);
			break;
		case 10:ex6_1_10(str1, continueYesNo);
			break;
		case 11:ex6_1_11(str1, continueYesNo);
			break;
		case 12:ex6_1_12(str1, continueYesNo);
			break;
		case 13:ex6_1_13(str1, continueYesNo);
			break;
		case 14:ex6_1_14(str1, continueYesNo);
			break;
		case 15:ex6_1_15(str1, continueYesNo);
			break;
		case 16:ex6_1_16(str1, continueYesNo);
			break;
		case 17:ex6_1_17(str1, continueYesNo);
			break;
		case 18:ex6_1_18(str1, continueYesNo);
			break;
		case 19:ex6_1_19(str1, continueYesNo);
			break;
		case 20:ex6_1_20(str1, continueYesNo);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}