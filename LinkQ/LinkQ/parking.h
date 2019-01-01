//parking.h 停车场管理 数据结构的定义

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
	cout << endl << "停车场车位已满，请该汽车在停车场外停靠等待！" << endl;
	Q.enQueue(p);

}

void PushCar(SqStack<CarNode> &S, CarNode *p)
{
	int S_length = S.getLength();
	S_length++;
	cout << "汽车停在停车场第" << S_length << "个位置" << endl;
loop:
	cout << "汽车到达的时间为[小时(0-23)和分钟(0-59)以空格隔开]：";
	cin >> p->reach.hour >> p->reach.min;
	while ((p->reach.hour < 0 || p->reach.hour>23) || (p->reach.min < 0 || p->reach.min>59))
	{
		cout << endl << "你的输入时间范围有误，请重新输入!" << endl << endl;
		goto loop;
	}
	CarNode q = *p;
	S.push(q);
	cout << "汽车进入停车场成功！" << endl;
}
void InCar(SqStack<CarNode> &S, LinkQueue<CarNode>&Q,int parking_num)
{
	CarNode *p;
	p = new(CarNode);
	assert(p != 0);
	cout << "请输入到达汽车的车牌号：";
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
	cout << "(2) 场内停放在2号位置上车牌号为：" << p.num << "的车辆离开。" << endl;
loop:
	cout << "请输入汽车离开的时间[小时(0-23)和分钟(0-59)以空格隔开]：";
	cin >> p.leave.hour >> p.leave.min;
	while ((p.leave.hour < 0 || p.leave.hour>23) || (p.leave.min < 0 || p.leave.min>59))
	{
		cout << "你的输入时间范围有误，请重新输入!" << endl;
		goto loop;
	}
	cout << "该汽车到达的时间为：";
	cout << p.reach.hour << ":" << p.reach.min << endl;
	cout << "该汽车离开的时间为：";
	cout << p.leave.hour << ":" << p.leave.min << endl;
	cout << "应缴纳停车费：<单位：元>";
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
		cout << "请输入汽车在停车场的位置<1-" << parking_num << ">：";
		cin >> Location;
		if (Location<1 || Location>S.getLength())
		{
			cout << "停车场该车位还未停车，请重新输入!" << endl;
			goto loop;
		}

		cout << "(1) 下列车牌号的车辆先退出停车场让路：" << endl;
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
			cout << "(3) 先前退出的车辆再进停车场。" << endl;
			Temp.pop(m);
			S.push(m);
		}

		if (!Q.isEmpty() && S.getLength() < parking_num)
		{
			Q.deQueue(q);
			cout << "(4) 场外车牌号"<<q.num<<"的车辆现在进停车场。" << endl;
			CarNode *s = &q;
			PushCar(S, s);
		}
		else
		{
			cout << "(4) 停车场外没有汽车！" << endl<<endl<<endl;
		}
	}
	else
		cout << "停车场内没有汽车可以离去！" << endl;
}

void displayStack(SqStack<CarNode> S)
{
	cout << "停车场内停车车辆信息：" << endl;
	if (S.isEmpty())
		cout << "停车场没有车！" << endl;
	else
	{
		cout << "\t\t\t 车牌号    进入时间" << endl;
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
	cout << "停车场外车辆候车情况：" << endl;
	if (!Q.front)
	{
		cout << "停车场外无候车！" << endl;
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
	cout << "请输入最多可容纳的车辆数：";
	cin >> parking_max;
	cout << endl;
}

void setPrice(int & price)
{
	cout << "请输入停车场单位时间的收费值：";
	cin >> price;
	if (price)
	{
		cout << "已经设置停车场单位时间的收费值为："<<price << endl;
	}
}