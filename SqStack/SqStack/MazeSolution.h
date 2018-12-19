class MazePoint
{
public:
	int x;
	int y;
	int dir;  //0:无效,1:东,2:南,3:西,4:北
};

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