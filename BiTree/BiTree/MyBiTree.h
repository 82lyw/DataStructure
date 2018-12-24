//MyBiTree.h 二叉树（二叉链表存储） 派生类

#ifndef BITREE
#define BITREE
#include "BiTree.h"
#endif // !BITREE

template <typename ElemType>
class MyBiTree :public BiTree<ElemType>
{
public:
	//输入顺序栈
	void read(istream& in);
	//输出顺序栈
	void display(ostream& out) const;
	//随机生成顺序栈
	void suiji();
};

//功能：输入二叉树
template <typename ElemType>
void MyBiTree<ElemType>::read(istream& in)
{
	int n;
	cout << "请输入二叉树中的结点个数：" << endl;
	cin >> n;
	cout << "请输入二叉树每个结点的数据域：" << endl;
	for (int i = 1; i <= n; i++)
		cin >> elem[i - 1];
}

//功能：随机生成二叉树
template <typename ElemType>
void MyBiTree<ElemType>::suiji()
{
	initialAddress = NULL;
	finalIndex = rand() % 10;
	if (finalIndex != -1)
	{
		initialAddress = new ElemType[finalIndex + 1];
		assert(initialAddress != 0);
		for (int i = 0; i <= finalIndex; ++i)
			initialAddress[i] = rand() % 100;
	}
}

//功能：重载输入运算符的定义
template <typename ElemType>istream& operator>>(istream& in, MyBiTree<ElemType>& iD)
{
	iD.read(in);
	return in;
}

//输出二叉树
template <typename ElemType>
void MyBiTree<ElemType>::display(ostream& out) const
{
	if (finalindex == -1)
		cout << "空" << endl;
	else
	{
		int n = getfinalindex();
		qq* p = getinitialaddres();
		int h = gethigh(n);
		int t = 3 * getpow(2, h - 1);
		int i = 0;
		while (i <= n)
		{
			out << setw(t);
			int k = gethigh(i);
			int j;
			for (j = 1; j <= getpow(2, k - 1) && i <= n; j++)
			{
				if ((p[i] >= 'A'&&p[i] <= 'Z') || (p[i] >= 'a'&&p[i] <= 'z'))
					out << p[i];
				else
					out << " ";
				out << setw(6);
				i++;
			}
			i = i - j + 1;
			out << endl;
			out << setw(t - 1);
			for (int l = 1; l <= getpow(2, k - 1) && i <= n; l++)
			{
				if (2 * i + 1 <= n && ((p[2 * i + 1] >= 'A'&&p[2 * i + 1] <= 'Z') || (p[2 * i + 1] >= 'a'&&p[2 * i + 1] <= 'z')))
					out << "╱ ";
				if (2 * i + 2 <= n && ((p[2 * i + 2] >= 'A'&&p[2 * i + 2] <= 'Z') || (p[2 * i + 2] >= 'a'&&p[2 * i + 2] <= 'z')))
					out << " ╲";
				if ((2 * i + 1 > n && 2 * i + 2 > n) || (!((p[2 * i + 2] >= 'A'&&p[2 * i + 2] <= 'Z') || (p[2 * i + 2] >= 'a'&&p[2 * i + 2] <= 'z')) && !((p[2 * i + 1] >= 'A'&&p[2 * i + 1] <= 'Z') || (p[2 * i + 1] >= 'a'&&p[2 * i + 1] <= 'z'))))
					out << " ";
				out << setw(6);
				i++;

			}
			out << endl;
			t = t - 4;
		}
		out << " " << endl;

	}
}

//功能：重载输出运算符的定义
template <typename ElemType>
ostream& operator <<(ostream& out, const MyBiTree<ElemType>& oD)
{
	oD.display(out);
	return out;
}
