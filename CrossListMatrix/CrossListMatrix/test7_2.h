template <typename ElemType>
void displayCurrentObject(CrossListMatrix<ElemType> &T1)
{
	cout << endl;
	cout << T1;
}

template <typename ElemType>
void ex7_2_1(CrossListMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************稀疏矩阵的赋值运算*************************" << endl << endl;

	CrossListMatrix<ElemType> T2;
	T2 = T1;
	cout << T2;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_2_2(CrossListMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************求稀疏矩阵的加法*************************" << endl << endl;

	CrossListMatrix<ElemType> T2;
	cout << T2;
	cout << T2;
	cout << "两矩阵相加为:" << endl;
	T1 = T1 + T2;
	cout << T1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_2_3(CrossListMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "********************输入稀疏矩阵*************************" << endl << endl;

	cin >> T1;
	cout << T1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_2_4(CrossListMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************用已有的稀疏矩阵初始化一个新矩阵*************************" << endl << endl;

	CrossListMatrix<ElemType> T2(T1);
	cout << T2;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


