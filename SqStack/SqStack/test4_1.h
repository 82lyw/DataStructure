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
	//stack1 = stack2;
	cout << "��һ��˳��ջ��ֵ����ǰ˳��ջ��" << endl;
	//stack1.display();

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
	cout << "*********************���ʽ���*************************" << endl << endl;




	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_1_11(MySqStack<ElemType> & stack1, char & continueYesNo)
{
	cout << "*********************�Թ����*************************" << endl << endl;




	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


