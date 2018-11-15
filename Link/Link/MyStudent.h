// ѧ���� ���ݽṹC++��������ʵ�֣������ࣩ

// sqlist.h���ݽṹC++��������ʵ�֣����ࣩ

#define STUDENT_MAX_SIZE 100
#define STUDENTINCREMENT 10
#define random(a,b) (rand()%(b-a+1)+a)

template <typename ElemType>
class MyStudent //:public SqList<ElemType>
{
public:
	class studentNode
	{
	public:
		double student_id;
		string name;
		ElemType Chinese;
		ElemType English;
		ElemType Math;
		float average;
		ElemType Total;
	};

	//���ѧ����
	void RandomStudents();

	
	void readS();

	void displayS();

	MyStudent<ElemType> operator = (MyStudent<ElemType> rightS);
	
	void getAve();

	void getTotal();


	//////////
	void clear();

	//ɾ����i��Ԫ��
	Status deleteStu(int i, studentNode & s);

	//ȡ��i��Ԫ��
	Status getStu(int i, studentNode & s);

	//ȡ˳���洢�ռ�ĸ���
	int getLength();

	//ȡ˳���洢�ռ�Ĵ�С
	int getStuSize();

	//�ڵ�i��Ԫ��֮ǰ����һ��Ԫ��
	Status insertS(int i, studentNode & s);

	//�ж�˳����Ƿ�Ϊ��
	bool isEmpty();

	//���ҵ�i����e����compare()��ϵ�����
	//int locateStu(string s_name, Status(*compare)(string, string));
	int locateStu(string s_name);

	//����ĳԪ�صĺ��
	Status nextStu(string s_name, studentNode & next_s);

	//����ĳԪ�ص�ǰ��
	Status priorStu(string s_name, studentNode & prior_s);

	//��˳�����˳�����ĳԪ��
	//int sequentialSearch(ElemType e);

	//////////

	MyStudent();

	~MyStudent();

	MyStudent(const MyStudent<ElemType>& otherL);

protected:
	studentNode *studentElem;
	int studentSize;  //��ǰ�洢�ռ�Ĵ�С
	int length;  //ѧ����ǰ�ĸ���
};

template<typename ElemType>
void MyStudent<ElemType>::RandomStudents()
{
	char ch[10][10] = { "Сһ","С��","С��","С��","С��","С��","С��","С��","С��","Сʮ" };
	studentElem = new studentNode[1000];
	length = 0;
	int n = random(2, 9);
	for (int i = 0; i < n; i++)
	{
		int j = random(1, 10);
		studentElem[i].student_id = i;
		studentElem[i].name = ch[j];
		studentElem[i].Chinese = random(50, 99);
		studentElem[i].Math = random(50, 99);
		studentElem[i].English = random(50, 99);
	}
	length = n;

}

template<typename ElemType>
void MyStudent<ElemType>::readS()
{
	studentElem = new studentNode[1000];
	length = 0;
	int n;
	cout << "������ѧ�����е�ѧ��������";
	cin >> n;
		for (int i = 0; i <n; i++)
		{
			cout << "������ѧ�����"<<i+1<<"��ѧ������Ϣ" << endl;
			cout << "\tѧ�ţ�";
			cin >> studentElem[i].student_id;
			cout << "\t������";
			cin >> studentElem[i].name;
			cout << "\t���ģ�";
			cin >> studentElem[i].Chinese;
			cout << "\tӢ�";
			cin >> studentElem[i].English;
			cout << "\t��ѧ��";
			cin >> studentElem[i].Math;

			length=i+1;

			system("cls");
			displayS();
			cout << "***********************************************************" << endl << endl;
		}

	cout << endl;
}


template<typename ElemType>
void MyStudent<ElemType>::displayS()
{
	getAve();
	int i;
	if (length != 0)
	{
		cout << "��ǰѧ��������˳���洢����" << length << "��ѧ��" << endl << endl;
		cout << "ѧ��\t" << "����\t" << "����\t" << "Ӣ��\t" << "��ѧ\t" << "ƽ����\t" << "�ܷ�" << endl;
		for (i = 0; i < length; i++)
		{
			//cout << studentElem[i].student_id;
			cout << studentElem[i].student_id << "\t" << studentElem[i].name << "\t" << studentElem[i].Chinese << "\t" << studentElem[i].English << "\t" << studentElem[i].Math << "\t" << studentElem[i].average << "\t" << studentElem[i].Total << endl;
		}
	}
	else
	{
		cout << "��ǰѧ����Ϊ��";
	}
	cout << endl << endl;
}

template<typename ElemType>
MyStudent<ElemType> MyStudent<ElemType>::operator = (MyStudent<ElemType> rightS)
{
	if (this != &rightS)
	{
		if (studentSize < rightS.studentSize)
		{
			delete[] studentElem;
			studentElem = new studentNode[rightS.studentSize];
			assert(studentElem != 0);
			studentSize = rightS.studentSize;
		}
		length = rightS.length;
		for (int i = 1; i <= length; ++i)
			studentElem[i - 1] = rightS.studentElem[i - 1];
	}
	return *this;
}

template<typename ElemType>
void MyStudent<ElemType>::getAve()
{
	getTotal();
	for (int i = 0; i < length; i++)
	{
		studentElem[i].average=studentElem[i].Total/3;
	}
}

template<typename ElemType>
void MyStudent<ElemType>::getTotal() 
{
	for (int i = 0; i < length; i++)
	{
		studentElem[i].Total = studentElem[i].Chinese + studentElem[i].Math + studentElem[i].English;
	}
}


//////////////////////
template<typename ElemType>
void MyStudent<ElemType>::clear()
{
	length = 0;
}

template<typename ElemType>
Status MyStudent<ElemType>::deleteStu(int i, studentNode & s)
{
	if (i<1 || i>length) return ERROR;
	s = studentElem[i - 1];
	for (int j = i + 1; j <= length; ++j)
	{
		studentElem[j - 2] = studentElem[j - 1];
	}
	--length;
	return OK;
}

template<typename ElemType>
Status MyStudent<ElemType>::getStu(int i, studentNode & s)
{
	if (i<1 || i>length) return ERROR;
	s = studentElem[i - 1];
	return OK;
}

template<typename ElemType>
int MyStudent<ElemType>::getLength()
{
	return length;
}

template<typename ElemType>
int MyStudent<ElemType>::getStuSize()
{
	return studentSize;
}

template<typename ElemType>
Status MyStudent<ElemType>::insertS(int i, studentNode & s)
{
	studentNode *newbase;
	if (i<1 || i>length + 1) return ERROR;
	if (length >= studentSize)
	{
		newbase = new studentNode[studentSize + STUDENTINCREMENT];
		assert(newbase != 0);
		for (int j = 1; j <= length; ++j)
		{
			newbase[j - 1] = studentElem[j - 1];
		}
		delete[] studentElem;
		studentElem = newbase;
		studentSize += STUDENTINCREMENT;
	}
	for (int j = length; j >= i; --j)
	{
		studentElem[j] = studentElem[j - 1];
	}
	studentElem[i - 1] = s;
	++length;
	return OK;
}

template<typename ElemType>
bool MyStudent<ElemType>::isEmpty()
{
	return length ? false : true;
}

template<typename ElemType>
int MyStudent<ElemType>::locateStu(string s_name)
{
	int i;
	for (i = 1; (studentElem[i-1].name == s_name)!=1; i++);
	if (i <= length)
	{
		cout << i;
		return i;
	}
	else
		return 0;
}

template<typename ElemType>
Status MyStudent<ElemType>::nextStu(string s_name, studentNode & next_s)
{
	int i = locateStu(s_name);
	if (i < 1 || i == length)
		return ERROR;
	else
		getStu(i + 1, next_s);
	return OK;
}

template<typename ElemType>
Status MyStudent<ElemType>::priorStu(string s_name, studentNode & prior_s)
{
	int i = locateStu(s_name);
	if (i <= 1)
		return ERROR;
	else
		getStu(i - 1, prior_s);
	return OK;
}

/*
template<typename ElemType>
int SqList<ElemType>::sequentialSearch(ElemType key)
{
	int i;
	for (i = 1; i < n&&key != studentElem[i - 1]; ++1);
	if (i <= n)
		return i;
	else
		return 0;
}
*/


template<typename ElemType>
MyStudent<ElemType>::MyStudent()
{
	studentElem = new studentNode[STUDENT_MAX_SIZE];
	assert(studentElem != 0);
	studentSize = STUDENT_MAX_SIZE;
	length = 0;
}

template<typename ElemType>
MyStudent<ElemType>::MyStudent(const MyStudent<ElemType> & otherS)
{
	studentElem = new studentNode[otherS.studentSize];
	assert(studentElem != 0);
	studentSize = otherS.studentSize;
	length = otherS.length;

	for (int i = 1; i <= length; ++i)
	{
		studentElem[i - 1] = otherS.studentElem[i - 1];
	}
}

template <typename ElemType>
MyStudent<ElemType>::~MyStudent()
{
	delete[] studentElem;
}