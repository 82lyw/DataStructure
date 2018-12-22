#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;

#ifndef GLIST_H
#define GLIST_H
#include "GList.h"
#endif

//测试需要的一些操作
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
		cout << "*********************测试广义表（采用头尾链表存储）*************************" << endl << endl;

		cout << "\t 1.求广义表的深度" << endl;
		cout << "\t 2.广义表的赋值运算" << endl;
		cout << "\t 3.求广义表的长度" << endl;
		cout << "\t 4.判断广义表是否为空" << endl;
		cout << "\t 5.取广义表的表头" << endl;
		cout << "\t 6.取广义表的表尾" << endl;
		cout << "\t 7.删除广义表的表头" << endl;
		cout << "\t 8.插入一个广义表作为广义表的表头" << endl;
		cout << "\t 9.用已有的广义表初始化一个新广义表" << endl;
		cout << "\t 10.以字符串形式输入广义表" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(GL1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-11）号码：";
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
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}