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

	void setSizeEmptyTree(int size);

	SeqTree();
	~SeqTree();
	SeqTree(const SeqTree<ElemType>& seqT);

//protected:
public:
	ElemType* initialAddress;  //树的顺序存储空间的首地址
	int finalIndex;  //按层次存放，最后一个结点在顺序存储空间的下标
	ElemType elem[100];
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

template <typename ElemType>
void SeqTree<ElemType>::setSizeEmptyTree(int size)
{
	initialAddress = NULL;
	finalIndex = size - 1;
	if (finalIndex != -1)
	{
		initialAddress = new ElemType[finalIndex + 1];
		assert(finalIndex != 0);
		for (int i = 0; i <= finalIndex; ++i)
			initialAddress[i] = '0';
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
	void sequentialdisplay();
	void display(ostream& out) const;
	//随机生成顺序栈
	void randCreate();
};

template <typename ElemType>
void MySeqTree<ElemType>::read(istream& in)
{
	typename SeqTree<ElemType>::clear();
	int i, n;
	cout << "请输入最后一个结点在顺序存储空间的下标：";
	in >> n;
	this->finalIndex = n;
	if (this->finalIndex != -1)
	{
		cout << "按层次顺序输入树的各结点(空结点用'0'字符表示)：";
		this->initialAddress = new ElemType[this->finalIndex + 1];
		assert(this->initialAddress != 0);
		for (i = 0; i <= this->finalIndex; i++)
		{
			in >> this->initialAddress[i];
		}
		cout << endl;
	}
}

//功能：重载输入运算符的定义
template <typename ElemType>
istream& operator>>(istream& in, MySeqTree<ElemType>& iD)
{
	iD.read(in);
	return in;
}

template <typename ElemType>
void MySeqTree<ElemType>::sequentialdisplay()
{
	int i, n;
	n = typename SeqTree<ElemType>::getFinalIndex();
	cout << "该树的顺序存储输出为：" << endl;
	cout << " ";
	char no[5] = "[ i]";
	for (i = 0; i <= n; i++)
	{
		if (i < 9)
			no[2] = i + '0';
		else
		{
			no[1] = i / 10 + '0';
			no[2] = i % 10 + '0';
		}
		cout.width(4);
		cout.fill(' ');                             //不足空格补齐
		cout.setf(ios::right, ios::adjustfield);    //右对齐
		cout << no;
	}
	cout << endl;
	for (i = 0; i <= n; ++i)
	{
		if (this->initialAddress[i] != '0')
		{
			cout.width(4);
			cout.fill(' ');                             //不足空格补齐
			cout.setf(ios::right, ios::adjustfield);    //右对齐
			cout << this->initialAddress[i];
		}
		else
		{
			cout.width(4);
			cout.fill(' ');                             //不足空格补齐
			cout.setf(ios::right, ios::adjustfield);    //右对齐
			cout << "空";
		}
	}
	cout << endl;
}

template <typename ElemType>
void MySeqTree<ElemType>::display(ostream& out) const
{
	if (this->finalIndex != -1)
	{
		int i, j = 0, k, j2 = 1;
		int spacenum;//空格数
		int num, num2;//每行计数器
		int totalnum, totalnum2;//输出个数
		totalnum = 0, totalnum2 = 1;
		for (k = 0; pow(2, k) - 1 < (this->finalIndex + 1); k++);//根据最后一个结点的下标求二叉树的深度k
		for (i = 1; i <= k; i++)     //层数
		{
			//打印连接线
			if (i > 1)
			{
				for (num2 = 1; num2 <= pow(2, i - 1); num2++)
				{
					if (totalnum2 <= this->finalIndex)
					{
						if (num2 == 1)
						{
							for (spacenum = 1; spacenum <= pow(2, k - i) - 1; spacenum++)
								out << " ";
							if (this->initialAddress[j2] != '0')
							{
								if (j2 % 2)
								{
									out << "\57";
									j2++;
									totalnum2++;
								}
								else
								{
									out << "\134";
									j2++;
									totalnum2++;
								}
							}
							else
							{
								out << " ";
								j2++;
								totalnum2++;
							}

						}
						else
						{
							for (spacenum = 1; spacenum <= pow(2, k - i + 1) - 1; spacenum++)
								out << " ";
							if (this->initialAddress[j2] != '0')
							{
								if (j2 % 2)
								{
									out << "\57";
									j2++;
									totalnum2++;
								}
								else
								{
									out << "\134";
									j2++;
									totalnum2++;
								}
							}
							else
							{
								out << " ";
								j2++;
								totalnum2++;
							}
						}
					}
				}
				out << endl;
			}

			//打印结点
			for (num = 1; num <= pow(2, i - 1); num++)
			{
				if (totalnum < this->finalIndex + 1)
				{
					if (num == 1)      //每层第一个结点
					{
						for (spacenum = 1; spacenum <= pow(2, k - i) - 1; spacenum++)
							out << " ";
						if (this->initialAddress[j] != '0')
						{
							out << this->initialAddress[j++];
							totalnum++;
						}
						else
						{
							out << " ";
							j++;
							totalnum++;
						}

					}
					else          //每层除第一个以外的结点
					{
						for (spacenum = 1; spacenum <= pow(2, k - i + 1) - 1; spacenum++)
							out << " ";
						if (this->initialAddress[j] != '0')
						{
							out << this->initialAddress[j++];
							totalnum++;
						}
						else
						{
							out << " ";
							j++;
							totalnum++;
						}
					}
				}
			}
			out << endl;
		}
	}
}

//重载输出运算符的定义
template <typename ElemType>
ostream& operator <<(ostream& out, const MySeqTree<ElemType>& oD)
{
	oD.display(out);
	return out;
}

template <typename ElemType>
void MySeqTree<ElemType>::randCreate()
{
	typename SeqTree<ElemType>::clear();
	int i, n, j, flag;
	srand((unsigned)time(NULL));
	n = rand() % 14 + 5;
	this->finalIndex = n;
	if (this->finalIndex != -1)
	{
		this->initialAddress = new ElemType[this->finalIndex + 1];
		assert(this->initialAddress != 0);
		this->initialAddress[0] = 'A' + rand() % 26;
		for (i = 1; i <= this->finalIndex; i++)
		{
			if (this->initialAddress[i] == '0')
			{
				if (2 * 1 + 1 <= this->finalIndex)
					this->initialAddress[2 * i + 1] = '0';
				if (2 * 1 + 2 <= this->finalIndex)
					this->initialAddress[2 * i + 2] = '0';
				continue;
			}
			else
			{
				while (1)
				{
					switch ((rand() % 3))
					{
					case 1:this->initialAddress[i] = 'A' + rand() % 26;
						break;
					case 2:this->initialAddress[i] = 'A' + rand() % 26;
						break;
					default:this->initialAddress[i] = '0';
						break;
					}
					flag = 0;
					for (j = 0; j < i; j++)
					{
						if (this->initialAddress[j] == this->initialAddress[i])
						{
							flag++;
							break;
						}
					}
					if (flag == 1)
						continue;
					if (flag == 0)
						break;
				}
				if (this->initialAddress[i] == '0')
				{
					if (2 * 1 + 1 <= this->finalIndex)
						this->initialAddress[2 * i + 1] = '0';
					if (2 * 1 + 2 <= this->finalIndex)
						this->initialAddress[2 * i + 2] = '0';
				}
			}
			while (this->initialAddress[this->finalIndex] == '0')
			{
				this->finalIndex--;
			}
		}
		sequentialdisplay();
	}
}