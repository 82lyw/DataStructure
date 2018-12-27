class node {
public:
	int data;
	int next;
};

template <typename ElemType>
class MyStatic :public SqListSort<ElemType>
{
public:
	void randN();
	void display(ostream& out) const;
	void radixSort();
	void radixSortCollect_aux(int front[], int end[], int time);
	void radixSortDistribute_aux(int i, int front[], int end[]);
	void staticListSort();

};

template <typename ElemType>
void MyStatic<ElemType>::display(ostream& out) const
{
	int i;
	if (n)
	{
		for(i=0;i<this->n;i++)
			out << "\t" << "[" << i << "]";
		out << endl;
		out << "data:";
		for (i = 0; i < n; ++i)
			out << "\t" << this->elem[i].data;
		out << endl;
		out << "next:";
		for (i = 0; i < n; ++i)
			out << "\t" << this->elem[i].next;
	}
}

template <typename ElemType>
ostream& operator<<(ostream& out,MyStatic<ElemType>& oS)
{
	oS.display(out);
	return out;
}

template <typename ElemType>
void MyStatic<ElemType>::randN()
{
	this->n = random(1, 8);
	this->elem[0].data = NULL;
	this->elem[0].next = 0;
	for (int i = 1; i < n; i++)
	{
		this->elem[i].data = random(1,99);
		this->elem[i].next = 0;
	}
}

//ª˘ ˝≈≈–Ú£®≤…”√æ≤Ã¨¡¥±Ì¥Ê¥¢£©
template <typename ElemType>
void MyStatic<ElemType>::radixSort()
{
	int front[RADIX], end[RADIX];
	for (int i = 0; i < n; i++)
		elem[i].next = i + 1;
	elem[n - 1].next = 0;
	for (i = 1; i <= KEYNUM; i++)
	{
		radixSortDistribute_aux(i, front, end);
		radixSortCollect_aux(front, end, i);
	}
}

template <typename ElemType>
void MyStatic<ElemType>::radixSortCollect_aux(int front[], int end[], int time)
{
	int rear;
	for (int j = 0; !front[j]; j++);
	elem[0].next = front[j];
	rear = end[j];
	while (j < RADIX)
	{
		++j;
		for (; j < RADIX - 1 && !front[j]; j++);
		if (j < RADIX&&front[j])
		{
			elem[rear].next = front[j];
			rear = end[j];
		}
	}
	elem[rear].next = 0;
}

template <typename ElemType>
void MyStatic<ElemType>::radixSortDistribute_aux(int i, int front[], int end[])
{
	int p;
	int pos;
	int t;
	for (int j = 0; j < RADIX; j++)
		front[j] = 0;
	for (p = elem[0].next; p; p = elem[p].next)
	{
		t = elem[p].data;
		pos = i;
		while (pos > 1)
		{
			t /= 10;
			--pos;
		}
		j = t % 10;
		if (!front[j])
			front[j] = p;
		else
			elem[end[j]].next = p;
		end[j] = p;
	}
}

//æ≤Ã¨¡¥±Ì≈≈–Ú
template <typename ElemType>
void MyStatic<ElemType>::staticListSort()
{
	int q;
	int p;
	elem[0].next = 1;
	for (int i = 2; i < n; i++)
	{
		q = 0;
		p = elem[0].next;
		while (p&&elem[p].data <= elem[i].data)
		{
			q = p;
			p = elem[p].next;
		}
		elem[i].next = p;
		elem[q].next = i;
	}
}
