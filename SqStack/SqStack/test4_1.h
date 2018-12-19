template <typename ElemType>
void displayCurrentObject(MySqStack<ElemType> &stack1)
{
	cout << endl;
	cout << stack1;
}

template <typename ElemType>
void ex4_1_1(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************��ջ��ѹ��Ԫ��*************************" << endl << endl;

	ElemType e;
	cout << "��������Ҫ��ջ��ѹ���Ԫ�أ�" ;
	cin >> e;
	stack1.push(e);
	cout << "ѹ��Ԫ��" << e << "����˳��ջ������ʾ��" << endl;
	cout << stack1;
	
	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_2(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************����ջ����Ԫ�ص�e*************************" << endl << endl;

	ElemType e;
	if (stack1.pop(e))
	{
		cout << "������ջ��Ԫ��Ϊ��" << e << endl << endl;
		cout << "������˳��ջ�е�Ԫ��Ϊ��"<<endl;
		cout << stack1;
	}
	else
	{
		cout << "��ǰ˳��ջΪ�գ�" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_3(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************��ջ����Ԫ��*************************" << endl << endl;

	ElemType e;
	if (stack1.getTop(e))
	{
		cout << "��ջ��Ԫ��Ϊ��" << e << endl << endl;
		cout << "��ջ��Ԫ�غ�˳��ջ�е�Ԫ��Ϊ��"<<endl;
		cout << stack1;
	}
	else
	{
		cout << "��ǰ˳��ջΪ�գ�" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_4(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************�ж�˳��ջ�Ƿ�Ϊ��*************************" << endl << endl;

	if (stack1.isEmpty())
		cout << "��ǰ˳��ջΪ�գ�" << endl << endl;
	else
		cout << "��ǰ˳��ջ��Ϊ�գ�" << endl << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_5(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************��˳��ջ��Ԫ�صĸ���*************************" << endl << endl;

	cout << "��ǰ˳��ջ��Ԫ�صĸ���Ϊ��" << stack1.getLength()<<endl<<endl;


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_6(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************��һ��˳��ջ��ֵ����һ��˳��ջ*************************" << endl << endl;

	MySqStack<ElemType> stack2;
	stack2.randStack();
	cout<<stack2;
	//stack1 = stack2;
	cout << "��һ��˳��ջ��ֵ����ǰ˳��ջ��" << endl;
	cout<<stack1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_7(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************��˳��ջ�ÿ�*************************" << endl << endl;

	stack1.clear();
	if (stack1.isEmpty())
		cout << "��ǰ˳��ջ�ÿպ�Ԫ�صĸ���Ϊ"<<stack1.getLength() << endl << endl;
	else
		cout << "�ÿ�ʧ�ܣ�" << endl << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_8(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************�������˳��ջ*************************" << endl << endl;

	stack1.randStack();
	cout << stack1;


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_9(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************�����е�˳��ջ��ʼ����һ���µ�˳��ջ*************************" << endl << endl;

	MySqStack<ElemType> stack2(stack1);
	cout << "��ǰ˳��ջ��ʼ����һ��˳��ջΪ��" << endl;
	cout << stack1;


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_10(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	//cout << "*********************���ʽ���*************************" << endl << endl;
	char midS[100];
	midS[0] = NULL;
	int select;
	char continueSelect = 'n';
	while (1)
	{
		select = 0;
		system("cls");
		cout << "*********************���ʽ��⣨˳��ջ��Ӧ�ã�*************************" << endl << endl;
		cout << endl;

		cout << "\t 1.��׺���ʽת��Ϊ��׺���ʽ" << endl;
		cout << "\t 2.��׺���ʽ�ļ���" << endl;
		cout << "\t 3.������׺���ʽ" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		if (midS[0] == NULL)
		{
			cout << "��ǰ��׺���ʽΪ�գ�" << endl;
		}
		else
		{
			cout << "��ǰ��׺���ʽΪ��" << midS << endl;
		}
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-3�����룺";

		cin >> select;

		if (select > 0 && select < 4)
		{
			system("cls");
			if (midS[0] == NULL)
			{
				cout << "��ǰ��׺���ʽΪ�գ�" << endl;
			}
			else
			{
				cout << "��ǰ��׺���ʽΪ��" << midS << endl;
			}
		}

		switch (select)
		{
		case 1:ex4_1_10_1(stack1, continueSelect,midS);
			break;
		case 2:ex4_1_10_2(stack1, continueSelect,midS);
			break;
		case 3:ex4_1_10_3(stack1, continueSelect,midS);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return;
		}
		if (continueSelect == 'n' || continueSelect == 'n')
			break;
	}


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_10_1(MySqStack<ElemType> & stack1, char & continueSelect, char(&midS)[100])
{
	cout << "**********************��׺���ʽת��Ϊ��׺���ʽ ************************" << endl << endl;

	char suffixS[100];
	transform(midS, suffixS);
	cout << "��ǰ��׺���ʽ��Ӧ�ĺ�׺���ʽΪ��";
	cout << suffixS;
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_10_2(MySqStack<ElemType> & stack1, char & continueSelect, char (&midS)[100])
{
	cout << "**********************��׺���ʽ�ļ���************************" << endl << endl;

	//cout << "������һ����׺���ʽ��";
	//cin >> midS;
	char suffixS[100];
	transform(midS, suffixS);
	double result = evaluation(suffixS);
	cout << "��ǰ��׺���ʽ" << suffixS << "�Ľ����" << result << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_10_3(MySqStack<ElemType> & stack1, char & continueSelect, char(&midS)[100])
{
	cout << "**********************������׺���ʽ************************" << endl << endl;

	//char midS[100];
	cout << "������һ����׺���ʽ��";
	cin >> midS;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_11(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	system("cls");
	cout << "*********************�Թ���⣨˳��ջ��Ӧ�ã�*************************" << endl << endl;
	
	int **maze;//�����άָ���ȡ�Թ�
	maze = NULL;
	int m=0;//������
	MazePoint start, end;
	maze = GetMaze(m);
	cout << "��������Թ�����Ϊ��" << endl;
	displayM(m, maze);
	inputPoint(start, end, m, maze);
	if (MazePath(maze,m, start, end))
	{
		cout << "�Թ�·��̽���ɹ�!" << endl;
		//displayM(m, maze);
	}
	else
		cout << "·��������!" << endl;

	/*
	int select;
	char continueSelect = 'n';
	while (1)
	{
		select = 0;
		system("cls");
		cout << "\n\n*********************�Թ���⣨˳��ջ��Ӧ�ã�*************************" << endl << endl;
		cout << endl;

		cout << "\t 1.���Թ�" << endl;
		cout << "\t 2.��һ���Թ���ֵ����һ���Թ�" << endl;
		cout << "\t 3.��������Թ�" << endl;
		cout << "\t 4.�����Թ�" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		displayM(m,maze);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-4�����룺";

		cin >> select;

		if (select > 0 && select < 5)
		{
			system("cls");
			displayM(m, maze);
		}

		switch (select)
		{
		case 1:ex4_1_11_1(stack1, continueSelect,maze,m,start,end);
			break;
		case 2:ex4_1_11_2(stack1, continueSelect, maze, m, start, end);
			break;
		case 3:ex4_1_11_3(stack1, continueSelect, maze, m, start, end);
			break;
		case 4:ex4_1_11_4(stack1, continueSelect, maze, m, start, end);
			break;
		default:cout << "\n ��ѡ���˽�����" << endl << endl;
			return;
		}
		if (continueSelect == 'n' || continueSelect == 'n')
			break;
	}
	*/

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

/*
template <typename ElemType>
void ex4_1_11_1(MySqStack<ElemType> & stack1, char & continueSelect,int **maze,int &m,MazePoint &start,MazePoint & end)
{
	cout << "**********************���Թ�************************" << endl << endl;

	maze = GetMaze(m);
	cout << "��������Թ�����Ϊ��" << endl;
	displayM(m, maze);
	inputPoint(start, end, m, maze);
	if (MazePath(maze,start,end))
	{
		cout << "�Թ�·��̽���ɹ�!" << endl;
		displayM(m, maze);
	}
	else
		cout << "·��������!"<<endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_11_2(MySqStack<ElemType> & stack1, char & continueSelect, int **maze, int &m, MazePoint &start, MazePoint & end)
{
	cout << "**********************��һ���Թ���ֵ����һ���Թ�************************" << endl << endl;

	int **maze2;//�����άָ���ȡ�Թ�
	maze2 = NULL;
	int m2;//������
	maze2= RandMaze(m2);
	displayM(m2,maze2);

	m = m2;
	maze = new int *[m];//��ȡ���ȵ���������2�Ķ���ָ��
	for (int i = 0; i < m; i++)//ÿ����άָ��Ŀռ�
	{
		maze[i] = new int[m];
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			maze[i][j]=maze2[i][j];
	displayM(m, maze);

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_11_3(MySqStack<ElemType> & stack1, char & continueSelect, int **maze, int &m, MazePoint &start, MazePoint & end)
{
	cout << "**********************��������Թ�************************" << endl << endl;

	maze = RandMaze(m);
	cout << "��������Թ�����Ϊ��" << endl;
	displayM(m, maze);

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_11_4(MySqStack<ElemType> & stack1, char & continueSelect, int **maze, int &m, MazePoint &start, MazePoint & end)
{
	cout << "**********************�����Թ�************************" << endl << endl;

	maze = GetMaze(m);
	cout << "��������Թ�����Ϊ��" << endl;
	displayM(m,maze);

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}
*/