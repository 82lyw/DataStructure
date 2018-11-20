#include <iostream>
#include <string>
//using namespace std;
using std::cout;
using std::endl;
using std::cin;

// MyExampleClass.h顺序表数据结构C++类声明和实现（派生类）
#ifndef MYSQLIST_H
#define MYSQLIST_H
#include "MySqList.h"
#endif

#ifndef MYSTUDENT_H
#define MYSTUDENT_H
#include "MyStudent.h"
#endif

//测试需要的一些操作
#ifndef TEST_H
#define TEST_H
#include "test.h"
#endif

int main()
{
	MySqList<int> list_1;
	MyStudent<int> list2;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************测试顺序表的操作*************************" << endl << endl;

		cout << "\t 1.在第i个元素之前插入一个元素" << endl;
		cout << "\t 2.判断顺序表是否为空" << endl;
		cout << "\t 3.求顺序表中元素的个数" << endl;
		cout << "\t 4.取第i个元素" << endl;
		cout << "\t 5.查找第i个与某元素满足compare（）关系元素的序号" << endl;
		cout << "\t 6.返回某元素的前驱" << endl;
		cout << "\t 7.返回某元素的后继" << endl;
		cout << "\t 8.删除第i个元素" << endl;
		cout << "\t 9.把一个顺序表赋值给另一个顺序表" << endl;
		cout << "\t 10.把顺序表置空" << endl;
		cout << "\t 11.随机生成顺序表（元素值在0到99之间的整数）" << endl;
		cout << "\t 12.用已有的顺序表初始化另一个顺序表" << endl;
		cout << "\t 13.输入顺序表" << endl;
		cout << "\t 14.两个顺序表的交并差运算" << endl;
		cout << "\t 15.学生信息管理" << endl;

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
		case 1:ex3_1_1(list_1, continueYesNo);
			break;
		case 2:ex3_1_2(list_1, continueYesNo);
			break;
		case 3:ex3_1_3(list_1, continueYesNo);
			break;
		case 4:ex3_1_4(list_1, continueYesNo);
			break;
		case 5:ex3_1_5(list_1, continueYesNo);
			break;
		case 6:ex3_1_6(list_1, continueYesNo);
			break;
		case 7:ex3_1_7(list_1, continueYesNo);
			break;
		case 8:ex3_1_8(list_1, continueYesNo);
			break;
		case 9:ex3_1_9(list_1, continueYesNo);
			break;
		case 10:ex3_1_10(list_1, continueYesNo);
			break;
		case 11:ex3_1_11(list_1, continueYesNo);
			break;
		case 12:ex3_1_12(list_1, continueYesNo);
			break;
		case 13:ex3_1_13(list_1, continueYesNo);
			break;
		case 14:ex3_1_14(list_1, continueYesNo);
			break;
		case 15:ex3_1_15(list2, continueYesNo);
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}