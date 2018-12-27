#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
using std::cout;
using std::endl;
using std::cin;

#ifndef MYBITREE_H
#define MYBITREE_H
#include "BiTree.h"
#endif

//测试需要的一些操作
#ifndef TEST_H
#define TEST_H
#include "test9.h"
#endif

int main()
{
	MyBiTree<char> BT1;

	int choose;
	char continueYesNo = 'N';
	while (1)
	{
		choose = 0;
		system("cls");
		cout << endl;
		cout << "*********************测试（中序穿线）二叉树的操作*************************" << endl << endl;

		cout << "\t 1.求二叉树的结点数" << endl;
		cout << "\t 2.求二叉树的叶子数" << endl;
		cout << "\t 3.递归求二叉树深度" << endl;
		cout << "\t 4.交换二叉树中所有结点的左右子树" << endl;
		cout << "\t 5.前序递归遍历二叉树" << endl;
		cout << "\t 6.中序递归遍历二叉树" << endl;
		cout << "\t 7.后序递归遍历二叉树" << endl;
		cout << "\t 8.非递归中序遍历二叉树" << endl;
		cout << "\t 9.按层次顺序遍历二叉树" << endl;
		cout << "\t 10.以顺序存储的方式显示二叉树" << endl;
		cout << "\t 11.二叉树的二叉链表存储转换为顺序存储结构" << endl;
		cout << "\t 12.二叉树的顺序存储转换为二叉链表存储结构" << endl;
		cout << "\t 13.随机生成二叉树" << endl;
		cout << "\t 14.输入二叉树" << endl<<endl;

		/*
		cout << "\t 15.中序遍历中序穿线二叉树" << endl;
		cout << "\t 16.中序穿线二叉树顺序存储转换为二叉链表存储" << endl;
		cout << "\t 17.中序穿线二叉树中找指定结点中序的前驱与后继" << endl;
		cout << "\t 18.随机生成中序穿线二叉树" << endl;
		cout << "\t 19.输入中序穿线二叉树" << endl;
		cout << "\t 20.哈夫曼树（二叉树的应用）" << endl;
		*/

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayCurrentObject(BT1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-20）号码：";
		cin >> choose;

		if (choose > 0 && choose < 15)
		{
			system("cls");
			displayCurrentObject(BT1);
		}

		switch (choose)
		{
		case 1:ex9_2_1(BT1, continueYesNo);
			break;
			
		case 2:ex9_2_2(BT1, continueYesNo);
			break;
		case 3:ex9_2_3(BT1, continueYesNo);
			break;
		case 4:ex9_2_4(BT1, continueYesNo);
			break;
		case 5:ex9_2_5(BT1, continueYesNo);
			break;
		case 6:ex9_2_6(BT1, continueYesNo);
			break;
		case 7:ex9_2_7(BT1, continueYesNo);
			break;
		case 8:ex9_2_8(BT1, continueYesNo);
			break;
		case 9:ex9_2_9(BT1, continueYesNo);
			break;
		case 10:ex9_2_10(BT1, continueYesNo);
			break;
		case 11:ex9_2_11(BT1, continueYesNo);
			break;
		case 12:ex9_2_12(BT1, continueYesNo);
			break;
		case 13:ex9_2_13(BT1, continueYesNo);
			break;
		case 14:ex9_2_14(BT1, continueYesNo);
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return 0;
		}

		if (continueYesNo == 'N' || continueYesNo == 'n')
			break;
	}

	return 0;
}