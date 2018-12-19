#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;

#ifndef TSMATRIX_H
#define TSMATRIX_H
#include "TSMatrix.h"
#endif


//测试需要的一些操作
#ifndef TEST_H
#define TEST_H
#include "test7_1.h"
#endif

int main()
{
	TSMatrix<int> T1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "************** 测试稀疏矩阵的转置矩阵的操作（采用三元组表顺序存储）******************" << endl << endl;

		cout << "\t 1.求稀疏矩阵的转置矩阵" << endl;
		cout << "\t 2.快速求稀疏矩阵的转置矩阵" << endl;
		cout << "\t 3.计算稀疏矩阵各行第一个非零元素在三元组表中的下标" << endl;
		cout << "\t 4.稀疏矩阵的赋值运算" << endl;
		cout << "\t 5.求稀疏矩阵的加法" << endl;
		cout << "\t 6.求稀疏矩阵的乘法" << endl;
		cout << "\t 7.显示稀疏矩阵的三元组表示" << endl;
		cout << "\t 8.随机生成稀疏矩阵" << endl;
		cout << "\t 9.用已有的稀疏矩阵初始化一个新矩阵" << endl;
		cout << "\t 10.输入稀疏矩阵的三元组表" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(T1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-10）号码：";
		cin >> choose;

		if (choose > 0 && choose < 12)
		{
			system("cls");
			displayCurrentObject(T1);
		}

		switch (choose)
		{
		case 1:ex7_1_1(T1, continueYesNo);
			break;
		case 2:ex7_1_2(T1, continueYesNo);
			break;
		case 3:ex7_1_3(T1, continueYesNo);
			break;
		case 4:ex7_1_4(T1, continueYesNo);
			break;
		case 5:ex7_1_5(T1, continueYesNo);
			break;
		case 6:ex7_1_6(T1, continueYesNo);
			break;
		case 7:ex7_1_7(T1, continueYesNo);
			break;
		case 8:ex7_1_8(T1, continueYesNo);
			break;
		case 9:ex7_1_9(T1, continueYesNo);
			break;
		case 10:ex7_1_10(T1, continueYesNo);
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}