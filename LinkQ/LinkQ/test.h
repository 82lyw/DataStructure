template <typename ElemType>
void displayCurrentObject(MyLinkQueue<ElemType> &Q1)
{
	cout << endl;
	cout << Q1;
}

template <typename ElemType>
void ex5_1_1(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************进队列（在非循环链队队尾插入元素）*************************" << endl << endl;

	ElemType e;
	cout << "请输入你要插入的元素：";
	cin >> e;
	Q1.enQueue(e);
	cout << "在队尾插入元素" << e << "后，非循环链队为：" << endl;
	cout << Q1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_2(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************出队列（删除循环队列队头元素）*************************" << endl << endl;

	ElemType e;
	Q1.deQueue(e);
	cout << "删除队头的元素" << e << "后，非循环链队为" << endl;
	cout << Q1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_3(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************读非循环链队队头的元素到e*************************" << endl << endl;

	ElemType e;
	Q1.getFront(e);
	cout << "读对头的元素" << e << "后，非循环链队为：" << endl;
	cout << Q1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_4(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************判断非循环链队是否为空*************************" << endl << endl;

	if (Q1.isEmpty())
	{
		cout << "当前非循环链队为空！" << endl;
	}
	else
	{
		cout << "当前非循环链队不为空！" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_5(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************求非循环链队中元素的个数*************************" << endl << endl;

	int n = Q1.getLength();
	cout << "非循环链队中元素的个数为" << n << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_6(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************把一个非循环链队赋值给另一个非循环链队*************************" << endl << endl;

	cout << "另一个非循环链队赋值给当前非循环链队为：" << endl;
	MyLinkQueue<int> Q2;
	Q2.RandLinkQ();
	cout << Q2;
	Q1 = Q2;
	cout << Q1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_7(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************把一个非循环链队置空*************************" << endl << endl;

	Q1.clear();
	if (Q1.isEmpty())
		cout << "当前顺序栈置空后，元素的个数为" << Q1.getLength() << endl << endl;
	else
		cout << "置空失败！" << endl << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_8(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************随机生成非循环链队*************************" << endl << endl;

	Q1.RandLinkQ();
	cout << Q1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_9(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************用已有的非循环链队初始化另一个新非循环链队*************************" << endl << endl;

	MyLinkQueue<int> Q2(Q1);
	cout << "当前非循环链队初始化另一个非循环链队为：" << endl;
	cout << Q2;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_10(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	//cout << "*********************停车场管理（栈和队列的应用）*************************" << endl << endl;

	int select;
	char continueSelect = 'n';
	while (1)
	{
		select = 0;
		system("cls");
		cout << "*********************停车场管理（栈和队列的应用）*************************" << endl << endl;
		cout << endl;

		cout << "\t 1.模拟车辆调度" << endl;
		cout << "\t 2.设置停车场可停车辆的最大数目" << endl;
		cout << "\t 3.设置单位时间的收费值" << endl;
		cout << "\t 4.随机生成停车场的车辆" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		//displayCurrentObject(list_1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-4）号码：";

		cin >> select;

		if (select > 0 && select < 5)
		{
			system("cls");
			//stack1.displayS();
		}

		switch (select)
		{
		case 1:ex5_2_10_1(Q1, continueSelect);
			break;
		case 2:ex5_2_10_2(Q1, continueSelect);
			break;
		case 3:ex5_2_10_3(Q1, continueSelect);
			break;
		case 4:ex5_2_10_4(Q1, continueSelect);
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return;
		}
		if (continueSelect == 'n' || continueSelect == 'n')
			break;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_2_10_1(MyLinkQueue<ElemType> & Q1, char & continueSelect)
{
	cout << "**********************模拟车辆调度************************" << endl << endl;

	//

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

template <typename ElemType>
void ex5_2_10_2(MyLinkQueue<ElemType> & Q1, char & continueSelect)
{
	cout << "**********************设置停车场可停车辆的最大数目************************" << endl << endl;

	//

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

template <typename ElemType>
void ex5_2_10_3(MyLinkQueue<ElemType> & Q1, char & continueSelect)
{
	cout << "**********************设置单位时间的收费值************************" << endl << endl;

	//

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

template <typename ElemType>
void ex5_2_10_4(MyLinkQueue<ElemType> & Q1, char & continueSelect)
{
	cout << "**********************随机生成停车场的车辆************************" << endl << endl;

	//

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}