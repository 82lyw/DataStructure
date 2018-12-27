template <typename ElemType>
void displayCurrentObject(MySeqTree<ElemType>& ST)
{
	cout << endl;
	cout << ST;
}



template <typename ElemType>
void ex9_1_1(MySeqTree<ElemType>& ST1, char& continueYesNo)
{
	cout << "*********************输入二叉树*************************" << endl << endl;

	cin >> ST1;
	ST1.sequentialdisplay();
	cout << ST1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_1_2(MySeqTree<ElemType>& ST1, char& continueYesNo)
{
	cout << "*********************随机生成*************************" << endl << endl;

	ST1.randCreate();
	cout << "随机生成的二叉树为：" << endl;
	cout << ST1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}