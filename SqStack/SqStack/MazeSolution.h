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
		int dir;  //0:无效,1:东,2:南,3:西,4:北
	};
public:
	void randCreate();
	Status maze_aux(MazePoint start, MazePoint end);
	Status maze(int s_x, int q_y, int z_x, int z_y);
	bool mazePath(MazePoint i);
	void read(istream& in);
	void display(ostream& out) const;
protected:
	ElemType **map;	//迷宫矩阵
};

template <typename ElemType>
void Maze<ElemType>::read(istream& in)
{
	int i, j, l, length = 0;
	delete[] this->base;
	this->base = new ElemType[STACK_MAX_SIZE];
	assert(this->base != 0);
	this->StackSize = STACK_MAX_SIZE;
	cout << "请输入迷宫的行列数：";
	in >> number;
	cout << endl;
	cout << "请输入迷宫的数据：" << endl;
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
		cout << "从起点(" << q_x << "," << q_y << ")" << "到终点" << "(" << z_x << "," << z_y << ")" << "有通路，现用2标注如下:" << endl;
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
		cout << " 起点为墙，所以迷宫";

	while (!s.isEmpty())
	{
		s.pop(cur_S);
		if (mazePath(cur_S))      //当前位置可通过，即是未曾走到过的坐标
		{
			map[cur_S.x][cur_S.y] = 2;//留下足迹
			cur_S.dir = 1;
			if (cur_S.x == end.x && cur_S.y == end.y)   //到达终点
				return OK;
			c_x = cur_S.x;   c_y = cur_S.y;
			s.push(cur_S);                     //加入路径
			cur_S.x = c_x;   cur_S.y = c_y + 1;     //右移
			s.push(cur_S);                     //加入路径
			continue;
		}
		else    // 当前位置不能通过
		{
			if (!s.isEmpty())
			{
				s.pop(cur_S);
				while (cur_S.dir == 4 && !s.isEmpty())
				{
					map[cur_S.x][cur_S.y] = 0;
					s.pop(cur_S);    // 不能通过则把 2 改回 0，并退回一步
					continue;
				}
				if (cur_S.dir == 1)
				{
					cur_S.dir++;
					c_x = cur_S.x;   c_y = cur_S.y;        // 记录位置
					s.push(cur_S);                     //加入路径
					cur_S.x = c_x + 1;   cur_S.y = c_y;    //下移
					s.push(cur_S);                     //加入路径
					continue;
				}
				if (cur_S.dir == 2)
				{
					cur_S.dir++;
					c_x = cur_S.x;   c_y = cur_S.y;        // 记录位置
					s.push(cur_S);                     //加入路径
					cur_S.x = c_x;   cur_S.y = c_y - 1;    //左移
					s.push(cur_S);                     //加入路径
					continue;
				}
				if (cur_S.dir == 3)
				{
					cur_S.dir++;
					c_x = cur_S.x;   c_y = cur_S.y;        // 记录位置
					s.push(cur_S);                     //加入路径
					cur_S.x = c_x - 1;   cur_S.y = c_y;    //上移
					s.push(cur_S);                     //加入路径
					continue;
					cout << "keyi" << endl;
				}
			}
		}
	}
	return ERROR;
}




/*
int moveDir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };//定义当前位置移动的4个方向

//输出路径
void PrintPath(SqStack<MazePoint> p,int** maze)
{
	cout << "迷宫的路径为\n";
	cout << "括号内的内容分别表示为(行坐标,列坐标,数字化方向,方向)"<<endl;
	SqStack<MazePoint> t;
	int a, b;
	MazePoint data;
	MazePoint temp;
	p.pop(temp);
	t.push(temp);
	while (!p.isEmpty())  //如果栈p非空，则反复转移
	{
		p.pop(temp);
		MazePoint tp;
		t.getTop(tp);
		a = tp.x - temp.x;//行坐标方向
		b = tp.y - temp.y;//列坐标方向
		if (a == 1)
			temp.dir = 1;//方向向下，用1表示
		else if (b == 1)
			temp.dir = 2;//方向向右，用2表示
		else if (a == -1)
			temp.dir = 3;//方向向上，用3表示
		else if (b == -1)
			temp.dir = 4;//方向向左，用4表示
		t.push(temp);//把新位置入栈
	}

	while (!t.isEmpty())
	{
		t.pop(data);
		cout << '(' << data.x << ',' << data.y << ',' << data.dir << ",";//输出行坐标，列坐标
		//maze[data.x][data.y] = 2;
		switch (data.dir)//输出相应的方向
		{
		case 1:cout << "↓)\n"; break;
		case 2:cout << "→)\n"; break;
		case 3:cout << "↑)\n"; break;
		case 4:cout << "←)\n"; break;
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
	maze = new int *[m];//获取长度等于行数加2的二级指针
	for (i = 0; i < m; i++)//每个二维指针的空间
	{
		maze[i] = new int[m];
	}
	for (i = 1; i <= m-2; i++)//输入迷宫的内容，0代表可通，1代表不通
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
	cout << "请输入迷宫的行列数：";
	cin >> m;
	maze = new int *[m];//获取长度等于行数加2的二级指针
	for (i = 0; i < m; i++)//每个二维指针的空间
	{
		maze[i] = new int[m];
	}
	for (i = 0; i < m; i++)//输入迷宫的内容，0代表可通，1代表不通
		for (j = 0; j < m; j++)
			cin >> maze[i][j];
	
	return maze;//返回存贮迷宫的二维指针maze
}

bool MazePath(int** maze,int m,MazePoint start,MazePoint end)  //寻找迷宫maze中从（0，0）到（m,n）的路径
{
	SqStack<MazePoint> q, p;
	MazePoint temp1, temp2,temp3;
	temp1.x = start.x;
	temp1.y = start.y;
	int x, y, loop;
	q.push(temp1);//将入口位置入栈
	p.push(temp1);
	maze[temp1.x][temp1.y] = -1;//标志入口位置已到达过
	int ab = 0;
	while (!q.isEmpty())
	{
		ab++;
		q.getTop(temp2);
		p.getTop(temp3);
		//不相等入栈
		if (!((temp3.x) == (temp2.x)) && ((temp3.y) == (temp2.y)))
			p.push(temp2);
		for (loop = 0; loop < 4; loop++)//探索当前位置的4个相邻位置
		{
			x = temp2.x + moveDir[loop][0];//计算出新位置x位置值
			y = temp2.y + moveDir[loop][1];//计算出新位置y位置值
			if (maze[x][y] == 0)//判断新位置是否可达
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
	cout << "请输入起始点的坐标：" << endl;
	cout << "x:";
	cin >> start.x;
	cout << "y:";
	cin >> start.y;

	cout << "请输入终点的坐标：" << endl;
	cout << "x:";
	cin >> end.x;
	cout << "y:";
	cin >> end.y;

	if (start.x >= m || start.y >= m || start.x >= m || start.x >= m)
	{
		cout << "找不到该点！" << endl;
		goto loop;
	}

	if (maze[start.x][start.y]==1|| maze[end.x][end.y]==1)
	{
		cout << "起始点或终点不可走" << endl;
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