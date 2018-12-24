//BiTree.h �����������ö�������

//myhead.h
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

//MySeqTree.h ��������˳��洢���������ࣩ
#ifndef MYSEQTREE_H
#define MYSEQTREE_H
#include "SeqTree.h"
#endif // !MYSEQTREE_H

//SqStack.h
#ifndef SQSTACK_H
#define SQSTACK_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\SqStack\SqStack\SqStack.h"
#endif // !SQSTACK_H

//SqQueue.h
#ifndef SQQUEUE_H
#define SQQUEUE_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\Queue\Queue\SqQueue.h"
#endif // !SQQUEUE_H


#define LH 1;
#define EH 0;
#define RH -1;

template <typename ElemType>
class BiTree
{
public:
	class Node
	{
	public:
		//���캯������ʼ���б�ִ�п죩
		Node() :lchild(NULL), rchild(NULL) {};

		ElemType data;
		class Node *lchild, *rchild;
	};
	typedef Node* NodePointer;

public:
	//�Ѷ������ÿ�
	void clear();

	//���������Ҷ����
	int countLeaf();

	//��������Ľ����
	int countNode();

	//�ݹ�������������
	int depth();

	//��ʾ��������˳��洢
	void displaySeqTree();

	//���������������н�������������
	void exchangeLRchild();

	//ȡ��ָ��
	NodePointer getRoot();

	//����ݹ����������
	void inOrderTraverse();

	//�ж��Ƿ�Ϊ�ն�����
	bool isEmpty();

	//�����˳�����������
	void layOrderTraverse();

	//�������Ķ�������洢ת��Ϊ˳��洢�ṹ
	void linkToSeqquential();

	//�ǵݹ��������������
	void noRecursionInOrderTraverse();

	//�����ݹ����������
	void postOrderTraverse();

	//ǰ��ݹ����������
	void preOrderTraverse();

	//�������һ�ö�����
	void randomCreate();

	//��������˳��洢ת��Ϊ��������洢�ṹ
	void sequentialToLink(MySeqTree<ElemType> T);

private:
	//������ʼ�����캯���ĸ�������
	void BiTree_aux(NodePointer& p, NodePointer otherP);

	//�������Ҷ�����ĸ�������
	int countLeaf_aux(NodePointer p);

	//�������������ĸ�������
	int countNode_aux(NodePointer p);

	//���ն��������洢�ռ�ĸ�������
	void deleteNode_aux(NodePointer p);

	//�ݹ����������ȵĸ�������
	int depth_aux(NodePointer p);

	//���������������н�����������ĸ�������
	void exchangeLRchild_aux(NodePointer p);

	//����ݹ�����������ĸ�������
	void inOrderTraverse_aux(NodePointer p);

	//�������Ķ�������洢ת��Ϊ˳��洢�ṹ�ĸ�������
	void linkToSequential_aux(MySeqTree<ElemType>& tempT,NodePointer p,int i);
	
	//����ݹ�����������ĸ�������
	void postOrderTraverse_aux(NodePointer p);

	//ǰ��ݹ�����������ĸ�������
	void preOrderTraverse_aux(NodePointer p);

	//��������˳��洢ת��Ϊ��������洢�ṹ�ĸ�������
	void sequentialToLink_aux(int i, NodePointer& subroot);

public:
	BiTree();
	~BiTree();
	BiTree(const BiTree<ElemType>& otherT);
	void read(istream& in);
	void display(ostream& out);

protected:
	NodePointer root;  //�������ĸ�ָ�루���ö�������洢��
	MySeqTree<ElemType> seqT;  //��������Ӧ��˳��洢��
};

//�Ѷ������ÿ�
template <typename ElemType>
void BiTree<ElemType>::clear()
{
	seqT.clear();
	deleteNode_aux(root);
	root = NULL;
}

//���������Ҷ����
template <typename ElemType>
int BiTree<ElemType>::countLeaf()
{
	return countLeaf_aux(root);
}

//�������Ҷ�����ĸ�������
template <typename ElemType>
int BiTree<ElemType>::countLeaf_aux(NodePointer p)
{
	int num;
	static int i = 0;
	if (p)
	{
		if (!p->lchild && !p->rchild)
			++i;
		countLeaf_aux(p->lchild);
		countLeaf_aux(p->rchild);
	}
	if (p == root)
	{
		num = i;
		i = 0;
	}
	return num;
}

//��������Ľ����
template <typename ElemType>
int BiTree<ElemType>::countNode()
{
	return countNode_aux(root);
}

//�������������ĸ�������
template <typename ElemType>
int BiTree<ElemType>::countNode_aux(NodePointer p)
{
	int num;
	static int i = 0;
	if (p)
	{
		i++;
		countNode_aux(p->lchild);
		countNode_aux(p->rchild);
	}
	if (p == root)
	{
		num = i;
		i = 0;
	}
	return num;
}

//���ն��������洢�ռ�ĸ�������
template <typename ElemType>
void BiTree<ElemType>::deleteNode_aux(NodePointer p)
{
	if (p)
	{
		deleteNode_aux(p->lchild);
		deleteNode_aux(p->rchild);
		delete p;
	}
}

//�ݹ�������������
template <typename ElemType>
int BiTree<ElemType>::depth()
{
	return depth_aux(root);
}

//�ݹ����������ȵĸ�������
template <typename ElemType>
int BiTree<ElemType>::depth_aux(NodePointer p)
{
	int lDep, rDep;
	if (!p)
		return 0;
	else
	{
		lDep = depth_aux(p->lchild);
		rDep = depth_aux(p->rchild);
		return (lDep > rDep ? lDep : rDep) + 1;
	}
}

//��ʾ��������˳��洢
template <typename ElemType>
void BiTree<ElemType>::displaySeqTree()
{
	seqT.sequentialDisplay();
}

//���������������н���������s��
template <typename ElemType>
void BiTree<ElemType>::exchangeLRchild()
{
	exchangeLRchild_aux(root);
	linkToSeqquential();
}

//���������������н�����������ĸ�������
template <typename ElemType>
void BiTree<ElemType>::exchangeLRchild_aux(NodePointer p)
{
	NodePointer s;
	if (p)
	{
		exchangeLRchild_aux(p->lchild);
		exchangeLRchild_aux(p->rchild);
		s = p->lchild;
		p->lchild = p->rchild;
		p->rchild = s;
	}
}

//ȡ��ָ��
template <typename ElemType>
BiTree<ElemType>::NodePointer BiTree<ElemType>::getRoot()
{
	return root;
}

//����ݹ����������
template <typename ElemType>
void BiTree<ElemType>::inOrderTraverse()
{
	inOrderTraverse_aux(root);
}

//����ݹ�����������ĸ�������
template <typename ElemType>
void BiTree<ElemType>::inOrderTraverse_aux(NodePointer p)
{
	if (p)
	{
		inOrderTraverse_aux(p->lchild);
		cout << p->data;
		inOrderTraverse_aux(p->rchild);
	}
}

//�ж��Ƿ�Ϊ�ն�����
template <typename ElemType>
bool BiTree<ElemType>::isEmpty()
{
	return root ? false : true;
}

//�����˳�����������
template <typename ElemType>
void BiTree<ElemType>::layOrderTraverse()
{
	NodePointer p;
	SqQueue<NodePointer> Q;
	if (root != NULL)
		Q.enQueue(root);
	while (!Q.isEmpty())
	{
		Q.deQueue(p);
		cout << p->data;
		if (p->lchild)
			Q.enQueue(p->lchild);
		if (p->rchild)
			Q.enQueue(p->rchild);
	}
}

//�������Ķ�������洢ת��Ϊ˳��洢�ṹ
template <typename ElemType>
void BiTree<ElemType>::linkToSeqquential()
{
	int max_tital;
	MySeqTree<ElemType> tempT;
	if (!root)
	{
		seqT.clear();
		return;
	}
	max_total = 1;
	for (int d = 1; d <= depth(); d++)
		max_total *= 2;
	max_total -= 1;
	tempT.setSizeEmptyTree(max_total);
	linkToSequential_aux(tempT, root, 0);
	seqT = tempT;
}

//�������Ķ�������洢ת��Ϊ˳��洢�ṹ�ĸ�������
template <typename ElemType>
void BiTree<ElemType>::linkToSequential_aux(MySeqTree<ElemType>& tempT, NodePointer p, int i)
{
	tempT.setNode(i, p->data);
	if (p->lchild != NULL)
		linkToSequential_aux(tempT, p->lchild, 2 * i + 1);
	if (p->rchild != NULL)
		linkToSequential_aux(tempT, p->rchild, 2 * i + 1);
}

//�ǵݹ��������������
template <typename ElemType>
void BiTree<ElemType>::noRecursionInOrderTraverse()
{
	NodePointer p = root;
	SqStack<NodePointer> S;
	while (p || !S.isEmpty())
	{
		if (p)
		{
			S.push(p);
			p = p->lchild;
		}
		else
		{
			S.pop(p);
			cout << p->data;
			p = p->rchild;
		}
	}
}

//�����ݹ����������
template <typename ElemType>
void BiTree<ElemType>::postOrderTraverse()
{
	postOrderTraverse_aux(root);
}

//����ݹ�����������ĸ�������
template <typename ElemType>
void BiTree<ElemType>::postOrderTraverse_aux(NodePointer p)
{
	if (p)
	{
		postOrderTraverse_aux(p->lchild);
		postOrderTraverse_aux(p->rchild);
		cout << p->data;
	}
}

//ǰ��ݹ����������
template <typename ElemType>
void BiTree<ElemType>::preOrderTraverse()
{
	preOrderTraverse_aux(root);
}

//ǰ��ݹ�����������ĸ�������
template <typename ElemType>
void BiTree<ElemType>::preOrderTraverse_aux(NodePointer p)
{
	if (p)
	{
		cout << p->data;
		preOrderTraverse_aux(p->lchild);
		preOrderTraverse_aux(p->rchild);
	}
}

//�������һ�ö�����
template <typename ElemType>
void BiTree<ElemType>::randomCreate()
{
	seqT.randomCreateSeq_tree(1);
	sequentialToLink_aux(0, root);
}

//��������˳��洢ת��Ϊ��������洢�ṹ
template <typename ElemType>
void BiTree<ElemType>::sequentialToLink(MySeqTree<ElemType> T)
{
	seqT = T;
	sequentialToLink_aux(0, root);
}

//��������˳��洢ת��Ϊ��������洢�ṹ�ĸ�������
template <typename ElemType>
void BiTree<ElemType>::sequentialToLink_aux(int i, NodePointer& subroot)
{
	int n = seqT.getFinalIndex();
	if (n == -1)
	{
		p = NULL;
		return;
	}
	p = new BiTree<ElemType>::Node;
	assert(p != 0);
	p->data = seqT.getNode(i);
	if (2 * i + 1 > n || seqT.getNode(2 * i + 1) == ' ')
		p->lchild = NULL;
	else
		sequentialToLink_aux(2 * i + 2, p->rchild);
}


template <typename ElemType>
BiTree<ElemType>::BiTree()
{
	root = NULL;
	seqT.clear();
}

template <typename ElemType>
BiTree<ElemType>::~BiTree()
{
	clear();
}

template <typename ElemType>
BiTree<ElemType>::BiTree(const BiTree<ElemType>& otherT)
{
	if (!otherT.root)
	{
		root = NULL;
		seqT.clear();
	}
	else
	{
		BiTree_aux(root, otherT.root);
		linkToSeqquential()
	}
}

template <typename ElemType>
void BiTree<ElemType>::BiTree_aux(NodePointer& p, NodePointer otherP)
{
	if (!otherP)
	{
		p = NULL;
		return;
	}
	p = new Node;
	assert(p != 0);
	p->data = otherP->data;
	if (!otherP->lchild)
		p->lchild = NULL;
	else
		BiTree_aux(p->lchild, otherP->lchild);
	if (!otherP->rchild)
		p->rchild = NULL;
	else
		BiTree_aux(p->rchild, otherP->rchild);
}

//���ܣ���������������ö�������洢��
template <typename ElemType>
void BiTree<ElemType>::read(istream& in)
{
	cout << "����˳��洢��ʽ����һ�Ŷ�����" << endl << endl;
	in >> seqT;
	sequentialToLink_aux(0, root);
}

//���ܣ���������������Ķ���
template <typename ElemType>
istream& operator>>(istream& in, BiTree<ElemType>& bT)
{
	bT.read(in);
	return in;
}

//���ܣ���������������ö�������洢��
template <typename ElemType>
void BiTree<ElemType>::display(ostream& out)
{
	out << seqT;
}

//���ܣ��������������Ķ���
template <typename ElemType>
ostream& operator>>(ostream& in, BiTree<ElemType>& bT)
{
	bT.display(out);
	return out;
}
