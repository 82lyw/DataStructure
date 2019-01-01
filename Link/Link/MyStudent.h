// 学生表 数据结构C++类声明和实现（派生类）

class student
{
public:
	void read(istream& in);
	void display(ostream& out) const;
public:
	double student_id;		//学号
	string name;		//姓名
	float score[3];    //三科的成绩
	float total;       //总分
	float average;         //平均分
};

void student::read(istream& in)
{
	cout << "学号:";
	cin >> student_id;
	cout << "姓名:";
	cin >> name;
	cout << "语文成绩:";
	cin >> score[0];
	cout << "数学成绩:";
	cin >> score[1];
	cout << "英语成绩:";
	cin >> score[2];
	total = score[0] + score[1] + score[2];
	average = total / 3.0f;
}

istream& operator>>(istream& in, student& id)
{
	id.read(in);
	return in;
}

void student::display(ostream& out) const
{
	cout << student_id << "\t" << name << "\t" << score[0] << "\t" 
		<< score[1] << "\t" << score[2] << "\t" << total << "\t" << average << endl;
}

ostream& operator<<(ostream& out, student& od)
{
	od.display(out);
	return out;
}


template <typename ElemType>
class MyStudent :public SqList<ElemType>
{
public:
	bool prior_stu(string e, ElemType& prior_e);
	bool next_stu(string e, ElemType& next_e);
	void randStudent();
	void read(istream& in);
	void display(ostream& out) const;
};


template <typename ElemType>
bool MyStudent<ElemType>::prior_stu(string e, ElemType& prior_e)
{
	int i;
	for (i = 0; i < this->n&&this->elem[i].name != e; i++);
	if (i < 1 || i >= this->n)
		return false;
	else
	{
		prior_e.student_id = this->elem[i - 1].student_id;
		prior_e.name = this->elem[i - 1].name;
		prior_e.score[0] = this->elem[i - 1].score[0];
		prior_e.score[1] = this->elem[i - 1].score[1];
		prior_e.score[2] = this->elem[i - 1].score[2];
		prior_e.total = this->elem[i - 1].total;
		prior_e.average = this->elem[i - 1].average;
		return true;
	}
}

template <typename ElemType>
bool MyStudent<ElemType>::next_stu(string e, ElemType& next_e)
{
	int i;
	for (i = 0; i < this->n&&this->elem[i].name != e; i++);
	if (i < 0 || (i == this->n-1))
		return false;
	else
	{
		next_e.student_id = this->elem[i + 1].student_id;
		next_e.name = this->elem[i + 1].name;
		next_e.score[0] = this->elem[i + 1].score[0];
		next_e.score[1] = this->elem[i + 1].score[1];
		next_e.score[2] = this->elem[i + 1].score[2];
		next_e.total = this->elem[i + 1].total;
		next_e.average = this->elem[i + 1].average;
		return true;
	}
}

template <typename ElemType>
void MyStudent<ElemType>::randStudent()
{
	typename SqList<ElemType>::clear();
	this->elem = new ElemType[LIST_MAX_SIZE];
	assert(this->elem != 0);
	this->n = random(2, 8);
	string all_student[10] = { "张三","李四","王五","小六","小二","猴儿","王惠","赵启","刘星","林八" };
	cout << "依次生成学生表，有" << this->n << "个学生：" << endl;
	for (int i = 0; i < this->n; i++)
	{
		this->elem[i].student_id = random(1, 999);
		this->elem[i].name = all_student[random(0, 9)];
		this->elem[i].score[0] = random(0, 99);
		this->elem[i].score[1] = random(0, 99);
		this->elem[i].score[2] = random(0, 99);
		this->elem[i].total = this->elem[i].score[0] + this->elem[i].score[1] + this->elem[i].score[2];
		this->elem[i].average = this->elem[i].total / 3.0f;
	}
}

template <typename ElemType>
void MyStudent<ElemType>::read(istream& in)
{
	delete[] this->elem;
	this->n = 0;
	this->elem = new ElemType[LIST_MAX_SIZE];
	int j;
	assert(this->elem != 0);
	cout << "请输入学生个数：";
	in >> j;
	for (int i = 0; i < j; i++)
	{
		cout << "请输入第" << i + 1 << "个学生信息：" << endl;
		in >> this->elem[i];
		this->n=i+1;

		system("cls");
		cout << endl;
		cout << *this;
		cout << "***********************************************************" << endl << endl;
	}
}

template <typename ElemType>
istream& operator>>(istream& in, MyStudent<ElemType>& id)
{
	id.read(in);
	return in;
}

template <typename ElemType>
void MyStudent<ElemType>::display(ostream& out) const
{
	if (this->n <= 0)
	{
		cout << "当前学生信息表为空！" << endl << endl;
		return;
	}
	cout << "学号\t姓名\t语文\t数学\t英语\t总分\t平均分" << endl;
	for (int i = 0; i < this->n; ++i)
		out << this->elem[i];
}

template <typename ElemType>
ostream& operator<<(ostream& out, MyStudent<ElemType>& od)
{
	od.display(out);
	return out;
}