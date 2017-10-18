//M//////////////////////////////////////////////////////////////////////////
//  ͼ��ʮ������ṹ��ʽ������
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
	VertexData		data;         // ������Ϣ
	OrthArcNode *	firstin;
	OrthArcNode *	firstout;   
}VertexNode;

typedef struct OrthListNode
{
	VertexNode	vertex[MAX_VERTEX_NUM];   
	int			vexnum;
	int			arcnum;          // ͼ�Ķ������ͻ���
	GraphKind	kind;            // ͼ������
}OrthList;                       // ͼ��ʮ�������ʾ��(Orthogonal List)

/******************************************************************************
 *      ����ʮ������ͼ                                                        *
 ******************************************************************************/
void CreateOrthList(OrthList * G,  int vexnum, int arcnum, VertexData vexs[],
			 VertexData arcs[][MAX]);

/******************************************************************************
 *      �󶥵�λ�ú���                                                        *
 ******************************************************************************/
int OrthListLocateVertex(OrthList * G, VertexData v);

#endif // ORTHLIST_H
