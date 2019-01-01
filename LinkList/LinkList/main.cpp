#include <iostream>
using namespace std;

// MyExampleClass.h顺序表数据结构C++类声明和实现（派生类）
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

//测试需要的一些操作
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
		cout << "*********************测试非循环单链表的操作*************************" << endl << endl;
		cout << "\t 1.取非循环单链表的第i个结点" << endl;
		cout << "\t 2.在第i个结点之前插入一个数据域为e的结点" << endl;
		cout << "\t 3.判断非循环单链表是否为空" << endl;
		cout << "\t 4.求非循环单链表中结点的个数" << endl;
		cout << "\t 5.查找第i个与某元素满足compare（）关系元素的序号" << endl;
		cout << "\t 6.返回某元素的前驱的数据域" << endl;
		cout << "\t 7.返回某元素的后继的数据域" << endl;
		cout << "\t 8.删除非循环 单链表中数据域为e的第一个结点" << endl;
		cout << "\t 9.删除非循环单链表中重复的值" << endl;
		cout << "\t 10.非循环单链表的逆置" << endl;
		cout << "\t 11.把一个非循环单链表赋值给另一个非循环单链表" << endl;
		cout << "\t 12.把非循环单链表置空" << endl;
		cout << "\t 13.随机生成非循环单链表" << endl;
		cout << "\t 14.用已有的非循环单链表初始化另一个非循环单链表" << endl;
		cout << "\t 15.输入非循环单链表" << endl;
		cout << "\t16.多项式的运算（非循环单链表的应用）" << endl;
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
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}
		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}
	return 0;
}