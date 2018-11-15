template <typename ElemType>
void displayCurrentObject(DoubleLinkList<ElemType> rec)
{
	cout << endl;
	//cout << rec;
}

template <typename ElemType>
void ex3_4_1(DoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************ȡѭ��˫�����i������������*************************" << endl << endl;
	int i;
	ElemType e;
	cout << "��������Ҫȡ�Ľ�����ţ�";
	cin >> i;
	rec.getElem(i, e);
	if (rec.getElem(i, e))
	{
		cout << "��Ҫȡѭ��˫����ĵ�" << i << "������������Ϊ" << e << endl;
	}
	else
	{
		if (i <= 0)
			cout << "iӦΪ����0������" << endl;
		if (i > rec.getLength())
			cout << "i��Խ�磬�޷�ȡ���ý���������" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_2(DoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************�ڵ�i�����֮ǰ����һ��������Ϊe�Ľ��*************************" << endl << endl;
	int i;
	ElemType e;
	cout << "��������Ҫ����֮ǰ����������";
	cin >> i;
	cout << "��������Ҫ�������������";
	cin >> e;
	cout << endl;

	rec.insert(i, e);
	if (rec.insert(i, e))
	{
		cout << "���Ѿ��ڵ�" << i << "�����֮ǰ����������Ϊ" << e << "�Ľ��" << endl;
		//cout << rec;
	}
	else
	{
		if (rec.isEmpty())
			cout << "ѭ��˫����Ϊ��" << endl;
		else
			cout << "����ķ�ΧԽ��" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_3(DoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************�ж�ѭ��˫�����Ƿ�Ϊ��*************************" << endl << endl;

	if (rec.isEmpty())
		cout << "��ǰѭ��˫����Ϊ��" << endl;
	else
		cout << "��ǰѭ��˫����Ϊ��" << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_4(DoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************��ѭ��˫�����н��ĸ���*************************" << endl << endl;

	rec.getLength();
	cout << "ѭ��˫�����н��ĸ���Ϊ" << rec.getLength() << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_5(DoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************����ѭ��˫������������Ϊe�ĵ�һ������ָ��*************************" << endl << endl;

	ElemType e;
	typename DoubleLinkList<ElemType>::NodePointer r;

	cout << "\t������������ҵĽ���������";
	cin >> e;
	rec.locateElem(e,r);
	if (rec.locateElem(e, r))
	{
		cout << "������ҵ�һ�����������" << e << "�Ľ���������Ϊ" << r->data;
		cout << endl << endl;
	}
	else
	{
		cout << "�Ҳ�����������Ľ��ָ��" << endl << endl;
	}


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_6(DoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************����ĳ����ǰ����������*************************" << endl << endl;

	ElemType e, prior_e;
	cout << "����������Ҫ���ҽ���������";
	cin >> e;
	rec.priorElem(e, prior_e);
	cout << "�������" << e << "ǰ����������Ϊ" << prior_e << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_7(DoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************����ĳ���ĺ�̵�������*************************" << endl << endl;

	ElemType e, next_e;
	cout << "����������Ҫ���ҽ���������";
	cin >> e;
	rec.nextElem(e, next_e);
	cout << "�������" << e << "��̵�������Ϊ" << next_e << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_8(DoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************ɾ��ѭ��˫������������Ϊe�ĵ�һ�����*************************" << endl << endl;

	ElemType e;
	cout << "����������ɾ������������";
	cin >> e;
	if (rec.deleteElem(e))
	{
		cout << "ɾ�����ѭ��˫����Ϊ" << endl;
		//cout << rec;
	}
	else
	{
		cout << "��Ԫ�ز�����" << endl;
	}


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_9(DoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************��һ��ѭ��˫����ֵ����һ��ѭ��˫����*************************" << endl << endl;

	DoubleLinkList<ElemType> list2;
	cout << "��һ��ѭ��˫����ֵ����ǰѭ��˫����Ϊ��" << endl;
	//
	//cout<<rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_10(DoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************��ѭ��˫�����ÿ�*************************" << endl << endl;

	rec.clear();
	cout << "��ǰѭ��˫�������ÿգ�" << endl << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_11(DoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************�������ѭ��˫����*************************" << endl << endl;

	DoubleLinkList<ElemType> list2;
	cout << "��ǰѭ��˫�����ʼ����һ��ѭ��˫����" << endl;
	//list2 = rec;
	//cout << list2;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_12(DoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************�����е�ѭ��˫�����ʼ����һ��ѭ��˫����*************************" << endl << endl;

	

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_13(DoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************����ѭ��˫����*************************" << endl << endl;

	//cin >> rec;

	cout << "�������ѭ��˫�������£�" << endl;
	//cout<<rec
	

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}
