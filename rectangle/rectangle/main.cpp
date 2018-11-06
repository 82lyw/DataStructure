#include <iostream>
using namespace std;

// MyExampleClass.h长方形数据结构C++类声明和实现（派生类）
#ifndef MYEXAMPLECLASS_H
#define MYEXAMPLECLASS_H
#include "MyExampleClass.h"
#endif

#ifndef TEST_H
#define TEST_H
#include "test.h"
#endif

//int main()
//{
//	float aL = (float)8.2;
//	MyRectangle<int> d1;
//	MyRectangle<float> d2, d3;
//
//	d1.setNo(1);
//	d2.setNo(2);
//	d3.setNo(3);
//	cout << d1 << d2 << d3;
//
//	cin >> d1 >> d2;
//
//	cout << "把第二个长方形对象赋给第三个长方形对象" << endl;
//	d3 = d3;
//	cout << "设置第二个长方形对象的长为" << aL << endl;
//	d2.setLength(aL);
//	cout << d1 << d2 << d3;
//	cout << "各对象按声明是相反的顺序逐一自动析构，结束各自的生命周期" << endl;
//
//	return 0;
//}

int main()
{
	MyRectangle<float> rec;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************测试长方形的操作*************************" << endl << endl;

		cout << "\t 1.设置长方形的序号：" << endl;
		cout << "\t 2.设置长方形的长：" << endl;
		cout << "\t 3.重载赋值运算符的定义：" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(rec);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-3）号码：";
		cin >> choose;

		if (choose > 0 && choose < 3)
		{
			system("cls");
			displayCurrentObject(rec);
		}

		switch (choose)
		{
		case 1:ex2_1_1(rec, continueYesNo);
			break;
		case 2:ex2_1_2(rec, continueYesNo);
			break;
		case 3:ex2_1_3(rec, continueYesNo);
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}
	return 0;
}