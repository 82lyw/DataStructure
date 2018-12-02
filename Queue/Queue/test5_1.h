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
	cout << "*********************�����У���ѭ��˳����ж�β����Ԫ�أ�*************************" << endl << endl;

	ElemType e;
	cout << "��������Ҫ�����Ԫ�أ�";
	cin >> e;
	Q1.enQueue(e);
	cout << "�ڶ�β����Ԫ��" << e << "��ѭ��˳�����Ϊ��" << endl;
	Q1.display();

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_2(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************�����У�ɾ��ѭ�����ж�ͷԪ�أ�*************************" << endl << endl;

	ElemType e;
	Q1.deQueue(e);
	cout << "ɾ����ͷ��Ԫ��"<<e<<"��ѭ��˳�����Ϊ" << endl;
	Q1.display();

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_3(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************��ѭ��˳����ж�ͷ��Ԫ�ص�e*************************" << endl << endl;

	ElemType e;
	Q1.getFront(e);
	cout << "����ͷ��Ԫ��" << e << "��ѭ��˳�����Ϊ��" << endl;
	Q1.display();

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_4(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************�ж�ѭ��˳������Ƿ�Ϊ��*************************" << endl << endl;

	if (Q1.isEmpty())
	{
		cout << "��ǰѭ��˳�����Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��ǰѭ��˳����в�Ϊ�գ�" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_5(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************�ж�ѭ��˳������Ƿ���*************************" << endl << endl;

	if (Q1.isFull())
	{
		cout << "��ǰѭ��˳�����������" << endl;
	}
	else
	{
		cout << "��ǰѭ��˳�����û����" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_6(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************��ѭ��˳�������Ԫ�صĸ���*************************" << endl << endl;

	int n = Q1.getLength();
	cout << "ѭ��˳�������Ԫ�صĸ���Ϊ" <<n<< endl;
	

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_7(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************��һ��ѭ��˳����и�ֵ����һ��ѭ��˳�����*************************" << endl << endl;

	cout << "��һ��ѭ��˳����и�ֵ����ǰѭ��˳�����Ϊ��" << endl;
	MySqQueue<ElemType> Q2;
	Q2.RandQ();
	Q2.display();
	Q1 = Q2;
	Q1.display();

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_8(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************��һ��ѭ��˳������ÿ�*************************" << endl << endl;

	Q1.clear();
	if (Q1.isEmpty())
		cout << "��ǰ˳��ջ�ÿպ�Ԫ�صĸ���Ϊ" << Q1.getLength() << endl << endl;
	else
		cout << "�ÿ�ʧ�ܣ�" << endl << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_9(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************�������ѭ��˳�����*************************" << endl << endl;

	Q1.RandQ();
	Q1.display();

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_10(MySqQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************�����е�ѭ��˳����г�ʼ����һ����ѭ��˳�����*************************" << endl << endl;

	MySqQueue<ElemType> Q2;
	cout << "��ǰѭ��˳����г�ʼ����һ��ѭ��˳�����Ϊ��" << endl;
	Q2 = Q1;
	Q2.display();

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_11(MySqQueue<ElemType> & Q1,char & continueYesNo,MySports & S1)
{
	//cout << "*********************�˶����������*************************" << endl << endl;
	int select;
	char continueSelect = 'n';
	while (1)
	{
		select = 0;
		system("cls");
		cout << "*********************�˶����������*************************" << endl << endl;
		cout << endl;

		cout << "\t 1.���ű���" << endl;
		cout << "\t 2.�����˶�����Ŀ���˶�Ա�������" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		cout << S1;
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-2�����룺";

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
void ex5_1_11_1(MySqQueue<ElemType> & Q1, char & continueSelect, MySports & S1)
{
	cout << "**********************���ű���************************" << endl << endl;

	S1.arrangeSports();
	cout << S1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex5_1_11_2(MySqQueue<ElemType> & Q1, char & continueSelect, MySports & S1)
{
	cout << "**********************�����˶�����Ŀ���˶�Ա�������************************" << endl << endl;

	cin >> S1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}