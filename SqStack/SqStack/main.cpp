#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;

#ifndef MYEXPRESS_H
#define MYEXPRESS_H
#include "MyExpress.h"
#endif

//测试需要的一些操作
#ifndef TEST_H
#define TEST_H
#include "test4_1.h"
#endif

int main()
{
	MySqStack<char> list_1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************测试顺序表的操作*************************" << endl << endl;

		cout << "\t 1.在栈顶压入元素" << endl;
		cout << "\t 2.弹出栈顶的元素到e" << endl;
		cout << "\t 3.读栈顶的元素" << endl;
		cout << "\t 4.判断顺序栈是否为空" << endl;
		cout << "\t 5.求顺序栈中元素的个数" << endl;
		cout << "\t 6.把一个顺序栈赋值给另一个顺序栈" << endl;
		cout << "\t 7.把顺序栈置空" << endl;
		cout << "\t 8.随机生成顺序栈" << endl;
		cout << "\t 9.用已有的顺序栈初始化另一个新的顺序栈" << endl;
		cout << "\t 10.表达式求解" << endl;
		cout << "\t 11.迷宫求解" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(list_1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-15）号码：";
		cin >> choose;

		if (choose > 0 && choose < 13)
		{
			system("cls");
			displayCurrentObject(list_1);
		}

		switch (choose)
		{
		case 1:ex4_1_1(list_1, continueYesNo);
			break;
		case 2:ex4_1_2(list_1, continueYesNo);
			break;
		case 3:ex4_1_3(list_1, continueYesNo);
			break;
		case 4:ex4_1_4(list_1, continueYesNo);
			break;
		case 5:ex4_1_5(list_1, continueYesNo);
			break;
		case 6:ex4_1_6(list_1, continueYesNo);
			break;
		case 7:ex4_1_7(list_1, continueYesNo);
			break;
		case 8:ex4_1_8(list_1, continueYesNo);
			break;
		case 9:ex4_1_9(list_1, continueYesNo);
			break;
		case 10:ex4_1_10(list_1, continueYesNo);
			break;
		case 11:ex4_1_11(list_1, continueYesNo);
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}