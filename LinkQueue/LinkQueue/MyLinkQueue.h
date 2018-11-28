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
	//void read(istream& in);
	void display(ostream& out);
	void randLinkQ();
};
template <typename ElemType>
istream& operator>>(istream& in, MyLinkQueue<ElemType>& iL)
{
	iL.read(in);
	return in;
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
	ElemType e;
	typename LinkQueue<ElemType>::clear();
	n = random(2,8);
	cout << "有如下随机数生成非循环链队：" << endl;
	for (i = 0; i < n; i++)
	{
		e = random(1,99);
		cout << e<<"  ";
		typename LinkQueue<ElemType>::enQueue(e);
	}
	cout << endl;
	cout << "随机生成的非循环链队如下：" << endl;
}
