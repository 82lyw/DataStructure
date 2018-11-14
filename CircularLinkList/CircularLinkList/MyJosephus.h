template<typename ElemType>
void Josephus(MyCircularLinkList<ElemType> L, int start, int i)
{
	int times = 0;
	ElemType e;

	if (L.isEmpty())
	{
		cout << "约瑟夫环为空，无法出列！" << endl;
		return;
	}

	L.moveHead(start);
	while (!L.isEmpty())
	{
		L.deleteElem(i, e);
		cout << "\n 第" << ++times << "次出列的结点为" << e << "，出列后约瑟夫环为";

		if (!L.isEmpty())
		{
			cout << ":\n" << L;
		}
		else
		{
			cout << "空。" << endl;
		}
	}
}
