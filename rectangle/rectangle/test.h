template <typename ElemType>
void displayCurrentObject(MyRectangle<ElemType> rec)
{
	cout << endl;
	cout << rec;
}

template <typename ElemType>
void ex2_1_1(MyRectangle<ElemType> & rec, char & continueYesNo)
{
	int no;
	cout << "*********************���ó����ε����*************************" << endl << endl;

	cout << "�����뵱ǰ�����ζ������ţ�";
	cin >> no;
	rec.setNo(no);
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex2_1_2(MyRectangle<ElemType> & rec, char & continueYesNo)
{
	ElemType aL;
	cout << "*********************���ó����εĳ�*************************" << endl << endl;
	cout << "�����뵱ǰ�����ζ���ĳ���";
	cin >> aL;
	rec.setLength(aL);
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex2_1_3(MyRectangle<ElemType> & rec, char & continueYesNo)
{
	MyRectangle<float> recOther;
	cout << "*********************�����ζ���ĸ�ֵ*************************" << endl << endl;
	cout << "�ѵ�ǰ�����ζ���ֵ����һ�������ζ���";
	recOther = rec;
	cout << "\n ��ֵ����һ�������ζ���Ϊ��" << endl;
	cout << recOther;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}
