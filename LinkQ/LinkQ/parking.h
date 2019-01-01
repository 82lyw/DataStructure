//parking.h ͣ�������� ���ݽṹ�Ķ���

class Time
{
public:
	int hour;
	int min;
};
class CarNode
{
public:
	char num[20];
	Time reach;
	Time leave;
};
void enQCar(LinkQueue<CarNode>&Q, CarNode p)
{
	cout << endl << "ͣ������λ���������������ͣ������ͣ���ȴ���" << endl;
	Q.enQueue(p);

}

void PushCar(SqStack<CarNode> &S, CarNode *p)
{
	int S_length = S.getLength();
	S_length++;
	cout << "����ͣ��ͣ������" << S_length << "��λ��" << endl;
loop:
	cout << "���������ʱ��Ϊ[Сʱ(0-23)�ͷ���(0-59)�Կո����]��";
	cin >> p->reach.hour >> p->reach.min;
	while ((p->reach.hour < 0 || p->reach.hour>23) || (p->reach.min < 0 || p->reach.min>59))
	{
		cout << endl << "�������ʱ�䷶Χ��������������!" << endl << endl;
		goto loop;
	}
	CarNode q = *p;
	S.push(q);
	cout << "��������ͣ�����ɹ���" << endl;
}
void InCar(SqStack<CarNode> &S, LinkQueue<CarNode>&Q,int parking_num)
{
	CarNode *p;
	p = new(CarNode);
	assert(p != 0);
	cout << "�����뵽�������ĳ��ƺţ�";
	cin >> p->num;
	int S_length = S.getLength();
	if (S_length < parking_num)
	{
		PushCar(S, p);
	}
	else
	{
		CarNode q = *p;
		enQCar(Q, q);
	}

}

void PayPrice(CarNode p, int Location, int Price)
{
	cout << "(2) ����ͣ����2��λ���ϳ��ƺ�Ϊ��" << p.num << "�ĳ����뿪��" << endl;
loop:
	cout << "�����������뿪��ʱ��[Сʱ(0-23)�ͷ���(0-59)�Կո����]��";
	cin >> p.leave.hour >> p.leave.min;
	while ((p.leave.hour < 0 || p.leave.hour>23) || (p.leave.min < 0 || p.leave.min>59))
	{
		cout << "�������ʱ�䷶Χ��������������!" << endl;
		goto loop;
	}
	cout << "�����������ʱ��Ϊ��";
	cout << p.reach.hour << ":" << p.reach.min << endl;
	cout << "�������뿪��ʱ��Ϊ��";
	cout << p.leave.hour << ":" << p.leave.min << endl;
	cout << "Ӧ����ͣ���ѣ�<��λ��Ԫ>";
	if ((p.leave.hour < p.reach.hour) || ((p.leave.hour == p.reach.hour) && (p.leave.min < p.reach.min)))
		cout << fixed << setprecision(2) << ((23 - p.reach.hour + p.leave.hour) * 60 + (60 - p.reach.min + p.leave.min))*Price << endl;
	else
		cout << fixed << setprecision(2) << ((p.leave.hour - p.reach.hour) * 60 + (p.leave.min - p.reach.min))*Price << endl;
}

void OutCar(SqStack<CarNode> &S, SqStack<CarNode> & Temp, LinkQueue<CarNode> &Q,int parking_num,int price)
{
	int Location;
	CarNode *p, q;
	if (S.getLength() > 0)
	{
	loop:
		cout << "������������ͣ������λ��<1-" << parking_num << ">��";
		cin >> Location;
		if (Location<1 || Location>S.getLength())
		{
			cout << "ͣ�����ó�λ��δͣ��������������!" << endl;
			goto loop;
		}

		cout << "(1) ���г��ƺŵĳ������˳�ͣ������·��" << endl;
		CarNode m;
		while (S.getLength() > Location)
		{
			S.pop(m);
			cout << "\t" << m.num<<endl;
			Temp.push(m);
		}
		S.pop(m);
		PayPrice(m, Location, price);
		while (Temp.getLength() >= 1)
		{
			cout << "(3) ��ǰ�˳��ĳ����ٽ�ͣ������" << endl;
			Temp.pop(m);
			S.push(m);
		}

		if (!Q.isEmpty() && S.getLength() < parking_num)
		{
			Q.deQueue(q);
			cout << "(4) ���⳵�ƺ�"<<q.num<<"�ĳ������ڽ�ͣ������" << endl;
			CarNode *s = &q;
			PushCar(S, s);
		}
		else
		{
			cout << "(4) ͣ������û��������" << endl<<endl<<endl;
		}
	}
	else
		cout << "ͣ������û������������ȥ��" << endl;
}

void displayStack(SqStack<CarNode> S)
{
	cout << "ͣ������ͣ��������Ϣ��" << endl;
	if (S.isEmpty())
		cout << "ͣ����û�г���" << endl;
	else
	{
		cout << "\t\t\t ���ƺ�    ����ʱ��" << endl;
		int i;
		int length = S.getLength();
		for (i = 0; i < length; i++)
		{
			if (i == 0)
				cout << "\t base->";
			else if (i == length - 1)
				cout << "\t top->";
			else
				cout << "\t";
			cout << i;
			cout << "\t" << (*(S.base + i)).num << "\t   " << (*(S.base + i)).reach.hour << ":" << (*(S.base + i)).reach.min << endl;
		}
		cout << endl;
	}
	cout << endl;
}

void displayQueue(LinkQueue<CarNode> Q)
{
	LinkQueue<CarNode>::NodePointer t = Q.front;
	cout << "ͣ�����⳵���������" << endl;
	if (!Q.front)
	{
		cout << "ͣ�������޺򳵣�" << endl;
		return;
	}
	else if (Q.getLength() == 1)
	{
		cout << "\t front/rear->" << "\t" << t->data.num;
	}
	else
	{
		while (t != Q.rear)
		{
			if (t == Q.front)
			{
				cout << "\t front->" << t->data.num<<endl;
			}
			else
			{
				cout << "\t" << t->data.num<<endl;
			}
			t = t->next;
		}
		if (t == Q.rear)
		{
			cout << "\t rear->" << t->data.num<<endl;
		}
	}
	cout << endl;
}

void setNum(int & parking_max)
{
	cout << "�������������ɵĳ�������";
	cin >> parking_max;
	cout << endl;
}

void setPrice(int & price)
{
	cout << "������ͣ������λʱ����շ�ֵ��";
	cin >> price;
	if (price)
	{
		cout << "�Ѿ�����ͣ������λʱ����շ�ֵΪ��"<<price << endl;
	}
}