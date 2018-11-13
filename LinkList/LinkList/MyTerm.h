//MyTerm.h 多项式项的数据结构C++类定义

class MyTerm
{
public:

	void read(istream & in);

	void display(ostream & out);

public:
	float coef;
	int expn;
};

void MyTerm::read(istream & in)
{
	cout << "系数：";
	while (!(in >> coef))
		cout << "系数不能为零，重新输入！";
	cout << "\t 指数：";
	in >> expn;
	cout << endl;
}

istream & operator>>(istream & in, MyTerm & s)
{
	s.read(in);
	return in;
}

void MyTerm::display(ostream & out)
{
	if (coef != 1)
		out << coef;
	if (expn)
		out << "x" << expn;
}