#include <iostream>
using namespace std;


#ifndef DOUBLELINKLIST_H
#define DOUBLELINKLIST_H
#include "DoubleLinkList.h"
#endif

//测试需要的一些操作
#ifndef TEST_H
#define TEST_H
#include "test3_4.h"
#endif

int main()
{
	MyDoubleLinkList<int> list1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************测试循环双链表的操作*************************" << endl << endl;

		cout << "\t 1.取循环双链表第i个结点的数据域" << endl;
		cout << "\t 2.在第i个结点之前插入一个数据域为e的结点" << endl;
		cout << "\t 3.判断循环双链表是否为空：" << endl;
		cout << "\t 4.求循环双链表中结点的个数" << endl;
		cout << "\t 5.返回循环双链表中数据域为e的第一个结点的指针" << endl;
		cout << "\t 6.返回某结点的前驱的数据域" << endl;
		cout << "\t 7.返回某结点的后继的数据域" << endl;
		cout << "\t 8.删除循环双链表中数据域为e的第一个结点" << endl;
		cout << "\t 9.把一个循环双链表赋值给另一个循环双链表" << endl;
		cout << "\t 10.把循环双链表置空" << endl;
		cout << "\t 11.随机生成循环双链表" << endl;
		cout << "\t 12.用已有的循环双链表初始化另一个循环双链表" << endl;
		cout << "\t 13.输入循环双链表" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(list1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-16）号码：";
		cin >> choose;

		if (choose > 0 && choose < 16)
		{
			system("cls");
			displayCurrentObject(list1);
		}

		switch (choose)
		{
		case 1:ex3_4_1(list1, continueYesNo);
			break;
		case 2:ex3_4_2(list1, continueYesNo);
			break;
		case 3:ex3_4_3(list1, continueYesNo);
			break;
		case 4:ex3_4_4(list1, continueYesNo);
			break;
		case 5:ex3_4_5(list1, continueYesNo);
			break;
		case 6:ex3_4_6(list1, continueYesNo);
			break;
		case 7:ex3_4_7(list1, continueYesNo);
			break;
		case 8:ex3_4_8(list1, continueYesNo);
			break;
		case 9:ex3_4_9(list1, continueYesNo);
			break;
		case 10:ex3_4_10(list1, continueYesNo);
			break;
		case 11:ex3_4_11(list1, continueYesNo);
			break;
		case 12:ex3_4_12(list1, continueYesNo);
			break;
		case 13:ex3_4_13(list1, continueYesNo);
			break;
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}
		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}
	return 0;
}
