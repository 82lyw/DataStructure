template <typename ElemType>
void displayCurrentObject(MyLinkList<ElemType> rec)
{
	cout << endl;
	cout << rec;
}

template <typename ElemType>
void ex3_2_1(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "**************ȡ��ѭ��������ĵ�i�����*****************" << endl << endl;
	int i;
	ElemType e;
	cout << "��������Ҫȡ�Ľ�����ţ�";
	cin >> i;
	rec.getElem(i,e);
	if (rec.getElem(i, e)) 
	{
		cout << "��Ҫȡ��ѭ��������ĵ�" << i << "������������Ϊ" << e << endl;
	}
	else
	{
		if (i <= 0)
			cout << "iӦΪ����0������" << endl;
		if (i > rec.getLength())
			cout << "i��Խ�磬�޷�ȡ���ý���������" << endl;
	}

	cout << "**********************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_2(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "***********�ڵ�i�����֮ǰ����һ��������Ϊe�Ľ��************" << endl << endl;
	int i;
	ElemType e;
	cout << "��������Ҫ����֮ǰ����������";
	cin >> i;
	cout << "��������Ҫ�������������";
	cin >> e;
	cout << endl;
	if (rec.insert(i,e))
	{
		cout << "���Ѿ��ڵ�" << i << "�����֮ǰ����������Ϊ" << e << "�Ľ��" << endl;
		cout << rec;
	}
	else
	{
		if (rec.isEmpty())
			cout << "��ѭ��������Ϊ��" << endl;
		else
			cout << "����ķ�ΧԽ��" << endl;
	}
	cout << "*************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_3(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "************�жϷ�ѭ���������Ƿ�Ϊ��*****************" << endl << endl;

	if (rec.isEmpty())
		cout << "��ǰ��ѭ��������Ϊ��" << endl;
	else
		cout << "��ǰ��ѭ��������Ϊ��" << endl;

	cout << "**********************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_4(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "**********���ѭ���������н��ĸ���**************" << endl << endl;

	rec.getLength();
	cout << "��ѭ���������н��ĸ���Ϊ" << rec.getLength() << endl;

	cout << "********************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_5(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*****���ҵ�i����ĳԪ������compare������ϵԪ�ص����*****" << endl << endl;

	int i1, i2, i3;
	ElemType a, b, c;

	cout << "���ҵ���ĳ�����Ĳ�����" << endl;
	cout << "\t������������ҵĽ�㣺";
	cin >> a;
	rec.locateElem(a, equal,i1);
	if (rec.locateElem(a, equal, i1))
	{
		cout << "\t���������" << a << "�ĵ�һ���������Ϊ��" << i1;
		cout << endl << endl;
	}

	cout << "���Ҵ���ĳ�����Ĳ�����" << endl;
	cout << "\t������������ҵĽ�㣺";
	cin >> b;
	rec.locateElem(b, great,i2);
	if (rec.locateElem(b, great, i2))
	{
		cout << "\t���������" << b << "�ĵ�һ���������Ϊ��" << i2;
		cout << endl << endl;
	}

	cout << "����С��ĳ��Ԫ�صĲ�����" << endl;
	cout << "\t������������ҵ�Ԫ�أ�";
	cin >> c;
	rec.locateElem(c, small,i3);
	if (rec.locateElem(c, small, i3))
	{
		cout << "\t������С��" << c << "�ĵ�һ���������Ϊ��" << i3;
		cout << endl << endl;
	}

	cout << "************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_6(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*******����ĳԪ�ص�ǰ����������**********" << endl << endl;
	
	ElemType e,prior_e;
	cout << "����������Ҫ���ҽ���������";
	cin >> e;
	rec.priorElem(e, prior_e);
	cout << "�������"<<e<<"ǰ����������Ϊ"<<prior_e<<endl;

	cout << "************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_7(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*******����ĳԪ�صĺ�̵�������*********" << endl << endl;

	ElemType e, next_e;
	cout << "����������Ҫ���ҽ���������";
	cin >> e;
	rec.nextElem(e, next_e);
	cout << "�������" << e << "��̵�������Ϊ" << next_e << endl;


	cout << "***********************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_8(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "**********ɾ����ѭ����������������Ϊe�ĵ�һ�����**********" << endl << endl;

	ElemType e;
	cout << "����������ɾ������������";
	cin >> e;
	if (rec.deleteElem(e))
	{
		cout << "ɾ����ķ�ѭ��������Ϊ" << endl;
		cout << rec;
	}
	else 
		cout << "��Ԫ�ز�����" << endl;

	cout << "****************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_9(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********ɾ����ѭ�����������ظ���ֵ***********" << endl << endl;

	rec.deleteRepeat();
	cout << rec;

	cout << "****************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_10(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "************��ѭ�������������*************" << endl << endl;

	rec.adverse();
	cout << rec;

	cout << "***************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_11(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "******��һ����ѭ��������ֵ����һ����ѭ��������******" << endl << endl;

	MyLinkList<ElemType> list2;
	cout << "��ǰ��ѭ���������ʼ����һ����ѭ��������" << endl;
	list2 = rec;
	cout << list2;

	cout << "*********************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_12(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*************�ѷ�ѭ���������ÿ�****************" << endl << endl;

	rec.clear();
	cout << rec;

	cout << "******************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_13(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "**************������ɷ�ѭ��������**************" << endl << endl;

	rec.RandomLink();

	cout << "*******************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_14(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "********�����еķ�ѭ���������ʼ����һ����ѭ��������*********" << endl << endl;

	MyLinkList<ElemType> list2(rec);
	cout << "��ǰ��˳����ʼ����һ��˳���Ϊ��" << endl;
	cout << list2;

	cout << "*************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_15(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "***********�����ѭ��������*************************" << endl << endl;

	cin >> rec;

	cout << "***********************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_16(MyLinkList<ElemType> & list1, char & continueYesNo)
{
	cout << "*********************����ʽ�����㣨��ѭ���������Ӧ�ã�*************************" << endl << endl;

	MyPolynomialLinkList<MyTerm> list2;
	int select;
	char continueSelect = 'n';
	while (1)
	{
		select = 0;
		system("cls");
		cout << endl;
		cout << "*********************����ʽ�����㣨��ѭ���������Ӧ�ã�*************************" << endl << endl;

		cout << "\t 16.1.�ж϶���ʽ�Ƿ�Ϊ��" << endl;
		cout << "\t 16.2.��һ������ʽ��ֵ����һ������ʽ" << endl;
		cout << "\t 16.3.��������ʽ�ļӷ�" << endl;
		cout << "\t 16.4.��������ʽ�ļ���" << endl;
		cout << "\t 16.5.���ö���ʽΪ�ն���ʽ" << endl;
		cout << "\t 16.6.������ɶ���ʽ" << endl;
		cout << "\t 16.7.�����еĶ���ʽ��ʼ����һ������ʽ" << endl;
		cout << "\t 16.8.�������ʽ" << endl;

		cout << "����.����" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		cout << list2;
		cout << endl;
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "��ѡ����Ҫ�����Ĵ��루1-8�����룺";
		cin >> select;

		if (select > 0 && select < 9)
		{
			system("cls");
			cout << list2;
			cout << endl;
		}

		switch (select)
		{
		case 1:ex3_2_16_1(list2, continueSelect);
			break;
		case 2:ex3_2_16_2(list2, continueSelect);
			break;
		case 3:ex3_2_16_3(list2, continueSelect);
			break;
		case 4:ex3_2_16_4(list2, continueSelect);
			break;
		case 5:ex3_2_16_5(list2, continueSelect);
			break;
		case 6:ex3_2_16_6(list2, continueSelect);
			break;
		case 7:ex3_2_16_7(list2, continueSelect);
			break;
		case 8:ex3_2_16_8(list2, continueSelect);
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

void ex3_2_16_1(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************�ж϶���ʽ�Ƿ�Ϊ��*************************" << endl << endl;

	if (rec.isEmpty())
		cout << "��ǰ����ʽΪ��" << endl;
	else
		cout << "��ǰ����ʽ��Ϊ��" << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

void ex3_2_16_2(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************��һ������ʽ��ֵ����һ������ʽ*************************" << endl << endl;

	MyPolynomialLinkList<MyTerm> list2;
	list2.randomInitialFill();
	rec = list2;
	cout << "��һ������ʽ��ֵ����ǰ����ʽΪ��" << endl;
	cout << rec;


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

void ex3_2_16_3(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************��������ʽ�ļӷ�*************************" << endl << endl;

	MyPolynomialLinkList<MyTerm> list2;
	list2.randomInitialFill();
	cout << "��һ������ʽΪ��" << endl;
	cout << list2;

	cout <<endl<< "������������ʽ��ӣ���Ϊ��" << endl;
	cout << (rec + list2);
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

void ex3_2_16_4(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************��������ʽ�ļ���*************************" << endl << endl;

	MyPolynomialLinkList<MyTerm> list2;
	list2.randomInitialFill();
	cout << "��һ������ʽΪ��" << endl;
	cout << list2;

	cout << endl << "������������ʽ�������Ϊ��" << endl;
	cout << (rec - list2);
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

void ex3_2_16_5(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************���ö���ʽΪ�ն���ʽ*************************" << endl << endl;

	rec.clear();
	cout << "��ǰ����ʽ���ÿգ�" << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

void ex3_2_16_6(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************������ɶ���ʽ*************************" << endl << endl;

	rec.randomInitialFill();
	cout << endl << "������ɶ���ʽ�����÷�ѭ��������洢��Ϊ��" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

void ex3_2_16_7(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************�����еĶ���ʽ��ʼ����һ������ʽ*************************" << endl << endl;

	MyPolynomialLinkList<MyTerm> list2(rec);
	cout << "�õ�ǰ����ʽ��ʼ����һ������ʽΪ��" << endl;
	cout << list2;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

void ex3_2_16_8(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************�������ʽ*************************" << endl << endl;

	cin >> rec;
	cout <<endl<< "��ǰ����ʽ�����÷�ѭ��������洢��Ϊ��" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}