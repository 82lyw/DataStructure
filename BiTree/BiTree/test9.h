template <typename ElemType>
void displayCurrentObject(MyBiTree<ElemType> &BT1)
{
	cout << endl;
	cout << BT1;
}

template <typename ElemType>
void ex9_2_1(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************求二叉树的结点数*************************" << endl << endl;

	cout << "当前二叉树的结点数为：" << BT1.countNode() << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_2(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************求二叉树的叶子数*************************" << endl << endl;

	cout << "当前二叉树的叶子数为：" << BT1.countLeaf() << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_3(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************递归求二叉树深度*************************" << endl << endl;

	cout << "当前二叉树的深度为：" << BT1.depth() << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_4(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************交换二叉树中所有结点的左右子树*************************" << endl << endl;

	cout << " 交换当前二叉树中所有结点的左右子树：" << endl;
	BT1.exchangeLRchild();
	cout << BT1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_5(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************前序递归遍历二叉树*************************" << endl << endl;

	cout << " 当前二叉树按前序递归遍历的结点序列为：";
	BT1.preOrderTraverse();
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_6(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************中序递归遍历二叉树*************************" << endl << endl;

	cout << " 当前二叉树按中序递归遍历的结点序列为：";
	BT1.inOrderTraverse();
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_7(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************后序递归遍历二叉树*************************" << endl << endl;

	cout << " 当前二叉树按后序递归遍历的结点序列为：";
	BT1.postOrderTraverse();
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_8(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************非递归中序遍历二叉树*************************" << endl << endl;

	cout << " 非递归中序遍历当前二叉树中的结点为：";
	BT1.noRecursionInOrderTraverse();
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_9(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************按层次顺序遍历二叉树*************************" << endl << endl;

	cout << " 按层次顺序遍历前二叉树中的结点为：";
	BT1.layOrderTraverse();
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_10(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************以顺序存储的方式显示二叉树*************************" << endl << endl;

	BT1.displaySeqTree();
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_11(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************二叉树的二叉链表存储转换为顺序存储结构*************************" << endl << endl;

	cout << " 当前二叉树已转换为如下的顺序存储结构：" << endl;
	BT1.displaySeqTree();
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_12(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************二叉树的顺序存储转换为二叉链表存储结构*************************" << endl << endl;

	cout << " 输入一棵顺序存储的二叉树：" << endl << endl;
	cin >> BT1;  
	cout << endl;
	BT1.displaySeqTree();
	cout << endl;
	cout << " 上面二叉树的顺序存储转换为二叉链表存储结构如下：" << endl;
	cout << BT1;
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_13(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************随机生成二叉树*************************" << endl << endl;

	BT1.randomCreate();
	cout << "随机生成的二叉树为：" << endl;
	cout << BT1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_14(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************输入二叉树*************************" << endl << endl;

	cin >> BT1;
	BT1.displaySeqTree();
	cout << BT1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

/*
template <typename ElemType>
void ex9_2_15(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************中序遍历中序穿线二叉树*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_16(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************中序穿线二叉树顺序存储转换为二叉链表存储*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_17(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************中序穿线二叉树中找指定结点中序的前驱与后继*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_18(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************随机生成中序穿线二叉树*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_19(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************输入中序穿线二叉树*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex9_2_20(MyBiTree<ElemType>& BT1, char& continueYesNo)
{
	cout << "*********************哈夫曼树（二叉树的应用）*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}
*/