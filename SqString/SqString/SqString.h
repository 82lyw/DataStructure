//SqString.h 顺序串数据结构C++类定义（基类）

//myhead.h包含自己设定的一些常量和类型
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

#define random(a,b) (rand()%(b-a+1)+a)

class SqString
{
public:
	//把顺序串置空
	void clear();

	//取第i个字符
	Status getChar(int i, char& c);

	//求顺序串的长度
	int getLength();

	//求顺序串的next数组
	void get_next(int* next, int display = 1);

	//串的朴素匹配（有溯回查找）
	int index(SqString p, int pos);

	//模式匹配（有回溯KMP方法查找)
	int index_KMP(SqString p, int pos);

	//在第i个字符前插入另一个顺序串
	Status insert(int i, SqString t);

	//判断顺序串是否为空
	bool isEmpty();

	//重载赋值运算符的定义SqString顺序串=C++String顺序串
	SqString operator=(char *s);

	//重载赋值运算符的定义SqString顺序串=SqString顺序串
	SqString operator=(const SqString s);

	//重载加法运算符的定义SqString顺序串 + C++String顺序串
	SqString operator +(char *s);

	//重载加法运算符的定义SqString顺序串 + SqString顺序串
	SqString operator +(SqString s);

	//重载是否小于运算符的定义 SqString顺序串<SqString顺序串
	Status operator<(SqString s);

	//重载是否相等运算符的定义 SqString顺序串==C++String顺序串
	int operator==(char *s);

	//重载是否相等运算符的定义 SqString顺序串==SqString顺序串
	int operator==(SqString s);

protected:
	//把C++String顺序串赋值给当前顺序串的辅助函数
	void strAssign_aux(char *s);

public:
	//删除从第i个字符起长度为len的子串
	Status strDelete(int i, int len);

	//取顺序串的子串
	Status subString(SqString& sub, int i, int len);

	//顺序串构造函数
	SqString();

	//顺序串析构函数
	~SqString();

	//顺序串拷贝初始化构造函数（用C++Strring顺序串初始化）
	SqString(char *s);

	//顺序串拷贝初始化构造函数（用另一个SqString顺序串初始化）
	SqString(const SqString& s);

	//输入顺序串
	void read(istream& in);

	//输出顺序串
	void display(ostream& out) const;

	//随机生成字符串
	void RandomStr();

protected:
	int length;
	char *ch;
};

//功能：把顺序串置空
void SqString::clear()
{
	if (ch)
	{
		delete[]ch;
		ch = NULL;
		length = 0;
	}
}

//功能：取第i个字符
Status SqString::getChar(int i, char& c)
{
	if (i<1 || i>length)
		return ERROR;
	c = ch[i - 1];
	return OK;
}

//功能：求顺序串的长度
int SqString::getLength()
{
	return length;
}

//功能：求模式串的next数组
void SqString::get_next(int* next, int display)
{
	int j = -1, i = 0;
	int first_i;
	char no[5] = "[i]";
	next[0] = -1;
	while (i < length)
	{
		if (j == -1 || ch[j] == ch[i])
		{
			++j;
			++i;
			next[i] = j;
		}
		else
			j = next[j];
	}
	if (display == 1)
	{
		cout << "当前模式串的next[]数组为：" << endl;
		first_i = 0;
		while (first_i < length)
		{
			i = first_i;
			cout << "   ";
			do
			{
				if (i < 10)
					no[2] = i + '0';
				else
				{
					no[1] = i / 10 + '0';
					no[2] = i % 10 + '0';
				}
				cout.width(5);
				cout.fill(' ');
				cout.setf(ios::right, ios::adjustfield);
				cout << no;
				++i;
			} while (i % 10 && i < length);
			cout << endl;
			cout << "   ";
			i = first_i;
			do
			{
				cout.width(5);
				cout.fill(' ');
				cout.setf(ios::right, ios::adjustfield);
				cout << ch[i];
				++i;
			} while (i % 10 && i < length);
			cout << endl;

			cout << "   ";
			i = first_i;
			do
			{
				cout.width(5);
				cout.fill(' ');
				cout.setf(ios::right, ios::adjustfield);
				cout << next[i];
				++i;
			} while (i % 10 && i < length);
			first_i = i;
			cout << endl << endl;
		}
	}
}

//功能：串的朴素匹配（有溯回查找）
int SqString::index(SqString p, int pos)
{
	int i = pos - 1;
	int j = 0;
	while (i < length&&j < p.length)
	{
		if (ch[i] == p.ch[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == p.length)
		return i - p.length + 1;
	else
		return 0;
}

//功能：模式匹配（无回溯KMP方法查找）
int SqString::index_KMP(SqString p, int pos)
{
	int i = pos - 1;
	int j = -1;
	int *next;
	next = new int[p.length];
	assert(next != 0);
	p.get_next(next, 0);
	while (i < length&&j < p.length)
	{
		if (j == -1 || ch[i] == p.ch[j])
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if (j == p.length)
		return i - p.length + 1;
	else
		return 0;
}

//功能：在第i个字符前插入另一个顺序串
Status SqString::insert(int i, SqString t)
{
	char *temp;
	if (i<1 || i>length + 1 || t.isEmpty())
		return ERROR;
	temp = new char[length + t.length];
	assert(temp != 0);
	int j;
	for (j = 0; j < i - 1; j++)
		temp[j] = ch[j];
	for (; j < i - 1 + t.length; j++)
		temp[j] = t.ch[j - i + 1];
	for (; j < length + t.length; j++)
		temp[j] = ch[j - t.length];
	delete[]ch;
	ch = temp;
	length += t.length;
	return OK;
}

//功能：判断顺序串是否为空
bool SqString::isEmpty()
{
	return length ? false : true;
}

//功能：重载赋值运算符的定义SqString顺序串=C++String顺序串
SqString SqString::operator=(char *s)
{
	strAssign_aux(s);
	return *this;
}

//功能：重载赋值运算符的定义SqString顺序串=SqString顺序串
SqString SqString::operator=(SqString rightS)
{
	if (this != &rightS)
	{
		clear();
		ch = new char[rightS.length];
		assert(ch != 0);
		length = rightS.length;
		for (int i = 0; i < length; ++i)
			ch[i] = rightS.ch[i];
	}
	return *this;
}

//功能：重载赋值运算符的定义SqString顺序串+C++String顺序串
SqString SqString::operator +(char *s)
{
	insert(length + 1, s);
	return *this;
}

//功能：重载赋值运算符的定义SqString顺序串+SqString顺序串
SqString SqString::operator +(SqString rightS)
{
	insert(length + 1, rightS);
	return *this;
}

//功能：重载是否小于运算符的定义SqString顺序串<SqString顺序串
Status SqString::operator<(SqString rightS)
{
	for (int i = 0; i < length&&i < rightS.length; ++i)
	{
		if (ch[i] < rightS.ch[i])
			return true;
		else
			return false;
	}
}

//功能：重载是否相等运算符的定义SqString顺序串==C++String顺序串
int SqString::operator==(char*s)
{
	int s_length;
	int i;
	for (i = 0; s[i]; ++i)
		s_length = i;
	for (i = 0; i < length&&i < s_length; ++i)
		if (ch[i] != s[i])
			return ch[i] - s[i];
	return length - s_length;
}

//功能：重载是否相等运算符的定义SqString顺序串==SqString顺序串
int SqString::operator==(SqString rightS)
{
	for (int i = 0; i < length&&i < rightS.length; i++)
		if (ch[i] != rightS.ch[i])
			return ch[i] - rightS.ch[i];
	return length - rightS.length;
}

//功能：把C++String顺序串赋值给当前顺序串的辅助函数
void SqString::strAssign_aux(char *s)
{
	clear();
	int i;
	for (i = 0; s[i]; ++i)
		length = i+1;
	ch = new char[length];
	assert(ch != 0);
	for (i = 0; i < length; ++i)
		ch[i] = s[i];
}

//功能：删除从第i个字符起长度为len的子串
Status SqString::strDelete(int i, int len)
{
	char *temp;
	if (i<1 || i>length + 1)
		return ERROR;
	temp = new char[length - len];
	assert(temp != 0);
	int j;
	for (j = 0; j < i - 1; ++j)
		temp[j] = ch[j];
	for (j = i - 1 + len; j < length; ++j)
		temp[j - len] = ch[j];
	delete[] ch;
	ch = temp;
	length -= len;
	return OK;
}

//功能：取顺序串的子串，即用sub返回当前顺序串第i个字符起长度为len的子串
Status SqString::subString(SqString& sub, int i, int len)
{
	if (i<1 || i>length || len<0 || len>length - i + 1)
		return ERROR;
	sub.clear();
	sub.ch = new char[len];
	assert(sub.ch != 0);
	for (int j = 0; j < len; ++j)
		sub.ch[j] = ch[i - 1 + j];
	sub.length = len;
	return OK;
}

//功能：顺序串构造函数
SqString::SqString()
{
	ch = NULL;
	length = 0;
}

//功能：顺序串析构函数
SqString::~SqString()
{
	clear();
}

//功能：顺序串拷贝初始化构造函数（用C++String顺序串初始化）
SqString::SqString(char *s)
{
	ch = NULL;
	strAssign_aux(s);
}

//功能：顺序串拷贝初始化构造函数（用另一个SqString顺序串初始化）
SqString::SqString(const SqString& otherS)
{
	ch = new char[otherS.length];
	assert(ch != 0);
	length = otherS.length;
	for (int i = 0; i < length; ++i)
		ch[i] = otherS.ch[i];
}

//功能：输入顺序串
void SqString::read(istream& in)
{
	char s[50];
	in >> s;
	strAssign_aux(s);
}

//功能：重载输入运算符的定义
istream& operator>>(istream& in, SqString& s)
{
	s.read(in);
	return in;
}

//功能：输出顺序串
void SqString::display(ostream& out) const
{
	for (int i = 0; i < length; ++i)
		out << ch[i];
	out << endl << endl;
}

//功能：重载输出运算符的定义
ostream& operator<<(ostream& out, const SqString& s)
{
	s.display(out);
	return out;
}

void SqString::RandomStr()
{
	int n = random(5, 20);
	//cout << n << endl;
	char *s = new char[n];
	for (int i = 0; i < n-1; i++)
	{
		//s[i] = random(97, 122) + 'a';
		s[i] = 'a' + rand ()% 26;
	}
	strAssign_aux(s);
}