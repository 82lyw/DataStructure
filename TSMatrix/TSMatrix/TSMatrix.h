//TSMatrix.h 稀疏矩阵（采用三元组表顺序存储）数据结构C++类定义（基类）

//myhead.h
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

#define random(a,b) (rand()%(b-a+1)+a)

template <typename ElemType>
class TSMatrix
{
protected:
	//三元组数据结构C++类定义
	class Triple
	{
	public:
		int i;  //非零元素的行下标
		int j;  //非零元素的列下标
		ElemType e;  //非零元素的数据值
	};

public:
	//把稀疏矩阵置空
	void clear();

	//计算稀疏矩阵各行第一个非零元素在三元组表中的下标
	void calcuate_rpos(int *rpos, int display = 0);

	//输出稀疏矩阵的三元组表
	void displayTriple();

	//快速求稀疏矩阵的转置矩阵
	void fastTransposeMatrix(TSMatrix<ElemType> & s);

	//取矩阵的列数
	int getColNum();

	//取稀疏矩阵三元组表某个非零元素的数据值
	ElemType get_data_k_e(int p);

	//取稀疏矩阵三元组表某个非零元素的行下标
	int get_data_k_i(int p);

	//取稀疏矩阵三元组表某个非零元素的列下标
	int get_data_k_j(int p);

	//取稀疏矩阵的行数
	int getRowNum();

	//取稀疏矩阵非零元素的个数
	int getTotalNum();

	//判断稀疏矩阵是否为空
	bool isEmpty();

	//重载赋值运算符的定义
	TSMatrix<ElemType> operator=(TSMatrix<ElemType> s);

	//重载加法运算符的定义
	TSMatrix<ElemType> operator+(TSMatrix<ElemType> s);

	//重载乘法运算符的定义
	TSMatrix<ElemType> operator*(TSMatrix<ElemType> s);

	//求稀疏矩阵的转置矩阵
	void transposeMatrix(TSMatrix<ElemType> & s);

	//输入稀疏矩阵
	void read(istream & in);

	//输出稀疏矩阵
	void display(ostream & out);
	int display_aux(int i, int j);

	//随机生成稀疏矩阵
	//void RandTS();
	void suiji();

	TSMatrix();

	~TSMatrix();

	TSMatrix(const TSMatrix<ElemType> & s);

protected:
	int rowNum;
	int colNum;
	int totalNum;
	Triple *data;  //稀疏矩阵（采用三元组表顺序存储）动态存储空间首地址
};

template <typename ElemType>
void TSMatrix<ElemType>::clear()
{
	if (data)
		delete[] data;

	data = NULL;
	rowNum = 0;
	colNum = 0;
	totalNum = 0;
}

template <typename ElemType>
void TSMatrix<ElemType>::calcuate_rpos(int * rpos, int display)
{
	int k;
	int cur_i;
	int pre_num;
	int cur_num;
	if (!totalNum)
		return;
	for (cur_i = 0; cur_i < rowNum; ++cur_i)
	{
		rpos[cur_i] = 0;
	}
	for (k = 0; k < totalNum; ++k)
	{
		++rpos[data[k].i];
	}
	rpos[0] = 0;
	pre_num = rpos[0];
	for (cur_i = 1; cur_i < rowNum; ++cur_i)
	{
		cur_num = rpos[cur_i];
		rpos[cur_i] = rpos[cur_i - 1] + pre_num;
		pre_num = cur_num;
	}
	if (display)
	{
		cout << "\t行号\t第一个非零元素在三元组表中的下标" << endl;
		for (cur_i = 0; cur_i < rowNum; ++cur_i)
			cout << "\t" << "[" << cur_i << "]\t\t" << rpos[cur_i] << endl;
	}
}

//输出稀疏矩阵的三元组表示
template <typename ElemType>
void TSMatrix<ElemType>::displayTriple()
{
	/*
	int k;
	char no[] = "[ i]";
	cout << "该" << rowNum << "*" << colNum << "稀疏矩阵共有";
	cout << " 下标  行  列  值" << endl;
	for (k = 0; k < totalNum; k++)
	{
		cout << " ";
		if (k < 10)
			no[2] = k + '0';
		else
		{
			no[1] = k / 10 + '0';
			no[2] = k % 10 + '0';
		}
		//显示三元组表下标的字符表示
		cout << " " << no;
		//显示三元组表非零元素的行下标
		cout.width(7);
		cout.fill(' ');
		cout.setf(ios::right, ios::adjustfield);
		cout << data[k].i;
		//显示三元组表非零元素的列下标
		cout.width(7);
		cout.fill(' ');
		cout.setf(ios::right, ios::adjustfield);
		cout << data[k].j;
		//显示三元组表非零元素的数据值
		cout.width(7);
		cout.fill(' ');
		cout.setf(ios::right, ios::adjustfield);
		cout << data[k].e;
		//换行，准备显示三元组表的下一个元素
	}
	*/
	cout << "该" << rowNum << "*" << colNum << "稀疏矩阵共有"<<totalNum<<"个非零元素";
	cout << "三元组中的元素如下："<<endl;
	cout << "\t [i]" << "\t [j]" << "\t e" << endl;
	for (int k = 0; k < totalNum; k++)
	{
		cout << "\t  " << data[k].i << "\t  " << data[k].j<<"\t" << data[k].e << endl;
	}
	
}

//取稀疏矩阵的列数
template <typename ElemType>
int TSMatrix<ElemType>::getColNum()
{
	return colNum;
}

//取稀疏矩阵三元组表某个非零元素的数据值
template <typename ElemType>
ElemType TSMatrix<ElemType>::get_data_k_e(int p)
{
	return data[p].e;
}

//取稀疏矩阵三元组表某个非零元素的行下标
template <typename ElemType>
int TSMatrix<ElemType>::get_data_k_i(int p)
{
	return data[p].i;
}

//取稀疏矩阵三元组表某个非零元素的列下标
template <typename ElemType>
int TSMatrix<ElemType>::get_data_k_j(int p)
{
	return data[p].j;
}

//取稀疏矩阵的行数
template <typename ElemType>
int TSMatrix<ElemType>::getRowNum()
{
	return rowNum;
}

//取稀疏矩阵非零元素的个数
template <typename ElemType>
int TSMatrix<ElemType>::getTotalNum()
{
	return totalNum;
}

//快速求稀疏矩阵的转置矩阵
template <typename ElemType>
void TSMatrix<ElemType>::fastTransposeMatrix(TSMatrix<ElemType> & S)
{
	int k1;
	int k2;
	int cur_i;
	int pre_num;
	int cur_num;
	int *rpos;
	S.clear();
	S.rowNum = colNum;
	S.colNum = rowNum;
	S.totalNum = totalNum;
	if (!S.totalNum)
		return;
	S.data = new Triple[totalNum];
	assert(S.data != 0);

	//计算S每行非零元素的个数
	rpos = new int[S.rowNum];
	assert(rpos != 0);
	for (cur_i = 0; cur_i < S.rowNum; cur_i++)
		rpos[cur_i] = 0;
	
	//扫描当前的三元组表，计算S每行非零元素的个数
	for (k1 = 0; k1 < totalNum; k1++)
		++rpos[data[k1].j];

	//利用每行非零元素的个数，计算 S各行第一个非零元素在三元组表中的下标
	pre_num = rpos[0];
	rpos[0] = 0;
	for (cur_i = 1; cur_i < colNum; cur_i++)
	{
		cur_num = rpos[cur_i];
		rpos[cur_i] = rpos[cur_i - 1] + pre_num;
		pre_num = cur_num;
	}

	//求稀疏矩阵的转置矩阵，即三元组表对应元素的逆转
	for (k1 = 0; k1 < totalNum; k1++)
	{
		cur_i = data[k1].j;
		k2 = rpos[cur_i];
		S.data[k2].i = data[k1].j;
		S.data[k2].j = data[k1].i;
		S.data[k2].e = data[k1].e;
		++rpos[cur_i];
	}
	delete[] rpos;
}

template <typename ElemType>
bool TSMatrix<ElemType>::isEmpty()
{
	return totalNum ? false : true;
}

//重载赋值运算符的定义
template <typename ElemType>
TSMatrix<ElemType> TSMatrix<ElemType>::operator=(TSMatrix<ElemType> rightS)
{
	if (this != &rightS)
	{
		clear();
		rowNum = rightS.rowNum;
		colNum = rightS.colNum;
		totalNum = rightS.totalNum;
		if (totalNum)
		{
			data = new Triple[totalNum];
			assert(data != 0);
			for (int k = 0; k < totalNum; k++)
			{
				data[k].i = rightS.data[k].i;
				data[k].j = rightS.data[k].j;
				data[k].e = rightS.data[k].e;
			}
		}
	}
	return *this;
}

//重载加法运算符的定义
template <typename ElemType>
TSMatrix<ElemType> TSMatrix<ElemType>::operator+(TSMatrix<ElemType> rightS)
{
	int k1 = 0;
	int k2 = 0;
	int k3 = 0;
	TSMatrix S;
	TSMatrix T;

	if (colNum != rightS.colNum || rowNum != rightS.rowNum)
	{
		cout << "两稀疏矩阵行列不等，无法相加！";
		exit(1);
	}
	T.rowNum = S.rowNum = rowNum;
	T.colNum = S.rowNum = rowNum;
	if (totalNum + S.totalNum)
	{
		S.data = new Triple[totalNum + rightS.totalNum];
		assert(S.data != 0);
		while (k1 < totalNum&&k2 < rightS.totalNum)
		{
			if (data[k1].i < rightS.data[k2].i || data[k1].i == rightS.data[k2].i&&data[k1].j < rightS.data[k2].j)
			{
				S.data[k3].i = data[k1].i;
				S.data[k3].j = data[k1].j;
				S.data[k3].e = data[k1].e;
				++k3;
				++k1;
			}
			else if (data[k1].i == rightS.data[k2].i&&data[k1].j == rightS.data[k2].j)
			{
				if (data[k1].e + rightS.data[k2].e)
				{
					S.data[k3].i = data[k1].i;
					S.data[k3].j = data[k1].j;
					S.data[k3].e = data[k1].e + rightS.data[k2].e;
					++k3;
				}
				++k1;
				++k2;
			}
			else
			{
				S.data[k3].i = rightS.data[k2].i;
				S.data[k3].j = rightS.data[k2].j;
				S.data[k3].e = rightS.data[k2].e;
				++k3;
				++k2;
			}
		}
		
		while (k1 < totalNum)
		{
			S.data[k3].i = data[k1].i;
			S.data[k3].j = data[k1].j;
			S.data[k3].e = data[k1].e;
			++k3;
			++k1;
		}

		while (k2 < rightS.totalNum)
		{
			S.data[k3].i = rightS.data[k2].i;
			S.data[k3].j = rightS.data[k2].j;
			S.data[k3].e = rightS.data[k2].e;
			++k3;
			++k2;
		}
		T.totalNum = k3;
		T.data = new Triple[T.totalNum];
		assert(T.data != 0);
		for (int k3 = 0; k3 < T.totalNum; ++k3)
		{
			T.data[k3].i = S.data[k3].i;
			T.data[k3].j = S.data[k3].j;
			T.data[k3].e = S.data[k3].e;
		}
	}
	return T;
}

//重载乘法运算符的定义
template <typename ElemType>
TSMatrix<ElemType> TSMatrix<ElemType>::operator*(TSMatrix<ElemType> rightS)
{
    int cur_i;
	int cur_j;
	int k1Max;
	int k2Max;
	int brow;
	int *rpos1;
	int *rpos2;
	ElemType *ctemp;
	TSMatrix S;
	TSMatrix T;
	if(colNum!=rightS.rowNum)
	{
		cout<<"两稀疏矩阵行列不等，无法相乘！";
		exit(1);
	}
	T.rowNum=S.rowNum=rowNum;
	T.colNum=S.colNum=rightS.colNum;
	T.totalNum=0;
	if(totalNum*rightS.totalNum)
	{
		//申请存放左边稀疏矩阵各行第一个非零元素在三元组表中下标的存储空间
		rpos1=new int[rowNum];
		assert(rpos1!=0);
		//计算左边稀疏矩阵各行第一个非零元素在三元组表中的下标
		calcuate_rpos(rpos1);
		//申请存放右边稀疏矩阵各行第一个非零元素在三元组表中下标的存储空间
		rpos2=new int[rightS.rowNum];
		assert(rpos2!=0);
		//计算右边稀疏矩阵各行第一个非零元素在三元组表中的下标
		rightS.calcuate_rpos(rpos2);
		//申请过渡稀疏矩阵积三元组表的最大存储空间
		S.data=new Triple[S.rowNum*S.colNum];
		assert(S.data!=0);
		//申请计算过渡稀疏矩阵当前的存储空间；
		ctemp=new ElemType[S.colNum];
		assert(ctemp!=0);
		//逐行生成过渡稀疏矩阵当前的存储空间
		for(cur_i=0;cur_i<S.rowNum;cur_i++)
		{
			//把过渡稀疏矩阵当前行清空
			for(cur_j=0;cur_j<S.colNum;cur_j++)
				ctemp[cur_j]=0;
			//计算左边稀疏矩阵三元组表当前元素下表的上界
			if(cur_i<rowNum-1)
				k1Max=rpos1[cur_i+1];
			else
				k1Max=totalNum;
			//通过累加器，实现两稀疏矩阵对应行列元素乘积的累加，从而得到过渡稀疏矩阵当前行
			for(int k1=rpos1[cur_i];k1<k1Max;k1++)
			{
				brow=data[k1].j;
				//计算右边稀疏矩阵三元组表当前行元素下标的上界
				if(brow<rightS.rowNum-1)
					k2Max=rpos2[brow+1];
				else
					k2Max=rightS.totalNum;
				//计算过渡稀疏矩阵当前行
				for(int k2=rpos2[brow];k2<k2Max;k2++)
				{
					//过渡稀疏矩阵三元组表当前行的非零元素的列号
					cur_j=rightS.data[k2].j;
					ctemp[cur_j]+=data[k1].e*rightS.data[k2].e;
				}
			}
			//把过渡稀疏矩阵当前行的非零数据复制到其三元组表的存储空间
			for(cur_j=0;cur_j<S.colNum;cur_j++)
			{
				if(ctemp[cur_j]!=0)
				{
					S.data[T.totalNum].i=cur_i;
					S.data[T.totalNum].j=cur_j;
					S.data[T.totalNum].e=ctemp[cur_j];
					++T.totalNum;
				}
			}
		}
		//回收左边稀疏矩阵各行第一个非零元素在三元组表中下标的存储空间
		delete[] rpos1;
		//回收右边稀疏矩阵各行第一个非零元素在三元组表中下标的存储空间
		delete[] rpos2;
		//根据过渡稀疏矩阵实际非零元素的个数，生成最后的两矩阵积
		T.data=new Triple[T.totalNum];
		assert(T.data!=0);
		//把过渡稀疏矩阵三元组表的元素复制到两稀疏矩阵积三元组表的存储空间
		for(int k3=0;k3<T.totalNum;k3++)
		{
			T.data[k3].i=S.data[k3].i;
			T.data[k3].j=S.data[k3].j;
			T.data[k3].e=S.data[k3].e;
		}
	}
	return T;                  
} 

//求稀疏矩阵的转置矩阵
template <typename ElemType>
void TSMatrix<ElemType>::transposeMatrix(TSMatrix<ElemType> & S)
{
	int k1;
	int k2 = 0;
	int cur_i;
	S.clear();
	if (totalNum)
	{
		S.rowNum = colNum;
		S.colNum = rowNum;
		S.totalNum = totalNum;
		S.data = new Triple[totalNum];
		assert(S.data != 0);
		//逐行生成三元组表的非零元素
		for (cur_i = 0; cur_i < colNum; cur_i++)
		{
			for (k1 = 0; k1 < totalNum; k1++)
			{
				if (data[k1].j == cur_i)
				{
					S.data[k2].i = data[k1].j;
					S.data[k2].j = data[k1].i;
					S.data[k2].e = data[k1].e;
					++k2;
				}
			}
		}
	}
}

//构造函数（设置一个零稀疏矩阵）
template <typename ElemType>
TSMatrix<ElemType>::TSMatrix()
{
	data = NULL;
	rowNum = 0;
	colNum = 0;
	totalNum = 0;
}

//析构函数（回收存储空间）
template <typename ElemType>
TSMatrix<ElemType>::~TSMatrix()
{
	clear();
}

//拷贝初始化构造函数
template <typename ElemType>
TSMatrix<ElemType>::TSMatrix(const TSMatrix<ElemType> & otherS)
{
	rowNum = otherS.rowNum;
	colNum = otherS.colNum;
	totalNum = otherS.totalNum;
	if (totalNum)
	{
		data = new Triple[totalNum];
		assert(data != 0);
		for (int k = 0; k < totalNum; k++)
		{
			data[k].i = otherS.data[k].i;
			data[k].j = otherS.data[k].j;
			data[k].e = otherS.data[k].e;
		}
	}
	else
		data = NULL;
}

template <typename ElemType>
void TSMatrix<ElemType>::read(istream & in)
{
	cout << "请输入行数：";
	in >> rowNum;
	cout << "请输入列数：";
	in >> colNum;
	cout << "请输入非零元素的个数：";
	in >> totalNum;


	if (totalNum > 0)
	{
		data = new typename TSMatrix<ElemType>::Triple[totalNum];
		assert(data != 0);
		for (int k = 0; k < totalNum; k++)
		{
			cout << endl;
			cout << "请输入行号：";
			in >> data[k].i;
			cout << "请输入列号：";
			in >> data[k].j;
			cout << "请输入元素的数据值：";
			in >> data[k].e;
		}
	}
	else
		data = NULL;
}

template <typename ElemType>
istream& operator>>(istream& in, TSMatrix<ElemType>&iT)
{
	iT.read(in);
	return in;
}

template <typename ElemType>
int TSMatrix<ElemType>::display_aux(int i, int j)
{
	for (int index = 0; index < totalNum; index++)
	{
		if ((data[index].i == i) && (data[index].j == j))
			return index;
	}
	return 1000;
}


template <typename ElemType>
void TSMatrix<ElemType>::display(ostream & out)
{
	int index = 0;
	cout << "\t";
	for (int i = 0; i < colNum; i++)
		cout << "\t [" << i << "]";
	cout << endl;
	for (int i = 0; i < rowNum; i++)
	{
		cout << "\t [" << i << "]";
		for (int j = 0; j < colNum; j++)
		{
			/*
			if (index < totalNum && (data[index].i == i) && (data[index].j == j))
			{
				cout << "\t" << data[index++].e;
			}*/
			if (display_aux(i, j) != 1000)
			{
				out << "\t" << data[display_aux(i, j)].e;
			}
			else
			{
				cout << "\t 0";
			}
		}
		cout << endl;
	}
}

template <typename ElemType>
ostream& operator<<(ostream& out, TSMatrix<ElemType>&iT)
{
	iT.display(out);
	return out;
}

template <typename ElemType>
void TSMatrix<ElemType>::suiji()
{
	cout << "..." << endl;
	rowNum = random(2, 6);
	colNum = random(2, 6);
	totalNum = random(2, 8);
	data = new typename TSMatrix<ElemType>::Triple[totalNum];
	assert(data != 0);
	for (int i = 0; i < totalNum; i++)
	{
		data[i].i = random(0, rowNum - 1);
		data[i].j = random(0, colNum - 1);
		data[i].e = random(0, 99);
	}
	cout << "生成一个包含" << totalNum << "个非零元素的" << rowNum << "*" << colNum << "的稀疏矩阵" << endl;
}