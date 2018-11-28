#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;

#ifndef MYLINKQUEUE_H
#define MYLINKQUEUE_H
#include "MyLinkQueue.h"
#endif



//测试需要的一些操作
#ifndef TEST_H
#define TEST_H
#include "test5_2.h"
#endif

int main()
{
	MyLinkQueue<int> Q1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************测试非循环链队的操作*************************" << endl << endl;

		cout << "\t 1.进队列（在非循环链队队尾插入元素）" << endl;
		cout << "\t 2.出队列（删除循环队列队头元素）" << endl;
		cout << "\t 3.读非循环链队队头的元素到e" << endl;
		cout << "\t 4.判断非循环链队是否为空" << endl;
		cout << "\t 5.求非循环链队中元素的个数" << endl;
		cout << "\t 6.把一个非循环链队赋值给另一个非循环链队" << endl;
		cout << "\t 7.把一个非循环链队置空" << endl;
		cout << "\t 8.随机生成非循环链队" << endl;
		cout << "\t 9.用已有的非循环链队初始化另一个新非循环链队" << endl;
		cout << "\t 10.运动会比赛安排" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(Q1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-11）号码：";
		cin >> choose;

		if (choose > 0 && choose < 12)
		{
			system("cls");
			displayCurrentObject(Q1);
		}

		switch (choose)
		{
		case 1:ex5_1_1(Q1, continueYesNo);
			break;
		case 2:ex5_1_2(Q1, continueYesNo);
			break;
		case 3:ex5_1_3(Q1, continueYesNo);
			break;
		case 4:ex5_1_4(Q1, continueYesNo);
			break;
		case 5:ex5_1_5(Q1, continueYesNo);
			break;
		case 6:ex5_1_6(Q1, continueYesNo);
			break;
		case 7:ex5_1_7(Q1, continueYesNo);
			break;
		case 8:ex5_1_8(Q1, continueYesNo);
			break;
		case 9:ex5_1_9(Q1, continueYesNo);
			break;
		case 10:ex5_1_10(Q1, continueYesNo);
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}