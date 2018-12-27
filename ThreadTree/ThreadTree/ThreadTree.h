//ThreadTree.h �����߶����������ö�������洢��

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

	//�ݹ��������߶����������
	int depth();

	//ȡ�����߶������ĸ�ָ��
	ThreadTNPointer getRoot()();

	//������������߶�����
	void inOrderTraverse_ThreadTree();

	//�ж��Ƿ�Ϊ��
	bool isEmpty();

	//�������һ�������߶�����
	void randomCreate();

	//��ָ����������ǰ��
	Status searchPriorNode(ElemType key, ElemType & prior);

	//��ָ���������ĺ��
	Status searchNextNode(ElemType key, ElemType & next);

	//��ָ�����
	Status searchNode(ElemType key, ThreadTNPointer &p);

	//�����߶�����˳��洢ת��Ϊ��������洢
	void sequentialToThreadTree(MySeqTree<ElemType> T);

	//�����߶������Ķ�������洢ת��Ϊ˳��洢
	void ThreadTreeToSequential();

private:
	//���������߶������ڵ�洢�ռ�ĸ�������
	void deleteNode_aux(ThreadTNPointer p);

	//�ݹ��������߶�������ȵĸ�������
	int depth_aux(ThreadTNPointer p);

	//
	void sequentialToThreadTree_aux1(int index, ThreadTNPointer& p);

	void sequentialToThreadTree_aux2(ThreadTNPointer& p);

	void ThreadTreeToSequential_aux(MySeqTree<ElemType>& TempT, ThreadTNPointer p, int index);

	void ThreadTree_aux(ThreadTNPointer& p, ThreadTNPointer p, ThreadTNPointer otherP);
};

