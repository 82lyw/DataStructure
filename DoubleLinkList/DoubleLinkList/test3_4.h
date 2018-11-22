template <typename ElemType>
void displayCurrentObject(MyDoubleLinkList<ElemType> rec)
{
	cout << endl;
	cout << rec;
}

template <typename ElemType>
void ex3_4_1(MyDoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************取循环双链表第i个结点的数据域*************************" << endl << endl;
	int i;
	ElemType e;
	cout << "请输入你要取的结点的序号：";
	cin >> i;
	rec.getElem(i, e);
	if (rec.getElem(i, e))
	{
		cout << "你要取循环双链表的第" << i << "个结点的数据域为：" << e << endl;
	}
	else
	{
		if (i <= 0)
			cout << "i应为大于0的整数！" << endl;
		if (i > rec.getLength())
			cout << "i已越界，无法取到该结点的数据域！" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_2(MyDoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************在第i个结点之前插入一个数据域为e的结点*************************" << endl << endl;
	int i;
	ElemType e;
	cout << "请输入你要在它之前插入结点的序号";
	cin >> i;
	cout << "请输入你要插入结点的数据域：";
	cin >> e;
	cout << endl;

	if (rec.insert(i, e))
	{
		cout << "你已经在第" << i << "个结点之前插入数据域为" << e << "的结点" << endl;
		cout << rec;
	}
	else
	{
		if (rec.isEmpty())
			cout << "循环双链表为空！" << endl;
		else
			cout << "待插的范围越界！" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_3(MyDoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************判断循环双链表是否为空*************************" << endl << endl;

	if (rec.isEmpty())
		cout << "当前循环双链表为空！" << endl;
	else
		cout << "当前循环双链表不为空！" << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_4(MyDoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************求循环双链表中结点的个数*************************" << endl << endl;

	rec.getLength();
	cout << "循环双链表中结点的个数为" << rec.getLength() << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_5(MyDoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************返回循环双链表中数据域为e的第一个结点的指针*************************" << endl << endl;

	ElemType e;
	typename DoubleLinkList<ElemType>::NodePointer r;

	cout << "\t请输入你想查找的结点的数据域：";
	cin >> e;
	rec.locateElem(e,r);
	if (rec.locateElem(e, r))
	{
		cout << "你想查找第一个数据域等于" << e << "的结点的数据域为" << r->data;
		cout << endl << endl;
	}
	else
	{
		cout << "找不到该数据域的结点指针" << endl << endl;
	}


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_6(MyDoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************返回某结点的前驱的数据域*************************" << endl << endl;

	ElemType e, prior_e;
	cout << "请输入你想要查找结点的数据域：";
	cin >> e;
	if (rec.priorElem(e, prior_e))
	{
		cout << "你想查找" << e << "前驱的数据域为" << prior_e << endl;
	}
	else
	{
			cout<<"该节点不存在！"
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_7(MyDoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************返回某结点的后继的数据域*************************" << endl << endl;

	ElemType e, next_e;
	cout << "请输入你想要查找结点的数据域：";
	cin >> e;
	if (rec.nextElem(e, next_e))
	{
		cout << "你想查找" << e << "后继的数据域为" << next_e << endl;
	}
	else
	{
		cout << "找不到该元素！";
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_8(MyDoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************删除循环双链表中数据域为e的第一个结点*************************" << endl << endl;

	ElemType e;
	cout << "请输入你想删除结点的数据域：";
	cin >> e;
	if (rec.deleteElem(e))
	{
		cout << "删除后的循环双链表为：" << endl;
		cout << rec;
	}
	else
	{
		cout << "该元素不存在！" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_9(MyDoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************把一个循环双链表赋值给另一个循环双链表*************************" << endl << endl;

	DoubleLinkList<ElemType> list2;
	cout << "另一个循环双链表赋值给当前循环双链表为：" << endl;
	list2.Randomborn();
	rec = list2;
	cout<<rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_10(MyDoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************把循环双链表置空*************************" << endl << endl;

	rec.clear();
	cout << "当前循环双链表已置空！" << endl << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_11(MyDoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************随机生成循环双链表*************************" << endl << endl;

	rec.Randborn();
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_12(MyDoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************用已有的循环双链表初始化另一个循环双链表*************************" << endl << endl;

	MyDoubleLink<ElemType> list2(rec);
	cout << "当前循环双链表初始化另一个循环双链表：" << endl;
	cout << list2;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_4_13(MyDoubleLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************输入循环双链表*************************" << endl << endl;

	cin >> rec;
	cout << "新输入的循环双链表如下：" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}
