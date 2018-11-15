template <typename ElemType>
void displayCurrentObject(MyCircularLinkList<ElemType> rec)
{
	cout << endl;
	cout << rec;
}

template <typename ElemType>
void ex3_3_1(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************判断循环单链表是否为空*************************" << endl << endl;

	if (rec.isEmpty())
	{
		cout << "该循环单链表为空" << endl;
	}
	else 
	{
		cout << "该循环单链表不为空" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_2(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************把循环单链表的头指针后移至第i个结点*************************" << endl << endl;

	int i;
	ElemType e;
	cout << "请输入头指针后移到的结点的序号：";
	cin >> i;
	rec.moveHead(i);
	rec.getHeadElem(e);
	cout << "移动后，头指针所指结点的数据域为：" << e << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_3(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************删除第i个结点，头指针移至其下一个结点*************************" << endl << endl;

	int i;
	ElemType e;
	cout << "请输入欲删除的结点序号：";
	cin >> i;
	rec.deleteElem(i, e);
	cout << endl << "删除第4个结点" << e << "后，循环单链表为：";
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_4(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************把一个循环单链表赋值给另一个循环单链表*************************" << endl << endl;

	MyCircularLinkList<ElemType> list2;
	cin >> list2;
	rec = list2;
	cout << "另一个循环单链表赋值赋值给当前循环单链表：" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_5(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************循环单链表置空*************************" << endl << endl;

	rec.clear();
	if (rec.isEmpty())
	{
		cout << "当前循环单链表已置空！" << endl;
	}
	else
	{
		cout << "置空失败！！" << endl;
	}
	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_6(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************随机生成循环单链表*************************" << endl << endl;

	rec.Randborn();
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_7(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************用已有的循环单链表初始化另一个循环单链表*************************" << endl << endl;

	MyCircularLinkList<ElemType> list2(rec);
	cout << "当前循环单链表初始化另一个循环单链表为：" << endl;
	cout << list2;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_8(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************输入循环单链表*************************" << endl << endl;

	cin >> rec;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_3_9(MyCircularLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************约瑟夫（Josephus）环出列（循环单链表的应用）*************************" << endl << endl;

	cout << "当前的约瑟夫环为：" << endl;


	cout << "请输入起始的结点号：";
	//cin>>
	cout << "\t间隔间隔结点数：";
	//cin>>

	int i;
	int n = 10;
	for (i = 0; i < n; i++)
	{
		cout << "第" << i << "次出列的结点为1，出列后的约瑟夫环为："<<endl;
		//cout << ;
	}



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

