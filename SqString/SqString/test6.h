
void displayCurrentObject(SqString &str1)
{
	cout << endl;
	cout << str1;
}


void ex6_1_1(SqString & str1, char & continueYesNo)
{
	cout << "*********************��˳�򴮵ĳ���*************************" << endl << endl;

	int n=str1.getLength();
	cout << "��ǰ˳�򴮵ĳ���Ϊ��"<<n << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_2(SqString & str1, char & continueYesNo)
{
	cout << "*********************�ж�˳���Ƿ�Ϊ��*************************" << endl << endl;

	if (str1.isEmpty())
	{
		cout << "��ǰ˳��Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��ǰ˳�򴮲�Ϊ�գ�" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_3(SqString & str1, char & continueYesNo)
{
	cout << "*********************ȡ˳�򴮵��Ӵ�*************************" << endl << endl;

	int a, b;
	cout << "�������Ӵ���ʼ���ַ���ţ�";
	cin >> a;
	cout << "�������Ӵ��ĳ��ȣ�";
	cin >> b;
	SqString str2;
	if (str1.subString(str2, a, b))
	{
		cout << "��ǰ���ӵ�" << a << "���ַ���ʼ����Ϊ" << b << "���Ӵ�Ϊ" << str2 << endl;
	}
	else
	{
		cout << "�޷�ȡ�����Ӵ�" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_4(SqString & str1, char & continueYesNo)
{
	cout << "*********************�ڵ�i���ַ�ǰ������һ��˳��*************************" << endl << endl;

	SqString str2;
	cout << "��һ��˳��Ϊ��";
	cin >> str2;
	int a;
	cout << "�����������һ��˳�򴮵�λ�ã�";
	cin >> a;
	
	if (str1.insert(a, str2))
	{
		cout << "�ڵ�" << a << "���ַ�ǰ����" << str2 << "�󣬵�ǰ˳��Ϊ��" << str1 << endl;
	}
	else
	{
		cout << "����λ��Խ�磡" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_5(SqString & str1, char & continueYesNo)
{
	cout << "*********************ɾ���ӵ�i���ַ��𳤶�Ϊlen���Ӵ�*************************" << endl << endl;

	int a, b;
	cout << "������ɾ���Ӵ�����ʼλ�ã�";
	cin >> a;
	cout << "������ɾ���Ӵ��ĳ��ȣ�";
	cin >> b;
	
	if (str1.strDelete(a,b))
	{
		cout << "�ӵ�" << a << "���ַ���ʼɾ������Ϊ" << b << "���Ӵ�Ϊ��" << str1 << endl;
	}
	else
	{
		cout << "����ֵ������Χ���޷�ɾ����" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_6(SqString & str1, char & continueYesNo)
{
	
	cout << "*********************�ж��Ƿ����  SqString˳��==C++String˳��*************************" << endl << endl;

	char str2[100];
	cout << "������һ��C++String˳�򴮣�";
	cin >> str2;

	int l = (str1 == str2);
	if (l == 0)
	{
		cout << "��ǰ��SqString˳��" << str1 << "����C++˳��" << str2<<endl;
	}
	else
	{
		cout << "��ǰ��SqString˳��" << str1 << "������C++˳��" << str2<<endl;
	}


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_7(SqString & str1, char & continueYesNo)
{
	cout << "*********************�ж��Ƿ����  SqString˳��==SqString˳��*************************" << endl << endl;

	SqString str2;
	cout << "������һ��SqString˳�򴮣�";
	cin >> str2;
	int l = (str1 == str2);
	if (l == 0)
	{
		cout << "��ǰ��SqString˳��" << str1 << "����SqString˳��" << str2 << endl;
	}
	else
	{
		cout << "��ǰ��SqString˳��" << str1 << "������SqString˳��" << str2 << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_8(SqString & str1, char & continueYesNo)
{
	cout << "*********************�ӷ����� SqString˳�� + C++String˳��*************************" << endl << endl;

	char str2[100];
	cout << "������һ��C++String˳�򴮣�";
	cin >> str2;

	cout << "C++String˳��" << str2 << "�������ӳ�" << (str1 + str2) << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_9(SqString & str1, char & continueYesNo)
{
	
	cout << "*********************�ӷ����� SqString˳�� + SqString˳��************************" << endl << endl;

	SqString str2;
	cout << "������һ��SqString˳�򴮣�";
	cin >> str2;
	cout << "SqString˳��" << str2 << "�������ӳ�" << (str1 + str2) << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_10(SqString & str1, char & continueYesNo)
{
	cout << "*********************��������ƥ�䣨�л��ݲ��ң�*************************" << endl << endl;
	cout << "***********����ģʽ���������е�pos���ַ����һ�γ��ֵ�λ��******************" << endl;

	cout << "��ǰ������"<<str1<<endl;
	SqString str2;
	cout << "������һ��ģʽ����";
	cin >> str2;
	int i;
	cout << "�����뿪ʼ���ҵ��ַ�����ţ���1��ʼ����";
	cin >> i;

	int first_i;
	first_i = str1.index(str2, i);
	cout << "\nģʽ��" << str2 << "������" << str1 << "�ӵ�" << i << "���ַ���" << endl;
	cout << "��һ�γ��ֵ�λ��Ϊ��" << first_i << endl;
	
	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_11(SqString & str1, char & continueYesNo)
{
	cout << "*********************��ģʽ����next����*************************" << endl << endl;

	SqString str2;
	cout << "������һ��ģʽ����";
	cin >> str2;
	//cout << "" << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_12(SqString & str1, char & continueYesNo)
{
	cout << "*********************ģʽƥ�䣨�޻���KMP�������ң�*************************" << endl << endl;

	

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_13(SqString & str1, char & continueYesNo)
{
	cout << "*********************��ֵ����  SqString˳��=C++String˳��*************************" << endl << endl;

	char str2[100];
	cout << "����C++String˳��Ϊ��";
	cin >> str2;
	str1 = str2;
	cout <<"��ǰ˳�򴮱���ֵΪ��"<< str1<<endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_14(SqString & str1, char & continueYesNo)
{
	cout << "*********************��ֵ����  SqString˳��=SqString˳��*************************" << endl << endl;
	
	SqString str2;
	cout << "����SqString˳��Ϊ��";
	cin >> str2;
	str1 = str2;
	cout << "��ǰ˳�򴮱���ֵΪ��" << str1 << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_15(SqString & str1, char & continueYesNo)
{
	cout << "**********************��˳���ÿ�************************" << endl << endl;

	int length = str1.getLength();
	cout << "��ǰ˳�򴮵ĳ���Ϊ��" << length << endl;
	str1.clear();
	int len = str1.getLength();
	cout << "�ѵ�ǰ˳���ÿպ�ĳ���Ϊ��" << len << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}



void ex6_1_16(SqString & str1, char & continueYesNo)
{
	cout << "**********************�������˳��************************" << endl << endl;

	str1.RandomStr();
	cout << str1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_17(SqString & str1, char & continueYesNo)
{
	cout << "**********************��C++String˳�򴮳�ʼ��һ��˳�򴮣����ÿ�����ʼ�����캯����************************" << endl << endl;



	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}



void ex6_1_18(SqString & str1, char & continueYesNo)
{
	cout << "**********************����һ��SqString˳�򴮳�ʼ��************************" << endl << endl;

	SqString str2;
	cout << "������һ��C++String˳�򴮣�";
	cin >> str2;
	SqString str3(str2);
	cout << "ͨ��������ʼ�����캯����\n�������C++String˳�򴮳�ʼ����SqString˳��Ϊ��" << str3<<endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}


void ex6_1_19(SqString & str1, char & continueYesNo)
{
	cout << "**********************����˳��************************" << endl << endl;

	cin >> str1;

	cout << str1;


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}



void ex6_1_20(SqString & str1, char & continueYesNo)
{
	cout << "**********************�򵥵��ı��༭����˳�򴮵�Ӧ�ã�************************" << endl << endl;


	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}