template <typename ElemType>
void displayCurrentObject(MyLinkList<ElemType> rec)
{
	cout << endl;
	cout << rec;
}

template <typename ElemType>
void ex3_2_1(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "**************取非循环单链表的第i个结点*****************" << endl << endl;
	int i;
	ElemType e;
	cout << "请输入你要取的结点的序号：";
	cin >> i;
	rec.getElem(i,e);
	if (rec.getElem(i, e)) 
	{
		cout << "你要取非循环单链表的第" << i << "个结点的数据域为" << e << endl;
	}
	else
	{
		if (i <= 0)
			cout << "i应为大于0的整数" << endl;
		if (i > rec.getLength())
			cout << "i已越界，无法取到该结点的数据域" << endl;
	}

	cout << "**********************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_2(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "***********在第i个结点之前插入一个数据域为e的结点************" << endl << endl;
	int i;
	ElemType e;
	cout << "请输入你要在它之前插入结点的序号";
	cin >> i;
	cout << "请输入你要插入结点的数据域：";
	cin >> e;
	cout << endl;
	if (rec.insert(i,e))
	{
		cout << "你已经在第" << i << "个结点之前插入数据域为" << e << "的结点" << endl;
		cout << rec;
	}
	else
	{
		if (rec.isEmpty())
			cout << "非循环单链表为空" << endl;
		else
			cout << "待插的范围越界" << endl;
	}
	cout << "*************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_3(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "************判断非循环单链表是否为空*****************" << endl << endl;

	if (rec.isEmpty())
		cout << "当前非循环单链表为空" << endl;
	else
		cout << "当前非循环单链表不为空" << endl;

	cout << "**********************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_4(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "**********求非循环单链表中结点的个数**************" << endl << endl;

	rec.getLength();
	cout << "非循环单链表中结点的个数为" << rec.getLength() << endl;

	cout << "********************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_5(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*****查找第i个与某元素满足compare（）关系元素的序号*****" << endl << endl;

	int i1, i2, i3;
	ElemType a, b, c;

	cout << "查找等于某个结点的操作：" << endl;
	cout << "\t请输入你想查找的结点：";
	cin >> a;
	rec.locateElem(a, equal,i1);
	if (rec.locateElem(a, equal, i1))
	{
		cout << "\t数据域等于" << a << "的第一个结点的序号为：" << i1;
		cout << endl << endl;
	}

	cout << "查找大于某个结点的操作：" << endl;
	cout << "\t请输入你想查找的结点：";
	cin >> b;
	rec.locateElem(b, great,i2);
	if (rec.locateElem(b, great, i2))
	{
		cout << "\t数据域大于" << b << "的第一个结点的序号为：" << i2;
		cout << endl << endl;
	}

	cout << "查找小于某个元素的操作：" << endl;
	cout << "\t请输入你想查找的元素：";
	cin >> c;
	rec.locateElem(c, small,i3);
	if (rec.locateElem(c, small, i3))
	{
		cout << "\t数据域小于" << c << "的第一个结点的序号为：" << i3;
		cout << endl << endl;
	}

	cout << "************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_6(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*******返回某元素的前驱的数据域**********" << endl << endl;
	
	ElemType e,prior_e;
	cout << "请输入你想要查找结点的数据域：";
	cin >> e;
	rec.priorElem(e, prior_e);
	cout << "你想查找"<<e<<"前驱的数据域为"<<prior_e<<endl;

	cout << "************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_7(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*******返回某元素的后继的数据域*********" << endl << endl;

	ElemType e, next_e;
	cout << "请输入你想要查找结点的数据域：";
	cin >> e;
	rec.nextElem(e, next_e);
	cout << "你想查找" << e << "后继的数据域为" << next_e << endl;


	cout << "***********************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_8(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "**********删除非循环单链表中数据域为e的第一个结点**********" << endl << endl;

	ElemType e;
	cout << "请输入你想删除结点的数据域：";
	cin >> e;
	if (rec.deleteElem(e))
	{
		cout << "删除后的非循环单链表为" << endl;
		cout << rec;
	}
	else 
		cout << "该元素不存在" << endl;

	cout << "****************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_9(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********删除非循环单链表中重复的值***********" << endl << endl;

	rec.deleteRepeat();
	cout << rec;

	cout << "****************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_10(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "************非循环单链表的逆置*************" << endl << endl;

	rec.adverse();
	cout << rec;

	cout << "***************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_11(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "******把一个非循环单链表赋值给另一个非循环单链表******" << endl << endl;

	MyLinkList<ElemType> list2;
	cout << "当前非循环单链表初始化另一个非循环单链表" << endl;
	list2 = rec;
	cout << list2;

	cout << "*********************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_12(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "*************把非循环单链表置空****************" << endl << endl;

	rec.clear();
	cout << rec;

	cout << "******************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_13(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "**************随机生成非循环单链表**************" << endl << endl;

	rec.RandomLink();

	cout << "*******************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_14(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "********用已有的非循环单链表初始化另一个非循环单链表*********" << endl << endl;

	MyLinkList<ElemType> list2(rec);
	cout << "当前的顺序表初始化另一个顺序表为：" << endl;
	cout << list2;

	cout << "*************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_15(MyLinkList<ElemType> & rec, char & continueYesNo)
{
	cout << "***********输入非循环单链表*************************" << endl << endl;

	cin >> rec;

	cout << "***********************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_2_16(MyLinkList<ElemType> & list1, char & continueYesNo)
{
	cout << "*********************多项式的运算（非循环单链表的应用）*************************" << endl << endl;

	MyPolynomialLinkList<MyTerm> list2;
	int select;
	char continueSelect = 'n';
	while (1)
	{
		select = 0;
		system("cls");
		cout << endl;
		cout << "*********************多项式的运算（非循环单链表的应用）*************************" << endl << endl;

		cout << "\t 16.1.判断多项式是否为空" << endl;
		cout << "\t 16.2.把一个多项式赋值给另一个多项式" << endl;
		cout << "\t 16.3.两个多项式的加法" << endl;
		cout << "\t 16.4.两个多项式的减法" << endl;
		cout << "\t 16.5.设置多项式为空多项式" << endl;
		cout << "\t 16.6.随机生成多项式" << endl;
		cout << "\t 16.7.用已有的多项式初始化另一个多项式" << endl;
		cout << "\t 16.8.输入多项式" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		cout << list2;
		cout << endl;
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-8）号码：";
		cin >> select;

		if (select > 0 && select < 9)
		{
			system("cls");
			cout << list2;
			cout << endl;
		}

		switch (select)
		{
		case 1:ex3_2_16_1(list2, continueSelect);
			break;
		case 2:ex3_2_16_2(list2, continueSelect);
			break;
		case 3:ex3_2_16_3(list2, continueSelect);
			break;
		case 4:ex3_2_16_4(list2, continueSelect);
			break;
		case 5:ex3_2_16_5(list2, continueSelect);
			break;
		case 6:ex3_2_16_6(list2, continueSelect);
			break;
		case 7:ex3_2_16_7(list2, continueSelect);
			break;
		case 8:ex3_2_16_8(list2, continueSelect);
			break;
		default:cout << "\n 你选择了结束。" << endl << endl;
			return;
		}
		if (continueSelect == 'n' || continueSelect == 'n')
			break;
	}
	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

void ex3_2_16_1(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************判断多项式是否为空*************************" << endl << endl;

	if (rec.isEmpty())
		cout << "当前多项式为空" << endl;
	else
		cout << "当前多项式不为空" << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

void ex3_2_16_2(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************把一个多项式赋值给另一个多项式*************************" << endl << endl;

	MyPolynomialLinkList<MyTerm> list2;
	list2.randomInitialFill();
	rec = list2;
	cout << "另一个多项式赋值给当前多项式为：" << endl;
	cout << rec;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

void ex3_2_16_3(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************两个多项式的加法*************************" << endl << endl;

	MyPolynomialLinkList<MyTerm> list2;
	list2.randomInitialFill();
	cout << "另一个多项式为：" << endl;
	cout << list2;

	cout <<endl<< "以上两个多项式相加，和为：" << endl;
	cout << (rec + list2);
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

void ex3_2_16_4(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************两个多项式的减法*************************" << endl << endl;

	MyPolynomialLinkList<MyTerm> list2;
	list2.randomInitialFill();
	cout << "另一个多项式为：" << endl;
	cout << list2;

	cout << endl << "以上两个多项式相减，差为：" << endl;
	cout << (rec - list2);
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

void ex3_2_16_5(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************设置多项式为空多项式*************************" << endl << endl;

	rec.clear();
	cout << "当前多项式已置空！" << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

void ex3_2_16_6(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************随机生成多项式*************************" << endl << endl;

	rec.randomInitialFill();
	cout << endl << "随机生成多项式（采用非循环单链表存储）为：" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

void ex3_2_16_7(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************用已有的多项式初始化另一个多项式*************************" << endl << endl;

	MyPolynomialLinkList<MyTerm> list2(rec);
	cout << "用当前多项式初始化另一个多项式为：" << endl;
	cout << list2;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}

void ex3_2_16_8(MyPolynomialLinkList<MyTerm> & rec, char & continueSelect)
{
	cout << "*********************输入多项式*************************" << endl << endl;

	cin >> rec;
	cout <<endl<< "当前多项式（采用非循环单链表存储）为：" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueSelect;
}