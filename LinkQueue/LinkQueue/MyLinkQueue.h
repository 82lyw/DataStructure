#ifndef LinkQueue_H
#define LinkQueue_H
#include "LinkQueue.h"
#endif

#include <iomanip>
#include "iostream"
using namespace std;

template<typename ElemType>
class MyLinkQueue :public LinkQueue<ElemType>
{
public:
	void read(istream& in);
	void display(ostream& out);
	void randLinkQ();
};

template <typename ElemType>
istream& operator>>(istream& in, MyLinkQueue<ElemType>& iL)
{
	iL.read(in);
	return in;
}

template <typename ElemType>
void MyLinkQueue<ElemType>::read(istream & in)
{
	typename LinkQueue<ElemType>::NodePointer p, s;
	p = this->rear = NULL;
	int n;
	cout << "请输入非循环链队中的结点个数：" << endl;
	cin >> n;
	cout << "请输入非循环链队每个结点的数据域：" << endl;
	for (int i = 1; i <= n; ++i)
	{
		s = new typename LinkQueue<ElemType>::LinkNode;
		assert(s != 0);
		cin >> s->data;
		if (i == 1)
		{
			p = s;
			this->front = this->rear = p;
		}
		else
		{
			p->next = s;
			p = p->next;
		}
	}
	p->next = NULL;
}

template<typename ElemType>
void MyLinkQueue<ElemType>::display(ostream& out)
{
	typename LinkQueue<ElemType>::NodePointer t = this->front;
	int len = typename LinkQueue<ElemType>::getLength();
	if (!this->front)
		return;
	out << "\t";
	while (t != this->rear)
	{
		out << setw(2) << t->data << "->";
		t = t->next;
	}
	if (this->rear == t)
		out << setw(2) << t->data;
	out << endl;

	out << "\t";
	out << "↑" << setw(4 * (len - 1)) << "↑" << endl;
	out << "\t";
	out << "front" << setw(4 * (len - 1)) << "rear" << endl;
}
template <typename ElemType>
ostream& operator<<(ostream& out, MyLinkQueue<ElemType>& oL)
{
	oL.display(out);
	return out;
}

template<typename ElemType>
void MyLinkQueue<ElemType>::randLinkQ()
{
	int i, n;
	typename LinkQueue<ElemType>::NodePointer s;
	//typename LinkQueue<ElemType>::clear();
	this->rear = this->front = NULL;
	n = random(2,8);
	cout << "有如下随机数生成非循环链队：" << endl;
	for (i = 0; i < n; i++)
	{
		s = new typename LinkQueue<ElemType>::LinkNode;
		assert(s != 0);
		s->data = random(1,99);
		s->next = NULL;
		cout << s->data<<"  ";
		//typename LinkQueue<ElemType>::enQueue(e);
		if (!this->front)
			this->front = this->rear = s;
		else
		{
			this->rear->next = s;
			this->rear = s;
		}
	}
	cout << endl;
	cout << "随机生成的非循环链队如下：" << endl;
}
