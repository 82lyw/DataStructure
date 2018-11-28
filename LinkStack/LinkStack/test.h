template <typename ElemType>
void displayCurrentObject(MyLinkStack<ElemType> rec)
{
	cout << endl;
	cout << rec;
}

template <typename ElemType>
void ex4_2_1(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************在栈顶压入一个数据域为e的结点*************************" << endl << endl;

	ElemType e;
	cout << "请输入你要在栈顶压入的结点的数据域：";
	cin >> e;

	rec.push(e);
	cout << "栈顶压入数据域为" << e << "结点后，链栈中的结点为：" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_2(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************弹出栈顶结点*************************" << endl << endl;

	ElemType e;
	rec.pop(e);
	cout << "弹出数据域为" << e << "栈顶结点后，链栈中的结点为：" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_3(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************读栈顶结点的数据域*************************" << endl << endl;

	ElemType e;
	rec.getTop(e);
	cout << "读栈顶结点数据域为" << e << "栈顶结点后，链栈中的结点为：" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_4(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************判断链栈是否为空*************************" << endl << endl;

	if (rec.isEmpty())
	{
		cout << "当前链栈为空！"<<endl;
	}
	else
	{
		cout << "当前链栈不为空！"<<endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_5(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************求链栈中结点的个数*************************" << endl << endl;

	int n=rec.getLength();
	cout << "当前链栈中结点个数为：" << n<<endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_6(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************把一个链栈赋值给另一个链栈*************************" << endl << endl;

	MyLinkStack<ElemType> stack2;
	stack2.RandStack();
	cout << "另一个链栈赋值给当前链栈：" << endl;
	rec = stack2;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_7(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************把链栈置空*************************" << endl << endl;

	rec.clear();
	int n = rec.getLength();
	cout << "当前链表置空后，结点的个数为" << n << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_8(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************随机生成链栈*************************" << endl << endl;

	rec.RandStack();
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_9(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************用已有的链栈初始化另一个链栈*************************" << endl << endl;

	MyLinkStack<ElemType> stack2(rec);
	cout << "当前链栈初始化另一个链栈：" << endl;
	cout << stack2;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}
