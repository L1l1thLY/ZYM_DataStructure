#ifndef ADJLIST_H
#define ADJLIST_H

#include "common.h"
#define N 10

// 边节点
typedef struct AdjListArcNode
{
	int 				adjvex;
	struct ArcNode * 	nextarc;
} AdjListArcNode;

// 定点节点
typedef struct VertexNode  
{
	VertexData			data;
	AdjListArcNode *	firstarc;
}VertexNode;

typedef struct AdjListNode
{
	VertexNode	vertex[N]; // 图中每个点与之相邻的定点链表 
	int 		vexnum;    // 图中的点数
	int 		arcnum;    // 图中的边数 
	GraphKind	kind;
}AdjList;

/******************************************************************************
 *        获取数据节点在邻接表中位置                                          *
 ******************************************************************************/
int AdjListLocateVertex(AdjList * g, VertexData v);

/******************************************************************************
 *        创建邻接表存储方式的无向图                                          *
 ******************************************************************************/
int CreateAdjListUDG(AdjList * g, int vexnum, int arcnum, VertexData vexs[],
			 VertexData arcs[][MAX]);

/******************************************************************************
 *        邻接表存储方式的无向图的深度优先算法                                *
 ******************************************************************************/
void AdjListDFS(AdjList g,int vo);

/******************************************************************************
 *        邻接表存储方式的无向图的广度优先算法                                *
 ******************************************************************************/
void AdjListBFS(AdjList g,int vo);

/******************************************************************************
 *        邻接表存储方式的无向图的遍历                                        *
 ******************************************************************************/
void AdjListTraverse(AdjList g);

#endif // END ADJLIST_H
