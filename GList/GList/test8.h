void displayCurrentObject(GList & GL1)
{
	cout << endl;
	//cout << GL1;
}

void ex8_1(GList & GL1, char & continueYesNo)
{
	cout << "*********************求广义表的深度*************************" << endl << endl;

	int n = GL1.depth();
	cout << "广义表的深度为：" << n << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

void ex8_2(GList & GL1, char & continueYesNo)
{
	cout << "*********************广义表的赋值运算*************************" << endl << endl;

	cout << "把当前的广义表赋值给另一个广义表：" << endl;
	GList GL2;
	GL2 = GL1;
	//cout<<GL2;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

void ex8_3(GList & GL1, char & continueYesNo)
{
	cout << "*********************求广义表的长度*************************" << endl << endl;

	int n;
	n = GL1.length();
	cout << "广义表的长度为：" << n << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

void ex8_4(GList & GL1, char & continueYesNo)
{
	cout << "*********************判断广义表是否为空*************************" << endl << endl;

	if (GL1.isEmpty())
	{
		cout << "当前广义表为空" << endl;
	}
	else
	{
		cout << "当前广义表不为空" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

void ex8_5(GList & GL1, char & continueYesNo)
{
	cout << "*********************取广义表的表头*************************" << endl << endl;

	GList headGL;
	GL1.getHead(headGL);
	cout << "广义表的表头为：" << endl;
	//cout<<headGL;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

void ex8_6(GList & GL1, char & continueYesNo)
{
	cout << "*********************取广义表的表尾*************************" << endl << endl;

	GList tailGL;
	GL1.getHead(tailGL);
	cout << "广义表的表尾为：" << endl;
	//cout<<tailGL;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

void ex8_7(GList & GL1, char & continueYesNo)
{
	cout << "*********************删除广义表的表头*************************" << endl << endl;

	GList secondGL;
	GL1.deleteHead(secondGL);
	cout << "删除广义表的表头" << endl;
	//cout<<secondGL;
	cout << endl;
	cout << "后，当前的广义表为：" << endl;
	//cout<<GL1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

void ex8_8(GList & GL1, char & continueYesNo)
{
	cout << "*********************插入一个广义表作为广义表的表头*************************" << endl << endl;

	GList GL2;
	cout << "请输入待插入的广义表：" << endl;
	//cin >> GL2;
	//cout << GL2;
	cout << endl;
	GL1.insertHead(GL2);
	cout << "作为广义表的表头后，当前广义表为：" << endl;
	//cout << GL1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

void ex8_9(GList & GL1, char & continueYesNo)
{
	cout << "*********************用已有的广义表初始化一个新广义表*************************" << endl << endl;

	GList GL2(GL1);
	cout << "当前广义表初始化另一个广义表为：" << endl;
	//cout<<GL2;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}

void ex8_10(GList & GL1, char & continueYesNo)
{
	cout << "*********************以字符串形式输入广义表*************************" << endl << endl;

	cin>>GL1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}