template <typename ElemType>
void displayCurrentObject(MyLinkStack<ElemType> rec)
{
	cout << endl;
	//cout << rec;
}

template <typename ElemType>
void ex4_2_1(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************在栈顶压入一个数据域为e的结点*************************" << endl << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_2(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************弹出栈顶结点*************************" << endl << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_3(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************读栈顶结点的数据域*************************" << endl << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_4(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************判断链栈是否为空*************************" << endl << endl;

	

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_5(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************求链栈中结点的个数*************************" << endl << endl;

	

	

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_6(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************把一个链栈赋值给另一个链栈*************************" << endl << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_7(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************把链栈置空*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_8(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************随机生成链栈*************************" << endl << endl;

	rec.RandStack();

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_9(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************用已有的链栈初始化另一个链栈*************************" << endl << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}
