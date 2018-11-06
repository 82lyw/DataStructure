// ExampleClass.h长方形数据结构C++类声明和实现（基类）
template <typename ElemType>
class Rectangle
{
public:
	class RectangleNo
	{
	public:
		//存放长方形的序号
		int no;
	};

	//重载赋值运算符的定义
	Rectangle operator = (Rectangle rightR);

	//设置长方形的长
	void setLength(ElemType l);

	//设置长方形的序号
	void setNo(int i);

	//构造函数
	Rectangle();

	//拷贝初始化构造函数
	Rectangle(const Rectangle <ElemType> & otherD);

	//析构函数
	~Rectangle();

protected:
	ElemType length;  //长
	ElemType width;  //宽
	RectangleNo myNo;  //序号
};

//长方形数据结构C++类实现（基类）
template <typename ElemType>
Rectangle<ElemType> Rectangle<ElemType>::operator = (Rectangle<ElemType> rightR)
{
	//判断左边长方形是否等于rightR
	if (this != &rightR)
	{
		length = rightR.length;
		width = rightR.width;
		myNo = rightR.myNo;
		cout << "赋值后，当前的长方形为（" << length << "，" << width << "）" << endl;
	}
	//函数的返回值 返回左边的长方形
	return *this;
}

//功能：设置长方形的长
//输入：函数的值参数l为待设置的长
template <typename ElemType>
void Rectangle<ElemType>::setLength(ElemType l)
{
	length = l;
}

//功能：设置长方形的序号
//输入：函数的值参数i为待设置的序号
template <typename ElemType>
void Rectangle<ElemType>::setNo(int i)
{
	myNo.no = i;
}

//功能：长方形构造函数
//说明：构造函数一般初始化一个空对象
template <typename ElemType>
Rectangle<ElemType>::Rectangle()
{
	length = width = 0;
	cout << "自动调用构造函数" << endl;
}

//功能：拷贝初始化构造函数
//输入：函数的参数otherD用于拷贝初始化的长方形
template <typename ElemType>
Rectangle<ElemType>::Rectangle(const Rectangle<ElemType>&otherD)
{
	length = otherD.length;
	width = otherD.width;
	myNo.no = otherD.myNo.no;
	cout << "自动调用拷贝初始化构造函数初始化为 （" << length << "，" << width << "）" << endl;
}

//功能：析构函数
//说明：对象生存周期结束时，系统自动调用该对象所属类的析构函数
template <typename ElemType>
Rectangle<ElemType>::~Rectangle()
{
	cout << "第" << myNo.no << "个长方形对象 （" << length << "，" << width << "）" << endl;
}
