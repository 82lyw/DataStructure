template <typename ElemType>
void displayCurrentObject(MyLinkStack<ElemType> rec)
{
	cout << endl;
	cout << rec;
}

template <typename ElemType>
void ex4_2_1(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************��ջ��ѹ��һ��������Ϊe�Ľ��*************************" << endl << endl;

	ElemType e;
	cout << "��������Ҫ��ջ��ѹ��Ľ���������";
	cin >> e;

	rec.push(e);
	cout << "ջ��ѹ��������Ϊ" << e << "������ջ�еĽ��Ϊ��" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_2(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************����ջ�����*************************" << endl << endl;

	ElemType e;
	rec.pop(e);
	cout << "����������Ϊ" << e << "ջ��������ջ�еĽ��Ϊ��" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_3(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************��ջ������������*************************" << endl << endl;

	ElemType e;
	rec.getTop(e);
	cout << "��ջ�����������Ϊ" << e << "ջ��������ջ�еĽ��Ϊ��" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_4(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************�ж���ջ�Ƿ�Ϊ��*************************" << endl << endl;

	if (rec.isEmpty())
	{
		cout << "��ǰ��ջΪ�գ�"<<endl;
	}
	else
	{
		cout << "��ǰ��ջ��Ϊ�գ�"<<endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_5(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************����ջ�н��ĸ���*************************" << endl << endl;

	int n=rec.getLength();
	cout << "��ǰ��ջ�н�����Ϊ��" << n<<endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_6(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************��һ����ջ��ֵ����һ����ջ*************************" << endl << endl;

	MyLinkStack<ElemType> stack2;
	stack2.RandStack();
	cout << "��һ����ջ��ֵ����ǰ��ջ��" << endl;
	rec = stack2;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_7(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************����ջ�ÿ�*************************" << endl << endl;

	rec.clear();
	int n = rec.getLength();
	cout << "��ǰ�����ÿպ󣬽��ĸ���Ϊ" << n << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_8(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************���������ջ*************************" << endl << endl;

	rec.RandStack();
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex4_2_9(MyLinkStack<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************�����е���ջ��ʼ����һ����ջ*************************" << endl << endl;

	MyLinkStack<ElemType> stack2(rec);
	cout << "��ǰ��ջ��ʼ����һ����ջ��" << endl;
	cout << stack2;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}
