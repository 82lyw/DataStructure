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
		cout << "\t 2.�ж�ѧ�����Ƿ�Ϊ��" << endl;
		cout << "\t 3.��ѧ������ѧ��������" << endl;
		cout << "\t 4.����ѧ�����е�i��ѧ��" << endl;
		cout << "\t 5.����ĳ����ѧ����ǰ��" << endl;
		cout << "\t 6.����ĳ����ѧ���ĺ��" << endl;
		cout << "\t 7.ɾ��ѧ����ĵ�i��ѧ��" << endl;
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

		if (select > 0 && select < 12)
		{
			system("cls");
			rec.displayS();
		}

		switch (select)
		{
			case 1:ex3_1_15_1(rec, continueSelect);
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
		case 7:ex3_1_15_7(rec, continueSelect);
			break;
		case 8:ex3_1_15_8(rec, continueSelect);
			break;
		case 9:ex3_1_15_9(rec, continueSelect);
			break;
		case 10:ex3_1_15_10(rec, continueSelect);
			break;
		case 11:ex3_1_15_11(rec, continueSelect);
			break;
		case 12:ex3_1_15_12(rec, continueSelect);
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
void ex3_1_15_1(MyStudent<ElemType> & rec, char & continueSelect)
{
	cout << "**********************�ڵ�i��ѧ��֮ǰ����һ��ѧ��************************" << endl << endl;

	int i;
	cout << "��������Ҫ�ڵڼ���ѧ��֮ǰ������ѧ����";
	cin >> i;

	typename MyStudent<ElemType>::studentNode s;
	cout << "\tѧ�ţ�";
	cin >> s.student_id;
	cout << "\t������";
	cin >> s.name;
	cout << "\t���ģ�";
	cin >> s.Chinese;
	cout << "\tӢ�";
	cin >> s.English;
	cout << "\t��ѧ��";
	cin >> s.Math;

	s.Total = s.Chinese + s.Math + s.English;
	s.average = s.Total / 3;

	cout << "��Ҫ�ڵ�" << i << "��ѧ��ǰ������ѧ��" << endl;
	cout << "ѧ��\t" << "����\t" << "����\t" << "Ӣ��\t" << "��ѧ\t" << "ƽ����\t" << "�ܷ�" << endl;
	cout << s.student_id << "\t" << s.name << "\t" << 
		s.Chinese << "\t" << s.English << "\t" << s.Math 
		<< "\t" << s.average << "\t" << s.Total << endl<<endl;

	if (rec.insertS(i, s))
	{
		cout << "������ѧ��������" << endl ;
		rec.displayS();
	}
	else
	{
		cout << "�������С�����ˣ���Խ��";
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex3_1_15_2(MyStudent<ElemType> & rec, char & continueSelect)
{
	cout << "**********************�ж�ѧ�����Ƿ�Ϊ��************************" << endl << endl;

	if (rec.isEmpty())
	{
		cout << "��ǰѧ����Ϊ�գ�"<<endl;
	}
	else
	{
		cout << "��ǰѧ����Ϊ�գ�"<<endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex3_1_15_3(MyStudent<ElemType> & rec, char & continueSelect)
{
	cout << "**********************��ѧ������ѧ��������************************" << endl << endl;

	int n;
	n = rec.getLength();
	cout << "��ǰѧ������ѧ��������Ϊ:" << n << endl<<endl;
	

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex3_1_15_4(MyStudent<ElemType> & rec, char & continueSelect)
{
	cout << "**********************����ѧ�����е�i��ѧ��************************" << endl << endl;

	int i;
	typename MyStudent<ElemType>::studentNode s;
	cout << "����������Ҫ��ѧ������ţ�1-" << rec.getLength() << "����" ;
	cin >> i;

	rec.getStu(i, s);
	if (rec.getStu(i, s))
	{
		cout << "����Ҫ�ĵ�" << i << "��ѧ������ϢΪ��" << endl;
		cout << "ѧ��\t" << "����\t" << "����\t" << "Ӣ��\t" << "��ѧ\t" << "ƽ����\t" << "�ܷ�" << endl;
		cout << s.student_id << "\t" << s.name << "\t" <<
			s.Chinese << "\t" << s.English << "\t" << s.Math
			<< "\t" << s.average << "\t" << s.Total << endl;
	}
	else
	{
		cout << "�����Խ��";
	}


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex3_1_15_5(MyStudent<ElemType> & rec, char & continueSelect)
{
	cout << "**********************����ĳ����ѧ����ǰ��************************" << endl << endl;

	string stu_name;
	typename MyStudent<ElemType>::studentNode prior_s;
	typename MyStudent<ElemType>::studentNode s;

	cout << "����������Ҫ������ǰ��ѧ����������";
	cin >> stu_name;

	cout << "����Ҫ��������Ϊ" << stu_name << "��ѧ��ǰ��Ϊ��" << endl << endl;

	rec.priorStu(stu_name, prior_s);
	if (rec.priorStu(stu_name, prior_s))
	{
		cout << "ѧ��\t" << "����\t" << "����\t" << "Ӣ��\t" << "��ѧ\t" << "ƽ����\t" << "�ܷ�" << endl;
		cout << prior_s.student_id << "\t" << prior_s.name << "\t" <<
			prior_s.Chinese << "\t" << prior_s.English << "\t" << prior_s.Math
			<< "\t" << prior_s.average << "\t" << prior_s.Total << endl;
	}
	else
	{
		cout<<"��ͬѧ��ǰ�������ڣ�"<<endl << endl;
	}


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex3_1_15_6(MyStudent<ElemType> & rec, char & continueSelect)
{
	cout << "**********************����ĳ����ѧ���ĺ��************************" << endl << endl;

	string stu_name;
	typename MyStudent<ElemType>::studentNode next_s;
	typename MyStudent<ElemType>::studentNode s;

	cout << "����������Ҫ��������ѧ����������";
	cin >> stu_name;

	cout << "����Ҫ��������Ϊ" << stu_name << "��ѧ�����Ϊ��" << endl << endl;

	rec.nextStu(stu_name, next_s);

	if (rec.nextStu(stu_name, next_s))
	{
		cout << "ѧ��\t" << "����\t" << "����\t" << "Ӣ��\t" << "��ѧ\t" << "ƽ����\t" << "�ܷ�" << endl;
		cout << next_s.student_id << "\t" << next_s.name << "\t" <<
			next_s.Chinese << "\t" << next_s.English << "\t" << next_s.Math
			<< "\t" << next_s.average << "\t" << next_s.Total << endl;
	}
	else
	{
		cout << "��ͬѧ�ĺ�̲����ڣ�" << endl << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex3_1_15_7(MyStudent<ElemType> & rec, char & continueSelect)
{
	cout << "**********************ɾ��ѧ����ĵ�i��ѧ��************************" << endl << endl;

	int i;
	typename MyStudent<ElemType>::studentNode s;
	cout << "����������ɾ��ѧ������ţ�1-" << rec.getLength() << "):";
	cin >> i;

	if (rec.deleteStu(i, s))
	{
		cout << "����ɾ���ĵ�" << i << "��ѧ������ϢΪ��" << endl;
		cout << "ѧ��\t" << "����\t" << "����\t" << "Ӣ��\t" << "��ѧ\t" << "ƽ����\t" << "�ܷ�" << endl;
		cout << s.student_id << "\t" << s.name << "\t" <<
			s.Chinese << "\t" << s.English << "\t" << s.Math
			<< "\t" << s.average << "\t" << s.Total << endl << endl;

		cout << "ɾ�����ѧ�������£�" << endl;
		rec.displayS();
	}
	else
	{
		cout << "�����Խ��" << endl << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex3_1_15_8(MyStudent<ElemType> & rec, char & continueSelect)
{
	cout << "**********************��һ��ѧ����ֵ����һ��ѧ����************************" << endl << endl;

	MyStudent<ElemType> stu2;
	stu2.readS();

	cout << "��һ��ѧ����ֵ����ǰѧ����";
	rec = stu2;
	rec.displayS();

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex3_1_15_9(MyStudent<ElemType> & rec, char & continueSelect)
{
	cout << "**********************����ѧ����Ϊ�ձ�************************" << endl << endl;

	rec.clear();
	cout << "��ǰ��ѧ�����ÿպ�ѧ������Ϊ" << rec.getLength() << endl << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex3_1_15_10(MyStudent<ElemType> & rec, char & continueSelect)
{
	cout << "**********************�������ѧ����************************" << endl << endl;

	rec.RandomStudents();
	rec.displayS();

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex3_1_15_11(MyStudent<ElemType> & rec, char & continueSelect)
{
	cout << "**********************�����е�ѧ�����ʼ����һ��ѧ����************************" << endl << endl;

	MyStudent<ElemType> stu2(rec);
	stu2.displayS();

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}

template <typename ElemType>
void ex3_1_15_12(MyStudent<ElemType> & rec, char & continueSelect)
{
	cout << "**********************����ѧ����************************" << endl << endl;

	rec.readS();

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueSelect;
}