#include <iostream>
#include <string>
#include <iomanip>

#ifndef SQLISTSORT_H
#define SQLISTSORT_H
#include "SqListSort.h"
#endif

#ifndef MYSTATIC_H
#define MYSTATIC_H
#include "MyStaticList.h"
#endif // !MYSTATIC_H


//测试需要的一些操作
#ifndef TEST_H
#define TEST_H
#include "test11.h"
#endif

int main()
{
	SqListSort<int> S1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "************** 测试排序操作******************" << endl << endl;

		cout << "\t 1.直接插入排序" << endl;
		cout << "\t 2.折半插入排序" << endl;
		cout << "\t 3.静态链表插入排序" << endl;
		cout << "\t 4.希尔排序" << endl;
		cout << "\t 5.冒泡排序" << endl;
		cout << "\t 6.快速排序" << endl;
		cout << "\t 7.直接选择排序" << endl;
		cout << "\t 8.堆排序" << endl;
		cout << "\t 9.归并排序" << endl;
		cout << "\t 10.基数排序（采用静态链表存储）" << endl;

		cout << "\t 11.随机生成顺序表" << endl;
		cout << "\t 12.随机生成静态链表" << endl;
		cout << "\t 13.输入顺序表" << endl;
		cout << "\t 14.学生信息排序（排序应用）" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(S1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-10）号码：";
		cin >> choose;

		if (choose > 0 && choose < 12)
		{
			system("cls");
			displayCurrentObject(S1);
		}

		switch (choose)
		{
		case 1:ex11_1(S1, continueYesNo);
			break;
		case 2:ex11_2(S1, continueYesNo);
			break;
		case 3:ex11_3(S1, continueYesNo);
			break;
		case 4:ex11_4(S1, continueYesNo);
			break;
		case 5:ex11_5(S1, continueYesNo);
			break;
		case 6:ex11_6(S1, continueYesNo);
			break;
		case 7:ex11_7(S1, continueYesNo);
			break;
		case 8:ex11_8(S1, continueYesNo);
			break;
		case 9:ex11_9(S1, continueYesNo);
			break;
		case 10:ex11_10(S1, continueYesNo);
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}