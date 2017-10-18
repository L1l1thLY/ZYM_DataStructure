#ifndef TOPOSORT_H
#define TOPOSORT_H

#include "common.h"

typedef struct ArcNode
{
	int 			adjvex;
	int 			weight;
	struct ArcNode	*nextarc;
}ArcNode, *AdjList;

typedef struct GraphNode
{
	AdjList 	elem[MAX+1];
	int 		vexnum;
	int 		arcnum;
	GraphKind 	kind;
}GraphNode, Graph;

/******************************************************************************
 *         创建拓扑排序问题的图                                               *
 ******************************************************************************/
void Create(Graph * G, int edge[][MAX]);

/******************************************************************************
 *         拓扑排序                                                           *
 ******************************************************************************/
int TopoSort(Graph * G);

#endif // END TOPOSORT_H
