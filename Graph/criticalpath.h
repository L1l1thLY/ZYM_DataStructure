/*M//////////////////////////////////////////////////////////////////////////// 
//   �ؼ�·���㷨ͷ�ļ� 
//*/

#ifndef CRITICALPATH_H
#define CRITICALPATH_H

#include "common.h" 

//typedef struct CGraphic
//{
//	VertexData 	vexs[MAX];      // �����ʾ 
//	int 		arcs[MAX][MAX]; // �߱�ʾ 
//	int			arcnum;         // ������ 
//	int 		vexnum;	        // �������� 
//}CGraphic;

/*****************************************************************************
 *     �����ؼ�·�������ͼ                                                  * 
 *****************************************************************************/ 
//void CreateGraphic(CGraphic * g, int vexnum, int arcnum, VertexData vexs[], 
//int arcs[][MAX], int weight[]);

/*****************************************************************************
 *     Ѱ��ͼ�еĹؼ�·�����������ʱ��                                      * 
 *****************************************************************************/ 
//void CriticalPath(CGraphic * g, int totaltime);

#define  MAXVEX   10
#define  MAXEDGE  13

typedef struct EdgeNode
{
    int 				adjvex;     // �ڽӵ��򣬴洢�ö����Ӧ���±�
    int 				weight;     // �ߵ�Ȩֵ
    struct EdgeNode * 	next;       // ����
}EdgeNode;

typedef struct VertexNode
{
    int 		innum;              // �������ֵ
    int 		data;               // ������ֵ�� 
    EdgeNode * 	firstedge;          // �߱�ͷָ��
}VertexNode, AdjList[MAXVEX];

typedef struct GraphAdjListNode
{
    AdjList adjList;
    int 	vexnum;                // ͼ�е�ǰ�������ͱ���
	int 	arcnum;                // ͼ�е�ǰ�������ͱ���
}GraphAdjListNode, *GraphAdjList;

/******************************************************************************
 *           ����ͼ                                                           *
 ******************************************************************************/
void CreateGraphic(GraphAdjList g, VertexNode vn[], int arcs[][MAXEDGE], 
int weight[]);

/******************************************************************************
 *           ��ӡ������Ϣ���߼�ͼ                                             *
 ******************************************************************************/
void PrintGraph(GraphAdjList g);

/******************************************************************************
 *           ��������                                                         *
 ******************************************************************************/
int TopologicalSort(GraphAdjList g, int * pEtv, Stack * stack);

/******************************************************************************
 *           �ؼ�·��                                                         *
 ******************************************************************************/
void CriticalPath(GraphAdjList g, int * pEtv, int * pLtv, Stack * stack);

#endif // CRITICALPATH_H
