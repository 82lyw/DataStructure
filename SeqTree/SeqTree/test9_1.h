template <typename ElemType>
void displayCurrentObject(MySeqTree<ElemType>& ST)
{
	cout << endl;
	cout << ST;
}



template <typename ElemType>
void ex9_1_1(MySeqTree<ElemType>& ST1, char& continueYesNo)
{
	cout << "*********************���������*************************" << endl << endl;

	cin >> ST1;
	ST1.sequentialdisplay();
	cout << ST1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_1_2(MySeqTree<ElemType>& ST1, char& continueYesNo)
{
	cout << "*********************�������*************************" << endl << endl;

	ST1.randCreate();
	cout << "������ɵĶ�����Ϊ��" << endl;
	cout << ST1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}