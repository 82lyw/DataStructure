#define MazeSize 30
#define random(a,b) (rand()%(b-a+1)+a)

class Maze
{
public:
	class MazeType
	{
	public:
		int i;  //������
		int j;  //������
		int di;  //��һ�����߷ַ�λ
	};
public:
	//�ÿ�
	void clear();

	//������ʼ����յ�
	void inputPoint();

	//���Թ�·��
	//bool MazePath(int xi, int yi, int xe, int ye);
	bool MazePath();

	//��������Թ�
	void randM();

	//�����Թ�
	void read();

	//����Թ�
	void displayM();

	//���ظ�ֵ������Ķ���
	Maze operator=(Maze rightM);

	Maze();

	~Maze();


public:
	//��ʼ������
	int xi;
	int yi;
	//�յ�����
	int xe;
	int ye;
	
	int row_colNum;
	int** mg;
};

void Maze::inputPoint()
{
loop:
	cout << "��������ʼ������꣺" << endl;
	cout << "x:";
	cin >> xi;
	cout << "y:";
	cin >> yi;

	cout << "�������յ�����꣺" << endl;
	cout << "x:";
	cin >> xe;
	cout << "y:";
	cin >> ye;

	while (xi>= row_colNum ||yi>= row_colNum || xe >= row_colNum || ye >= row_colNum)
	{
		cout << "�Ҳ����õ㣡" << endl;
		goto loop;
	}
}

//bool Maze::MazePath(int xi, int yi, int xe, int ye)
bool Maze::MazePath()
{
	int i, j, k, di, find;
	static int s_top = -1;
	SqStack<MazeType> St;
	MazeType temp;
	MazeType m;
	MazeType data[MazeSize];
	s_top++;
	m.i = xi;
	m.j = yi;
	m.di = -1;
	data[s_top] = m;
	St.push(m);
	mg[xi][yi] = -1;

	while (!St.isEmpty())
	{
		St.getTop(temp);
		i = temp.i;
		j = temp.j;
		di = temp.di;

		//�ҵ�·�������·��
		if (i == xe && j == ye)
		{
			cout << "�Թ�·�����£�"<<endl;
			for (k = 0; k <= s_top; k++)
			{
				cout << "\t (" << data[k].i << "," << data[k].j << ")";
				if ((k + 1) % 5 == 0)
					cout << endl;
			}
			cout << endl;
			return true;
		}
		find = 0;
		while (di < 4 && find == 0)
		{
			di++;
			switch(di)
			{
			case 0:i = data[s_top].i - 1; j = data[s_top].j;
				break;
			case 1:i = data[s_top].i; j = data[s_top].j + 1;
				break;
			case 2:i = data[s_top].i + 1; j = data[s_top].j;
				break;
			case 3:i = data[s_top].i; j = data[s_top].j - 1;
				break;
			}
			if (mg[i][j] == 0) find = 1;
		}
		if (find == 1)
		{
			data[s_top].di = di;
			s_top++;
			data[s_top].i = i;
			data[s_top].j = j;
			data[s_top].di = -1;
			mg[i][j] = -1;
		}
		else
		{
			mg[data[s_top].i][data[s_top].j] = 0;
			s_top--;
		}

	}
	return false;
}

void Maze::randM()
{
	clear(); 
	row_colNum=random(4,8);
	mg = new int*[row_colNum];
	for (int i = 0; i < row_colNum; i++)
	{
		mg[i] = new int[row_colNum];
	}
	assert(mg != 0);
	for (int i = 0; i < row_colNum; i++)
	{
		for (int j = 0; j < row_colNum; j++)
			mg[i][j] = rand() % 2;
	}
}

void Maze::read()
{
	clear();
	cout << "�������Թ�����������";
	cin >> row_colNum;
	mg = new int*[row_colNum];
	assert(mg != 0);
	for (int i = 0; i < row_colNum; i++)
	{
		mg[i] = new int[row_colNum];
	}
	cout << "�������Թ������ݣ�"<<endl;
	for (int i = 0; i < row_colNum; i++)
	{
		for (int j = 0; j < row_colNum; j++)
			cin >> mg[i][j];
	}


}

void Maze::displayM()
{
	cout << "\t";
	for (int i = 0; i < row_colNum; i++)
		cout << "\t[" << i << "]";
	cout << endl;
	for (int i = 0; i < row_colNum; i++)
	{
		cout << "\t[" << i << "]";
		for (int j = 0; j < row_colNum; j++)
		{
			cout << "\t" << mg[i][j];
		}
		cout << endl;
	}
}

Maze Maze::operator=(Maze rightM)
{
	clear();
	row_colNum = rightM.row_colNum;
	mg = new int*[row_colNum];
	for (int i = 0; i < row_colNum; i++)
	{
		mg[i] = new int[row_colNum];
	}
	assert(mg != 0);
	if (this != &rightM)
	{
		for (int i = 0; i < row_colNum; i++)
		{
			for (int j = 0; j < row_colNum; j++)
			{
				mg[i][j] = rightM.mg[i][j];
			}
		}
	}
	return *this;
}


void Maze::clear()
{
	xi=NULL;
	yi=NULL;
	xe=NULL;
	ye=NULL;
	row_colNum=NULL;
	for (int i = 0; i < row_colNum; i++) {
		delete[] mg[i];
	}
	//delete[] mg;
	//mg = NULL;
}

Maze::Maze()
{

}

Maze::~Maze()
{
	clear();
}