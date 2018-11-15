#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//MyCircularLinkList.h循环单链表数据结构C++类声明和实现（派生类）
#ifndef MYCIRCULARLINKLIST_H
#define MYCIRCULARLINKLIST_H
#include "MyCircularLinkList.h"
#endif

//测试需要的一些操作
#ifndef TEST_H
#define TEST_H
#include "test.h"
#endif

int main()
{
	MyCircularLinkList<int> list;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************测试循环单链表的操作*************************" << endl << endl;

		cout << "\t 1.判断循环单链表是否为空" << endl;
		cout << "\t 2.把循环单链表的头指针后移至第i个结点" << endl;
		cout << "\t 3.删除第i个结点，头指针移至其下一个结点" << endl;
		cout << "\t 4.把一个循环单链表赋值给另一个循环单链表" << endl;
		cout << "\t 5.循环单链表置空" << endl;
		cout << "\t 6.随机生成循环单链表" << endl;
		cout << "\t 7.用已有的循环单链表初始化另一个循环单链表" << endl;
		cout << "\t 8.输入循环单链表" << endl;
		cout << "\t 9.约瑟夫（Josephus）环出列（循环单链表的应用）" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		//displayCurrentObject(list);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-9）号码：";
		cin >> choose;

		if (choose > 0 && choose < 9)
		{
			system("cls");
			//displayCurrentObject(list);
		}

		switch (choose)
		{
		case 1:ex3_3_1(list, continueYesNo);
			break;
		case 2:ex3_3_2(list, continueYesNo);
			break;
		case 3:ex3_3_3(list, continueYesNo);
			break;
		case 4:ex3_3_4(list, continueYesNo);
			break;
		case 5:ex3_3_5(list, continueYesNo);
			break;
		case 6:ex3_3_6(list, continueYesNo);
			break;
		case 7:ex3_3_7(list, continueYesNo);
			break;
		case 8:ex3_3_8(list, continueYesNo);
			break;
		case 9:ex3_3_9(list, continueYesNo);
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}