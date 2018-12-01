#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;

#ifndef SQQUEUE_H
#define SQQUEUE_H
#include "SqQueue.h"
#endif

#ifndef MYSPORTS_H
#define MYSPORTS_H
#include "MySports.h"
#endif

//测试需要的一些操作
#ifndef TEST_H
#define TEST_H
#include "test5_1.h"
#endif

int main()
{
	MySqQueue<int> Q1;
	//MySports S1;
	MySports S1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************测试循环顺序队列的操作*************************" << endl << endl;

		cout << "\t 1.进队列（在循环顺序队列队尾插入元素）" << endl;
		cout << "\t 2.出队列（删除循环队列队头元素）" << endl;
		cout << "\t 3.读循环顺序队列队头的元素到e" << endl;
		cout << "\t 4.判断循环顺序队列是否为空" << endl;
		cout << "\t 5.判断循环顺序队列是否满" << endl;
		cout << "\t 6.求循环顺序队列中元素的个数" << endl;
		cout << "\t 7.把一个循环顺序队列赋值给另一个循环顺序队列" << endl;
		cout << "\t 8.把一个循环顺序队列置空" << endl;
		cout << "\t 9.随机生成循环顺序队列" << endl;
		cout << "\t 10.用已有的循环顺序队列初始化另一个新循环顺序队列" << endl;
		cout << "\t 11.运动会比赛安排" << endl;

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
		case 11:ex5_1_11(S1, continueYesNo);
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}