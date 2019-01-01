template <typename ElemType>
void displayCurrentObject(MySqListSort<ElemType> &S1,MyStatic<node> &S2)
{
	cout << endl;
	cout << S1;cout << endl<<endl;
	cout << S2;cout << endl;
}

template <typename ElemType>
void ex11_1(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************ֱ�Ӳ�������*************************" << endl << endl;

	S1.insertSort();
	cout << "��������"<<endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_2(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************�۰��������*************************" << endl << endl;

	S1.binaryInsertSort();
	cout << "��������" << endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_3(MyStatic<ElemType> & S2, char & continueYesNo)
{
	cout << "*********************��̬�����������*************************" << endl << endl;

	S2.staticListSort();
	cout << "��������"<<endl;
	cout << S2; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_4(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************ϣ������*************************" << endl << endl;

	S1.ShellSort();
	cout << "��������"<<endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_5(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************ð������*************************" << endl << endl;

	S1.bubbleSort();
	cout << "��������" << endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_6(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************��������*************************" << endl << endl;

	S1.quickSort();
	cout << "��������" << endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_7(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************ֱ��ѡ������*************************" << endl << endl;

	S1.selectSort();
	cout << "��������" << endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_8(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************������*************************" << endl << endl;

	S1.heapSort();
	cout << "��������" << endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_9(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************�鲢����*************************" << endl << endl;

	S1.mergeSort();
	cout << "��������" << endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_10(MyStatic<ElemType> & S2, char & continueYesNo)
{
	cout << "*********************�������򣨲��þ�̬����洢��*************************" << endl << endl;

	S2.radixSort();
	cout << "��������" << endl;
	cout << S2; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_11(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************�������˳���*************************" << endl << endl;

	S1.randS();
	cout << S1;
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_12(MyStatic<ElemType> & S2, char & continueYesNo)
{
	cout << "*********************������ɾ�̬����*************************" << endl << endl;

	S2.randN();
	cout << S2;
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_13(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************����˳���*************************" << endl << endl;

	cin >> S1;
	cout << S1;
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_14(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************ѧ����Ϣ��������Ӧ�ã�*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}