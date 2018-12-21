//CrossListMatrix.h 稀疏矩阵（采用十字链表存储）数据结构C++类定义（基类）

//head.h
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

#define random(a,b) (rand()%(b-a+1)+a)

template <typename ElemType>
class CrossListMatrix
{
private:
	class Node
	{
	public:
		int i;
		int j;
		ElemType e;
		Node *right, *down;
	};
	typedef Node * NodePointer;

public:
	//把稀疏矩阵置空
	void clear();

	//取稀疏矩阵的列数
	int getColNum();

	//取第i行结点的头指针
	NodePointer getRowHead(int i);

	//取稀疏矩阵的行数
	int getRowNum();

	//取稀疏矩阵的非零元素的个数
	int getTotalNum();

	//判断稀疏矩阵是否为空
	bool isEmpty();

	//重载赋值运算符的定义
	CrossListMatrix<ElemType> operator=(CrossListMatrix<ElemType>rightS);

	//重载加法运算符的定义
	CrossListMatrix<ElemType> operator+(CrossListMatrix<ElemType>rightS);

	//求转置矩阵
	//int transport();

	//输入稀疏矩阵
	void read(istream & in);

	//输出稀疏矩阵
	void display(ostream & out);

	//随机生成稀疏矩阵
	void suiji();

	CrossListMatrix();
	~CrossListMatrix();
	CrossListMatrix(const CrossListMatrix<ElemType> & otherS);

protected:
	int rowNum;
	int colNum;
	int totalNum;
	NodePointer *rowHead, *colHead;
};

//置空
template <typename ElemType>
void CrossListMatrix<ElemType>::clear()
{
	if (rowHead)
		delete[] rowHead;
	if (colHead)
		delete[] colHead;

	rowHead = NULL;
	colHead = NULL;
	rowNum = 0;
	colNum = 0;
	totalNum = 0;
}

//取稀疏矩阵的列数
template <typename ElemType>
int CrossListMatrix<ElemType>::getColNum()
{
	return colNum;
}

//取第i行结点的头指针
/*
template <typename ElemType>
CrossListMatrix<ElemType>::NodePointer CrossListMatrix<ElemType>::getRowHead(int i)
{
	return rowHead[i];
}
*/

//取稀疏矩阵的行数
template <typename ElemType>
int CrossListMatrix<ElemType>::getRowNum()
{
	return rowNum;
}

//取非零元素的个数
template <typename ElemType>
int CrossListMatrix<ElemType>::getTotalNum()
{
	return totalNum;
}

//判断稀疏矩阵是否为空
template <typename ElemType>
bool CrossListMatrix<ElemType>::isEmpty()
{
	return totalNum ? false : true;
}

//重载赋值运算符的定义
template <typename ElemType>
CrossListMatrix<ElemType> CrossListMatrix<ElemType>:: operator=(CrossListMatrix<ElemType>rightS)
{
	NodePointer p1;
	NodePointer rq1=NULL;
	NodePointer *cq1;
	NodePointer p2;
	int cur_i, cur_j;
	if (this != &rightS)
	{
		clear();
		rowNum = rightS.rowNum;
		colNum = rightS.colNum;
		totalNum = rightS.totalNum;
		rowHead = new NodePointer[rowNum];
		assert(rowHead != 0);
		for (int cur_i = 0; cur_i < rowNum; cur_i++)
		{
			rowHead[cur_i] = NULL;
		}
		colHead = new NodePointer[colNum];
		assert(colHead != 0);
		for (int cur_j = 0; cur_j < colNum; cur_j++)
		{
			colHead[cur_j] = NULL;
		}

		//如果左边稀疏矩阵的非零元素的个数不为零
		if (totalNum)
		{
			//申请存放左边稀疏矩阵每列指向处理完的最后一个结点的指针数组
			cq1 = new NodePointer[colNum];
			assert(cq1 != 0);
			//初始化左边稀疏矩阵每列指向处理完的最后一个结点的指针数组为空
			for (int cur_j = 0; cur_j < colNum; cur_j++)
			{
				cq1[cur_j] = colHead[cur_j] = NULL;
			}
			//左边稀疏矩阵逐行接受rightS的赋值
			for (cur_i = 0; cur_i < rightS.rowNum; cur_i++)
			{
				for (p2 = rightS.rowHead[cur_i]; p2; p2 = p2->right)
				{
					p1 = new Node;
					assert(p1!= 0);
					p1->i = p2->i;
					p1->j = p2->j;
					p1->e = p2->e;
					p1->right = NULL;
					p1->down = NULL;

					if (!rowHead[cur_i])
					{
						rowHead[cur_i] = p1;
					}
					else
					{
						rq1->right = p1;
					}
					rq1->right = p1;
					cur_j = p1->j;
					if (!colHead[cur_j])
					{
						colHead[cur_j] = p1;
					}
					else
					{
						cq1[cur_j]->down = p1;
					}
					cq1[cur_j] = p1;
				}
			}
			//回收左边稀疏矩阵对应列指向最后一个结点的指针数组
			delete[] cq1;
		}
	}
	return *this;
}

//重载加法运算符的定义
template <typename ElemType>
CrossListMatrix<ElemType> CrossListMatrix<ElemType>:: operator+(CrossListMatrix<ElemType>rightS)
{
	NodePointer p1;
	NodePointer p2;
	NodePointer p3;
	NodePointer rp3;
	NodePointer *cq3;
	CrossListMatrix T;
	
	//两稀疏矩阵行列不等，则无法相加，直接退出
	if (colNum != rightS.colNum || rowNum != rightS.rowNum)
	{
		cout << "两稀疏矩阵的行列不等，无法相加！";
		exit(1);
	}
	T.rowNum = rowNum;
	T.colNum = colNum;
	T.totalNum = 0;
	T.rowHead = new NodePointer[T.rowNum];
	assert(T.rowHead != 0);
	//两稀疏矩阵和的行链表指针数组初始为空
	int cur_i, cur_j;
	for (int cur_i = 0; cur_i < T.rowNum; cur_i++)
		T.rowHead[cur_i] = NULL;
	T.colHead = new NodePointer[colNum];
	assert(T.colHead != 0);
	//两稀疏矩阵和的列链表指针数组初始化为空
	for (int cur_j = 0; cur_j < T.colNum; cur_j++)
		T.colHead[cur_j] = NULL;

	if (totalNum + rightS.totalNum)
	{
		cq3 = new NodePointer[T.colNum];
		assert(cq3 != 0);
		//初始化两稀疏矩阵和每列指向最后一个结点的指针数组为空
		for (int cur_j = 0; cur_j < T.colNum; cur_j++)
		{
			cq3[cur_j] = colHead[cur_j] = NULL;
		}
		//逐行生成两稀疏矩阵和
		for (cur_i = 0; cur_i < T.colNum; cur_i++)
		{
			p1 = rowHead[cur_i];
			p2 = rightS.rowHead[cur_i];
			rp3 = NULL;
			while (p1 || p2)
			{
				if (p1&&p2&&p1->j == p2->j&&p1->e + p2->e == 0)
				{
					p1 = p1->right;
					p2 = p2->right;
				}
				else
				{
					p3 = new Node;
					assert(p3 != 0);
					p3->right = NULL;
					p3->down = NULL;
					if (p1 && (!p2 || p1->j < p2->j))
					{
						p3->i = p1->i;
						p3->j = p1->j;
						p3->e = p1->e;
						p1 = p1->right;
					}
					else if (p2 && (!p1 || p2->j < p1->j))
					{
						p3->i = p2->i;
						p3->j = p2->j;
						p3->e = p2->e;
						p2 = p2->right;
					}
					else if (p1->j == p2->j&&p1->e + p2->e)
					{
						p3->i = p1->i;
						p3->j = p1->j;
						p3->e = p1->e;
						p1 = p1->right;
						p2 = p2->right;
					}
				}

				//把新的结点添加到两稀疏矩阵和的当前行链表的尾部
				if (!T.rowHead[cur_i])
				{
					T.rowHead[cur_i] = p3;
				}
				else
				{
					rp3->right = p3;
				}
				rp3 = p3;

				cur_j = p3->j;
				if (!T.colHead[cur_j])
				{
					T.colHead[cur_j] = p3;
				}
				else
				{
					cq3[cur_j]->down = p3;
				}
				cq3[cur_j] = p3;
				++T.totalNum;
			}
		}
		delete[] cq3;
	}
	return T;
}

/*
template <typename ElemType>
void CrossListMatrix<ElemType>::transport()
{
	int i, u, temp;
	NodePointer *head, p, q, r;
	temp=rowNum
	rowNum = colNum;
	colNum = temp;
	head = rowHead;
	rowHead = colHead;
	colHead = head;
	for (u = 0;u < rowNum; u++)
	{
		p = T.rowHead[u];
		while (p)
		{
			q = p->down;
			i = p->i;
			p->i = p->j;
			p->j = i;
			r = p->down;
			p->down = p->right;
			p->right = r;
			p = q;
		}
	}
	return 0;
}
*/

//输入稀疏矩阵
template <typename ElemType>
void CrossListMatrix<ElemType>::read(istream & in)
{
	cout << "输入行数  列数  非零元素个数：" << endl;
	in >> rowNum;
	in >> colNum;
	in >> totalNum;
	if (rowNum*colNum < totalNum)
	{
		return;
	}
	rowHead = new NodePointer[rowNum];
	assert(rowHead != 0);
	if (rowHead == NULL)
	{
		return;
	}
	colHead = new NodePointer[colNum];
	assert(colHead != 0);
	if (colHead == NULL)
	{
		free(rowHead);
		return;
	}
	for (int cur_i = 0; cur_i < rowNum; cur_i++)
	{
		rowHead[cur_i] = NULL;
	}
	for (int cur_j = 0; cur_j < colNum; cur_j++)
	{
		colHead[cur_j] = NULL;
	}

	for (int i = 0; i < totalNum; i++)
	{
		NodePointer temp;
		temp = new Node;
		if (temp == NULL)
		{
			return;
		}
		cout << "请输入行号：";
		in >> temp->i;
		cout << "请输入列号：";
		in >> temp->j;
		cout << "请输入元素的数据值：";
		in >> temp->e;
		temp->down = NULL;
		temp->right = NULL;

		if (rowHead[temp->i] == NULL || rowHead[temp->j]->i > temp->i)
		{
			temp->right = rowHead[temp->i];
			rowHead[temp->i] = temp;
		}
		else
		{
			NodePointer pTravel = rowHead[temp->i];
			while (pTravel->right != NULL && pTravel->right->j < temp->j)
			{
				pTravel = pTravel->right;
			}
			temp->right = pTravel->right;
			pTravel->right = temp;
		}

		if (colHead[temp->j] == NULL || colHead[temp->j]->i > temp->i)
		{
			temp->down = colHead[temp->i];
			colHead[temp->j] = temp;
		}
		else
		{
			NodePointer pTravel = colHead[temp->j];
			while (pTravel->down != NULL && pTravel->down->i < temp->i)
			{
				pTravel = pTravel->down;
			}
			temp->down = pTravel->down;
			pTravel->down = temp;
		}
	}
}

template <typename ElemType>
istream& operator>>(istream& in, CrossListMatrix<ElemType>&iC)
{
	iC.read(in);
	return in;
}

//输出稀疏矩阵
template <typename ElemType>
void CrossListMatrix<ElemType>::display(ostream & out)
{
	NodePointer p;
	cout << "\t";
	for (int i = 0; i < colNum; i++)
		cout << "\t[" << i << "]";
	cout << endl;
	for (int i = 0; i < rowNum; i++)
	{
		cout << "\t[" << i << "]";
		p = rowHead[i];
		for (int j = 0; j < colNum; j++)
		{
			if (p != NULL && p->j == j)
			{
				cout << "\t" << p->e;
				p = p->right;
			}
			else
			{
				cout << "\t0";
			}
		}
		cout << endl;
	}
	cout << endl;
}

template <typename ElemType>
ostream& operator<<(ostream& out, CrossListMatrix<ElemType>&iC)
{
	iC.display(out);
	return out;
}

//随机生成稀疏矩阵
template <typename ElemType>
void CrossListMatrix<ElemType>::suiji()
{
	rowNum = random(1, 8);
	colNum = random(1, 8);
	totalNum = random(2, 6);


}




//稀疏矩阵（采用十字链表）构造函数 设置一个零稀疏矩阵
template <typename ElemType>
CrossListMatrix<ElemType>::CrossListMatrix()
{
	rowNum = 0;
	colNum = 0;
	totalNum = 0;
	rowHead = NULL;
	colHead = NULL;
}

template <typename ElemType>
CrossListMatrix<ElemType>::~CrossListMatrix()
{
	clear();
}

template <typename ElemType>
CrossListMatrix<ElemType>::CrossListMatrix(const CrossListMatrix<ElemType> & otherS)
{
	NodePointer p1;
	NodePointer rq1;
	NodePointer *cq1;
	NodePointer p2;
	rowNum = otherS.rowNum;
	colNum = otherS.colNum;
	totalNum = otherS.totalNum;

	rowHead = new NodePointer[rowNum];
	assert(rowHead != 0);
	for (int cur_i = 0; cur_i < rowNum; cur_i++)
	{
		rowHead[cur_i] = NULL;
	}

	colHead = new NodePointer[colNum];
	assert(colHead != 0);
	for (int cur_j = 0; cur_j < colNum; cur_j)
	{
		colHead[cur_j] = NULL;
	}

	if (totalNum)
	{
		cq1 = new NodePointer[colNum];
		assert(cq1 != 0);
		for (int cur_j = 0; cur_j < colNum; cur_j++)
		{
			cq1[cur_j] = colHead[cur_j] = NULL;
		}
		for (int cur_i = 0; cur_i < otherS.rowNum; cur_i++)
		{
			for (p2 = otherS.rowHead[cur_i]; p2; p2 = p2->right)
			{
				p1 = new Node;
				assert(p1 != 0);
				p1->i = p2->i;
				p1->j = p2->j;
				p1->e = p2->e;
				p1->right = NULL;
				p1->down = NULL;

				//把新结点添加到当前稀疏矩阵当前行链表的尾部
				if (!rowHead[cur_i])
				{
					rowHead[cur_i] = p1;
				}
				else
				{
					rq1->right = p1;
				}
				rq1 = p1;

				int cur_j = p1->j;
				if (!colHead[cur_j])
				{
					colHead[cur_j]->down = p1;
				}
				else
				{
					cq1[cur_j]->down = p1;
				}
				cq1[cur_j] = p1;
			}
		}
		delete[] cq1;
	}
}