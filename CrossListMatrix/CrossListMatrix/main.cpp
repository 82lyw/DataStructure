#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;

#ifndef CROSSLISTMATRIX_H
#define CROSSLISTMATRIX_H
#include "CrossListMatrix.h"
#endif


//测试需要的一些操作
#ifndef TEST_H
#define TEST_H
#include "test7_2.h"
#endif

int main()
{
	CrossListMatrix<int> T1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "************** 测试稀疏矩阵的转置矩阵的操作（采用十字链表存储）******************" << endl << endl;

		cout << "\t 1.稀疏矩阵的赋值运算" << endl;
		cout << "\t 2.求稀疏矩阵的加法" << endl;
		cout << "\t 3.随机生成稀疏矩阵" << endl;
		cout << "\t 4.用已有的稀疏矩阵初始化一个新矩阵" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(T1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-4）号码：";
		cin >> choose;

		if (choose > 0 && choose < 5)
		{
			system("cls");
			displayCurrentObject(T1);
		}

		switch (choose)
		{
		case 1:ex7_2_1(T1, continueYesNo);
			break;
		case 2:ex7_2_2(T1, continueYesNo);
			break;
		case 3:ex7_2_3(T1, continueYesNo);
			break;
		case 4:ex7_2_4(T1, continueYesNo);
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}