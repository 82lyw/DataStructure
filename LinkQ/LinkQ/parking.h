//parking.h 停车场管理 数据结构的定义

class parking
{
public:
	//模拟车辆调度
	//设置停车场可停车辆的最大数目
	void setNum();
	//设置单位时间的收费值
	void setPrice();
	//随机生成停车场的车辆

protected:
	int parking_max;  //停车场最大可停车辆数目
	int parking_num;  //停车场已有停车辆数目
	int price; //单位时间收费值
};

void parking::setNum()
{
	cout << "请输入最多可容纳的车辆数：";
	cin >> parking_max;
	cout << endl;
}

void parking::setPrice()
{
	cout << "请输入停车场单位时间的收费值：";
	cin >> price;
	if (price)
	{
		cout << "已经设置停车场单位时间的收费值为："<<price << endl;
	}
}


