#include "criticalpath.h"
#include <stdio.h> 
#include <malloc.h>

void CreateGraphic(GraphAdjList g, VertexNode vn[], int arcs[][MAXEDGE], 
int weight[])
{
    int 		i;
    EdgeNode *  pNode;

    for (i = 0; i < MAXVEX; i++)
    {
        g->adjList[i].firstedge = NULL;
    }

    for (i = 0; i < MAXVEX; ++i)
    {
        g->adjList[i].data = vn[i].data;
        g->adjList[i].innum = vn[i].innum;
    }

    for (i = 0; i < MAXEDGE; ++i)
    {
        pNode = (EdgeNode *)malloc(sizeof(EdgeNode));
        pNode->adjvex = -1;
        pNode->next = NULL;
        pNode->adjvex = arcs[1][i];
        pNode->weight = weight[i];
        pNode->next = g->adjList[arcs[0][i]].firstedge;
        g->adjList[arcs[0][i]].firstedge = pNode;
    }
}

void PrintGraph(GraphAdjList g)
{
	int 		i;
	int 		index;
    EdgeNode * 	p;
	
    printf("��ӡAOE�����ڽӱ��߼�ͼ:\n" );
    for(i = 0; i < MAXVEX; ++i)
    {
        printf("%2d %3d", g->adjList[i].innum, g->adjList[i].data);
        p = g->adjList[i].firstedge;
        printf(" -->");
        while (p != NULL)
        {
            index = p->adjvex;
            printf("[%2d%3d] ", g->adjList[index].data, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}

int TopologicalSort(GraphAdjList g, int * pEtv, Stack * stack)
{
    EdgeNode * 	pNode;
    int 		i ;
    int 		k;
    int 		gettop;
    int 		nCnt;
   	Stack * 	s;
	
	s = (StackNode *)malloc(sizeof(StackNode));
	InitialStack(s);
	nCnt = 0;
	i = k = gettop = 0;
	
    for (i = 0; i < MAXVEX; ++i)
    {
        if (0 == g->adjList[i].innum)
        { 
            StackPush(s, i);
        } 
    }
    for (i = 0; i < MAXVEX; ++i)
    {
        pEtv[i] = 0;
    }
    while (!IsStackEmpty(s))
    {
        StackPop(s, &gettop);
        ++nCnt;
        StackPush(stack, gettop);    // �������Ķ������ѹ���������е�ջ
        if (MAXVEX == nCnt)
        {
            printf("%d\n", g->adjList[gettop].data); 
            break;
        }
        printf("%d-->", g->adjList[gettop].data);
        pNode = g->adjList[gettop].firstedge;
        while (pNode != NULL)
        {
            k = pNode->adjvex;
            -- g->adjList[k].innum;
            if (0 == g->adjList[k].innum)
                StackPush(s, k);
            if (pEtv[gettop] + pNode->weight > pEtv[k])
                pEtv[k] = pEtv[gettop] + pNode->weight;
            pNode = pNode->next;
        }
    }
    DestroyStack(s);
    return nCnt != MAXVEX;
}

void CriticalPath(GraphAdjList g, int * pEtv, int * pLtv, Stack * stack)
{
    // pEtv  �¼����緢��ʱ��
    // PLtv  �¼���ٷ���ʱ��

    EdgeNode * 	pNode;
    int 		i;
    int 		j;
    int 		k;
    int 		gettop;
    int 		ete;                  // ��������緢��ʱ��
	int 		lte;                  // �������ٷ���ʱ�����
    
	i = j = k = gettop = 0;
    ete = lte = 0;
	
	for (i = 0; i < MAXVEX; ++i)
    {
        pLtv[i] = pEtv[MAXVEX-1];     // ��ʼ��
    }
    
    while (!IsStackEmpty(stack))
    {
        StackPop(stack, &gettop);
        pNode = g->adjList[gettop].firstedge;
		// ��������¼�����ٷ���ʱ��pLtvֵ
        while (pNode != NULL)
        {    
            k = pNode->adjvex;
            if (pLtv[k] - pNode->weight < pLtv[gettop])
                pLtv[gettop] = pLtv[k] - pNode->weight;
            pNode = pNode->next;
        }
    }

    // �� ete, lte, �� �ؼ�·��
    for (j = 0; j < MAXVEX; ++j)
    {
        pNode = g->adjList[j].firstedge;
        while (pNode != NULL)
        {
            k = pNode->adjvex;
            ete = pEtv[j];                 // ����緢��ʱ��
            lte = pLtv[k] - pNode->weight; // ���ٷ���ʱ��
            if (ete == lte)
                printf("<V%d,V%d>:%d\n",g->adjList[j].data, g->adjList[k].data,
						pNode->weight);
            pNode = pNode->next;
        }
    }
}
