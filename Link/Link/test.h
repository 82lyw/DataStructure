template <typename ElemType>
void displayCurrentObject(MySqList<ElemType> rec)
{
	cout << endl;
	cout << rec;
}

template <typename ElemType>
void ex3_1_1(MySqList<ElemType> & rec, char & continueYesNo)
{
	int i;
	ElemType e;
	cout << "*********************在第i个元素之前插入一个元素*************************" << endl << endl;

	cout << "请输入你要在第几个元素之前插入元素：";
	cin >> i;
	cout << "请输入你要插入的元素：";
	cin >> e;
	rec.insert(i, e);
	//cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_2(MySqList<ElemType> & rec, char & continueYesNo)
{
	int b;
	cout << "*********************判断顺序表是否为空*************************" << endl << endl;

	cout << "当前顺序表：";

	b = rec.isEmpty();
	cout << (b ? "为空" : "不为空") << endl;;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_3(MySqList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************求顺序表中元素的个数*************************" << endl << endl;

	cout << "顺序表元素的个数为：";
	cout << rec.getLength()<<endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_4(MySqList<ElemType> & rec, char & continueYesNo)
{
	int i;
	ElemType e;
	cout << "*********************取第i个元素*************************" << endl << endl;

	cout << "请输入你想取得元素序号（1-10）：";
	cin >> i;
	rec.getElem(i, e);
	if (rec.getElem(i, e))
	{
		cout << "你想要取的第" << i << "元素的值为："<<e<<endl;
	}
	else
	{
		cout << "找不到该元素" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_5(MySqList<ElemType> & rec, char & continueYesNo)
{
	int i1, i2, i3;
	ElemType a, b, c;
	cout << "*********************查找第i个与e满足compare()关系的序号*************************" << endl << endl;

	cout << "查找等于某个元素的操作："<<endl;
	cout << "\t请输入你想查找的元素：";
	cin >> a;
	i1 = rec.locateElem(a, equal);
	cout << "\t你想要查找的第一个等于"<<a<<"的元素序号为："<<i1;
	cout << endl<<endl;
	
	cout << "查找大于某个元素的操作："<<endl;
	cout << "\t请输入你想查找的元素：";
	cin >> b;
	i2 = rec.locateElem(b, great);
	cout << "\t你想要查找的第一个大于" << b << "的元素序号为：" << i2;
	cout << endl<<endl;

	cout << "查找小于某个元素的操作："<<endl;
	cout << "\t请输入你想查找的元素：";
	cin >> c;
	i3 = rec.locateElem(c, small);
	cout << "\t你想要查找的第一个小于" << c << "的元素序号为：" << i3;
	cout << endl<<endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_6(MySqList<ElemType> & rec, char & continueYesNo)
{
	ElemType e, prior_e;
	cout << "*********************返回某元素的前驱*************************" << endl << endl;

	cout << "请输入你想查找其前驱的元素：";
	cin >> e;
	if (rec.priorElem(e, prior_e))
	{
		cout << "你想要查找的元素" << e << "的前驱为" << prior_e << endl;
	}
	else
	{
		cout << "找不到该元素的前驱"<<endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_7(MySqList<ElemType> & rec, char & continueYesNo)
{
	ElemType e, next_e;
	cout << "*********************返回某元素的后继*************************" << endl << endl;

	cout << "请输入你想查找其后继的元素：";
	cin >> e;
	if (rec.nextElem(e, next_e) == OK)
	{
		cout << "你想要查找的元素" << e << "的前驱为" << next_e;
	}
	else
	{
		cout << "找不到该元素的后继";
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_8(MySqList<ElemType> & rec, char & continueYesNo)
{
	int i;
	ElemType e;
	cout << "*********************删除第i个元素*************************" << endl << endl;

	cout << "请输入你想删除元素的序号（1-"<<rec.getLength()<<"）：";
	cin >> i;
	if (rec.deleteElem(i, e) == OK)
	{
		cout << "你想删除的第" << i << "个元素的值为：" << e << endl;
		cout << "删除后的顺序表为：" << endl;
		cout << rec;
	}
	else
		cout << "找不到待删除元素";

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_9(MySqList<ElemType> & rec, char & continueYesNo)
{
	// int i;
	// i = rec.getLength();
	MySqList<ElemType> list2;
	list2.RandomBorn();
	cout << list2;
	cout << "*********************把一个顺序表赋值给另一个顺序表*************************" << endl << endl;

	cout << "另一个顺序表赋值给当前顺序表：" << endl;
	rec = list2;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_10(MySqList<ElemType> & rec, char & continueYesNo)
{
	/*int i;
	i = rec.getLength();
	cout << "当前顺序表有" << i << "个元素，分别为：" << endl;
	cout << rec;*/
	cout << "*********************把当前的顺序表置空*************************" << endl << endl;

	rec.clear();
	int i;
	i = rec.getLength();
	cout << "当前顺序表置空后，元素的个数为" <<i<< endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_11(MySqList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************随机生成顺序表（元素值为0到99之间的整数）*************************" << endl << endl;

	rec.RandomBorn();
	cout << "随机生成的顺序表为：" << endl;
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_12(MySqList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************用已有的顺序表初始化另一个顺序表*************************" << endl << endl;
	
	MySqList<ElemType> list2(rec);
	cout << "当前的顺序表初始化另一个顺序表为：" << endl;
	cout << list2;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_13(MySqList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************输入顺序表*************************" << endl << endl;

	rec.inputList();
	cout << rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_14(MySqList<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************两个顺序表的交并差运算*************************" << endl << endl;
	cout << rec;
	MySqList<int> list2;
	list2.RandomBorn();
	cout << list2;
	cout << endl << endl;
	cout << "以上两顺序表的"<<endl;

	cout << "\t并集为：" << endl;
	cout << unionSet(rec, list2);
	cout << endl;

	cout << "\t交集为：" << endl;
	cout << intersectionSet(rec, list2);
	cout << endl;

	cout << "\t差集为：" << endl;
	cout << dirfferenceSet(rec, list2);
	cout << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

template <typename ElemType>
void ex3_1_15(MyStudent<ElemType> & rec, char & continueYesNo)
{
	cout << "*********************学生信息管理*************************" << endl << endl;

	int select;
	char continueSelect = 'n';
	while (1)
	{
		select = 0;
		system("cls");
		cout << "*********************学生信息管理*************************" << endl << endl;
		cout << endl;

		cout << "\t 1.在第i个学生之前插入一个学生" << endl;
		cout << "\t 2.判断学生表是否为空：" << endl;
		cout << "\t 3.求学生表中学生的人数：" << endl;
		cout << "\t 4.返回学生表中第i个学生：" << endl;
		cout << "\t 5.返回某姓名学生的前驱：" << endl;
		cout << "\t 6.返回某姓名学生的后继：" << endl;
		cout << "\t 7.删除学生表的第i个学生：" << endl;
		cout << "\t 8.把一个学生表赋值给另一个学生表：" << endl;
		cout << "\t 9.设置学生表为空表：" << endl;
		cout << "\t 10.随机生成学生表：" << endl;
		cout << "\t 11.用已有的学生表初始化另一个学生表：" << endl;
		cout << "\t 12.输入学生表：" << endl;

		cout << "其他.结束" << endl << endl;

		cout << "///////////////////////////////////////////////////////////////////////////////" << endl;
		//displayCurrentObject(list_1);
		cout << "///////////////////////////////////////////////////////////////////////////////" << endl << endl;

		cout << "请选择你要操作的代码（1-12）号码：";

		cin >> select;

		if (select > 0 && select < 9)
		{
			system("cls");
			//displayPolynomial(list1);
		}

		switch (select)
		{
			/*case 1:ex3_1_15_1(rec, continueSelect);
			break;
		case 2:ex3_1_15_2(rec, continueSelect);
			break;
		case 3:ex3_1_15_3(rec, continueSelect);
			break;
		case 4:ex3_1_15_4(rec, continueSelect);
			break;
		case 5:ex3_1_15_5(rec, continueSelect);
			break;
		case 6:ex3_1_15_6(rec, continueSelect);
			break;
		;*/
		case 6:ex3_1_15_12(rec, continueSelect);
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

template <typename ElemType>
void ex3_1_15_12(MyStudent<ElemType> & rec, char & continueYesNo)
{
	cout << "**********************输入学生表************************" << endl << endl;

	cin >> rec;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}