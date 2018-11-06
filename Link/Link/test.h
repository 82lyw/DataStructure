template <typename ElemType>
void displayCurrentObject(MySqList<ElemType> rec)
{
	cout << endl;
	cout << rec;
}

template <typename ElemType>
void ex3_1_1(MySqList<ElemType> & rec, char & continueYesNo)
{
	int i;
	ElemType e;
	cout << "*********************�ڵ�i��Ԫ��֮ǰ����һ��Ԫ��*************************" << endl << endl;

	cout << "��������Ҫ�ڵڼ���Ԫ��֮ǰ����Ԫ�أ�";
	cin >> i;
	cout << "��������Ҫ�����Ԫ�أ�";
	cin >> e;
	rec.insert(i, e);
	//cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_2(MySqList<ElemType> & rec, char & continueYesNo)
{
	int b;
	cout << "*********************�ж�˳����Ƿ�Ϊ��*************************" << endl << endl;

	cout << "��ǰ˳���";

	b = rec.isEmpty();
	cout << (b ? "Ϊ��" : "��Ϊ��") << endl;;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_3(MySqList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************��˳�����Ԫ�صĸ���*************************" << endl << endl;

	cout << "˳���Ԫ�صĸ���Ϊ��";
	cout << rec.getLength()<<endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_4(MySqList<ElemType> & rec, char & continueYesNo)
{
	int i;
	ElemType e;
	cout << "*********************ȡ��i��Ԫ��*************************" << endl << endl;

	cout << "����������ȡ��Ԫ����ţ�1-10����";
	cin >> i;
	rec.getElem(i, e);
	if (rec.getElem(i, e))
	{
		cout << "����Ҫȡ�ĵ�" << i << "Ԫ�ص�ֵΪ��"<<e<<endl;
	}
	else
	{
		cout << "�Ҳ�����Ԫ��" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_5(MySqList<ElemType> & rec, char & continueYesNo)
{
	int i1, i2, i3;
	ElemType a, b, c;
	cout << "*********************���ҵ�i����e����compare()��ϵ�����*************************" << endl << endl;

	cout << "���ҵ���ĳ��Ԫ�صĲ�����"<<endl;
	cout << "\t������������ҵ�Ԫ�أ�";
	cin >> a;
	i1 = rec.locateElem(a, equal);
	cout << "\t����Ҫ���ҵĵ�һ������"<<a<<"��Ԫ�����Ϊ��"<<i1;
	cout << endl<<endl;
	
	cout << "���Ҵ���ĳ��Ԫ�صĲ�����"<<endl;
	cout << "\t������������ҵ�Ԫ�أ�";
	cin >> b;
	i2 = rec.locateElem(b, great);
	cout << "\t����Ҫ���ҵĵ�һ������" << b << "��Ԫ�����Ϊ��" << i2;
	cout << endl<<endl;

	cout << "����С��ĳ��Ԫ�صĲ�����"<<endl;
	cout << "\t������������ҵ�Ԫ�أ�";
	cin >> c;
	i3 = rec.locateElem(c, small);
	cout << "\t����Ҫ���ҵĵ�һ��С��" << c << "��Ԫ�����Ϊ��" << i3;
	cout << endl<<endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_6(MySqList<ElemType> & rec, char & continueYesNo)
{
	ElemType e, prior_e;
	cout << "*********************����ĳԪ�ص�ǰ��*************************" << endl << endl;

	cout << "���������������ǰ����Ԫ�أ�";
	cin >> e;
	if (rec.priorElem(e, prior_e))
	{
		cout << "����Ҫ���ҵ�Ԫ��" << e << "��ǰ��Ϊ" << prior_e << endl;
	}
	else
	{
		cout << "�Ҳ�����Ԫ�ص�ǰ��"<<endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_7(MySqList<ElemType> & rec, char & continueYesNo)
{
	ElemType e, next_e;
	cout << "*********************����ĳԪ�صĺ��*************************" << endl << endl;

	cout << "����������������̵�Ԫ�أ�";
	cin >> e;
	if (rec.nextElem(e, next_e) == OK)
	{
		cout << "����Ҫ���ҵ�Ԫ��" << e << "��ǰ��Ϊ" << next_e;
	}
	else
	{
		cout << "�Ҳ�����Ԫ�صĺ��";
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_8(MySqList<ElemType> & rec, char & continueYesNo)
{
	int i;
	ElemType e;
	cout << "*********************ɾ����i��Ԫ��*************************" << endl << endl;

	cout << "����������ɾ��Ԫ�ص���ţ�1-"<<rec.getLength()<<"����";
	cin >> i;
	if (rec.deleteElem(i, e) == OK)
	{
		cout << "����ɾ���ĵ�" << i << "��Ԫ�ص�ֵΪ��" << e << endl;
		cout << "ɾ�����˳���Ϊ��" << endl;
		cout << rec;
	}
	else
		cout << "�Ҳ�����ɾ��Ԫ��";

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_9(MySqList<ElemType> & rec, char & continueYesNo)
{
	// int i;
	// i = rec.getLength();
	MySqList<ElemType> list2;
	list2.RandomBorn();
	cout << list2;
	cout << "*********************��һ��˳���ֵ����һ��˳���*************************" << endl << endl;

	cout << "��һ��˳���ֵ����ǰ˳���" << endl;
	rec = list2;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_10(MySqList<ElemType> & rec, char & continueYesNo)
{
	/*int i;
	i = rec.getLength();
	cout << "��ǰ˳�����" << i << "��Ԫ�أ��ֱ�Ϊ��" << endl;
	cout << rec;*/
	cout << "*********************�ѵ�ǰ��˳����ÿ�*************************" << endl << endl;

	rec.clear();
	int i;
	i = rec.getLength();
	cout << "��ǰ˳����ÿպ�Ԫ�صĸ���Ϊ" <<i<< endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_11(MySqList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************�������˳���Ԫ��ֵΪ0��99֮���������*************************" << endl << endl;

	rec.RandomBorn();
	cout << "������ɵ�˳���Ϊ��" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_12(MySqList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************�����е�˳����ʼ����һ��˳���*************************" << endl << endl;
	
	MySqList<ElemType> list2(rec);
	cout << "��ǰ��˳����ʼ����һ��˳���Ϊ��" << endl;
	cout << list2;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_13(MySqList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************����˳���*************************" << endl << endl;

	rec.inputList();
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_14(MySqList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************����˳���Ľ���������*************************" << endl << endl;
	cout << rec;
	MySqList<int> list2;
	list2.RandomBorn();
	cout << list2;
	cout << endl << endl;
	cout << "������˳����"<<endl;

	cout << "\t����Ϊ��" << endl;
	cout << unionSet(rec, list2);
	cout << endl;

	cout << "\t����Ϊ��" << endl;
	cout << intersectionSet(rec, list2);
	cout << endl;

	cout << "\t�Ϊ��" << endl;
	cout << dirfferenceSet(rec, list2);
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_15(MyStudent<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************ѧ����Ϣ����*************************" << endl << endl;

	int select;
	char continueSelect = 'n';
	while (1)
	{
		select = 0;
		system("cls");
		cout << "*********************ѧ����Ϣ����*************************" << endl << endl;
		cout << endl;

		cout << "\t 1.�ڵ�i��ѧ��֮ǰ����һ��ѧ��" << endl;
		cout << "\t 2.�ж�ѧ�����Ƿ�Ϊ�գ�" << endl;
		cout << "\t 3.��ѧ������ѧ����������" << endl;
		cout << "\t 4.����ѧ�����е�i��ѧ����" << endl;
		cout << "\t 5.����ĳ����ѧ����ǰ����" << endl;
		cout << "\t 6.����ĳ����ѧ���ĺ�̣�" << endl;
		cout << "\t 7.ɾ��ѧ����ĵ�i��ѧ����" << endl;
		cout << "\t 8.��һ��ѧ����ֵ����һ��ѧ����" << endl;
		cout << "\t 9.����ѧ����Ϊ�ձ�" << endl;
		cout << "\t 10.�������ѧ����" << endl;
		cout << "\t 11.�����е�ѧ�����ʼ����һ��ѧ����" << endl;
		cout << "\t 12.����ѧ����" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		//displayCurrentObject(list_1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-12�����룺";

		cin >> select;

		if (select > 0 && select < 9)
		{
			system("cls");
			//displayPolynomial(list1);
		}

		switch (select)
		{
			/*case 1:ex3_1_15_1(rec, continueSelect);
			break;
		case 2:ex3_1_15_2(rec, continueSelect);
			break;
		case 3:ex3_1_15_3(rec, continueSelect);
			break;
		case 4:ex3_1_15_4(rec, continueSelect);
			break;
		case 5:ex3_1_15_5(rec, continueSelect);
			break;
		case 6:ex3_1_15_6(rec, continueSelect);
			break;
		;*/
		case 6:ex3_1_15_12(rec, continueSelect);
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
void ex3_1_15_12(MyStudent<ElemType> & rec, char & continueYesNo)
{
	cout << "**********************����ѧ����************************" << endl << endl;

	cin >> rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}