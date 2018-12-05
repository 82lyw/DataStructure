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
	MyLinkQueue<ElemType> Q2;
	Q2.randLinkQ();
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

	Q1.randLinkQ();
	cout << Q1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_9(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************用已有的非循环链队初始化另一个新非循环链队*************************" << endl << endl;

	MyLinkQueue<ElemType> Q2(Q1);
	cout << "当前非循环链队初始化另一个非循环链队为：" << endl;
	cout << Q2;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_10(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************停车场管理（栈和队列的应用）*************************" << endl << endl;




	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}
