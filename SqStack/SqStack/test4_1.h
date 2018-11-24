template <typename ElemType>
void displayCurrentObject(MySqStack<ElemType> &stack1)
{
	cout << endl;
	cout << stack1;
}

template <typename ElemType>
void ex4_1_1(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************在栈顶压入元素*************************" << endl << endl;

	ElemType e;
	cout << "请输入你要在栈顶压入的元素：" ;
	cin >> e;
	stack1.push(e);
	cout << "压入元素" << e << "后，新顺序栈如下所示：" << endl;
	cout << stack1;
	
	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_2(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************弹出栈顶的元素到e*************************" << endl << endl;

	ElemType e;
	if (stack1.pop(e))
	{
		cout << "弹出的栈顶元素为：" << e << endl << endl;
		cout << "弹出后顺序栈中的元素为："<<endl;
		cout << stack1;
	}
	else
	{
		cout << "当前顺序栈为空！" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_3(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************读栈顶的元素*************************" << endl << endl;

	ElemType e;
	if (stack1.getTop(e))
	{
		cout << "读栈顶元素为：" << e << endl << endl;
		cout << "读栈顶元素后，顺序栈中的元素为："<<endl;
		cout << stack1;
	}
	else
	{
		cout << "当前顺序栈为空！" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_4(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************判断顺序栈是否为空*************************" << endl << endl;

	if (stack1.isEmpty())
		cout << "当前顺序栈为空！" << endl << endl;
	else
		cout << "当前顺序栈不为空！" << endl << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_5(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************求顺序栈中元素的个数*************************" << endl << endl;

	cout << "当前顺序栈中元素的个数为：" << stack1.getLength()<<endl<<endl;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_6(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************把一个顺序栈赋值给另一个顺序栈*************************" << endl << endl;

	MySqStack<ElemType> stack2;
	stack2.randStack();
	//stack1 = stack2;
	cout << "另一个顺序栈赋值给当前顺序栈：" << endl;
	//stack1.display();

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_7(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************把顺序栈置空*************************" << endl << endl;

	stack1.clear();
	if (stack1.isEmpty())
		cout << "当前顺序栈置空后，元素的个数为"<<stack1.getLength() << endl << endl;
	else
		cout << "置空失败！" << endl << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_8(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************随机生成顺序栈*************************" << endl << endl;

	stack1.randStack();
	cout << stack1;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_9(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************用已有的顺序栈初始化另一个新的顺序栈*************************" << endl << endl;

	MySqStack<ElemType> stack2(stack1);
	cout << "当前顺序栈初始化另一个顺序栈为：" << endl;
	cout << stack1;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_10(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************表达式求解*************************" << endl << endl;




	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_11(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************迷宫求解*************************" << endl << endl;




	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


