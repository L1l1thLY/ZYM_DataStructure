#ifndef FLOYD_H
#define FLOYD_H

#include "common.h"

typedef char VexType;
typedef int  ArcType;

typedef struct FloydNode
{
	int 	arcnum;
	int 	vexnum;
	VexType vexs[MAX];
	ArcType arcs[MAX][MAX];
}FloydNode; 

/*****************************************************************************
 *         Floyd算法                                                         *
 *****************************************************************************/
Status Floyd(FloydNode * F); 

/*****************************************************************************
 *         建立带权图的邻接矩阵                                              *
 *****************************************************************************/
Status CreateFloydGraph(FloydNode * F, int vexnum, int arcnum, VexType vexs[], 
ArcType arcs[][MAX], int weight[]);



#endif // FLOYD_H
