//BiTree.h 二叉树（采用二叉链表）

//myhead.h
#ifndef MYHEAD_H
#define MYHEAD_H
#include "C:\Users\lyw\Desktop\lyw\DataStructure\head.h"
#endif

//MySeqTree.h 树（采用顺序存储）（派生类）
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
		//构造函数：初始化列表（执行快）
		Node() :lchild(NULL), rchild(NULL) {};

		ElemType data;
		class Node *lchild, *rchild;
	};
	typedef Node* NodePointer;

public:
	//把二叉树置空
	void clear();

	//求二叉树的叶子数
	int countLeaf();

	//求二叉树的结点数
	int countNode();

	//递归求二叉树的深度
	int depth();

	//显示二叉树的顺序存储
	void displaySeqTree();

	//交换二叉树中所有结点的左右子树；
	void exchangeLRchild();

	//取根指针
	NodePointer getRoot();

	//中序递归遍历二叉树
	void inOrderTraverse();

	//判断是否为空二叉树
	bool isEmpty();

	//按层次顺序遍历二叉树
	void layOrderTraverse();

	//二叉树的二叉链表存储转换为顺序存储结构
	void linkToSeqquential();

	//非递归中序遍历二叉树
	void noRecursionInOrderTraverse();

	//后续递归遍历二叉树
	void postOrderTraverse();

	//前序递归遍历二叉树
	void preOrderTraverse();

	//随机生成一棵二叉树
	void randomCreate();

	//二叉树的顺序存储转换为二叉链表存储结构
	void sequentialToLink(MySeqTree<ElemType> T);

private:
	//拷贝初始化构造函数的辅助函数
	void BiTree_aux(NodePointer& p, NodePointer otherP);

	//求二叉树叶子数的辅助函数
	int countLeaf_aux(NodePointer p);

	//求二叉树结点数的辅助函数
	int countNode_aux(NodePointer p);

	//回收二叉树结点存储空间的辅助函数
	void deleteNode_aux(NodePointer p);

	//递归求二叉树深度的辅助函数
	int depth_aux(NodePointer p);

	//交换二叉树中所有结点左右子树的辅助函数
	void exchangeLRchild_aux(NodePointer p);

	//中序递归遍历二叉树的辅助函数
	void inOrderTraverse_aux(NodePointer p);

	//二叉树的二叉链表存储转换为顺序存储结构的辅助函数
	void linkToSequential_aux(MySeqTree<ElemType>& tempT,NodePointer p,int i);
	
	//后序递归遍历二叉树的辅助函数
	void postOrderTraverse_aux(NodePointer p);

	//前序递归遍历二叉树的辅助函数
	void preOrderTraverse_aux(NodePointer p);

	//二叉树的顺序存储转换为二叉链表存储结构的辅助函数
	void sequentialToLink_aux(int i, NodePointer& subroot);

public:
	BiTree();
	~BiTree();
	BiTree(const BiTree<ElemType>& otherT);
	void read(istream& in);
	void display(ostream& out);

protected:
	NodePointer root;  //二叉树的根指针（采用二叉链表存储）
	MySeqTree<ElemType> seqT;  //二叉树对应的顺序存储树
};

//把二叉树置空
template <typename ElemType>
void BiTree<ElemType>::clear()
{
	seqT.clear();
	deleteNode_aux(root);
	root = NULL;
}

//求二叉树的叶子数
template <typename ElemType>
int BiTree<ElemType>::countLeaf()
{
	return countLeaf_aux(root);
}

//求二叉树叶子数的辅助函数
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

//求二叉树的结点数
template <typename ElemType>
int BiTree<ElemType>::countNode()
{
	return countNode_aux(root);
}

//求二叉树结点数的辅助函数
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

//回收二叉树结点存储空间的辅助函数
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

//递归求二叉树的深度
template <typename ElemType>
int BiTree<ElemType>::depth()
{
	return depth_aux(root);
}

//递归求二叉树深度的辅助函数
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

//显示二叉树的顺序存储
template <typename ElemType>
void BiTree<ElemType>::displaySeqTree()
{
	seqT.sequentialDisplay();
}

//交换二叉树中所有结点的左右子s树
template <typename ElemType>
void BiTree<ElemType>::exchangeLRchild()
{
	exchangeLRchild_aux(root);
	linkToSeqquential();
}

//交换二叉树中所有结点左右子树的辅助函数
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

//取根指针
template <typename ElemType>
BiTree<ElemType>::NodePointer BiTree<ElemType>::getRoot()
{
	return root;
}

//中序递归遍历二叉树
template <typename ElemType>
void BiTree<ElemType>::inOrderTraverse()
{
	inOrderTraverse_aux(root);
}

//中序递归遍历二叉树的辅助函数
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

//判断是否为空二叉树
template <typename ElemType>
bool BiTree<ElemType>::isEmpty()
{
	return root ? false : true;
}

//按层次顺序遍历二叉树
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

//二叉树的二叉链表存储转换为顺序存储结构
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

//二叉树的二叉链表存储转换为顺序存储结构的辅助函数
template <typename ElemType>
void BiTree<ElemType>::linkToSequential_aux(MySeqTree<ElemType>& tempT, NodePointer p, int i)
{
	tempT.setNode(i, p->data);
	if (p->lchild != NULL)
		linkToSequential_aux(tempT, p->lchild, 2 * i + 1);
	if (p->rchild != NULL)
		linkToSequential_aux(tempT, p->rchild, 2 * i + 1);
}

//非递归中序遍历二叉树
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

//后续递归遍历二叉树
template <typename ElemType>
void BiTree<ElemType>::postOrderTraverse()
{
	postOrderTraverse_aux(root);
}

//后序递归遍历二叉树的辅助函数
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

//前序递归遍历二叉树
template <typename ElemType>
void BiTree<ElemType>::preOrderTraverse()
{
	preOrderTraverse_aux(root);
}

//前序递归遍历二叉树的辅助函数
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

//随机生成一棵二叉树
template <typename ElemType>
void BiTree<ElemType>::randomCreate()
{
	seqT.randomCreateSeq_tree(1);
	sequentialToLink_aux(0, root);
}

//二叉树的顺序存储转换为二叉链表存储结构
template <typename ElemType>
void BiTree<ElemType>::sequentialToLink(MySeqTree<ElemType> T)
{
	seqT = T;
	sequentialToLink_aux(0, root);
}

//二叉树的顺序存储转换为二叉链表存储结构的辅助函数
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

//功能：输入二叉链表（采用二叉链表存储）
template <typename ElemType>
void BiTree<ElemType>::read(istream& in)
{
	cout << "采用顺序存储方式创建一颗二叉树" << endl << endl;
	in >> seqT;
	sequentialToLink_aux(0, root);
}

//功能：重载输入运算符的定义
template <typename ElemType>
istream& operator>>(istream& in, BiTree<ElemType>& bT)
{
	bT.read(in);
	return in;
}

//功能：输出二叉树（采用二叉链表存储）
template <typename ElemType>
void BiTree<ElemType>::display(ostream& out)
{
	out << seqT;
}

//功能：重载输出运算符的定义
template <typename ElemType>
ostream& operator>>(ostream& in, BiTree<ElemType>& bT)
{
	bT.display(out);
	return out;
}
