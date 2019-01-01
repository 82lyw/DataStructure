#include <iostream>
#include <string>
#include <iomanip>

#ifndef SQLISTSORT_H
#define SQLISTSORT_H
#include "SqListSort.h"
#endif

#ifndef MYSTATIC_H
#define MYSTATIC_H
#include "MyStaticList.h"
#endif // !MYSTATIC_H


//������Ҫ��һЩ����
#ifndef TEST_H
#define TEST_H
#include "test11.h"
#endif

int main()
{
	MySqListSort<int> S1;
	MyStatic<node> S2;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "************** �����������******************" << endl << endl;

		cout << "\t 1.ֱ�Ӳ�������" << endl;
		cout << "\t 2.�۰��������" << endl;
		cout << "\t 3.��̬�����������" << endl;
		cout << "\t 4.ϣ������" << endl;
		cout << "\t 5.ð������" << endl;
		cout << "\t 6.��������" << endl;
		cout << "\t 7.ֱ��ѡ������" << endl;
		cout << "\t 8.������" << endl;
		cout << "\t 9.�鲢����" << endl;
		cout << "\t 10.�������򣨲��þ�̬����洢��" << endl;

		cout << "\t 11.�������˳���" << endl;
		cout << "\t 12.������ɾ�̬����" << endl;
		cout << "\t 13.����˳���" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(S1,S2);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-14�����룺";
		cin >> choose;

		if (choose==1||choose==2||(choose>3&&choose<10)||choose==11||choose==13)
		{
			system("cls");
			cout << endl;
			cout << S1; cout << endl;
		}
		if (choose == 3 || choose == 10 || choose == 12)
		{
			system("cls");
			cout << endl;
			cout << S2; cout << endl;
		}

		switch (choose)
		{
		case 1:ex11_1(S1, continueYesNo);
			break;
		case 2:ex11_2(S1, continueYesNo);
			break;
		case 3:ex11_3(S2, continueYesNo);
			break;
		case 4:ex11_4(S1, continueYesNo);
			break;
		case 5:ex11_5(S1, continueYesNo);
			break;
		case 6:ex11_6(S1, continueYesNo);
			break;
		case 7:ex11_7(S1, continueYesNo);
			break;
		case 8:ex11_8(S1, continueYesNo);
			break;
		case 9:ex11_9(S1, continueYesNo);
			break;
		case 10:ex11_10(S2, continueYesNo);
			break;
		case 11:ex11_11(S1, continueYesNo);
			break;
		case 12:ex11_12(S2, continueYesNo);
			break;
		case 13:ex11_13(S1, continueYesNo);
			break;
		case 14:ex11_14(S1, continueYesNo);
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}