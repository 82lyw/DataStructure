void displayCurrentObject(GList & GL1)
{
	cout << endl;
	//cout << GL1;
}

void ex8_1(GList & GL1, char & continueYesNo)
{
	cout << "*********************����������*************************" << endl << endl;

	int n = GL1.depth();
	cout << "���������Ϊ��" << n << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

void ex8_2(GList & GL1, char & continueYesNo)
{
	cout << "*********************�����ĸ�ֵ����*************************" << endl << endl;

	cout << "�ѵ�ǰ�Ĺ����ֵ����һ�������" << endl;
	GList GL2;
	GL2 = GL1;
	//cout<<GL2;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

void ex8_3(GList & GL1, char & continueYesNo)
{
	cout << "*********************������ĳ���*************************" << endl << endl;

	int n;
	n = GL1.length();
	cout << "�����ĳ���Ϊ��" << n << endl;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

void ex8_4(GList & GL1, char & continueYesNo)
{
	cout << "*********************�жϹ�����Ƿ�Ϊ��*************************" << endl << endl;

	if (GL1.isEmpty())
	{
		cout << "��ǰ�����Ϊ��" << endl;
	}
	else
	{
		cout << "��ǰ�����Ϊ��" << endl;
	}

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

void ex8_5(GList & GL1, char & continueYesNo)
{
	cout << "*********************ȡ�����ı�ͷ*************************" << endl << endl;

	GList headGL;
	GL1.getHead(headGL);
	cout << "�����ı�ͷΪ��" << endl;
	//cout<<headGL;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

void ex8_6(GList & GL1, char & continueYesNo)
{
	cout << "*********************ȡ�����ı�β*************************" << endl << endl;

	GList tailGL;
	GL1.getHead(tailGL);
	cout << "�����ı�βΪ��" << endl;
	//cout<<tailGL;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

void ex8_7(GList & GL1, char & continueYesNo)
{
	cout << "*********************ɾ�������ı�ͷ*************************" << endl << endl;

	GList secondGL;
	GL1.deleteHead(secondGL);
	cout << "ɾ�������ı�ͷ" << endl;
	//cout<<secondGL;
	cout << endl;
	cout << "�󣬵�ǰ�Ĺ����Ϊ��" << endl;
	//cout<<GL1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

void ex8_8(GList & GL1, char & continueYesNo)
{
	cout << "*********************����һ���������Ϊ�����ı�ͷ*************************" << endl << endl;

	GList GL2;
	cout << "�����������Ĺ����" << endl;
	//cin >> GL2;
	//cout << GL2;
	cout << endl;
	GL1.insertHead(GL2);
	cout << "��Ϊ�����ı�ͷ�󣬵�ǰ�����Ϊ��" << endl;
	//cout << GL1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

void ex8_9(GList & GL1, char & continueYesNo)
{
	cout << "*********************�����еĹ�����ʼ��һ���¹����*************************" << endl << endl;

	GList GL2(GL1);
	cout << "��ǰ������ʼ����һ�������Ϊ��" << endl;
	//cout<<GL2;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}

void ex8_10(GList & GL1, char & continueYesNo)
{
	cout << "*********************���ַ�����ʽ��������*************************" << endl << endl;

	cin>>GL1;

	cout << "***********************************************************" << endl << endl;
	cout << "��������Y.����\tN.��������";
	cin >> continueYesNo;
}