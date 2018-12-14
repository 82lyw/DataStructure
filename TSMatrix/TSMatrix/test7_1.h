template <typename ElemType>
void displayCurrentObject(MyTSMatrix<ElemType> &T1)
{
	cout << endl;
	//cout << T1;
}

template <typename ElemType>
void ex7_1_1(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************求稀疏矩阵的转置矩阵*************************" << endl << endl;

	//T1.transposeMatrix(s);
	//

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_2(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************快速求稀疏矩阵的转置矩阵*************************" << endl << endl;

	//T1.fastTransposeMatrix();
	//cout<<T1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_3(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************计算稀疏矩阵各行第一个非零元素在三元组表中的下标*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_4(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************稀疏矩阵的赋值运算*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_5(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************求稀疏矩阵的加法*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_6(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************求稀疏矩阵的乘法*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_7(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************显示稀疏矩阵的三元组表示*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_8(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************随机生成稀疏矩阵*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_9(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************用已有的稀疏矩阵初始化一个新矩阵*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex7_1_10(MyTSMatrix<ElemType> & T1, char & continueYesNo)
{
	cout << "*********************输入稀疏矩阵的三元组表*************************" << endl << endl;

	cin >> T1;
	T1.displayTriple();

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}