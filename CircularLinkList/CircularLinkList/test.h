template <typename ElemType>
void displayCurrentObject(MyCircularLinkList<ElemType> rec)
{
	cout << endl;
	cout << rec;
}

template <typename ElemType>
void ex3_3_1(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************�ж�ѭ���������Ƿ�Ϊ��*************************" << endl << endl;

	if (rec.isEmpty())
	{
		cout << "��ѭ��������Ϊ��" << endl;
	}
	else 
	{
		cout << "��ѭ��������Ϊ��" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_2(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************��ѭ���������ͷָ���������i�����*************************" << endl << endl;

	int i;
	ElemType e;
	cout << "������ͷָ����Ƶ��Ľ�����ţ�";
	cin >> i;
	rec.moveHead(i);
	rec.getHeadElem(e);
	cout << "�ƶ���ͷָ����ָ����������Ϊ��" << e << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_3(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************ɾ����i����㣬ͷָ����������һ�����*************************" << endl << endl;

	int i;
	ElemType e;
	cout << "��������ɾ���Ľ����ţ�";
	cin >> i;
	rec.deleteElem(i, e);
	cout << endl << "ɾ����4�����" << e << "��ѭ��������Ϊ��";
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_4(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************��һ��ѭ��������ֵ����һ��ѭ��������*************************" << endl << endl;

	MyCircularLinkList<ElemType> list2;
	cin >> list2;
	rec = list2;
	cout << "��һ��ѭ��������ֵ��ֵ����ǰѭ��������" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_5(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************ѭ���������ÿ�*************************" << endl << endl;

	rec.clear();
	if (rec.isEmpty())
	{
		cout << "��ǰѭ�����������ÿգ�" << endl;
	}
	else
	{
		cout << "�ÿ�ʧ�ܣ���" << endl;
	}
	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_6(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************�������ѭ��������*************************" << endl << endl;

	rec.Randborn();
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_7(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************�����е�ѭ���������ʼ����һ��ѭ��������*************************" << endl << endl;

	MyCircularLinkList<ElemType> list2(rec);
	cout << "��ǰѭ���������ʼ����һ��ѭ��������Ϊ��" << endl;
	cout << list2;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_8(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************����ѭ��������*************************" << endl << endl;

	cin >> rec;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_9(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************Լɪ��Josephus�������У�ѭ���������Ӧ�ã�*************************" << endl << endl;

	cout << "��ǰ��Լɪ��Ϊ��" << endl;


	cout << "��������ʼ�Ľ��ţ�";
	//cin>>
	cout << "\t�������������";
	//cin>>

	int i;
	int n = 10;
	for (i = 0; i < n; i++)
	{
		cout << "��" << i << "�γ��еĽ��Ϊ1�����к��Լɪ��Ϊ��"<<endl;
		//cout << ;
	}



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

