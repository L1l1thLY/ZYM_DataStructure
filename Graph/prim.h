#ifndef PRIM_H
#define PRIM_H

#include "common.h"

typedef int AdjMatrix[N][N];      // �ö�ά������Ϊ�ڽӾ����ʾ 

// ���߽��
typedef struct TreeEdgeNode{
	int fromvex;                  // �ߵ����
	int tovex;                    // �ߵ��յ� 
	int length;                   // ���ϵ�Ȩ 
}TreeEdgeNode; 

typedef TreeEdgeNode MST[N-1];    // ��С���������� 

AdjMatrix	G;                    // ��ͨ���Ĵ�Ȩ�ڽӾ���,��ΪPrim�㷨������ 
MST 		T;                    // ���G����С����������ΪPrim�㷨����� 

/******************************************************************************
 *    ��ӡ������Ϣ                                                            *
 ******************************************************************************/
void Log(char * msg);

/******************************************************************************
 *    ͼ�������㷨                                                            *
 ******************************************************************************/
void CreateGraph(AdjMatrix G, int vexnum, int arcnum, int arcs[][MAX], int w[]);

/******************************************************************************
 *    Ĭ��ͼ����                                                              *
 ******************************************************************************/
void DefaultCreateGraph(AdjMatrix G);

/******************************************************************************
 *    �����ʼ��ʱ��ѡ��߼�T[0...n-2]�����߼�TE!=Null,��㼯U={r}            *
 ******************************************************************************/
void InitCandidateSet(AdjMatrix G, MST T, int r);
 
/******************************************************************************
 *    �ڵ�ǰ��ѡ��߼���ѡ��һ�����,��ѡ�񳤶���̵��ϱ�                     *
 ******************************************************************************/ 
int SelectLightEdge(MST T, int k);

/******************************************************************************
 *    ������ѡ�߼�                                                            *
 ******************************************************************************/
void ModifyCandidateSet(AdjMatrix G, MST T, int k, int v);

/******************************************************************************
 *    ��ͼG����rΪ����MST,rΪ��ʼ�Ľ��                                       *
 ******************************************************************************/
void PrimMST(AdjMatrix G, MST T, int r);

/******************************************************************************
 *    ��ӡ��С������                                                           *
 ******************************************************************************/
void PrintMST(MST T);

#endif // PRIM_H