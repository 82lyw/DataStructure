//parking.h ͣ�������� ���ݽṹ�Ķ���

class parking
{
public:
	//ģ�⳵������
	//����ͣ������ͣ�����������Ŀ
	void setNum();
	//���õ�λʱ����շ�ֵ
	void setPrice();
	//�������ͣ�����ĳ���

protected:
	int parking_max;  //ͣ��������ͣ������Ŀ
	int parking_num;  //ͣ��������ͣ������Ŀ
	int price; //��λʱ���շ�ֵ
};

void parking::setNum()
{
	cout << "�������������ɵĳ�������";
	cin >> parking_max;
	cout << endl;
}

void parking::setPrice()
{
	cout << "������ͣ������λʱ����շ�ֵ��";
	cin >> price;
	if (price)
	{
		cout << "�Ѿ�����ͣ������λʱ����շ�ֵΪ��"<<price << endl;
	}
}


