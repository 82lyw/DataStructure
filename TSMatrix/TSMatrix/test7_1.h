template <typename ElemType>
void displayCurrentObject(MyTSMatrix<ElemType> &T1)
{
	cout << endl;
	//cout << T1;
}

template <typename ElemType>
void ex7_1_1(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************��ϡ������ת�þ���*************************" << endl << endl;

	//T1.transposeMatrix(s);
	//

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_2(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************������ϡ������ת�þ���*************************" << endl << endl;

	//T1.fastTransposeMatrix();
	//cout<<T1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_3(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************����ϡ�������е�һ������Ԫ������Ԫ����е��±�*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_4(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************ϡ�����ĸ�ֵ����*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_5(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************��ϡ�����ļӷ�*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_6(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************��ϡ�����ĳ˷�*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_7(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************��ʾϡ��������Ԫ���ʾ*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_8(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************�������ϡ�����*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_9(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************�����е�ϡ������ʼ��һ���¾���*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_10(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************����ϡ��������Ԫ���*************************" << endl << endl;

	cin >> T1;
	T1.displayTriple();

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}