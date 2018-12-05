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
	MyLinkQueue<ElemType> Q2;
	Q2.randLinkQ();
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

	Q1.randLinkQ();
	cout << Q1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_9(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************�����еķ�ѭ�����ӳ�ʼ����һ���·�ѭ������*************************" << endl << endl;

	MyLinkQueue<ElemType> Q2(Q1);
	cout << "��ǰ��ѭ�����ӳ�ʼ����һ����ѭ������Ϊ��" << endl;
	cout << Q2;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex5_1_10(MyLinkQueue<ElemType> & Q1, char & continueYesNo)
{
	cout << "*********************ͣ��������ջ�Ͷ��е�Ӧ�ã�*************************" << endl << endl;




	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}
