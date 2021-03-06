#ifndef THREADTREE_H
#define THREADTREE_H

#define ENDIDENTIFIER 	-9999
#define RANGE   		13 

typedef int DataType;

typedef struct ThreadTreeNode
{
	DataType				data;
	int      				ltag;
	int      				rtag;
	struct ThreadTreeNode * lchild;
	struct ThreadTreeNode * rchild;
}ThreadTreeNode, *ThreadTree;

ThreadTree pre;

/*****************************************************************************
 *         创建线索二叉树                                                    *
 *****************************************************************************/
void CreateThreadTree(ThreadTree * bt, DataType datas[], int * pos);

/*****************************************************************************
 *         中序线索化                                                        *
 *****************************************************************************/
void InThread(ThreadTree root);

/*****************************************************************************
 *         中序线索二叉树中查找p的中序前驱,并返回前序结点                    *
 *****************************************************************************/
ThreadTreeNode * InPre(ThreadTreeNode * p);

/*****************************************************************************
 *         中序线索二叉树中查找p的中序后继节点，并返回后继结点               *
 *****************************************************************************/
ThreadTreeNode * InNext(ThreadTreeNode * p);

/*****************************************************************************
 *          获取中序线索二叉树中序遍历的第一个结点                           *
 *****************************************************************************/
ThreadTreeNode * InFirst(ThreadTree root);

/*****************************************************************************
 *          遍历中序线索二叉树                                               *
 *****************************************************************************/
void InOrder(ThreadTree root);

/*****************************************************************************
 *          线索二叉树中插入q                                                *
 *****************************************************************************/
void InsertNode(ThreadTreeNode * p, ThreadTreeNode * q);

#endif
