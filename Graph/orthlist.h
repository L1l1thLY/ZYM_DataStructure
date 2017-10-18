//M//////////////////////////////////////////////////////////////////////////
//  图的十字链表结构形式化定义
//M

#ifndef ORTHLIST_H
#define ORTHLIST_H

#include "common.h"

typedef struct OrthArcNode 
{
	int						tailvex;
	int						headvex;  
	struct OrthArcNode *	hlink;
	struct OrthArcNode *	tlink;    
}OrthArcNode;

typedef struct VertexNode
{
	VertexData		data;         // 顶点信息
	OrthArcNode *	firstin;
	OrthArcNode *	firstout;   
}VertexNode;

typedef struct OrthListNode
{
	VertexNode	vertex[MAX_VERTEX_NUM];   
	int			vexnum;
	int			arcnum;          // 图的顶点数和弧数
	GraphKind	kind;            // 图的种类
}OrthList;                       // 图的十字链表表示法(Orthogonal List)

/******************************************************************************
 *      创建十字链表图                                                        *
 ******************************************************************************/
void CreateOrthList(OrthList * G,  int vexnum, int arcnum, VertexData vexs[],
			 VertexData arcs[][MAX]);

/******************************************************************************
 *      求顶点位置函数                                                        *
 ******************************************************************************/
int OrthListLocateVertex(OrthList * G, VertexData v);

#endif // ORTHLIST_H
