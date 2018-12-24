//TSMatrix.h ϡ����󣨲�����Ԫ���˳��洢�����ݽṹC++�ඨ�壨���ࣩ

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
	//��Ԫ�����ݽṹC++�ඨ��
	class Triple
	{
	public:
		int i;  //����Ԫ�ص����±�
		int j;  //����Ԫ�ص����±�
		ElemType e;  //����Ԫ�ص�����ֵ
	};

public:
	//��ϡ������ÿ�
	void clear();

	//����ϡ�������е�һ������Ԫ������Ԫ����е��±�
	void calcuate_rpos(int *rpos, int display = 0);

	//���ϡ��������Ԫ���
	void displayTriple();

	//������ϡ������ת�þ���
	void fastTransposeMatrix(TSMatrix<ElemType> & s);

	//ȡ���������
	int getColNum();

	//ȡϡ�������Ԫ���ĳ������Ԫ�ص�����ֵ
	ElemType get_data_k_e(int p);

	//ȡϡ�������Ԫ���ĳ������Ԫ�ص����±�
	int get_data_k_i(int p);

	//ȡϡ�������Ԫ���ĳ������Ԫ�ص����±�
	int get_data_k_j(int p);

	//ȡϡ����������
	int getRowNum();

	//ȡϡ��������Ԫ�صĸ���
	int getTotalNum();

	//�ж�ϡ������Ƿ�Ϊ��
	bool isEmpty();

	//���ظ�ֵ������Ķ���
	TSMatrix<ElemType> operator=(TSMatrix<ElemType> s);

	//���ؼӷ�������Ķ���
	TSMatrix<ElemType> operator+(TSMatrix<ElemType> s);

	//���س˷�������Ķ���
	TSMatrix<ElemType> operator*(TSMatrix<ElemType> s);

	//��ϡ������ת�þ���
	void transposeMatrix(TSMatrix<ElemType> & s);

	//����ϡ�����
	void read(istream & in);

	//���ϡ�����
	void display(ostream & out);
	int display_aux(int i, int j);

	//�������ϡ�����
	//void RandTS();
	void suiji();

	TSMatrix();

	~TSMatrix();

	TSMatrix(const TSMatrix<ElemType> & s);

protected:
	int rowNum;
	int colNum;
	int totalNum;
	Triple *data;  //ϡ����󣨲�����Ԫ���˳��洢����̬�洢�ռ��׵�ַ
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
		cout << "\t�к�\t��һ������Ԫ������Ԫ����е��±�" << endl;
		for (cur_i = 0; cur_i < rowNum; ++cur_i)
			cout << "\t" << "[" << cur_i << "]\t\t" << rpos[cur_i] << endl;
	}
}

//���ϡ��������Ԫ���ʾ
template <typename ElemType>
void TSMatrix<ElemType>::displayTriple()
{
	/*
	int k;
	char no[] = "[ i]";
	cout << "��" << rowNum << "*" << colNum << "ϡ�������";
	cout << " �±�  ��  ��  ֵ" << endl;
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
		//��ʾ��Ԫ����±���ַ���ʾ
		cout << " " << no;
		//��ʾ��Ԫ������Ԫ�ص����±�
		cout.width(7);
		cout.fill(' ');
		cout.setf(ios::right, ios::adjustfield);
		cout << data[k].i;
		//��ʾ��Ԫ������Ԫ�ص����±�
		cout.width(7);
		cout.fill(' ');
		cout.setf(ios::right, ios::adjustfield);
		cout << data[k].j;
		//��ʾ��Ԫ������Ԫ�ص�����ֵ
		cout.width(7);
		cout.fill(' ');
		cout.setf(ios::right, ios::adjustfield);
		cout << data[k].e;
		//���У�׼����ʾ��Ԫ������һ��Ԫ��
	}
	*/
	cout << "��" << rowNum << "*" << colNum << "ϡ�������"<<totalNum<<"������Ԫ��";
	cout << "��Ԫ���е�Ԫ�����£�"<<endl;
	cout << "\t [i]" << "\t [j]" << "\t e" << endl;
	for (int k = 0; k < totalNum; k++)
	{
		cout << "\t  " << data[k].i << "\t  " << data[k].j<<"\t" << data[k].e << endl;
	}
	
}

//ȡϡ����������
template <typename ElemType>
int TSMatrix<ElemType>::getColNum()
{
	return colNum;
}

//ȡϡ�������Ԫ���ĳ������Ԫ�ص�����ֵ
template <typename ElemType>
ElemType TSMatrix<ElemType>::get_data_k_e(int p)
{
	return data[p].e;
}

//ȡϡ�������Ԫ���ĳ������Ԫ�ص����±�
template <typename ElemType>
int TSMatrix<ElemType>::get_data_k_i(int p)
{
	return data[p].i;
}

//ȡϡ�������Ԫ���ĳ������Ԫ�ص����±�
template <typename ElemType>
int TSMatrix<ElemType>::get_data_k_j(int p)
{
	return data[p].j;
}

//ȡϡ����������
template <typename ElemType>
int TSMatrix<ElemType>::getRowNum()
{
	return rowNum;
}

//ȡϡ��������Ԫ�صĸ���
template <typename ElemType>
int TSMatrix<ElemType>::getTotalNum()
{
	return totalNum;
}

//������ϡ������ת�þ���
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

	//����Sÿ�з���Ԫ�صĸ���
	rpos = new int[S.rowNum];
	assert(rpos != 0);
	for (cur_i = 0; cur_i < S.rowNum; cur_i++)
		rpos[cur_i] = 0;
	
	//ɨ�赱ǰ����Ԫ�������Sÿ�з���Ԫ�صĸ���
	for (k1 = 0; k1 < totalNum; k1++)
		++rpos[data[k1].j];

	//����ÿ�з���Ԫ�صĸ��������� S���е�һ������Ԫ������Ԫ����е��±�
	pre_num = rpos[0];
	rpos[0] = 0;
	for (cur_i = 1; cur_i < colNum; cur_i++)
	{
		cur_num = rpos[cur_i];
		rpos[cur_i] = rpos[cur_i - 1] + pre_num;
		pre_num = cur_num;
	}

	//��ϡ������ת�þ��󣬼���Ԫ����ӦԪ�ص���ת
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

//���ظ�ֵ������Ķ���
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

//���ؼӷ�������Ķ���
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
		cout << "��ϡ��������в��ȣ��޷���ӣ�";
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

//���س˷�������Ķ���
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
		cout<<"��ϡ��������в��ȣ��޷���ˣ�";
		exit(1);
	}
	T.rowNum=S.rowNum=rowNum;
	T.colNum=S.colNum=rightS.colNum;
	T.totalNum=0;
	if(totalNum*rightS.totalNum)
	{
		//���������ϡ�������е�һ������Ԫ������Ԫ������±�Ĵ洢�ռ�
		rpos1=new int[rowNum];
		assert(rpos1!=0);
		//�������ϡ�������е�һ������Ԫ������Ԫ����е��±�
		calcuate_rpos(rpos1);
		//�������ұ�ϡ�������е�һ������Ԫ������Ԫ������±�Ĵ洢�ռ�
		rpos2=new int[rightS.rowNum];
		assert(rpos2!=0);
		//�����ұ�ϡ�������е�һ������Ԫ������Ԫ����е��±�
		rightS.calcuate_rpos(rpos2);
		//�������ϡ��������Ԫ�������洢�ռ�
		S.data=new Triple[S.rowNum*S.colNum];
		assert(S.data!=0);
		//����������ϡ�����ǰ�Ĵ洢�ռ䣻
		ctemp=new ElemType[S.colNum];
		assert(ctemp!=0);
		//�������ɹ���ϡ�����ǰ�Ĵ洢�ռ�
		for(cur_i=0;cur_i<S.rowNum;cur_i++)
		{
			//�ѹ���ϡ�����ǰ�����
			for(cur_j=0;cur_j<S.colNum;cur_j++)
				ctemp[cur_j]=0;
			//�������ϡ�������Ԫ���ǰԪ���±���Ͻ�
			if(cur_i<rowNum-1)
				k1Max=rpos1[cur_i+1];
			else
				k1Max=totalNum;
			//ͨ���ۼ�����ʵ����ϡ������Ӧ����Ԫ�س˻����ۼӣ��Ӷ��õ�����ϡ�����ǰ��
			for(int k1=rpos1[cur_i];k1<k1Max;k1++)
			{
				brow=data[k1].j;
				//�����ұ�ϡ�������Ԫ���ǰ��Ԫ���±���Ͻ�
				if(brow<rightS.rowNum-1)
					k2Max=rpos2[brow+1];
				else
					k2Max=rightS.totalNum;
				//�������ϡ�����ǰ��
				for(int k2=rpos2[brow];k2<k2Max;k2++)
				{
					//����ϡ�������Ԫ���ǰ�еķ���Ԫ�ص��к�
					cur_j=rightS.data[k2].j;
					ctemp[cur_j]+=data[k1].e*rightS.data[k2].e;
				}
			}
			//�ѹ���ϡ�����ǰ�еķ������ݸ��Ƶ�����Ԫ���Ĵ洢�ռ�
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
		//�������ϡ�������е�һ������Ԫ������Ԫ������±�Ĵ洢�ռ�
		delete[] rpos1;
		//�����ұ�ϡ�������е�һ������Ԫ������Ԫ������±�Ĵ洢�ռ�
		delete[] rpos2;
		//���ݹ���ϡ�����ʵ�ʷ���Ԫ�صĸ��������������������
		T.data=new Triple[T.totalNum];
		assert(T.data!=0);
		//�ѹ���ϡ�������Ԫ����Ԫ�ظ��Ƶ���ϡ��������Ԫ���Ĵ洢�ռ�
		for(int k3=0;k3<T.totalNum;k3++)
		{
			T.data[k3].i=S.data[k3].i;
			T.data[k3].j=S.data[k3].j;
			T.data[k3].e=S.data[k3].e;
		}
	}
	return T;                  
} 

//��ϡ������ת�þ���
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
		//����������Ԫ���ķ���Ԫ��
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

//���캯��������һ����ϡ�����
template <typename ElemType>
TSMatrix<ElemType>::TSMatrix()
{
	data = NULL;
	rowNum = 0;
	colNum = 0;
	totalNum = 0;
}

//�������������մ洢�ռ䣩
template <typename ElemType>
TSMatrix<ElemType>::~TSMatrix()
{
	clear();
}

//������ʼ�����캯��
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
	cout << "������������";
	in >> rowNum;
	cout << "������������";
	in >> colNum;
	cout << "���������Ԫ�صĸ�����";
	in >> totalNum;


	if (totalNum > 0)
	{
		data = new typename TSMatrix<ElemType>::Triple[totalNum];
		assert(data != 0);
		for (int k = 0; k < totalNum; k++)
		{
			cout << endl;
			cout << "�������кţ�";
			in >> data[k].i;
			cout << "�������кţ�";
			in >> data[k].j;
			cout << "������Ԫ�ص�����ֵ��";
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
	cout << "����һ������" << totalNum << "������Ԫ�ص�" << rowNum << "*" << colNum << "��ϡ�����" << endl;
}