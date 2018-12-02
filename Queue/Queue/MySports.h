//MySports.h �˶��ᰲ�����ݽṹ�Ķ���

class MySports
{
public:
	//���ű���
	void arrangeSports();
	
	//��ʾ��Ŀ��ͻ�ľ���
	void displayCollusion()const;

	//�˶��ᰲ�ű������캯��
	MySports(int a = 9, int b = 3, int c = 7, int *d = NULL, int *e = NULL);

	//�����˶�����Ŀ���������
	void read(istream & in);

	//����˶�����Ŀ���������
	void display(ostream & out)const;
private:
	int game_num;
	int max;
	int anthele_num;
	int *collusion;
	int *game_arrange;

};

//���ű���
void MySports::arrangeSports()
{
	int pre = game_num;
	int group = 0;
	int *clash;
	MySqQueue<int> Q;

	if (!collusion)
	{
		cout << "û����Ŀ��ͻ���󣬱����޷����ţ�" << endl;
		return;
	}
	int i;
	for (i = 0; i < game_num; i++)
		Q.enQueue(i);
	clash = new int[game_num];
	assert(clash != 0);

	while (!Q.isEmpty())
	{
		Q.deQueue(i);
		if (i <= pre)
		{
			++group;
			for (int j = 0; j < game_num; j++)
				clash[j] = 0;
		}
		if (clash[i] == 0)
		{
			game_arrange[i] = group;
			for (int j = 0; j < game_num; j++)
				clash[j] += *(collusion + i * game_num + j);
		}
		else
		{
			Q.enQueue(i);
		}
		pre = i;
	}
}

//��ʾ��Ŀ��ͻ����
void MySports::displayCollusion() const
{
	int i, j;
	char no[5] = "[ i]";
	cout << "\t";
	for (i = 0; i < game_num; i++)
	{
		if (i < 9)
			no[2] = i + '0';
		else
		{
			no[1] = i / 10 + '0';
			no[2] = i % 10 + '0';
		}
		/*cout << "     ";
		cout.width(4);
		cout.fill(' ');
		cout.setf(ios::right, ios::adjustfield);
		cout << no;*/
		cout << "\t" << no;
	}
	cout << endl;

	for (i = 0; i < game_num; i++)
	{
		/*cout << "     ";*/
		if (i < 9)
			no[2] = i + '0';
		else
		{
			no[1] = i / 10 + '0';
			no[2] = i % 10 + '0';
		}
		/*cout.width(4);
		cout.fill(' ');
		cout.setf(ios::right, ios::adjustfield);
		cout << no;*/
		cout << "\t" << no;
		for (j = 0; j < game_num; j++)
		{
			//cout << "     " << *(collusion + i * game_num + j) << "     ";
			cout << "\t  " << *(collusion + i * game_num + j) ;
		}
		cout << endl;
	}
}

//�˶��ᰲ�Ź��캯��
MySports::MySports(int a, int b, int c, int *d, int *e)
{
	game_num = a;
	max = b;
	anthele_num = c;
	collusion = new int[game_num*game_num];
	assert(collusion != 0);

	//��ʼ���˶���İ���
	*(collusion + 0) = 0; *(collusion + 1) = 1; *(collusion + 2) = 0;
	*(collusion + 3) = 0; *(collusion + 4) = 0; *(collusion + 5) = 1;
	*(collusion + 6) = 0; *(collusion + 7) = 0; *(collusion + 8) = 0;

	*(collusion + 9) = 1; *(collusion + 10) = 0; *(collusion + 11) = 0;
	*(collusion + 12) = 0; *(collusion + 13) = 1; *(collusion + 14) = 1;
	*(collusion + 15) = 0; *(collusion + 16) = 1; *(collusion + 17) = 1;

	*(collusion + 18) = 0; *(collusion + 19) = 0; *(collusion + 20) = 0;
	*(collusion + 21) = 0; *(collusion + 22) = 0; *(collusion + 23) = 1;
	*(collusion + 24) = 1; *(collusion + 25) = 0; *(collusion + 26) = 0;

	*(collusion + 27) = 0; *(collusion + 28) = 0; *(collusion + 29) = 0;
	*(collusion + 30) = 0; *(collusion + 31) = 1; *(collusion + 32) = 0;
	*(collusion + 33) = 0; *(collusion + 34) = 0; *(collusion + 35) = 1;

	*(collusion + 36) = 0; *(collusion + 37) = 1; *(collusion + 38) = 0;
	*(collusion + 39) = 1; *(collusion + 40) = 0; *(collusion + 41) = 0;
	*(collusion + 42) = 1; *(collusion + 43) = 0; *(collusion + 44) = 1;

	*(collusion + 45) = 1; *(collusion + 46) = 1; *(collusion + 47) = 1;
	*(collusion + 48) = 0; *(collusion + 49) = 0; *(collusion + 50) = 0;
	*(collusion + 51) = 1; *(collusion + 52) = 0; *(collusion + 53) = 0;

	*(collusion + 54) = 0; *(collusion + 55) = 0; *(collusion + 56) = 1;
	*(collusion + 57) = 0; *(collusion + 58) = 1; *(collusion + 59) = 1;
	*(collusion + 60) = 0; *(collusion + 61) = 0; *(collusion + 62) = 0;

	*(collusion + 63) = 0; *(collusion + 64) = 1; *(collusion + 65) = 0;
	*(collusion + 66) = 0; *(collusion + 67) = 0; *(collusion + 68) = 0;
	*(collusion + 69) = 0; *(collusion + 70) = 0; *(collusion + 71) = 0;

	*(collusion + 72) = 0; *(collusion + 73) = 1; *(collusion + 74) = 0;
	*(collusion + 75) = 1; *(collusion + 76) = 1; *(collusion + 77) = 0;
	*(collusion + 78) = 0; *(collusion + 79) = 0; *(collusion + 80) = 0;


	game_arrange = new int[game_num];
	assert(game_arrange != 0);
	for (int i = 0; i < game_num; i++)
	{
		game_arrange[i] = 0;
	}
}

//�����˶�����Ŀ���˶�Ա������Ŀ
void MySports::read(istream & in)
{
	int i, j, k;
	int x;
	int num;
	int temp[10];

	cout << "�������������Ŀ����";
	in >> game_num;
	cout << "������ÿ���˶�Ա�������μӵı�����Ŀ����";
	in >> max;
	cout << "�������˶�Ա��������";
	in >> anthele_num;

	collusion = new int[game_num*game_num];
	assert(collusion != 0);

	//��ʼ����Ŀ��ͻ����Ϊ0
	for (i = 0; i < game_num; i++)
	{
		for (j = 0; j < game_num; j++)
		{
			*(collusion + i * game_num + j) = 0;
		}
	}
	cout << "\n ������ÿ���˶�Ա���������" << endl << endl;
	for (k = 1; k <= anthele_num; k++)
	{
		cout << "�������" << k << "���˶�Ա�������������" << endl;
		while (1)
		{
			cout << "�����" << k << "���˶�Ա������Ŀ��";
			in >> num;
			if (num > 0 && num <= max)
				break;
			else
			{
				cout << "ÿ���˶�Ա�������μӵı�����Ŀ��Ϊ��" << max<<",���������룡";
			}
		}
		j = 0;
		while (j < num)
		{
			cout << "��" << j + 1 << "��������ĿΪ��";
			in >> x;
			if (x > -1 && x < game_num)
			{
				for (i = 0; i < j; i++)
				{
					if (temp[i] == x)
						break;
				}
				if (i == j)
					temp[j++] = x;
				else
					cout << "�ñ�����Ŀ�Ѿ�����" << endl;
			}
			else
			{
				cout << " ������ĿӦ����0��" << game_num - 1;
				cout << "֮�䣬���������룡" << endl;
			}
		}

		for (i = 0; i < num; i++)
		{
			for (j = i + 1; j < num; j++)
			{
				*(collusion + temp[i] * game_num + temp[j]) = 1;
				*(collusion + temp[j] * game_num + temp[i]) = 1;
			}
		}
		cout << endl;
	}
	//��ʾ��Ŀ��ͻ����
	displayCollusion();
}

istream &operator>>(istream& in, MySports & sQ)
{
	sQ.read(in);
	return in;
}

void MySports::display(ostream & out)const
{
	char no[5] = "[ i]";
	if (!game_num)
	{
		out << "û���κ��˶������Ϣ��" << endl;
		return;
	}
	out << "������Ŀ����"<<game_num << endl;
	out << "ÿ���˶�Ա�������μӵı�����Ŀ����" << max << endl;
	if (!anthele_num)
	{
		out << "��û���˶�Ա������" << endl;
		return;
	}
	out << "��Ŀ��ͻ����" << endl;
	displayCollusion();

	if (!game_arrange)
	{
		out << "����������黹û�а��ţ�" << endl;
		return;
	}

	out << "\n ����������鰲�����£�" << endl;
	out << "     ";
	for (int i = 0; i < game_num; i++)
	{
		if (i < 9)
			no[2] = i + '0';
		else
		{
			no[1] = i / 10 + '0';
			no[2] = i % 10 + '0';
		}
		out.width(4);
		out.fill(' ');
		out.setf(ios::right, ios::adjustfield);
		out << no;
	}
	out << endl;

	out << "     ";
	for (int i = 0; i < game_num; i++)
	{
		out.width(4);
		out.fill(' ');
		out.setf(ios::right, ios::adjustfield);
		out << *(game_arrange + 1);
	}
	out << endl;
}

ostream & operator <<(ostream & out, MySports & sQ)
{
	sQ.display(out);
	return out;
}
