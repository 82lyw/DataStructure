//ThreadTree.h 中序穿线二叉树（采用二叉链表存储）

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

typedef enum PointerTag { LINK, THREAD };

template <typename ElemType>
class Thread
{
public:
	class ThreadTNode
	{
	public:
		ThreadTNode() :ltag(LINK), lchild(NULL), rtag(LINK), rchild(NULL) {};
		~ThreadTNode();
	public:
		ElemType data;
		class ThreadTNode *lchild, *rchild;
		PointerTag ltag, rtag;
	};
	typedef ThreadTNode* ThreadTNPointer;

public:
	void clear();

	//递归求中序穿线二叉树的深度
	int depth();

	//取中序穿线二叉树的根指针
	ThreadTNPointer getRoot()();

	//中序遍历中序穿线二叉树
	void inOrderTraverse_ThreadTree();

	//判断是否为空
	bool isEmpty();

	//随机生成一棵中序穿线二叉树
	void randomCreate();

	//找指定结点中序的前驱
	Status searchPriorNode(ElemType key, ElemType & prior);

	//找指定结点中序的后继
	Status searchNextNode(ElemType key, ElemType & next);

	//找指定结点
	Status searchNode(ElemType key, ThreadTNPointer &p);

	//中序穿线二叉树顺序存储转换为二叉链表存储
	void sequentialToThreadTree(MySeqTree<ElemType> T);

	//中序穿线二叉树的二叉链表存储转换为顺序存储
	void ThreadTreeToSequential();

private:
	//回收中序穿线二叉树节点存储空间的辅助函数
	void deleteNode_aux(ThreadTNPointer p);

	//递归求中序穿线二叉树深度的辅助函数
	int depth_aux(ThreadTNPointer p);

	//
	void sequentialToThreadTree_aux1(int index, ThreadTNPointer& p);

	void sequentialToThreadTree_aux2(ThreadTNPointer& p);

	void ThreadTreeToSequential_aux(MySeqTree<ElemType>& TempT, ThreadTNPointer p, int index);

	void ThreadTree_aux(ThreadTNPointer& p, ThreadTNPointer p, ThreadTNPointer otherP);
};

