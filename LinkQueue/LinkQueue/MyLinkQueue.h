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
	void randLinkQ(MyLinkQueue<ElemType>& otherLinkQ);
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
	NodePointer t = front;
	int len = getLength();
	if (!front)
		return;
	out << "\t";
	while (t != rear)
	{
		out << setw(2) << t->data << "->";
		t = t->next;
	}
	if (rear == t)
		out << setw(2) << t->data;
	out << endl;

	out << "\t";
	out << "¡ü" << setw(4 * (len - 1)) << "¡ü" << endl;
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
void MyLinkQueue<ElemType>::randLinkQ(MyLinkQueue<ElemType>& otherLinkQ)
{
	int i, n;
	ElemType e;
	clear();
	srand((unsigned)time(NULL));
	n = rand() % 8 + 1;
	for (i = 0; i < n; i++)
	{
		e = rand() % 100 + 1;
		otherLinkQ.enQueue(e);
	}
}
