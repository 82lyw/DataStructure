template <typename ElemType>
void displayCurrentObject(CrossListMatrix<ElemType> &T1)
{
	cout << endl;
	cout << T1;
}

template <typename ElemType>
void ex7_2_1(CrossListMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************ϡ�����ĸ�ֵ����*************************" << endl << endl;

	CrossListMatrix<ElemType> T2;
	T2 = T1;
	cout << T2;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_2_2(CrossListMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************��ϡ�����ļӷ�*************************" << endl << endl;

	CrossListMatrix<ElemType> T2;
	cout << T2;
	cout << T2;
	cout << "���������Ϊ:" << endl;
	T1 = T1 + T2;
	cout << T1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_2_3(CrossListMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "********************����ϡ�����*************************" << endl << endl;

	cin >> T1;
	cout << T1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_2_4(CrossListMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************�����е�ϡ������ʼ��һ���¾���*************************" << endl << endl;

	CrossListMatrix<ElemType> T2(T1);
	cout << T2;


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


