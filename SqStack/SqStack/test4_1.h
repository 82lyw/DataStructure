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
		
		if (midS)
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
			if (midS == NULL)
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
		/*case 1:ex4_1_10_1(midS, continueSelect);
			break;
		case 2:ex4_1_10_2(midS, continueSelect);
			break;
		case 3:ex4_1_10_3(midS, continueSelect);*/
			break;
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
void ex4_1_10_1(char & midS, char & continueSelect)
{
	cout << "**********************��׺���ʽת��Ϊ��׺���ʽ ************************" << endl << endl;

	/*char suffixS[100];
	transform(midS, suffixS);
	cout << "��ǰ��׺���ʽ��Ӧ�ĺ�׺���ʽΪ��";
	cout << suffixS;*/

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_10_2(char & midS, char & continueSelect)
{
	cout << "**********************��׺���ʽ�ļ���************************" << endl << endl;

	/*char suffixS[100];
	transform(midS, suffixS);
	double result = evaluation(suffixS);
	cout << "��ǰ��׺���ʽ"<<suffixS<<"�Ľ����"<<result;*/

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_10_3(char & midS, char & continueSelect)
{
	cout << "**********************������׺���ʽ************************" << endl << endl;

	cout << "������һ����׺���ʽ��";
	cin >> midS;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_11(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	//cout << "*********************�Թ����*************************" << endl << endl;

	int select;
	char continueSelect = 'n';
	while (1)
	{
		select = 0;
		system("cls");
		cout << "*********************�Թ���⣨˳��ջ��Ӧ�ã�*************************" << endl << endl;
		cout << endl;

		cout << "\t 1.���Թ�" << endl;
		cout << "\t 2.��һ���Թ���ֵ����һ���Թ�" << endl;
		cout << "\t 3.��������Թ�" << endl;
		cout << "\t 4.�����Թ�" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		//displayCurrentObject(list_1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-4�����룺";

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
void ex4_1_11_1(MySqStack<ElemType> & stack1, char & continueSelect)
{
	cout << "**********************���Թ�************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_11_2(MySqStack<ElemType> & stack1, char & continueSelect)
{
	cout << "**********************��һ���Թ���ֵ����һ���Թ�************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_11_3(MySqStack<ElemType> & stack1, char & continueSelect)
{
	cout << "**********************��������Թ�************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex4_1_11_4(MySqStack<ElemType> & stack1, char & continueSelect)
{
	cout << "**********************�����Թ�************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}