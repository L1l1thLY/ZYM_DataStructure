#ifndef ADJLIST_H
#define ADJLIST_H

#include "common.h"
#define N 10

// �߽ڵ�
typedef struct AdjListArcNode
{
	int 				adjvex;
	struct ArcNode * 	nextarc;
} AdjListArcNode;

// ����ڵ�
typedef struct VertexNode  
{
	VertexData			data;
	AdjListArcNode *	firstarc;
}VertexNode;

typedef struct AdjListNode
{
	VertexNode	vertex[N]; // ͼ��ÿ������֮���ڵĶ������� 
	int 		vexnum;    // ͼ�еĵ���
	int 		arcnum;    // ͼ�еı��� 
	GraphKind	kind;
}AdjList;

/******************************************************************************
 *        ��ȡ���ݽڵ����ڽӱ���λ��                                          *
 ******************************************************************************/
int AdjListLocateVertex(AdjList * g, VertexData v);

/******************************************************************************
 *        �����ڽӱ�洢��ʽ������ͼ                                          *
 ******************************************************************************/
int CreateAdjListUDG(AdjList * g, int vexnum, int arcnum, VertexData vexs[],
			 VertexData arcs[][MAX]);

/******************************************************************************
 *        �ڽӱ�洢��ʽ������ͼ����������㷨                                *
 ******************************************************************************/
void AdjListDFS(AdjList g,int vo);

/******************************************************************************
 *        �ڽӱ�洢��ʽ������ͼ�Ĺ�������㷨                                *
 ******************************************************************************/
void AdjListBFS(AdjList g,int vo);

/******************************************************************************
 *        �ڽӱ�洢��ʽ������ͼ�ı���                                        *
 ******************************************************************************/
void AdjListTraverse(AdjList g);

#endif // END ADJLIST_H
