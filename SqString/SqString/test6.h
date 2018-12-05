
void displayCurrentObject(SqString &str1)
{
	cout << endl;
	cout << str1;
}


void ex6_1_1(SqString & str1, char & continueYesNo)
{
	cout << "*********************求顺序串的长度*************************" << endl << endl;

	int n=str1.getLength();
	cout << "当前顺序串的长度为："<<n << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_2(SqString & str1, char & continueYesNo)
{
	cout << "*********************判断顺序串是否为空*************************" << endl << endl;

	if (str1.isEmpty())
	{
		cout << "当前顺序串为空！" << endl;
	}
	else
	{
		cout << "当前顺序串不为空！" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_3(SqString & str1, char & continueYesNo)
{
	cout << "*********************取顺序串的子串*************************" << endl << endl;

	int a, b;
	cout << "请输入子串开始的字符序号：";
	cin >> a;
	cout << "请输入子串的长度：";
	cin >> b;
	SqString str2;
	if (str1.subString(str2, a, b))
	{
		cout << "当前串从第" << a << "个字符开始长度为" << b << "的子串为" << str2 << endl;
	}
	else
	{
		cout << "无法取到该子串" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_4(SqString & str1, char & continueYesNo)
{
	cout << "*********************在第i个字符前插入另一个顺序串*************************" << endl << endl;

	SqString str2;
	cout << "另一个顺序串为：";
	cin >> str2;
	int a;
	cout << "请输入插入另一个顺序串的位置：";
	cin >> a;
	
	if (str1.insert(a, str2))
	{
		cout << "在第" << a << "个字符前插入" << str2 << "后，当前顺序串为：" << str1 << endl;
	}
	else
	{
		cout << "插入位置越界！" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_5(SqString & str1, char & continueYesNo)
{
	cout << "*********************删除从第i个字符起长度为len的子串*************************" << endl << endl;

	int a, b;
	cout << "请输入删除子串的起始位置：";
	cin >> a;
	cout << "请输入删除子串的长度：";
	cin >> b;
	
	if (str1.strDelete(a,b))
	{
		cout << "从第" << a << "个字符开始删除长度为" << b << "的子串为：" << str1 << endl;
	}
	else
	{
		cout << "输入值超出范围，无法删除！" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_6(SqString & str1, char & continueYesNo)
{
	
	cout << "*********************判断是否相等  SqString顺序串==C++String顺序串*************************" << endl << endl;

	char str2[100];
	cout << "请输入一个C++String顺序串：";
	cin >> str2;

	int l = (str1 == str2);
	if (l == 0)
	{
		cout << "当前的SqString顺序串" << str1 << "等于C++顺序串" << str2<<endl;
	}
	else
	{
		cout << "当前的SqString顺序串" << str1 << "不等于C++顺序串" << str2<<endl;
	}


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_7(SqString & str1, char & continueYesNo)
{
	cout << "*********************判断是否相等  SqString顺序串==SqString顺序串*************************" << endl << endl;

	SqString str2;
	cout << "请输入一个SqString顺序串：";
	cin >> str2;
	int l = (str1 == str2);
	if (l == 0)
	{
		cout << "当前的SqString顺序串" << str1 << "等于SqString顺序串" << str2 << endl;
	}
	else
	{
		cout << "当前的SqString顺序串" << str1 << "不等于SqString顺序串" << str2 << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_8(SqString & str1, char & continueYesNo)
{
	cout << "*********************加法运算 SqString顺序串 + C++String顺序串*************************" << endl << endl;

	char str2[100];
	cout << "请输入一个C++String顺序串：";
	cin >> str2;

	cout << "C++String顺序串" << str2 << "可以连接成" << (str1 + str2) << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_9(SqString & str1, char & continueYesNo)
{
	
	cout << "*********************加法运算 SqString顺序串 + SqString顺序串************************" << endl << endl;

	SqString str2;
	cout << "请输入一个SqString顺序串：";
	cin >> str2;
	cout << "SqString顺序串" << str2 << "可以连接成" << (str1 + str2) << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_10(SqString & str1, char & continueYesNo)
{
	cout << "*********************串的朴素匹配（有回溯查找）*************************" << endl << endl;
	cout << "***********返回模式串在主串中第pos个字符起第一次出现的位置******************" << endl;

	cout << "当前主串："<<str1<<endl;
	SqString str2;
	cout << "请输入一个模式串：";
	cin >> str2;
	int i;
	cout << "请输入开始查找的字符的序号（从1开始）：";
	cin >> i;

	int first_i;
	first_i = str1.index(str2, i);
	cout << "\n模式串" << str2 << "在主串" << str1 << "从第" << i << "个字符起" << endl;
	cout << "第一次出现的位置为：" << first_i << endl;
	
	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_11(SqString & str1, char & continueYesNo)
{
	cout << "*********************求模式串的next数组*************************" << endl << endl;

	SqString str2;
	cout << "请输入一个模式串：";
	cin >> str2;
	//cout << "" << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_12(SqString & str1, char & continueYesNo)
{
	cout << "*********************模式匹配（无回溯KMP方法查找）*************************" << endl << endl;

	

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_13(SqString & str1, char & continueYesNo)
{
	cout << "*********************赋值运算  SqString顺序串=C++String顺序串*************************" << endl << endl;

	char str2[100];
	cout << "输入C++String顺序串为：";
	cin >> str2;
	str1 = str2;
	cout <<"当前顺序串被赋值为："<< str1<<endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_14(SqString & str1, char & continueYesNo)
{
	cout << "*********************赋值运算  SqString顺序串=SqString顺序串*************************" << endl << endl;
	
	SqString str2;
	cout << "输入SqString顺序串为：";
	cin >> str2;
	str1 = str2;
	cout << "当前顺序串被赋值为：" << str1 << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_15(SqString & str1, char & continueYesNo)
{
	cout << "**********************把顺序串置空************************" << endl << endl;

	int length = str1.getLength();
	cout << "当前顺序串的长度为：" << length << endl;
	str1.clear();
	int len = str1.getLength();
	cout << "把当前顺序串置空后的长度为：" << len << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}



void ex6_1_16(SqString & str1, char & continueYesNo)
{
	cout << "**********************随机生成顺序串************************" << endl << endl;

	str1.RandomStr();
	cout << str1;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_17(SqString & str1, char & continueYesNo)
{
	cout << "**********************用C++String顺序串初始化一个顺序串（利用拷贝初始化构造函数）************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}



void ex6_1_18(SqString & str1, char & continueYesNo)
{
	cout << "**********************用另一个SqString顺序串初始化************************" << endl << endl;

	SqString str2;
	cout << "请输入一个C++String顺序串：";
	cin >> str2;
	SqString str3(str2);
	cout << "通过拷贝初始化构造函数，\n用上面的C++String顺序串初始化的SqString顺序串为：" << str3<<endl;

	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}


void ex6_1_19(SqString & str1, char & continueYesNo)
{
	cout << "**********************输入顺序串************************" << endl << endl;

	cin >> str1;

	cout << str1;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}



void ex6_1_20(SqString & str1, char & continueYesNo)
{
	cout << "**********************简单的文本编辑器（顺序串的应用）************************" << endl << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "还继续吗（Y.继续\tN.结束）？";
	cin >> continueYesNo;
}