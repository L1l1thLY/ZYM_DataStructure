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
 *         ��������������                                                    *
 *****************************************************************************/
void CreateThreadTree(ThreadTree * bt, DataType datas[], int * pos);

/*****************************************************************************
 *         ����������                                                        *
 *****************************************************************************/
void InThread(ThreadTree root);

/*****************************************************************************
 *         ���������������в���p������ǰ��,������ǰ����                    *
 *****************************************************************************/
ThreadTreeNode * InPre(ThreadTreeNode * p);

/*****************************************************************************
 *         ���������������в���p�������̽ڵ㣬�����غ�̽��               *
 *****************************************************************************/
ThreadTreeNode * InNext(ThreadTreeNode * p);

/*****************************************************************************
 *          ��ȡ����������������������ĵ�һ�����                           *
 *****************************************************************************/
ThreadTreeNode * InFirst(ThreadTree root);

/*****************************************************************************
 *          ������������������                                               *
 *****************************************************************************/
void InOrder(ThreadTree root);

/*****************************************************************************
 *          �����������в���q                                                *
 *****************************************************************************/
void InsertNode(ThreadTreeNode * p, ThreadTreeNode * q);

#endif