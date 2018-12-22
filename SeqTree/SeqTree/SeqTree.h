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