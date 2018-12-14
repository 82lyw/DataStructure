template <typename ElemType>
void displayCurrentObject(MyLinkQueue<ElemType> &Q1)
{
	cout << endl;
	cout << Q1;
}

template <typename ElemType>
void ex5_1_1(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************�����У��ڷ�ѭ�����Ӷ�β����Ԫ�أ�*************************" << endl << endl;

	ElemType e;
	cout << "��������Ҫ�����Ԫ�أ�";
	cin >> e;
	Q1.enQueue(e);
	cout << "�ڶ�β����Ԫ��" << e << "�󣬷�ѭ������Ϊ��" << endl;
	cout << Q1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_2(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************�����У�ɾ��ѭ�����ж�ͷԪ�أ�*************************" << endl << endl;

	ElemType e;
	Q1.deQueue(e);
	cout << "ɾ����ͷ��Ԫ��" << e << "�󣬷�ѭ������Ϊ" << endl;
	cout << Q1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_3(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************����ѭ�����Ӷ�ͷ��Ԫ�ص�e*************************" << endl << endl;

	ElemType e;
	Q1.getFront(e);
	cout << "����ͷ��Ԫ��" << e << "�󣬷�ѭ������Ϊ��" << endl;
	cout << Q1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_4(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************�жϷ�ѭ�������Ƿ�Ϊ��*************************" << endl << endl;

	if (Q1.isEmpty())
	{
		cout << "��ǰ��ѭ������Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��ǰ��ѭ�����Ӳ�Ϊ�գ�" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_5(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************���ѭ��������Ԫ�صĸ���*************************" << endl << endl;

	int n = Q1.getLength();
	cout << "��ѭ��������Ԫ�صĸ���Ϊ" << n << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_6(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************��һ����ѭ�����Ӹ�ֵ����һ����ѭ������*************************" << endl << endl;

	cout << "��һ����ѭ�����Ӹ�ֵ����ǰ��ѭ������Ϊ��" << endl;
	MyLinkQueue<int> Q2;
	Q2.RandLinkQ();
	cout << Q2;
	Q1 = Q2;
	cout << Q1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_7(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************��һ����ѭ�������ÿ�*************************" << endl << endl;

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
void ex5_1_8(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************������ɷ�ѭ������*************************" << endl << endl;

	Q1.RandLinkQ();
	cout << Q1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_9(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************�����еķ�ѭ�����ӳ�ʼ����һ���·�ѭ������*************************" << endl << endl;

	MyLinkQueue<int> Q2(Q1);
	cout << "��ǰ��ѭ�����ӳ�ʼ����һ����ѭ������Ϊ��" << endl;
	cout << Q2;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_10(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	//cout << "*********************ͣ����������ջ�Ͷ��е�Ӧ�ã�*************************" << endl << endl;

	int select;
	char continueSelect = 'n';
	while (1)
	{
		select = 0;
		system("cls");
		cout << "*********************ͣ����������ջ�Ͷ��е�Ӧ�ã�*************************" << endl << endl;
		cout << endl;

		cout << "\t 1.ģ�⳵������" << endl;
		cout << "\t 2.����ͣ������ͣ�����������Ŀ" << endl;
		cout << "\t 3.���õ�λʱ����շ�ֵ" << endl;
		cout << "\t 4.�������ͣ�����ĳ���" << endl;

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
		case 1:ex5_2_10_1(Q1, continueSelect);
			break;
		case 2:ex5_2_10_2(Q1, continueSelect);
			break;
		case 3:ex5_2_10_3(Q1, continueSelect);
			break;
		case 4:ex5_2_10_4(Q1, continueSelect);
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
void ex5_2_10_1(MyLinkQueue<ElemType> & Q1, char & continueSelect)
{
	cout << "**********************ģ�⳵������************************" << endl << endl;

	//

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex5_2_10_2(MyLinkQueue<ElemType> & Q1, char & continueSelect)
{
	cout << "**********************����ͣ������ͣ�����������Ŀ************************" << endl << endl;

	//

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex5_2_10_3(MyLinkQueue<ElemType> & Q1, char & continueSelect)
{
	cout << "**********************���õ�λʱ����շ�ֵ************************" << endl << endl;

	//

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex5_2_10_4(MyLinkQueue<ElemType> & Q1, char & continueSelect)
{
	cout << "**********************�������ͣ�����ĳ���************************" << endl << endl;

	//

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}