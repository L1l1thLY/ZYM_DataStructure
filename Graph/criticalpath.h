/*M//////////////////////////////////////////////////////////////////////////// 
//   关键路径算法头文件 
//*/

#ifndef CRITICALPATH_H
#define CRITICALPATH_H

#include "common.h" 

//typedef struct CGraphic
//{
//	VertexData 	vexs[MAX];      // 顶点表示 
//	int 		arcs[MAX][MAX]; // 边表示 
//	int			arcnum;         // 边数量 
//	int 		vexnum;	        // 顶点数量 
//}CGraphic;

/*****************************************************************************
 *     创建关键路径问题的图                                                  * 
 *****************************************************************************/ 
//void CreateGraphic(CGraphic * g, int vexnum, int arcnum, VertexData vexs[], 
//int arcs[][MAX], int weight[]);

/*****************************************************************************
 *     寻找图中的关键路径，计算最短时间                                      * 
 *****************************************************************************/ 
//void CriticalPath(CGraphic * g, int totaltime);

#define  MAXVEX   10
#define  MAXEDGE  13

typedef struct EdgeNode
{
    int 				adjvex;     // 邻接点域，存储该顶点对应的下标
    int 				weight;     // 边的权值
    struct EdgeNode * 	next;       // 链域
}EdgeNode;

typedef struct VertexNode
{
    int 		innum;              // 顶点入度值
    int 		data;               // 顶点数值域 
    EdgeNode * 	firstedge;          // 边表头指针
}VertexNode, AdjList[MAXVEX];

typedef struct GraphAdjListNode
{
    AdjList adjList;
    int 	vexnum;                // 图中当前顶点数和边数
	int 	arcnum;                // 图中当前顶点数和边数
}GraphAdjListNode, *GraphAdjList;

/******************************************************************************
 *           创建图                                                           *
 ******************************************************************************/
void CreateGraphic(GraphAdjList g, VertexNode vn[], int arcs[][MAXEDGE], 
int weight[]);

/******************************************************************************
 *           打印输入信息的逻辑图                                             *
 ******************************************************************************/
void PrintGraph(GraphAdjList g);

/******************************************************************************
 *           拓扑序列                                                         *
 ******************************************************************************/
int TopologicalSort(GraphAdjList g, int * pEtv, Stack * stack);

/******************************************************************************
 *           关键路径                                                         *
 ******************************************************************************/
void CriticalPath(GraphAdjList g, int * pEtv, int * pLtv, Stack * stack);

#endif // CRITICALPATH_H
