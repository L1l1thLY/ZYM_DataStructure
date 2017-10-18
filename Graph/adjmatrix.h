#ifndef ADJMATRIX_H
#define ADJMATRIX_H

#include "common.h"

typedef struct ArcNode
{
	int adj;
} ArcNode;

typedef struct AdjMatrixNode
{
	VertexData	vexs[N];
	ArcNode		arcs[N][N];
	int			vexnum; 
	int			arcnum;
	GraphKind	kind;
}AdjMatrix;

/******************************************************************************
 *      获取节点位置                                                          *
 ******************************************************************************/
int LocateVertex(AdjMatrix * g, VertexData v);

/******************************************************************************
 *      创建邻接矩阵方式存储的无向图                                          *
 ******************************************************************************/
int CreateUDG(AdjMatrix * g, int vexnum, int arcnum, VertexData vexs[],
			 VertexData arcs[][MAX]);

/******************************************************************************
 *      无向图的深度优先遍历                                                  *
 ******************************************************************************/
void DFS(AdjMatrix g,int v);

/******************************************************************************
 *      无向图的遍历                                                         *
 ******************************************************************************/
void Traverse(AdjMatrix g);

#endif // END ADJMATRIX_H
