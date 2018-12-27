template <typename ElemType>
void displayCurrentObject(MyBiTree<ElemType> &BT1)
{
	cout << endl;
	cout << BT1;
}

template <typename ElemType>
void ex9_2_1(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************��������Ľ����*************************" << endl << endl;

	cout << "��ǰ�������Ľ����Ϊ��" << BT1.countNode() << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_2(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************���������Ҷ����*************************" << endl << endl;

	cout << "��ǰ��������Ҷ����Ϊ��" << BT1.countLeaf() << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_3(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************�ݹ�����������*************************" << endl << endl;

	cout << "��ǰ�����������Ϊ��" << BT1.depth() << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_4(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************���������������н�����������*************************" << endl << endl;

	cout << " ������ǰ�����������н�������������" << endl;
	BT1.exchangeLRchild();
	cout << BT1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_5(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************ǰ��ݹ����������*************************" << endl << endl;

	cout << " ��ǰ��������ǰ��ݹ�����Ľ������Ϊ��";
	BT1.preOrderTraverse();
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_6(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************����ݹ����������*************************" << endl << endl;

	cout << " ��ǰ������������ݹ�����Ľ������Ϊ��";
	BT1.inOrderTraverse();
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_7(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************����ݹ����������*************************" << endl << endl;

	cout << " ��ǰ������������ݹ�����Ľ������Ϊ��";
	BT1.postOrderTraverse();
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_8(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************�ǵݹ��������������*************************" << endl << endl;

	cout << " �ǵݹ����������ǰ�������еĽ��Ϊ��";
	BT1.noRecursionInOrderTraverse();
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_9(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************�����˳�����������*************************" << endl << endl;

	cout << " �����˳�����ǰ�������еĽ��Ϊ��";
	BT1.layOrderTraverse();
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_10(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************��˳��洢�ķ�ʽ��ʾ������*************************" << endl << endl;

	BT1.displaySeqTree();
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_11(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************�������Ķ�������洢ת��Ϊ˳��洢�ṹ*************************" << endl << endl;

	cout << " ��ǰ��������ת��Ϊ���µ�˳��洢�ṹ��" << endl;
	BT1.displaySeqTree();
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_12(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************��������˳��洢ת��Ϊ��������洢�ṹ*************************" << endl << endl;

	cout << " ����һ��˳��洢�Ķ�������" << endl << endl;
	cin >> BT1;  
	cout << endl;
	BT1.displaySeqTree();
	cout << endl;
	cout << " �����������˳��洢ת��Ϊ��������洢�ṹ���£�" << endl;
	cout << BT1;
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_13(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************������ɶ�����*************************" << endl << endl;

	BT1.randomCreate();
	cout << "������ɵĶ�����Ϊ��" << endl;
	cout << BT1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_14(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************���������*************************" << endl << endl;

	cin >> BT1;
	BT1.displaySeqTree();
	cout << BT1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

/*
template <typename ElemType>
void ex9_2_15(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************������������߶�����*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_16(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************�����߶�����˳��洢ת��Ϊ��������洢*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_17(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************�����߶���������ָ����������ǰ������*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_18(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************������������߶�����*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_19(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************���������߶�����*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_20(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************������������������Ӧ�ã�*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}
*/