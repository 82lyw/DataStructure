static int number;

template <typename ElemType>
class Maze :public SqStack<ElemType>
{
public:
	class MazePoint
	{
	public:
		int x;
		int y;
		int dir;  //0:��Ч,1:��,2:��,3:��,4:��
	};
public:
	void randCreate();
	Status maze_aux(MazePoint start, MazePoint end);
	Status maze(int s_x, int q_y, int z_x, int z_y);
	bool mazePath(MazePoint i);
	void read(istream& in);
	void display(ostream& out) const;
protected:
	ElemType **map;	//�Թ�����
};

template <typename ElemType>
void Maze<ElemType>::read(istream& in)
{
	int i, j, l, length = 0;
	delete[] this->base;
	this->base = new ElemType[STACK_MAX_SIZE];
	assert(this->base != 0);
	this->StackSize = STACK_MAX_SIZE;
	cout << "�������Թ�����������";
	in >> number;
	cout << endl;
	cout << "�������Թ������ݣ�" << endl;
	for (i = 0; i < number; i++)
	{
		for (j = 0; j < number; j++)
		{
			in >> l;
			this->base[i*number + j] = l;
			length++;
		}
	}
	this->top = this->base + length;
}

template <typename ElemType>
istream& operator>>(istream& in, Maze<ElemType>& iS)
{
	iS.read(in);
	return in;
}

template <typename ElemType>
void Maze<ElemType>::display(ostream& out) const
{
	int length = this->top - this->base;
	if (length)
	{
		for (int i = 0; i < sqrt(length); i++)
			out << "\t" << "[" << i << "]";
		out << endl;
	}
	for (int i = 0; i < sqrt(length); i++)
	{
		out << setw(3) << "[" << i << "]";
		for (int j = 0; j < sqrt(length); j++)
		{
			out << "\t" << " " << this->base[i*(int)sqrt(length) + j] << setw(3);
		}
		out << endl;
	}
}

template <typename ElemType>
ostream& operator<<(ostream& out, Maze<ElemType>& oS)
{
	oS.display(out);
	return out;
}

template <typename ElemType>
void Maze<ElemType>::randCreate()
{
	int i, j, k, length = 0;
	delete[] this->base;
	this->base = new ElemType[STACK_MAX_SIZE];
	this->StackSize = STACK_MAX_SIZE;
	srand((unsigned)time(NULL));
	k = rand() % 6 + 3;
	for (i = 0; i < k; i++)
	{
		for (j = 0; j < k; j++)
		{
			if (i == 0 || j == 0 || i == k - 1 || j == k - 1)
			{
				this->base[i*k + j] = 1;
				length++;
			}
			else
			{
				this->base[i*k + j] = rand() % 2;
				length++;
			}
		}
	}
	this->top = this->base + length;
}

template <typename ElemType>
Status Maze<ElemType>::maze(int q_x, int q_y, int z_x, int z_y)
{
	int length = this->top - this->base;
	int k = (int)sqrt(length);
	map = new int*[k];
	for (int i = 0; i < k; i++)
	{
		map[i] = new int[k];
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			map[i][j] = this->base[i*k + j];
		}
	}

	MazePoint start, end;
	start.x = q_x;
	start.y = q_y;
	end.x = z_x;
	end.y = z_y;
	if (maze_aux(start, end))
	{
		cout << "�����(" << q_x << "," << q_y << ")" << "���յ�" << "(" << z_x << "," << z_y << ")" << "��ͨ·������2��ע����:" << endl;
		if (length)
		{
			for (int t = 0; t < sqrt(length); t++)
				cout << "\t" << "[" << t << "]";
			cout << endl;
		}
		for (int i = 0; i < sqrt(length); i++)
		{
			cout << setw(3) << "[" << i << "]";
			for (int j = 0; j < sqrt(length); j++)
			{
				cout << "\t" << " " << map[i][j] << setw(3);
			}
			cout << endl;
		}
		return OK;
	}
	else
	{
		return ERROR;
	}
}

template <typename ElemType>
bool Maze<ElemType>::mazePath(MazePoint i)
{
	return (map[i.x][i.y] == 0 ? true : false);
}

template <typename ElemType>
Status Maze<ElemType>::maze_aux(MazePoint start,MazePoint end)
{
	MySqStack<MazePoint> s;
	MazePoint cur_S;
	int c_x=0, c_y=0;
	if (mazePath(start))
	{
		s.push(start);
	}
	else
		cout << " ���Ϊǽ�������Թ�";

	while (!s.isEmpty())
	{
		s.pop(cur_S);
		if (mazePath(cur_S))      //��ǰλ�ÿ�ͨ��������δ���ߵ���������
		{
			map[cur_S.x][cur_S.y] = 2;//�����㼣
			cur_S.dir = 1;
			if (cur_S.x == end.x && cur_S.y == end.y)   //�����յ�
				return OK;
			c_x = cur_S.x;   c_y = cur_S.y;
			s.push(cur_S);                     //����·��
			cur_S.x = c_x;   cur_S.y = c_y + 1;     //����
			s.push(cur_S);                     //����·��
			continue;
		}
		else    // ��ǰλ�ò���ͨ��
		{
			if (!s.isEmpty())
			{
				s.pop(cur_S);
				while (cur_S.dir == 4 && !s.isEmpty())
				{
					map[cur_S.x][cur_S.y] = 0;
					s.pop(cur_S);    // ����ͨ����� 2 �Ļ� 0�����˻�һ��
					continue;
				}
				if (cur_S.dir == 1)
				{
					cur_S.dir++;
					c_x = cur_S.x;   c_y = cur_S.y;        // ��¼λ��
					s.push(cur_S);                     //����·��
					cur_S.x = c_x + 1;   cur_S.y = c_y;    //����
					s.push(cur_S);                     //����·��
					continue;
				}
				if (cur_S.dir == 2)
				{
					cur_S.dir++;
					c_x = cur_S.x;   c_y = cur_S.y;        // ��¼λ��
					s.push(cur_S);                     //����·��
					cur_S.x = c_x;   cur_S.y = c_y - 1;    //����
					s.push(cur_S);                     //����·��
					continue;
				}
				if (cur_S.dir == 3)
				{
					cur_S.dir++;
					c_x = cur_S.x;   c_y = cur_S.y;        // ��¼λ��
					s.push(cur_S);                     //����·��
					cur_S.x = c_x - 1;   cur_S.y = c_y;    //����
					s.push(cur_S);                     //����·��
					continue;
					cout << "keyi" << endl;
				}
			}
		}
	}
	return ERROR;
}




/*
int moveDir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };//���嵱ǰλ���ƶ���4������

//���·��
void PrintPath(SqStack<MazePoint> p,int** maze)
{
	cout << "�Թ���·��Ϊ\n";
	cout << "�����ڵ����ݷֱ��ʾΪ(������,������,���ֻ�����,����)"<<endl;
	SqStack<MazePoint> t;
	int a, b;
	MazePoint data;
	MazePoint temp;
	p.pop(temp);
	t.push(temp);
	while (!p.isEmpty())  //���ջp�ǿգ��򷴸�ת��
	{
		p.pop(temp);
		MazePoint tp;
		t.getTop(tp);
		a = tp.x - temp.x;//�����귽��
		b = tp.y - temp.y;//�����귽��
		if (a == 1)
			temp.dir = 1;//�������£���1��ʾ
		else if (b == 1)
			temp.dir = 2;//�������ң���2��ʾ
		else if (a == -1)
			temp.dir = 3;//�������ϣ���3��ʾ
		else if (b == -1)
			temp.dir = 4;//����������4��ʾ
		t.push(temp);//����λ����ջ
	}

	while (!t.isEmpty())
	{
		t.pop(data);
		cout << '(' << data.x << ',' << data.y << ',' << data.dir << ",";//��������꣬������
		//maze[data.x][data.y] = 2;
		switch (data.dir)//�����Ӧ�ķ���
		{
		case 1:cout << "��)\n"; break;
		case 2:cout << "��)\n"; break;
		case 3:cout << "��)\n"; break;
		case 4:cout << "��)\n"; break;
		case 0:cout << ")\n"; break;
		}
	}
}

void RestoreM(int **maze, int m)
{
	int i, j;
	for(i=0;i<m;i++)
		for (j = 0; j < m; j++)
		{
			if (maze[i][j] == -1)
				maze[i][j] = 0;
		}
}

int** RandMaze(int &m)
{
	int** maze;
	int i = 0, j = 0;
	m = random(5, 10);
	maze = new int *[m];//��ȡ���ȵ���������2�Ķ���ָ��
	for (i = 0; i < m; i++)//ÿ����άָ��Ŀռ�
	{
		maze[i] = new int[m];
	}
	for (i = 1; i <= m-2; i++)//�����Թ������ݣ�0�����ͨ��1����ͨ
		for (j = 1; j <= m-2; j++)
			maze[i][j]= rand() % 2;
	for (i = 0; i < m ; i++)
		maze[i][0] = maze[i][m - 1] = 1;
	for (i = 0; i < m ; i++)
		maze[0][i] = maze[m - 1][i] = 1;
	return maze;
}

int** GetMaze(int &m)
{
	int** maze;
	int i = 0, j = 0;
	cout << "�������Թ�����������";
	cin >> m;
	maze = new int *[m];//��ȡ���ȵ���������2�Ķ���ָ��
	for (i = 0; i < m; i++)//ÿ����άָ��Ŀռ�
	{
		maze[i] = new int[m];
	}
	for (i = 0; i < m; i++)//�����Թ������ݣ�0�����ͨ��1����ͨ
		for (j = 0; j < m; j++)
			cin >> maze[i][j];
	
	return maze;//���ش����Թ��Ķ�άָ��maze
}

bool MazePath(int** maze,int m,MazePoint start,MazePoint end)  //Ѱ���Թ�maze�дӣ�0��0������m,n����·��
{
	SqStack<MazePoint> q, p;
	MazePoint temp1, temp2,temp3;
	temp1.x = start.x;
	temp1.y = start.y;
	int x, y, loop;
	q.push(temp1);//�����λ����ջ
	p.push(temp1);
	maze[temp1.x][temp1.y] = -1;//��־���λ���ѵ����
	int ab = 0;
	while (!q.isEmpty())
	{
		ab++;
		q.getTop(temp2);
		p.getTop(temp3);
		//�������ջ
		if (!((temp3.x) == (temp2.x)) && ((temp3.y) == (temp2.y)))
			p.push(temp2);
		for (loop = 0; loop < 4; loop++)//̽����ǰλ�õ�4������λ��
		{
			x = temp2.x + moveDir[loop][0];//�������λ��xλ��ֵ
			y = temp2.y + moveDir[loop][1];//�������λ��yλ��ֵ
			if (maze[x][y] == 0)//�ж���λ���Ƿ�ɴ�
			{
				temp1.x = x;
				temp1.y = y;
				maze[x][y] = -1;
				q.push(temp1);
			}
			if ((x == (end.x)) && (y == (end.y)))
			{
				temp1.x = end.x;
				temp1.y = end.y;
				temp1.dir = 0;
				p.push(temp1);
				PrintPath(p,maze);
				RestoreM(maze, m);
				return OK;
			}
		}
		q.getTop(temp2);
		p.getTop(temp3);
		if (temp3.x==temp2.x&&temp3.y==temp2.y)
		{
			MazePoint temp4;
			p.pop(temp4);
			q.pop(temp4);
		}
	}
	return ERROR;
}

void inputPoint(MazePoint &start,MazePoint &end,int m,int **maze)
{
loop:
	cout << "��������ʼ������꣺" << endl;
	cout << "x:";
	cin >> start.x;
	cout << "y:";
	cin >> start.y;

	cout << "�������յ�����꣺" << endl;
	cout << "x:";
	cin >> end.x;
	cout << "y:";
	cin >> end.y;

	if (start.x >= m || start.y >= m || start.x >= m || start.x >= m)
	{
		cout << "�Ҳ����õ㣡" << endl;
		goto loop;
	}

	if (maze[start.x][start.y]==1|| maze[end.x][end.y]==1)
	{
		cout << "��ʼ����յ㲻����" << endl;
		goto loop;
	}

}

void displayM(int m,int** maze)
{
	int i, j;
		cout << "\t";
		for (i = 0; i < m; i++)
			cout << "\t[" << i << "]";
		cout << endl;
		for (i = 0; i < m; i++)
		{
			cout << "\t[" << i << "]";
			for (j = 0; j < m; j++)
			{
				cout << "\t" << maze[i][j]; 
			}
			cout << endl;
		}
}
*/