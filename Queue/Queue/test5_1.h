template <typename ElemType>
void displayCurrentObject(MySqQueue<ElemType> &Q1)
{
	cout << endl;
	//cout << Q1;
	Q1.display();
}

template <typename ElemType>
void ex5_1_1(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************进队列（在循环顺序队列队尾插入元素）*************************" << endl << endl;

	ElemType e;
	cout << "请输入你要插入的元素：";
	cin >> e;
	Q1.enQueue(e);
	cout << "在队尾插入元素" << e << "后，循环顺序队列为：" << endl;
	Q1.display();

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_2(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************出队列（删除循环队列队头元素）*************************" << endl << endl;

	ElemType e;
	Q1.deQueue(e);
	cout << "删除队头的元素"<<e<<"后，循环顺序队列为" << endl;
	Q1.display();

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_3(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************读循环顺序队列队头的元素到e*************************" << endl << endl;

	ElemType e;
	Q1.getFront(e);
	cout << "读对头的元素" << e << "后，循环顺序队列为：" << endl;
	Q1.display();

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_4(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************判断循环顺序队列是否为空*************************" << endl << endl;

	if (Q1.isEmpty())
	{
		cout << "当前循环顺序队列为空！" << endl;
	}
	else
	{
		cout << "当前循环顺序队列不为空！" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_5(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************判断循环顺序队列是否满*************************" << endl << endl;

	if (Q1.isFull())
	{
		cout << "当前循环顺序队列已满！" << endl;
	}
	else
	{
		cout << "当前循环顺序队列没满！" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_6(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************求循环顺序队列中元素的个数*************************" << endl << endl;

	int n = Q1.getLength();
	cout << "循环顺序队列中元素的个数为" <<n<< endl;
	

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_7(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************把一个循环顺序队列赋值给另一个循环顺序队列*************************" << endl << endl;

	cout << "另一个循环顺序队列赋值给当前循环顺序队列为：" << endl;
	MySqQueue<ElemType> Q2;
	Q2.RandQ();
	Q2.display();
	Q1 = Q2;
	Q1.display();

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_8(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************把一个循环顺序队列置空*************************" << endl << endl;

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
void ex5_1_9(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************随机生成循环顺序队列*************************" << endl << endl;

	Q1.RandQ();
	Q1.display();

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_10(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************用已有的循环顺序队列初始化另一个新循环顺序队列*************************" << endl << endl;

	MySqQueue<ElemType> Q2;
	cout << "当前循环顺序队列初始化另一个循环顺序队列为：" << endl;
	Q2 = Q1;
	Q2.display();

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_11(MySqQueue<ElemType> & Q1,char & continueYesNo,MySports & S1)
{
	//cout << "*********************运动会比赛安排*************************" << endl << endl;
	int select;
	char continueSelect = 'n';
	while (1)
	{
		select = 0;
		system("cls");
		cout << "*********************运动会比赛安排*************************" << endl << endl;
		cout << endl;

		cout << "\t 1.安排比赛" << endl;
		cout << "\t 2.输入运动会项目及运动员参赛情况" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		cout << S1;
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-2）号码：";

		cin >> select;

		if (select > 0 && select < 3)
		{
			system("cls");
			cout << S1;
		}

		switch (select)
		{
		case 1:ex5_1_11_1(Q1, continueSelect,S1);
			break;
		case 2:ex5_1_11_2(Q1, continueSelect,S1);
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
void ex5_1_11_1(MySqQueue<ElemType> & Q1, char & continueSelect, MySports & S1)
{
	cout << "**********************安排比赛************************" << endl << endl;

	S1.arrangeSports();
	cout << S1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

template <typename ElemType>
void ex5_1_11_2(MySqQueue<ElemType> & Q1, char & continueSelect, MySports & S1)
{
	cout << "**********************输入运动会项目及运动员参赛情况************************" << endl << endl;

	cin >> S1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}