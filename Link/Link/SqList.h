//SqList.h ˳������ݽṹC++�ඨ�壨���ࣩ

//myhead.h�����Լ��趨��һЩ����������
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\data\head.h"
#endif

#define LIST_MAX_SIZE 100
#define LISTINCREMENT 10
#define random(a,b) (rand()%(b-a+1)+a)

//˳������ݽṹC++�����������ࣩ

template <typename ElemType>
class SqList
{
public:
	//�������˳���0-99֮���������
	void RandomBorn();

	//����
	void inputList();

	//����˳����۰����
	int bin_Search(ElemType key);

	//˳����ÿ�
	void clear();

	//ɾ����i��Ԫ��
	Status deleteElem(int i, ElemType & e);

	//ȡ��i��Ԫ��
	Status getElem(int i, ElemType & e);

	//ȡ˳���洢�ռ�ĸ���
	int getLength();

	//ȡ˳���洢�ռ�Ĵ�С
	int getListSize();

	//�ڵ�i��Ԫ��֮ǰ����һ��Ԫ��
	Status insert(int i, ElemType e);

	//�ж�˳����Ƿ�Ϊ��
	bool isEmpty();

	//���ҵ�i����e����compare()��ϵ�����
	int locateElem(ElemType e, Status(*compare)(ElemType, ElemType));

	//����ĳԪ�صĺ��
	Status nextElem(ElemType e, ElemType & next_e);

	//���ظ�ֵ�����
	SqList<ElemType> operator = (SqList<ElemType> rightL);

	//����ĳԪ�ص�ǰ��
	Status priorElem(ElemType e, ElemType & prior_e);

	//��˳�����˳�����ĳԪ��
	int sequentialSearch(ElemType e);

	//���캯������������
	SqList();
	~SqList();
	SqList(const SqList<ElemType>& otherL);

protected:
	ElemType *elem;  //˳���̬�洢�ռ���׵�ַ
	int listSize;  //˳���ǰ�ѷ���Ĵ洢�ռ�
	int n;  //˳���ǰ�ĸ���
};

template <typename ElemType>
void SqList<ElemType>::inputList()
{
	int j;
	cout << "������˳�����Ԫ�صĸ�����";
	cin >> j;
	n = j;
	for (int i = 0; i < n; i++)
	{
		cin >> elem[i];
	}
}

template <typename ElemType>
void SqList<ElemType>::RandomBorn()
{
	/*delete[] elem;
	listsize = 10;
	elem = new elemtype[listsize];
	assert(elem != 0);*/
	int i;
	n = 10;
	cout << "�������������Ϊ��ǰ˳����Ԫ�أ�" << endl;
	for (i = 0; i < 10; i++)
	{
		elem[i] = random(1, 99);
		cout << elem[i] << "\t";
	}
	cout << endl;
}

template <typename ElemType>
int SqList<ElemType>::bin_Search(ElemType key)
{
	int low, mid, high;
	low = 0, high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (elem[mid] == key)
			return mid + 1;
		else if (elem[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return 0;
}

template<typename ElemType>
void SqList<ElemType>::clear()
{
	n = 0;
}

template<typename ElemType>
Status SqList<ElemType>::deleteElem(int i, ElemType & e)
{
	if (i<1 || i>n) return ERROR;
	e = elem[i - 1];
	for (int j = i + 1; j <= n; ++j)
	{
		elem[j - 2] = elem[j - 1];
	}
	--n;
	return OK;
}

template<typename ElemType>
Status SqList<ElemType>::getElem(int i, ElemType & e)
{
	if (i<1 || i>n) return ERROR;
	e = elem[i - 1];
	return OK;
}

template<typename ElemType>
int SqList<ElemType>::getLength()
{
	return n;
}

template<typename ElemType>
int SqList<ElemType>::getListSize()
{
	return listSize;
}

template<typename ElemType>
Status SqList<ElemType>::insert(int i, ElemType e)
{
	ElemType *newbase;
	if (i<1 || i>n + 1) return ERROR;
	if (n >= listSize)
	{
		newbase = new ElemType[listSize + LISTINCREMENT];
		assert(newbase != 0);
		for (int j = 1; j <= n; ++j)
		{
			newbase[j - 1] = elem[j - 1];
		}
		delete[] elem;
		elem = newbase;
		listSize += LISTINCREMENT;
	}
	for (int j = n; j >= i; --j)
	{
		elem[j] = elem[j - 1];
	}
	elem[i - 1] = e;
	++n;
	return OK;
}

template<typename ElemType>
bool SqList<ElemType>::isEmpty()
{
	return n ? false : true;
}

template<typename ElemType>
int SqList<ElemType>::locateElem(ElemType e, Status(*compare)(ElemType, ElemType))
{
	int i;
	for (i = 1; i <= n && !(*compare)(elem[i - 1], e); ++i);
	if (i <= n)
		return i;
	else
		return 0;
}

template<typename ElemType>
Status SqList<ElemType>::nextElem(ElemType e, ElemType & next_e)
{
	int i = locateElem(e, equal);
	if (i < 1 || i == n)
		return ERROR;
	else
		getElem(i + 1, next_e);
	return OK;
}

template<typename ElemType>
SqList<ElemType> SqList<ElemType>::operator=(SqList<ElemType>rightL)
{
	if (this != &rightL)
	{
		if (listSize < rightL.listSize)
		{
			delete[] elem;
			elem = new ElemType[rightL.listSize];
			assert(elem != 0);
			listSize = rightL.listSize;
		}
		n = rightL.n;
		for (int i = 1; i <= n; ++i)
			elem[i - 1] = rightL.elem[i - 1];
	}
	return *this;
}

template<typename ElemType>
Status SqList<ElemType>::priorElem(ElemType e, ElemType & prior_e)
{
	int i = locateElem(e, equal);
	if (i <= 1)
		return ERROR;
	else
		getElem(i - 1, prior_e);
	return OK;
}

template<typename ElemType>
int SqList<ElemType>::sequentialSearch(ElemType key)
{
	int i;
	for (i = 1; i < n&&key != elem[i - 1]; ++1);
	if (i <= n)
		return i;
	else
		return 0;
}

template<typename ElemType>
SqList<ElemType>::SqList()
{
	elem = new ElemType[LIST_MAX_SIZE];
	assert(elem != 0);
	listSize = LIST_MAX_SIZE;
	n = 0;
}

template<typename ElemType>
SqList<ElemType>::SqList(const SqList<ElemType> & otherL)
{
	elem = new ElemType[otherL.listSize];
	assert(elem != 0);
	listSize = otherL.listSize;
	n = otherL.n;
	for (int i = 1; i <= n; ++i)
	{
		elem[i - 1] = otherL.elem[i - 1];
	}
}

template <typename ElemType>
SqList<ElemType>::~SqList()
{
	delete[] elem;
}