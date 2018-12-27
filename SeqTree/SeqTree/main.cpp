#include <iostream>
#include <string>
#include <assert.h>
#include <iomanip>
using namespace std;

#ifndef SEQTREE_H
#define SEQTREE_H
#include "SeqTree.h"
#endif

//测试需要的一些操作
#ifndef TEST_H
#define TEST_H
#include "test9_1.h"
#endif

int main()
{
	MySeqTree<char> ST1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************测试二叉树(顺序存储)的操作*************************" << endl << endl;

		cout << "\t 1.输入二叉树" << endl;
		cout << "\t 2.随机生成" << endl;
		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(ST1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-2）号码：";
		cin >> choose;

		if (choose > 0 && choose < 3)
		{
			system("cls");
			displayCurrentObject(ST1);
		}

		switch (choose)
		{
		case 1:ex9_1_1(ST1, continueYesNo);
			break;

		case 2:ex9_1_2(ST1, continueYesNo);
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}