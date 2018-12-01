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
	cout<<stack2;
	//stack1 = stack2;
	cout << "另一个顺序栈赋值给当前顺序栈：" << endl;
	cout<<stack1;

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
	//cout << "*********************表达式求解*************************" << endl << endl;
	char midS[100];
	int select;
	char continueSelect = 'n';
	while (1)
	{
		select = 0;
		system("cls");
		cout << "*********************表达式求解（顺序栈的应用）*************************" << endl << endl;
		cout << endl;

		cout << "\t 1.中缀表达式转换为后缀表达式" << endl;
		cout << "\t 2.后缀表达式的计算" << endl;
		cout << "\t 3.输入中缀表达式" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		
		if (midS)
		{
			cout << "当前中缀表达式为空！" << endl;
		}
		else
		{
			cout << "当前中缀表达式为：" << midS << endl;
		}
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-3）号码：";

		cin >> select;

		if (select > 0 && select < 4)
		{
			system("cls");
			if (midS == NULL)
			{
				cout << "当前中缀表达式为空！" << endl;
			}
			else
			{
				cout << "当前中缀表达式为：" << midS << endl;
			}
		}

		switch (select)
		{
		/*case 1:ex4_1_10_1(midS, continueSelect);
			break;
		case 2:ex4_1_10_2(midS, continueSelect);
			break;
		case 3:ex4_1_10_3(midS, continueSelect);*/
			break;
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
void ex4_1_10_1(char & midS, char & continueSelect)
{
	cout << "**********************中缀表达式转换为后缀表达式 ************************" << endl << endl;

	/*char suffixS[100];
	transform(midS, suffixS);
	cout << "当前中缀表达式对应的后缀表达式为：";
	cout << suffixS;*/

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_10_2(char & midS, char & continueSelect)
{
	cout << "**********************后缀表达式的计算************************" << endl << endl;

	/*char suffixS[100];
	transform(midS, suffixS);
	double result = evaluation(suffixS);
	cout << "当前后缀表达式"<<suffixS<<"的结果是"<<result;*/

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_10_3(char & midS, char & continueSelect)
{
	cout << "**********************输入中缀表达式************************" << endl << endl;

	cout << "请输入一个中缀表达式：";
	cin >> midS;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_11(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	//cout << "*********************迷宫求解*************************" << endl << endl;

	int select;
	char continueSelect = 'n';
	while (1)
	{
		select = 0;
		system("cls");
		cout << "*********************迷宫求解（顺序栈的应用）*************************" << endl << endl;
		cout << endl;

		cout << "\t 1.走迷宫" << endl;
		cout << "\t 2.把一个迷宫赋值给另一个迷宫" << endl;
		cout << "\t 3.随机生成迷宫" << endl;
		cout << "\t 4.输入迷宫" << endl;

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
		case 1:ex4_1_11_1(stack1, continueSelect);
			break;
		case 2:ex4_1_11_2(stack1, continueSelect);
			break;
		case 3:ex4_1_11_3(stack1, continueSelect);
			break;
		case 4:ex4_1_11_4(stack1, continueSelect);
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
void ex4_1_11_1(MySqStack<ElemType> & stack1, char & continueSelect)
{
	cout << "**********************走迷宫************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_11_2(MySqStack<ElemType> & stack1, char & continueSelect)
{
	cout << "**********************把一个迷宫赋值给另一个迷宫************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_11_3(MySqStack<ElemType> & stack1, char & continueSelect)
{
	cout << "**********************随机生成迷宫************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_11_4(MySqStack<ElemType> & stack1, char & continueSelect)
{
	cout << "**********************输入迷宫************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}