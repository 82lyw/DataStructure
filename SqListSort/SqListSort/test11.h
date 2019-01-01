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
	cout << "*********************直接插入排序*************************" << endl << endl;

	S1.insertSort();
	cout << "排序结果："<<endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_2(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************折半插入排序*************************" << endl << endl;

	S1.binaryInsertSort();
	cout << "排序结果：" << endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_3(MyStatic<ElemType> & S2, char & continueYesNo)
{
	cout << "*********************静态链表插入排序*************************" << endl << endl;

	S2.staticListSort();
	cout << "排序结果："<<endl;
	cout << S2; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_4(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************希尔排序*************************" << endl << endl;

	S1.ShellSort();
	cout << "排序结果："<<endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_5(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************冒泡排序*************************" << endl << endl;

	S1.bubbleSort();
	cout << "排序结果：" << endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_6(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************快速排序*************************" << endl << endl;

	S1.quickSort();
	cout << "排序结果：" << endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_7(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************直接选择排序*************************" << endl << endl;

	S1.selectSort();
	cout << "排序结果：" << endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_8(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************堆排序*************************" << endl << endl;

	S1.heapSort();
	cout << "排序结果：" << endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_9(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************归并排序*************************" << endl << endl;

	S1.mergeSort();
	cout << "排序结果：" << endl;
	cout << S1; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_10(MyStatic<ElemType> & S2, char & continueYesNo)
{
	cout << "*********************基数排序（采用静态链表存储）*************************" << endl << endl;

	S2.radixSort();
	cout << "排序结果：" << endl;
	cout << S2; cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_11(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************随机生成顺序表*************************" << endl << endl;

	S1.randS();
	cout << S1;
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_12(MyStatic<ElemType> & S2, char & continueYesNo)
{
	cout << "*********************随机生成静态链表*************************" << endl << endl;

	S2.randN();
	cout << S2;
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_13(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************输入顺序表*************************" << endl << endl;

	cin >> S1;
	cout << S1;
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex11_14(MySqListSort<ElemType> & S1, char & continueYesNo)
{
	cout << "*********************学生信息排序（排序应用）*************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}