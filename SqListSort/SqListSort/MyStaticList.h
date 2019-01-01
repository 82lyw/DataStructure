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
	int n = this->n;
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
	for (int i = 1; i < this->n; i++)
	{
		this->elem[i].data = random(1,99);
		this->elem[i].next = 0;
	}
}

//ª˘ ˝≈≈–Ú£®≤…”√æ≤Ã¨¡¥±Ì¥Ê¥¢£©
template <typename ElemType>
void MyStatic<ElemType>::radixSort()
{
	int front[RADIX], end[RADIX],i;
	for (i = 0; i < this->n; i++)
		this->elem[i].next = i + 1;
	this->elem[this->n - 1].next = 0;
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
	int j;
	for (j = 0; !front[j]; j++);
	this->elem[0].next = front[j];
	rear = end[j];
	while (j < RADIX)
	{
		++j;
		for (; j < RADIX - 1 && !front[j]; j++);
		if (j < RADIX&&front[j])
		{
			this->elem[rear].next = front[j];
			rear = end[j];
		}
	}
	this->elem[rear].next = 0;
}

template <typename ElemType>
void MyStatic<ElemType>::radixSortDistribute_aux(int i, int front[], int end[])
{
	int p;
	int pos;
	int t;
	int j;
	for (j = 0; j < RADIX; j++)
		front[j] = 0;
	for (p = this->elem[0].next; p; p = this->elem[p].next)
	{
		t = this->elem[p].data;
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
			this->elem[end[j]].next = p;
		end[j] = p;
	}
}

//æ≤Ã¨¡¥±Ì≈≈–Ú
template <typename ElemType>
void MyStatic<ElemType>::staticListSort()
{
	int q;
	int p;
	this->elem[0].next = 1;
	for (int i = 2; i < this->n; i++)
	{
		q = 0;
		p = this->elem[0].next;
		while (p&&this->elem[p].data <= this->elem[i].data)
		{
			q = p;
			p = this->elem[p].next;
		}
		this->elem[i].next = p;
		this->elem[q].next = i;
	}
}
