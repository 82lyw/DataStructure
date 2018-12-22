//GList.h ���������ͷβ����洢�� ���ݽṹC++�ඨ�壨���ࣩ
  
//head.h 
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

//SqQueue.h ѭ��˳����У�����˳��洢�����ݽṹC++�ඨ�壨���ࣩ
#ifndef SQQUEUE_H
#define SQQUEUE_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\Queue\Queue\SqQueue.h"
#endif


//SqStack.h ˳��ջ��˳��洢�������ࣩ
#ifndef SQSTACK_H
#define SQSTACK_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\SqStack\SqStack\SqStack.h"
#endif

//SqStack.h ˳��
#ifndef SQSTRING_H
#define SQSTRING_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\SqString\SqString\SqString.h"
#endif

//ATOM ԭ�ӣ�LIST�ӱ�
typedef enum {ATOM,LIST} ElemTaq;

//���ǿմ�str�ֳ������֣�hstrΪ��һ��','֮ǰ���Ӵ�������str�洢������Ӵ�
void separate(SqString & str, SqString & hstr);

//�����
class GList
{
public:
	//����� �������ݽṹC++�ඨ��
	class GLNode
	{
	public:
		ElemTaq tag;  //����־����������ԭ�ӽ��ͱ���
		union
		{
			char atom;  //ԭ�ӽ���ֵ��
			struct
			{
				class GLNode *hp;  //ָ���ͷ��ָ����
				class GLNode *tp;  //ָ���β��ָ����
			}ptr;  //�����ָ����
		};
	};
	typedef GLNode* GListNodePointer;

	//��������ַ�����ͷβ����洢��ת��
	void createGList(SqString S);

	//ɾ�������ı�ͷ
	Status deleteHead(GList & secondGL);

	//����������
	int depth();

	//ȡ�����ı�ͷ
	Status getHead(GList & headGL);

	//ȡ�����ĸ�ָ��
	GListNodePointer getRoot();

	//ȡ�����ı�β
	Status getTail(GList & tailGL);

	//����һ���������Ϊ�����ı�ͷ
	void insertHead(GList & secondGL);

	//�жϹ�����Ƿ�Ϊ��
	bool isEmpty();

	//������ĳ���
	int length();

	//���ظ�ֵ������Ķ���
	GList operator=(GList rightGL);

	//���ø�ָ��
	void setRoot(GListNodePointer p);

private:
	//���ƹ����ĸ�������
	void copyGlist_aux(GListNodePointer & s, GListNodePointer p);
	
	//��������ַ�����ͷβ����洢ת���ĸ�������
	void createGList_aux(GListNodePointer & L, SqString s);

	//��������ȵĸ�������
	int depth_aux(GListNodePointer & p);

	//���������ĸ�������
	void destruction_aux(GListNodePointer & p);

public:
	//�����Ĺ��캯��
	GList();

	//��������������
	~GList();

	//���������ʼ�����캯��
	GList(const GList & s);

	//��������
	void read(istream & in);

	//��������
	void display(ostream & out);

private:
	GListNodePointer root;  //��ָ��
};

void GList::copyGlist_aux(GListNodePointer & s, GListNodePointer p)
{
	if (!p)
		s = NULL;
	else
	{
		s = new GLNode;
		assert(s != 0);
		s->tag = p->tag;
		if (p->tag == ATOM)
			s->atom = p->atom;
		else
		{
			copyGlist_aux(s->ptr.hp, p->ptr.hp);
			copyGlist_aux(s->ptr.tp, p->ptr.tp);
		}
	}
}

void GList::createGList(SqString S)
{
	destruction_aux(root);
	createGList_aux(root, S);
}

void GList::createGList_aux(GListNodePointer & L, SqString S)
{
	char c;
	SqString hS;
	if (!(S == "()"))
	{
		L = NULL;
		return;
	}
	L = new GLNode;
	assert(L != 0);
	if (S.getLength() == 1)
	{
		S.getChar(1, c);
		L->tag = ATOM;
		L->atom = c;
		return;
	}
	separate(S, hS);
	L->tag = LIST;
	createGList_aux(L->ptr.hp, hS);
	createGList_aux(L->ptr.tp, S);
}

Status GList::deleteHead(GList & secondGL)
{
	GListNodePointer p = root;
	if (!root)
		return ERROR;
	root = root->ptr.tp;
	p->ptr.tp = NULL;
	secondGL.setRoot(p);
	return OK;
}

int GList::depth()
{
	return depth_aux(root);
}

int GList::depth_aux(GListNodePointer & s)
{
	int dep, maxDep = 0;
	if (!s || s->tag == ATOM)
	{
		return 0;
	}
	for (GListNodePointer p = s; p; p = p->ptr.tp)
	{
		dep = depth_aux(p->ptr.hp);
		if (dep > maxDep)
			maxDep = dep;
	}
	return maxDep + 1;
}

void GList::destruction_aux(GListNodePointer & p)
{
	if (!p)
		return;
	if (p->tag == LIST)
	{
		destruction_aux(p->ptr.hp);
		destruction_aux(p->ptr.tp);
	}
	delete p;
}

Status GList::getHead(GList & headGL)
{
	GListNodePointer p;
	if (!root)
		return ERROR;
	p = root->ptr.hp;
	copyGlist_aux(headGL.root, p);
	return OK;
}

GList::GListNodePointer GList::getRoot()
{
	return root;
}

Status GList::getTail(GList & tailGL)
{
	GListNodePointer p;
	if (!root)
		return ERROR;
	p = root->ptr.tp;
	copyGlist_aux(tailGL.root, p);
	return OK;
}

void GList::insertHead(GList & secondGL)
{
	if (secondGL.isEmpty())
		return;
	if (!root)
		root = secondGL.root;
	else
	{
		GListNodePointer p;
		for (p = secondGL.root; p->ptr.tp; p = p->ptr.tp);
		p->ptr.tp = root;
		root = p;
	}
}

bool GList::isEmpty()
{
	return root ? false : true;
}

int GList::length()
{
	int length = 0;
	if (!root)
		return 0;
	for (GListNodePointer p = root; p; p = p->ptr.tp, ++length);
	return length;
}

GList GList::operator=(GList rightGL)
{
	copyGlist_aux(root, rightGL.root);
	return *this;
}

void GList::setRoot(GListNodePointer p)
{
	if (root)
		destruction_aux(root);
	root = p;
}

GList::GList()
{
	root = NULL;
}

GList::~GList()
{
	destruction_aux(root);
}

GList::GList(const GList & otherS)
{
	GListNodePointer p1;
	GListNodePointer pre_p1_hp;
	GListNodePointer pre_p1_tp;
	SqQueue<GListNodePointer> hpQ1;
	GListNodePointer p2;
	SqQueue<GListNodePointer> Q2;
	root = NULL;
	if (!otherS.root)
	{
		cout << "��ʼ��һ�������" << endl;
		return;
	}
	hpQ1.enQueue(NULL);
	Q2.enQueue(otherS.root);
	while (!Q2.isEmpty())
	{
		Q2.deQueue(p2);
		p1 = new GLNode;
		assert(p1 != 0);
		if (root == NULL)
			root = p1;
		hpQ1.deQueue(pre_p1_hp);
		if (pre_p1_hp)
			pre_p1_hp->ptr.hp = p1;
		if (p2->tag == ATOM)
		{
			p1->tag = ATOM;
			p1->atom = p2->atom;
		}
		else
		{
			pre_p1_tp = NULL;
			while (p2)
			{
				p1->tag = LIST;
				if (p2->ptr.hp)
				{
					Q2.enQueue(p2->ptr.hp);
					hpQ1.enQueue(p1);
				}
				else
				{
					p1->ptr.hp = NULL;
				}
				if (p2->ptr.tp)
				{
					pre_p1_tp = p1;
					p1 = new GLNode;
					assert(p1 != 0);
					if (pre_p1_tp)
					{
						pre_p1_tp->ptr.tp = p1;
					}
				}
				else
				{
					p1->ptr.tp = NULL;
				}
			}
		}
	}
}

void separate(SqString & S, SqString & hS)
{
	char c;
	int k = 0;
	int i = 1;
	int n = S.getLength() - 2;
	SqString tS;
	S.subString(tS, 2, S.getLength() - 2);
	while (i <= n)
	{
		tS.getChar(i, c);
		if (c == ','&&k == 0)
			break;
		if (c == '(')
			k++;
		else if (c == ')')
			k--;
		i++;
	}
	if (i <= n)
	{
		tS.subString(hS, 1, i - 1);
		tS.subString(S, i + 1, n - i);
		S.insert(1, "(");
		S.insert(S.getLength() + 1, ")");
	}
	else
	{
		hS = tS;
		S = "()";
	}
}