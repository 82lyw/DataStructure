//SqString.h ˳�����ݽṹC++�ඨ�壨���ࣩ

//myhead.h�����Լ��趨��һЩ����������
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

#define random(a,b) (rand()%(b-a+1)+a)

class SqString
{
public:
	//��˳���ÿ�
	void clear();

	//ȡ��i���ַ�
	Status getChar(int i, char& c);

	//��˳�򴮵ĳ���
	int getLength();

	//��˳�򴮵�next����
	void get_next(int* next, int display = 1);

	//��������ƥ�䣨���ݻز��ң�
	int index(SqString p, int pos);

	//ģʽƥ�䣨�л���KMP��������)
	int index_KMP(SqString p, int pos);

	//�ڵ�i���ַ�ǰ������һ��˳��
	Status insert(int i, SqString t);

	//�ж�˳���Ƿ�Ϊ��
	bool isEmpty();

	//���ظ�ֵ������Ķ���SqString˳��=C++String˳��
	SqString operator=(char *s);

	//���ظ�ֵ������Ķ���SqString˳��=SqString˳��
	SqString operator=(const SqString s);

	//���ؼӷ�������Ķ���SqString˳�� + C++String˳��
	SqString operator +(char *s);

	//���ؼӷ�������Ķ���SqString˳�� + SqString˳��
	SqString operator +(SqString s);

	//�����Ƿ�С��������Ķ��� SqString˳��<SqString˳��
	Status operator<(SqString s);

	//�����Ƿ����������Ķ��� SqString˳��==C++String˳��
	int operator==(char *s);

	//�����Ƿ����������Ķ��� SqString˳��==SqString˳��
	int operator==(SqString s);

protected:
	//��C++String˳�򴮸�ֵ����ǰ˳�򴮵ĸ�������
	void strAssign_aux(char *s);

public:
	//ɾ���ӵ�i���ַ��𳤶�Ϊlen���Ӵ�
	Status strDelete(int i, int len);

	//ȡ˳�򴮵��Ӵ�
	Status subString(SqString& sub, int i, int len);

	//˳�򴮹��캯��
	SqString();

	//˳����������
	~SqString();

	//˳�򴮿�����ʼ�����캯������C++Strring˳�򴮳�ʼ����
	SqString(char *s);

	//˳�򴮿�����ʼ�����캯��������һ��SqString˳�򴮳�ʼ����
	SqString(const SqString& s);

	//����˳��
	void read(istream& in);

	//���˳��
	void display(ostream& out) const;

	//��������ַ���
	void RandomStr();

protected:
	int length;
	char *ch;
};

//���ܣ���˳���ÿ�
void SqString::clear()
{
	if (ch)
	{
		delete[]ch;
		ch = NULL;
		length = 0;
	}
}

//���ܣ�ȡ��i���ַ�
Status SqString::getChar(int i, char& c)
{
	if (i<1 || i>length)
		return ERROR;
	c = ch[i - 1];
	return OK;
}

//���ܣ���˳�򴮵ĳ���
int SqString::getLength()
{
	return length;
}

//���ܣ���ģʽ����next����
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
		cout << "��ǰģʽ����next[]����Ϊ��" << endl;
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

//���ܣ���������ƥ�䣨���ݻز��ң�
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

//���ܣ�ģʽƥ�䣨�޻���KMP�������ң�
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

//���ܣ��ڵ�i���ַ�ǰ������һ��˳��
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

//���ܣ��ж�˳���Ƿ�Ϊ��
bool SqString::isEmpty()
{
	return length ? false : true;
}

//���ܣ����ظ�ֵ������Ķ���SqString˳��=C++String˳��
SqString SqString::operator=(char *s)
{
	strAssign_aux(s);
	return *this;
}

//���ܣ����ظ�ֵ������Ķ���SqString˳��=SqString˳��
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

//���ܣ����ظ�ֵ������Ķ���SqString˳��+C++String˳��
SqString SqString::operator +(char *s)
{
	insert(length + 1, s);
	return *this;
}

//���ܣ����ظ�ֵ������Ķ���SqString˳��+SqString˳��
SqString SqString::operator +(SqString rightS)
{
	insert(length + 1, rightS);
	return *this;
}

//���ܣ������Ƿ�С��������Ķ���SqString˳��<SqString˳��
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

//���ܣ������Ƿ����������Ķ���SqString˳��==C++String˳��
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

//���ܣ������Ƿ����������Ķ���SqString˳��==SqString˳��
int SqString::operator==(SqString rightS)
{
	for (int i = 0; i < length&&i < rightS.length; i++)
		if (ch[i] != rightS.ch[i])
			return ch[i] - rightS.ch[i];
	return length - rightS.length;
}

//���ܣ���C++String˳�򴮸�ֵ����ǰ˳�򴮵ĸ�������
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

//���ܣ�ɾ���ӵ�i���ַ��𳤶�Ϊlen���Ӵ�
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

//���ܣ�ȡ˳�򴮵��Ӵ�������sub���ص�ǰ˳�򴮵�i���ַ��𳤶�Ϊlen���Ӵ�
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

//���ܣ�˳�򴮹��캯��
SqString::SqString()
{
	ch = NULL;
	length = 0;
}

//���ܣ�˳����������
SqString::~SqString()
{
	clear();
}

//���ܣ�˳�򴮿�����ʼ�����캯������C++String˳�򴮳�ʼ����
SqString::SqString(char *s)
{
	ch = NULL;
	strAssign_aux(s);
}

//���ܣ�˳�򴮿�����ʼ�����캯��������һ��SqString˳�򴮳�ʼ����
SqString::SqString(const SqString& otherS)
{
	ch = new char[otherS.length];
	assert(ch != 0);
	length = otherS.length;
	for (int i = 0; i < length; ++i)
		ch[i] = otherS.ch[i];
}

//���ܣ�����˳��
void SqString::read(istream& in)
{
	char s[50];
	in >> s;
	strAssign_aux(s);
}

//���ܣ���������������Ķ���
istream& operator>>(istream& in, SqString& s)
{
	s.read(in);
	return in;
}

//���ܣ����˳��
void SqString::display(ostream& out) const
{
	for (int i = 0; i < length; ++i)
		out << ch[i];
	out << endl << endl;
}

//���ܣ��������������Ķ���
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