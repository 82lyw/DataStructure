//SqListSort.h 具有排序功能顺序表数据结构C++类定义（基类）

//SqList.h 顺序表数据结构
#ifndef SQLIST
#define SQLIST
#include "C:\Users\lyw\Desktop\lyw\DataStructure\Link\Link\SqList.h"
#endif // !SQLIST

#define KEYNUM 3
#define RADIX 10

template <typename ElemType>
class SqListSort :public SqList<ElemType>
{
public:
	void binaryInsertSort();
	void bubbleSort();
	int getIndex(int i);
	void heapSort();
	void insertSort();
	void mergeSort();
	void quickSort();
	void ShellSort();
	void selectSort();
	
	
private:
	void heapSortAdjust_aux(int s, int m);
	void mergeSort_aux(int s, int t);
	void mergeSortOne_aux(int i, int m, int n);
	void quickSort_aux(int low, int high);
	int quickSortPartition_aux(int low, int high);
	void ShellSort_aux(int  dk);

public:
	SqListSort();
	~SqListSort();
	SqListSort(const SqListSort& s);

protected:
	int *index;
};

//折半插入排序
template <typename ElemType>
void SqListSort<ElemType>::binaryInsertSort()
{
	int n = this->n;
	int low;
	int mid;
	int high;
	int k = -1;
	ElemType key;
	for (int i = 1; i < n; i++)
	{
		key = this->elem[i];
		low = 0;
		high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (key < this->elem[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (int j = i - 1; j >= high + 1; j--)
			this->elem[j + 1] = this->elem[j];
		this->elem[high + 1] = key;
	}
}

//冒泡排序
template <typename ElemType>
void SqListSort<ElemType>::bubbleSort()
{
	bool flag = true;
	ElemType t;
	for (int i = 1; i < this->n&&flag; i++)
	{
		flag = false;
		for (int j = 0; j < this->n - 1;j++)
		{
			if (this->elem[j + 1] < this->elem[j])
			{
				flag = true;
				t = this->elem[j + 1];
				this->elem[j + 1] = this->elem[j];
				this->elem[j] = t;
			}
		}
	}
}

//取顺序表各元素的原始位置（或下标、索引号）
template <typename ElemType>
int SqListSort<ElemType>::getIndex(int i)
{
	if (i<1 || i>this->n)
		return -1;
	return index[i - 1];
}

//堆排序
template <typename ElemType>
void SqListSort<ElemType>::heapSort()
{
	int i, j = 1;
	ElemType t;
	for (i = this->n / 2 - 1; i > -1; i--)
		heapSortAdjust_aux(i, this->n - 1);
	for (i = this->n - 1; i >= 1; i--)
	{
		t = this->elem[i];
		this->elem[i] = this->elem[0];
		this->elem[0] = t;
		heapSortAdjust_aux(0, i - 1);
	}
}

template <typename ElemType>
void SqListSort<ElemType>::heapSortAdjust_aux(int low, int high)
{
	ElemType t = this->elem[low];
	for (int max = 2 * low + 1; max <= high;)
	{
		if (max + 1 <= high && this->elem[max] < this->elem[max + 1])
			max++;
		if (t >= this->elem[max])
			break;
		this->elem[low] = this->elem[max];
		low = max;
		max = 2 * low + 1;
	}
	this->elem[low] = t;
}

//直接插入排序
template <typename ElemType>
void SqListSort<ElemType>::insertSort()
{
	ElemType key;
	int temp_index;
	int i;
	for (i = 0; i < this->n; i++)
	{
		index[i] = i;
	}
	for (i = 1; i < this->n; i++)
	{
		int j;
		key = this->elem[i];
		temp_index = index[i];
		for (j = i - 1; j >= 0 && key < this->elem[j]; j--)
		{
			this->elem[j + 1] = this->elem[j];
			index[j + 1] = index[j];
		}
		this->elem[j + 1] = key;
		index[j + 1] = temp_index;
	}
}

//归并排序
template <typename ElemType>
void SqListSort<ElemType>::mergeSort()
{
	mergeSort_aux(0, this->n - 1);
}

template <typename ElemType>
void SqListSort<ElemType>::mergeSort_aux(int low, int high)
{
	int mid;
	if (low != high)
	{
		mid = (low + high) / 2;
		mergeSort_aux(low, mid);
		mergeSort_aux(mid + 1, high);
		mergeSortOne_aux(low, mid, high);
	}
}

template <typename ElemType>
void SqListSort<ElemType>::mergeSortOne_aux(int low, int mid, int high)
{
	ElemType temp[LIST_MAX_SIZE];
	int k;
	static int time = 1;
	int i, j;
	for (i = k = low,j = mid + 1; i <= mid && j <= high;)
	{
		if (this->elem[i] <= this->elem[j])
			temp[k++] = this->elem[i++];
		else
			temp[k++] = this->elem[j++];
	}
	if (i <= mid)
	{
		for (; i <= mid;)
			temp[k++] = this->elem[i++];
	}
	if (j <= high)
	{
		for (; j <= high;)
			temp[k++] = this->elem[j++];
	}
	for (k = low; k <= high; k++)
		this->elem[k] = temp[k];
}

//快速排序
template <typename ElemType>
void SqListSort<ElemType>::quickSort()
{
	quickSort_aux(0, this->n - 1);
}

template <typename ElemType>
void SqListSort<ElemType>::quickSort_aux(int low, int high)
{
	int keyLoc;
	if (low < high)
	{
		keyLoc = quickSortPartition_aux(low, high);
		quickSort_aux(low, keyLoc - 1);
		quickSort_aux(keyLoc + 1, high);
	}
}

template <typename ElemType>
int SqListSort<ElemType>::quickSortPartition_aux(int low, int high)
{
	int i = low, j = high;
	ElemType t;
	t = this->elem[i];
	while (i < j)
	{
		while (i < j&&this->elem[j] >= t)
			j--;
		this->elem[i] = this->elem[j];
		while (i < j&&this->elem[i] <= t)
			i++;
		this->elem[j] = this->elem[i];
	}
	this->elem[i] = t;
	return i;
}

//希尔排序
template <typename ElemType>
void SqListSort<ElemType>::ShellSort()
{
	int dlta[LIST_MAX_SIZE];
	int k,d;
	for (d = this->n / 2, k = 0; d >= 1; d = d / 2)
		dlta[k++] = d;
	for (int i = 0; i < k; i++)
		ShellSort_aux(dlta[i]);
}

template <typename ElemType>
void SqListSort<ElemType>::ShellSort_aux(int dk)
{
	int j;
	static int time = 1;
	ElemType key;
	for (int i = dk; i < this->n; i++)
	{
		j = i - dk;
		if (this->elem[i] < this->elem[j])
		{
			key = this->elem[i];
			for (; j >= 0 && key < this->elem[j]; j -= dk)
				this->elem[j + dk] = this->elem[j];
			this->elem[j + dk] = key;
		}
	}
}

//直接选择排序
template <typename ElemType>
void SqListSort<ElemType>::selectSort()
{
	int min;
	ElemType t;
	for (int i = 1; i < this->n; i++)
	{
		min = i - 1;
		for (int j = i; j < this->n; j++)
			if (this->elem[j] < this->elem[min])
				min = j;
		if (min != i - 1)
		{
			t = this->elem[min];
			this->elem[min] = this->elem[i - 1];
			this->elem[i - 1] = t;
		}
	}
}

template <typename ElemType>
SqListSort<ElemType>::SqListSort()
{
	index = new int[LIST_MAX_SIZE];
	assert(index != 0);
}

template <typename ElemType>
SqListSort<ElemType>::~SqListSort()
{
	typename SqList<ElemType>::clear();
	delete[] index;
}

template <typename ElemType>
SqListSort<ElemType>::SqListSort(const SqListSort& otherS)
{
	index = new int[this->listSize];
	assert(index != 0);
	this->listSize = otherS.listSize;
	this->n = otherS.n;
	for (int i = 0; i < this->n; i++)
	{
		this->elem[i] = otherS.elem[i];
		index[i] = otherS.index[i];
	}
}


template <typename ElemType>
class MySqListSort :public SqListSort<ElemType>
{
public:
	void randS();
	void read(istream& in);
	void display(ostream& out) const;
};

template <typename ElemType>
void MySqListSort<ElemType>::read(istream& in)
{
	typename SqList<ElemType>::clear();
	delete this->elem;
	this->elem = new ElemType[LIST_MAX_SIZE];
	assert(this->elem != 0);
	cout << "请输入元素个数：";
	in >> this->n;
	cout << "请输入元素：";
	for (int i = 0; i < this->n; i++)
		in >> this->elem[i];
}

template <typename ElemType>
istream& operator>>(istream& in, MySqListSort<ElemType>& iS)
{
	iS.read(in);
	return in;
}

template <typename ElemType>
void MySqListSort<ElemType>::display(ostream& out) const
{
	for (int i = 0; i < this->n; i++)
		out << "[" << i << "]" << "\t";
	out << endl;
	for (int i = 0; i < this->n; i++)
		out << " " << this->elem[i] << "\t";
}

template <typename ElemType>
ostream& operator<<(ostream& out, MySqListSort<ElemType>& oS)
{
	oS.display(out);
	return out;
}

template <typename ElemType>
void MySqListSort<ElemType>::randS()
{
	this->n = (1, 10);
	for (int i = 0; i < this->n; i++)
	{
		this->elem[i] = random(0, 99);
	}
} 