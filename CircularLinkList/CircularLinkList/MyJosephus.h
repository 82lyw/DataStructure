template<typename ElemType>
void Josephus(MyCircularLinkList<ElemType> L, int start, int i)
{
	int times = 0;
	ElemType e;

	if (L.isEmpty())
	{
		cout << "Լɪ��Ϊ�գ��޷����У�" << endl;
		return;
	}

	L.moveHead(start);
	while (!L.isEmpty())
	{
		L.deleteElem(i, e);
		cout << "\n ��" << ++times << "�γ��еĽ��Ϊ" << e << "�����к�Լɪ��Ϊ";

		if (!L.isEmpty())
		{
			cout << ":\n" << L;
		}
		else
		{
			cout << "�ա�" << endl;
		}
	}
}
