template <typename ElemType>
void displayCurrentObject(MyCrossListMatrix<ElemType> &T1)
{
	cout << endl;
	cout << T1;
}

template <typename ElemType>
void ex7_2_1(MyCrossListMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************ϡ�����ĸ�ֵ����*************************" << endl << endl;

	MyCrossListMatrix<ElemType> T2;
	T2 = T1;
	cout << T2;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_2_2(MyCrossListMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************��ϡ�����ļӷ�*************************" << endl << endl;

	/*
	MyCrossListMatrix<ElemType> T2;
	T2.randCreate();
	cout << T2;
	cout << "���������Ϊ:" << endl;
	T1 = (T1 + T2);
	cout << T1;*/

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_2_3(MyCrossListMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "********************�������ϡ�����*************************" << endl << endl;

	T1.randCreate();
	cout<<T1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_2_4(MyCrossListMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************�����е�ϡ������ʼ��һ���¾���*************************" << endl << endl;

	MyCrossListMatrix<ElemType> T2(T1);
	cout << T2;


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


