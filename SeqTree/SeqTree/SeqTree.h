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