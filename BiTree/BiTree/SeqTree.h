//SeqTree.h ��������˳��洢��

template <typename ElemType>
class SeqTree
{
public:
	//��һ��˳��洢�����ÿ�
	void clear();

	//ȡ���һ�������˳��洢�ռ���±�
	int getFinalIndex();

	//����������˳��洢���׵�ַ
	ElemType* getInitialAddress();

	//ȡ�±�Ϊi�Ľ��
	ElemType getNode(int i);

	//���ظ�ֵ������Ķ���
	SeqTree<ElemType> operator=(SeqTree<ElemType> rightT);

	//�������һ�������˳��洢�ռ���±�
	void setFinalIndex(int i);

	//�����±�Ϊi�Ľ�㣨����i+1����㣩��ֵ
	void setNode(int i, ElemType value);

	SeqTree();
	~SeqTree();
	SeqTree(const SeqTree<ElemType>& seqT);

protected:
	ElemType* initialAddress;  //����˳��洢�ռ���׵�ַ
	int finalIndex;  //����δ�ţ����һ�������˳��洢�ռ���±�
};

template <typename ElemType>
void SeqTree<ElemType>::clear()
{
	if (initialAddress)
		delete[] initialAddress;
	initialAddress = NULL;
	finalIndex = -1;
}

template <typename ElemType>
int SeqTree<ElemType>::getFinalIndex()
{
	return finalIndex;
}

template <typename ElemType>
ElemType* SeqTree<ElemType>::getInitialAddress()
{
	return initialAddress;
}

template <typename ElemType>
ElemType SeqTree<ElemType>::getNode(int i)
{
	if (i<0 || i>finalIndex)
	{
		cerr << OVERFLOW;
		exit(1);
	}
	return initialAddress[i];
}

template <typename ElemType>
SeqTree<ElemType> SeqTree<ElemType>::operator=(SeqTree<ElemType> rightT)
{
	if (this != &rightT)
	{
		finalIndex = rightT.finalIndex;
		if (finalIndex != -1)
		{
			initialAddress = new ElemType[finalIndex + 1];
			assert(initialAddress != 0);
			for (int i = 0; i <= finalIndex; i++)
			{
				initialAddress[i] = rightT.initialAddress[i];
			}
		}
	}
	return *this;
}

template <typename ElemType>
void SeqTree<ElemType>::setFinalIndex(int i)
{
	finalIndex = i;
}

template <typename ElemType>
void SeqTree<ElemType>::setNode(int i, ElemType value)
{
	initialAddress[i] = value;
	if (i > finalIndex)
		finalIndex = i;
}

template <typename ElemType>
SeqTree<ElemType>::SeqTree()
{
	initialAddress = NULL;
	finalIndex = -1;
}

template <typename ElemType>
SeqTree<ElemType>::~SeqTree()
{
	clear();
}

template <typename ElemType>
SeqTree<ElemType>::SeqTree(const SeqTree<ElemType> &otherT)
{
	initialAddress = NULL;
	finalIndex = otherT.finalIndex;
	if (finalIndex != -1)
	{
		initialAddress = new ElemType[finalIndex + 1];
		assert(initialAddress != 0);
		for (int i = 0; i <= finalIndex; i++)
		{
			initialAddress[i] = otherT.initialAddress[i];
		}
	}
}


//MySeqTree.h ����˳��洢�� ������
template <typename ElemType>
class MySeqTree :public SeqTree<ElemType>
{
public:
	//����˳��ջ
	void read(istream& in);
	//���˳��ջ
	void display(ostream& out) const;
	//�������˳��ջ
	void suiji();
};

//���ܣ����������
template <typename ElemType>
void MySeqTree<ElemType>::read(istream& in)
{
	int n;
	cout << "������������еĽ�������" << endl;
	cin >> n;
	cout << "�����������ÿ������������" << endl;
	for (int i = 1; i <= n; i++)
		cin >> elem[i - 1];
}

//���ܣ�������ɶ�����
template <typename ElemType>
void MySeqTree<ElemType>::suiji()
{
	initialAddress = NULL;
	finalIndex = rand() % 10;
	if (finalIndex != -1)
	{
		initialAddress = new ElemType[finalIndex + 1];
		assert(initialAddress != 0);
		for (int i = 0; i <= finalIndex; ++i)
			initialAddress[i] = rand() % 100;
	}
}

//���ܣ���������������Ķ���
template <typename ElemType>
istream& operator>>(istream& in, MySeqTree<ElemType>& iD)
{
	iD.read(in);
	return in;
}

//���������
template <typename ElemType>
void MySeqTree<ElemType>::display(ostream& out) const
{
	if (finalindex == -1)
		cout << "��" << endl;
	else
	{
		int n = getfinalindex();
		qq* p = getinitialaddres();
		int h = gethigh(n);
		int t = 3 * getpow(2, h - 1);
		int i = 0;
		while (i <= n)
		{
			out << setw(t);
			int k = gethigh(i);
			int j;
			for (j = 1; j <= getpow(2, k - 1) && i <= n; j++)
			{
				if ((p[i] >= 'A'&&p[i] <= 'Z') || (p[i] >= 'a'&&p[i] <= 'z'))
					out << p[i];
				else
					out << " ";
				out << setw(6);
				i++;
			}
			i = i - j + 1;
			out << endl;
			out << setw(t - 1);
			for (int l = 1; l <= getpow(2, k - 1) && i <= n; l++)
			{
				if (2 * i + 1 <= n && ((p[2 * i + 1] >= 'A'&&p[2 * i + 1] <= 'Z') || (p[2 * i + 1] >= 'a'&&p[2 * i + 1] <= 'z')))
					out << "�u ";
				if (2 * i + 2 <= n && ((p[2 * i + 2] >= 'A'&&p[2 * i + 2] <= 'Z') || (p[2 * i + 2] >= 'a'&&p[2 * i + 2] <= 'z')))
					out << " �v";
				if ((2 * i + 1 > n && 2 * i + 2 > n) || (!((p[2 * i + 2] >= 'A'&&p[2 * i + 2] <= 'Z') || (p[2 * i + 2] >= 'a'&&p[2 * i + 2] <= 'z')) && !((p[2 * i + 1] >= 'A'&&p[2 * i + 1] <= 'Z') || (p[2 * i + 1] >= 'a'&&p[2 * i + 1] <= 'z'))))
					out << " ";
				out << setw(6);
				i++;

			}
			out << endl;
			t = t - 4;
		}
		out << " " << endl;

	}
}

//�������������Ķ���
template <typename ElemType>
ostream& operator <<(ostream& out, const MySeqTree<ElemType>& oD)
{
	oD.display(out);
	return out;
}