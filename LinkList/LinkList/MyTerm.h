//MyTerm.h ����ʽ������ݽṹC++�ඨ��

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
	cout << "ϵ����";
	while (!(in >> coef))
		cout << "ϵ������Ϊ�㣬�������룡";
	cout << "\t ָ����";
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