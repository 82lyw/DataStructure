// ExampleClass.h���������ݽṹC++��������ʵ�֣����ࣩ
template <typename ElemType>
class Rectangle
{
public:
	class RectangleNo
	{
	public:
		//��ų����ε����
		int no;
	};

	//���ظ�ֵ������Ķ���
	Rectangle operator = (Rectangle rightR);

	//���ó����εĳ�
	void setLength(ElemType l);

	//���ó����ε����
	void setNo(int i);

	//���캯��
	Rectangle();

	//������ʼ�����캯��
	Rectangle(const Rectangle <ElemType> & otherD);

	//��������
	~Rectangle();

protected:
	ElemType length;  //��
	ElemType width;  //��
	RectangleNo myNo;  //���
};

//���������ݽṹC++��ʵ�֣����ࣩ
template <typename ElemType>
Rectangle<ElemType> Rectangle<ElemType>::operator = (Rectangle<ElemType> rightR)
{
	//�ж���߳������Ƿ����rightR
	if (this != &rightR)
	{
		length = rightR.length;
		width = rightR.width;
		myNo = rightR.myNo;
		cout << "��ֵ�󣬵�ǰ�ĳ�����Ϊ��" << length << "��" << width << "��" << endl;
	}
	//�����ķ���ֵ ������ߵĳ�����
	return *this;
}

//���ܣ����ó����εĳ�
//���룺������ֵ����lΪ�����õĳ�
template <typename ElemType>
void Rectangle<ElemType>::setLength(ElemType l)
{
	length = l;
}

//���ܣ����ó����ε����
//���룺������ֵ����iΪ�����õ����
template <typename ElemType>
void Rectangle<ElemType>::setNo(int i)
{
	myNo.no = i;
}

//���ܣ������ι��캯��
//˵�������캯��һ���ʼ��һ���ն���
template <typename ElemType>
Rectangle<ElemType>::Rectangle()
{
	length = width = 0;
	cout << "�Զ����ù��캯��" << endl;
}

//���ܣ�������ʼ�����캯��
//���룺�����Ĳ���otherD���ڿ�����ʼ���ĳ�����
template <typename ElemType>
Rectangle<ElemType>::Rectangle(const Rectangle<ElemType>&otherD)
{
	length = otherD.length;
	width = otherD.width;
	myNo.no = otherD.myNo.no;
	cout << "�Զ����ÿ�����ʼ�����캯����ʼ��Ϊ ��" << length << "��" << width << "��" << endl;
}

//���ܣ���������
//˵���������������ڽ���ʱ��ϵͳ�Զ����øö������������������
template <typename ElemType>
Rectangle<ElemType>::~Rectangle()
{
	cout << "��" << myNo.no << "�������ζ��� ��" << length << "��" << width << "��" << endl;
}
