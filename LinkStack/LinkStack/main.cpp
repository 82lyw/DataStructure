#include <iostream>
using namespace std;

// LinkStack.h链栈数据结构C++类声明和实现（派生类）

#ifndef LINKSTACK_H
#define LINKSTACK_H
#include "LinkStack.h"
#endif

//测试需要的一些操作
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
		cout << "*********************测试链栈的操作*************************" << endl << endl;

		cout << "\t 1.在栈顶压入一个数据域为e的结点" << endl;
		cout << "\t 2.弹出栈顶结点" << endl;
		cout << "\t 3.读栈顶结点的数据域" << endl;
		cout << "\t 4.判断链栈是否为空" << endl;
		cout << "\t 5.求链栈中结点的个数" << endl;
		cout << "\t 6.把一个链栈赋值给另一个链栈" << endl;
		cout << "\t 7.把链栈置空" << endl;
		cout << "\t 8.随机生成链栈" << endl;
		cout << "\t 9.用已有的链栈初始化另一个链栈" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(list1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-9）号码：";
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
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}
		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}
	return 0;
}