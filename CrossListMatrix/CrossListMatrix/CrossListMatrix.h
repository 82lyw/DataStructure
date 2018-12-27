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
//private:
public:
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

	//生成随机...的辅助函数
	void insert(NodePointer p);

	//重载赋值运算符的定义
	CrossListMatrix<ElemType> operator=(CrossListMatrix<ElemType> rightS);

	//重载加法运算符的定义
	CrossListMatrix<ElemType> operator+(CrossListMatrix<ElemType> rightS);

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
template <typename ElemType>
typename CrossListMatrix<ElemType>::NodePointer CrossListMatrix<ElemType>::getRowHead(int i)
{
	return rowHead[i];
}

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

//生成随机...的辅助函数
template <typename ElemType>
void CrossListMatrix<ElemType>::insert(NodePointer p)
{
	NodePointer rp = NULL;
	NodePointer cp = NULL;
	int cur_i, cur_j;

	//将p插入到对应行
	cur_i = p->i;
	if (!rowHead[cur_i])            //如果该行为空，则将该行的头指针指向新结点
	{
		rowHead[cur_i] = p;
	}
	else                           //如果该行不为空
	{
		if (p->j < rowHead[cur_i]->j)   //如果新结点的列号小于头指针的列号，则把头指针指向新结点
		{
			p->right = rowHead[cur_i];
			rowHead[cur_i] = p;
		}
		else                            //如果新结点的列号大于头指针的列号
		{
			if (rowHead[cur_i]->right == NULL)    //如果头指针的后继为空，则把新结点插入到行链表尾部
				rowHead[cur_i]->right = p;
			else                                 //如果头指针的后继不为空
			{
				rp = rowHead[cur_i];                             //rp指向前驱
				cp = rowHead[cur_i]->right;                      //cp指向后继
				while (cp)
				{
					if (p->j < cp->j)
					{
						rp->right = p;
						p->right = cp;
						break;
					}
					else
					{
						if (cp->right == NULL)
						{
							cp->right = p;
							break;
						}
						else
						{
							rp = cp;
							cp = cp->right;
							continue;
						}
					}
				}
			}
		}
	}

	//将p插入到对应列
	cur_j = p->j;
	if (!colHead[cur_j])            //如果该列为空，则将该列的头指针指向新结点
	{
		colHead[cur_j] = p;
	}
	else                           //如果该列不为空
	{
		if (p->i < colHead[cur_j]->i)   //如果新结点的行号小于头指针的行号，则把头指针指向新结点
		{
			p->down = colHead[cur_j];
			colHead[cur_j] = p;
		}
		else                            //如果新结点的行号大于头指针的行号
		{
			if (colHead[cur_j]->down == NULL)    //如果头指针的后继为空，则把新结点插入到列链表尾部
				colHead[cur_j]->down = p;
			else                                 //如果头指针的后继不为空
			{
				rp = colHead[cur_j];                             //rp指向前驱
				cp = colHead[cur_j]->down;                       //cp指向后继
				while (cp)
				{
					if (p->i < cp->i)
					{
						rp->down = p;
						p->down = cp;
						break;
					}
					else
					{
						if (cp->down == NULL)
						{
							cp->down = p;
							break;
						}
						else
						{
							rp = cp;
							cp = cp->down;
							continue;
						}
					}
				}
			}
		}
	}
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
		for (cur_i = 0; cur_i < rowNum; cur_i++)
		{
			rowHead[cur_i] = NULL;
		}
		colHead = new NodePointer[colNum];
		assert(colHead != 0);
		for (cur_j = 0; cur_j < colNum; cur_j++)
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
			for (cur_j = 0; cur_j < colNum; cur_j++)
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

					//把新结点添加到左边稀疏矩阵该行行链表的尾部
					if (!rowHead[cur_i])
					{
						//如果新结点是改行的第一个非零元素，则把改行行链表表头指针指向新结点
						rowHead[cur_i] = p1;
					}
					else
					{
						rq1->right = p1;
					}
					rq1->right = p1;

					//把新结点添加到左边稀疏矩阵对应列列链表的尾部
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
	NodePointer rq1=NULL;
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


//MyCrossListMatrix.h 稀疏矩阵（十字链表存储）派生类
template <typename ElemType>
class MyCrossListMatrix :public CrossListMatrix<ElemType>
{
public:
	//输入稀疏矩阵
	void read(istream & in);

	//输出稀疏矩阵
	void display(ostream & out) const;

	//随机生成稀疏矩阵
	void randCreate();
};

/*
//输入稀疏矩阵
template <typename ElemType>
void MyCrossListMatrix<ElemType>::read(istream & in)
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
*/

template <typename ElemType>
istream& operator>>(istream& in, MyCrossListMatrix<ElemType>&iC)
{
	iC.read(in);
	return in;
}

//输出稀疏矩阵
template <typename ElemType>
void MyCrossListMatrix<ElemType>::display(ostream & out) const
{
	int c_i, c_j = 0;
	typename CrossListMatrix<ElemType>::NodePointer p;
	if (this->totalNum)
	{
		int ** a = new int*[this->rowNum];
		for (c_i = 0; c_i < this->rowNum; c_i++)
		{
			a[c_i] = new int[this->colNum];
		}
		for (c_i = 0; c_i < this->rowNum; c_i++)
		{
			for (c_j = 0; c_j < this->colNum; c_j++)
			{
				a[c_i][c_j] = 0;
			}
		}

		for (c_i = 0; c_i < this->rowNum; c_i++)
		{
			if (this->rowHead[c_i] != NULL)
			{
				for (p = this->rowHead[c_i]; p; p->right)
					a[c_i][p->j] = p->e;
			}
		}
		
		out << " 该" << this->rowNum << "*" << this->colNum << "稀疏矩阵共有" << this->totalNum << "个非零元素" << endl;
		for (c_i = 0; c_i < this->colNum; c_i++)
			out << "\t[" << c_i << "]";
		out << endl;
		for (c_i = 0; c_i < this->rowNum; c_i++)
		{
			out << "   [" << c_i << "]";
			for (c_j = 0; c_j < this->colNum; c_j++)
			{
				out << "\t" << a[c_i][c_j];
			}
			out << endl;
		}
	}
}

template <typename ElemType>
ostream& operator<<(ostream& out, MyCrossListMatrix<ElemType>&iC)
{
	iC.display(out);
	return out;
}

//随机生成稀疏矩阵
template <typename ElemType>
void MyCrossListMatrix<ElemType>::randCreate()
{
	typename CrossListMatrix<ElemType>::clear();
	int i_1,j_1,n_1;
	int i_2, j_2,e_2;
	typename CrossListMatrix<ElemType>::NodePointer p;
	i_1 = random(4, 7);
	this->rowNum = i_1;
	j_1 = random(4, 7);
	this->colNum = j_1;
	n_1 = random(1, 4);
	this->totalNum = n_1;
	cout << endl;

	int cur_i, cur_j;
	this->rowHead = new typename CrossListMatrix<ElemType>::NodePointer[this->rowNum];
	assert(this->rowHead != 0);
	for (cur_i = 0; cur_i < this->rowNum; cur_i++)
	{
		this->rowHead[cur_i] = NULL;
	}
	this->colHead = new typename CrossListMatrix<ElemType>::NodePointer[this->colNum];
	assert(this->colHead != 0);
	for (cur_j = 0; cur_j < this->colNum; cur_j++)
		this->colHead[cur_j] = NULL;

	int k2;
	if (this->totalNum)
	{
		for (int k = 0; k < this->totalNum; k++)
		{
			while (1)
			{
				i_2 = random(0, this->rowNum);
				j_2 = random(0, this->colNum);
				k2 = 0;
				for (cur_i = 0; cur_i < this->rowNum; cur_i++)
				{
					for (p = this->rowHead[cur_i]; p; p->right)
					{
						if (i_2 == p->i&&j_2 == p->j)
						{
							k2++;
							break;
						}
					}
				}
				if (k2 == 1)
					continue;
				if (k2 == 0)
					break;
			}
			e_2 = random(0, 99);
			p = new typename CrossListMatrix<ElemType>::Node;
			assert(p != 0);
			p->i = i_2;
			p->j = j_2;
			p->e = e_2;
			p->right = NULL;
			p->down = NULL;
			typename CrossListMatrix<ElemType>::insert(p);
		}
	}
	cout << " 生成了" << this->rowNum << "*" << this->colNum << "的稀疏矩阵，其非零元素如下：" << endl;
	cout << " 元素值如下：" << endl;
	cout << "\t行号\t列号\t值" << endl;
	for (cur_i = 0; cur_i < this->rowNum; cur_i++)
	{
		if (this->rowHead[cur_i] != NULL)
		{
			for (p = this->rowHead[cur_i]; p; p = p->right)
			{
				cout << "\t " << p->i << "\t " << p->j << "\t" << p->e << endl;
			}
		}
	}
}



