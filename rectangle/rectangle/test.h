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
	cout << "*********************设置长方形的序号*************************" << endl << endl;

	cout << "请输入当前长方形对象的序号：";
	cin >> no;
	rec.setNo(no);
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex2_1_2(MyRectangle<ElemType> & rec, char & continueYesNo)
{
	ElemType aL;
	cout << "*********************设置长方形的长*************************" << endl << endl;
	cout << "请输入当前长方形对象的长：";
	cin >> aL;
	rec.setLength(aL);
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex2_1_3(MyRectangle<ElemType> & rec, char & continueYesNo)
{
	MyRectangle<float> recOther;
	cout << "*********************长方形对象的赋值*************************" << endl << endl;
	cout << "把当前长方形对象赋值给另一个长方形对象：";
	recOther = rec;
	cout << "\n 赋值后，另一个长方形对象为：" << endl;
	cout << recOther;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}
