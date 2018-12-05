#include <iostream>
#include <string>
//using namespace std;
using std::cout;
using std::endl;
using std::cin;

// MyExampleClass.h顺序串数据结构C++类声明和实现（派生类）
#ifndef SQSTRING_H
#define SQSTRING_H
#include "SqString.h"
#endif

//测试需要的一些操作
#ifndef TEST_H
#define TEST_H
#include "test6.h"
#endif

int main()
{
	SqString str1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************测试顺序串的操作*************************" << endl << endl;

		cout << "\t 1.求顺序串的长度" << endl;
		cout << "\t 2.判断顺序串是否为空" << endl;
		cout << "\t 3.取顺序串的子串" << endl;
		cout << "\t 4.在第i个字符前插入另一个顺序串" << endl;
		cout << "\t 5.删除从第i个字符起长度为len的子串" << endl;
		cout << "\t 6.判断是否相等  SqString顺序串==C++String顺序串" << endl;
		cout << "\t 7.判断是否相等  SqString顺序串==SqString顺序串" << endl;
		cout << "\t 8.加法运算 SqString顺序串 + C++String顺序串" << endl;
		cout << "\t 9.加法运算 SqString顺序串 + SqString顺序串" << endl;
		cout << "\t 10.串的朴素匹配（有回溯查找）" << endl;
		cout << "\t 11.求模式串的next数组" << endl;
		cout << "\t 12.模式匹配（无回溯KMP方法查找）" << endl;
		cout << "\t 13.赋值运算  SqString顺序串=C++String顺序串" << endl;
		cout << "\t 14.赋值运算  SqString顺序串=SqString顺序串" << endl;
		cout << "\t 15.把顺序串置空" << endl;
		cout << "\t 16.随机生成顺序串" << endl;
		cout << "\t 17.用C++String顺序串初始化一个顺序串（利用拷贝初始化构造函数）" << endl;
		cout << "\t 18.用另一个SqString顺序串初始化" << endl;
		cout << "\t 19.输入顺序串" << endl;
		cout << "\t 20.简单的文本编辑器（顺序串的应用）" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(str1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-20）号码：";
		cin >> choose;

		if (choose > 0 && choose < 20)
		{
			system("cls");
			displayCurrentObject(str1);
		}

		switch (choose)
		{
		case 1:ex6_1_1(str1, continueYesNo);
			break;
		case 2:ex6_1_2(str1, continueYesNo);
			break;
		case 3:ex6_1_3(str1, continueYesNo);
			break;
		case 4:ex6_1_4(str1, continueYesNo);
			break;
		case 5:ex6_1_5(str1, continueYesNo);
			break;
		case 6:ex6_1_6(str1, continueYesNo);
			break;
		case 7:ex6_1_7(str1, continueYesNo);
			break;
		case 8:ex6_1_8(str1, continueYesNo);
			break;
		case 9:ex6_1_9(str1, continueYesNo);
			break;
		case 10:ex6_1_10(str1, continueYesNo);
			break;
		case 11:ex6_1_11(str1, continueYesNo);
			break;
		case 12:ex6_1_12(str1, continueYesNo);
			break;
		case 13:ex6_1_13(str1, continueYesNo);
			break;
		case 14:ex6_1_14(str1, continueYesNo);
			break;
		case 15:ex6_1_15(str1, continueYesNo);
			break;
		case 16:ex6_1_16(str1, continueYesNo);
			break;
		case 17:ex6_1_17(str1, continueYesNo);
			break;
		case 18:ex6_1_18(str1, continueYesNo);
			break;
		case 19:ex6_1_19(str1, continueYesNo);
			break;
		case 20:ex6_1_20(str1, continueYesNo);
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}