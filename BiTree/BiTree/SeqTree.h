//SeqTree.h 树（采用顺序存储）

template <typename ElemType>
class SeqTree
{
public:
	//把一个顺序存储的树置空
	void clear();

	//取最后一个结点在顺序存储空间的下标
	int getFinalIndex();

	//返回树采用顺序存储的首地址
	ElemType* getInitialAddress();

	//取下标为i的结点
	ElemType getNode(int i);

	//重载赋值运算符的定义
	SeqTree<ElemType> operator=(SeqTree<ElemType> rightT);

	//设置最后一个结点在顺序存储空间的下标
	void setFinalIndex(int i);

	//设置下标为i的结点（即第i+1个结点）的值
	void setNode(int i, ElemType value);

	SeqTree();
	~SeqTree();
	SeqTree(const SeqTree<ElemType>& seqT);

protected:
	ElemType* initialAddress;  //树的顺序存储空间的首地址
	int finalIndex;  //按层次存放，最后一个结点在顺序存储空间的下标
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


//MySeqTree.h 树（顺序存储） 派生类
template <typename ElemType>
class MySeqTree :public SeqTree<ElemType>
{
public:
	//输入顺序栈
	void read(istream& in);
	//输出顺序栈
	void display(ostream& out) const;
	//随机生成顺序栈
	void suiji();
};

//功能：输入二叉树
template <typename ElemType>
void MySeqTree<ElemType>::read(istream& in)
{
	int n;
	cout << "请输入二叉树中的结点个数：" << endl;
	cin >> n;
	cout << "请输入二叉树每个结点的数据域：" << endl;
	for (int i = 1; i <= n; i++)
		cin >> elem[i - 1];
}

//功能：随机生成二叉树
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

//功能：重载输入运算符的定义
template <typename ElemType>
istream& operator>>(istream& in, MySeqTree<ElemType>& iD)
{
	iD.read(in);
	return in;
}

//输出二叉树
template <typename ElemType>
void MySeqTree<ElemType>::display(ostream& out) const
{
	if (finalindex == -1)
		cout << "空" << endl;
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
					out << "╱ ";
				if (2 * i + 2 <= n && ((p[2 * i + 2] >= 'A'&&p[2 * i + 2] <= 'Z') || (p[2 * i + 2] >= 'a'&&p[2 * i + 2] <= 'z')))
					out << " ╲";
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

//重载输出运算符的定义
template <typename ElemType>
ostream& operator <<(ostream& out, const MySeqTree<ElemType>& oD)
{
	oD.display(out);
	return out;
}