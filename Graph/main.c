// #include "adjmatrix.h"      
// #include "adjlist.h"         
// #include "orthlist.h"
// #include "prim.h"          
// #include "toposort.h"
// #include "dijkstra.h"
// #include "floyd.h"           
// #include "criticalpath.h"

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
#ifdef ADJMATRIX_H
	AdjMatrix 	g;
	VertexData 	vexs[MAX];
	VertexData 	arcs[2][MAX];
	int 		vexnum;
	int 		arcnum;
	int 		i;
	printf("input vexnum and arcnum(e.g. 4,2):");
	fflush(stdin);
	scanf("%d,%d", &vexnum, &arcnum);
	
	// �洢���㼰��λ����Ϣ 
	for(i=0; i< vexnum; i++)
	{
		fflush(stdin);
		printf("input vexs[%d](e.g. A):", i);
		scanf("%c",&vexs[i]);
	}
	
	// ��������֮��Ļ���ϵ 
	for(i = 0; i < arcnum; i++)
	{ 
		printf("input arc[%d](e.g. A,B):", i);
		fflush(stdin);
		scanf("%c,%c",&arcs[0][i],&arcs[1][i]);
	}
	
	CreateUDG(&g, vexnum, arcnum, vexs, arcs);
	Traverse(g);
#endif

#ifdef ADJLIST_H
	AdjList 	g;
	VertexData 	vexs[MAX];
	VertexData 	arcs[2][MAX];
	int 		vexnum;
	int 		arcnum;
	int 		i;
	printf("input vexnum and arcnum(e.g. 4,2):");
	fflush(stdin);
	scanf("%d,%d",&vexnum,&arcnum);
	
	// �洢���㼰��λ����Ϣ 
	for(i=0; i< vexnum; i++)
	{
		fflush(stdin);
		printf("input vexs[%d](e.g. A):", i);
		scanf("%c",&vexs[i]);
	}
	
	// ��������֮��Ļ���ϵ 
	for(i = 0; i < arcnum; i++)
	{ 
		printf("input arc[%d](e.g. A,B):", i);
		fflush(stdin);
		scanf("%c,%c",&arcs[0][i],&arcs[1][i]);
	}
	
	CreateAdjListUDG(&g, vexnum, arcnum, vexs, arcs);
	AdjListTraverse(g);
#endif

#ifdef ORTHLIST_H
	OrthList 	g;
	VertexData 	vexs[MAX];
	VertexData 	arcs[2][MAX];
	int 		vexnum;
	int 		arcnum;
	int 		i;
	printf("input vexnum and arcnum(e.g. 4,2):");
	fflush(stdin);
	scanf("%d,%d",&vexnum,&arcnum);
	
	// �洢���㼰��λ����Ϣ 
	for(i=0; i< vexnum; i++)
	{
		fflush(stdin);
		printf("input vexs[%d](e.g. A):", i);
		scanf("%c",&vexs[i]);
	}
	
	// ��������֮��Ļ���ϵ 
	for(i = 0; i < arcnum; i++)
	{ 
		printf("input arc[%d](e.g. A,B):", i);
		fflush(stdin);
		scanf("%c,%c",&arcs[0][i],&arcs[1][i]);
	}
	CreateOrthList(&g, vexnum, arcnum, vexs, arcs);
#endif

#ifdef PRIM_H
	int		u; 
	char	j;
	j = 'y'; 
	printf("��������ʾ����ͼ����С������������\n"); 
	printf("��������ͼ�Ķ������ͻ���.\n��ʽ��������������������:4,4\n"); 
	printf("�������������(��β,��ͷ)�ͻ���Ȩֵ��\n"); 
	printf("��ʽ:��β����ͷ��Ȩֵ������\n1,2,1\n1,3,2\n2,4,3\n3,4,4\n"); 
	printf("���򽫻ṹ���ͼ����С������������\n"); 
	printf("����ʾ����С��������\n1,2\n1,3\n2,4\n"); 

	while(j!='N'&&j!='n') 
	{
		DefaultCreateGraph(G);              // �����ڽӾ���ṹ��ͼ 
		printf("����һ���㿪ʼ:"); 
		fflush(stdin);
		scanf("%d",&u);                     // ��������ķ�㷨�е���ʼ���� 
		PrimMST(G,T,u);                     // ����ķ�㷨����С������ 
		PrintMST(T);                        // ��ӡ��С������ 
		printf("��С����������������ϣ�����������?(Y/N)"); 
		fflush(stdin);
		scanf("%c",&j); 
	}
#endif

#ifdef TOPOSORT_H
	Graph 	G;
	int 	i;
	int 	edge[2][MAX];
	
	printf("input the number of vex, arc and GraphKind(e.g. 4,3,3):");
	fflush(stdin);
	scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&G.kind);
	for(i = 0; i < G.arcnum; i++)
	{
		printf("input the vertex of edge[%d](e.g. 1,2):", i);
		fflush(stdin);
		scanf("%d,%d", &edge[0][i], &edge[1][i]);
	}
	
	Create(&G, edge);
	printf("The outcome of TopoSort is:");
	TopoSort(&G);
	printf("\n");
#endif

#ifdef DIJKSTRA_H
	int i;
	int k;
	
	for(i=0; i<VertexNum; i++)
	{ 
		Visited[i] = 0;  
		Path[i] = 1;
	}
	Dijkstra(1);
	printf("\n\nAll Path-------------------------\n");
	
	for(i=2; i<VertexNum; i++)
	{
		printf("[%d] ",Distance[i]);
		k = i;
		do
		{
			printf("%d<--",k);
			k  = Path[k];
		}while(k!=1);
		printf("1 \n");
	}
#endif

#ifdef FLOYD_H
	FloydNode * F;
	int			i;
	int			vexnum;
	int 		arcnum;
	VexType 	vexs[MAX];
    ArcType 	arcs[2][MAX];
    int 		weight[MAX];
	
	F = (FloydNode *)malloc(sizeof(FloydNode));
	
	fflush(stdin); 
	printf("����ͼ�Ķ�������ͱߵ�����:");
	scanf("%d,%d", &vexnum, &arcnum);
	
	for(i = 0; i < vexnum; i++)
	{
		printf("���붥��[%d]�ı�ʶ��:", i);
		fflush(stdin);
		scanf("%c", &vexs[i]);
	}
	
	printf("�������Ϣ(��ʼ��,�յ�,Ȩֵ ��ʽ��:1,2,9<Enter>,�Ҷ�����Ŵ�0��ʼ)");
	printf("\n");
	for(i = 0; i < arcnum; i++)
	{
		printf("�����[%d]����Ϣ:", i);
		fflush(stdin);
		scanf("%d,%d,%d", &arcs[0][i],&arcs[1][i],&weight[i]);
	}
	
	CreateFloydGraph(F, vexnum, arcnum, vexs, arcs, weight);
	Floyd(F); 
	
	
#endif

#ifdef CRITICALPATH_H
    int 			i;
	int * 			pEtv;
	int * 			pLtv;
	int 			arcs[2][MAXEDGE];
	int 			weight[MAXEDGE];
	GraphAdjList 	g;
	VertexNode 		vn[MAXVEX];
	Stack * 		stack;
	
	stack = (StackNode *)malloc(sizeof(StackNode));
	InitialStack(stack);
	pEtv = (int *)malloc(sizeof(int) * MAXVEX);
	pLtv = (int *)malloc(sizeof(int) * MAXVEX);
	g = (GraphAdjListNode *)malloc(sizeof(GraphAdjListNode));
	
	/*
	printf("����ͼ:\n");
    
	printf("����%d��������Ϣ(����,���).\n", MAXVEX);
    for (i = 0; i < MAXVEX; ++i)
    {
    	printf("Vex[%d]��Ϣ:", i) ;
    	scanf("%d,%d", &vn[i].data, &vn[i].innum);
    }

	printf("����%d��������Ϣ(���,�յ�,Ȩֵ).\n", MAXEDGE);
    for (i = 0; i < MAXEDGE; ++i)
    {
        printf("Arc[%d]��Ϣ:", i) ;
    	scanf("%d,%d,%d", &arcs[0][i], &arcs[1][i], &weight[i]);
    }*/
	
	vn[0].data = 0; vn[0].innum = 0;
	vn[1].data = 1; vn[1].innum = 1;
	vn[2].data = 2; vn[2].innum = 1;
	vn[3].data = 3; vn[3].innum = 2;
	vn[4].data = 4; vn[4].innum = 2;
	vn[5].data = 5; vn[5].innum = 1;
	vn[6].data = 6; vn[6].innum = 1;
	vn[7].data = 7; vn[7].innum = 2;
	vn[8].data = 8; vn[8].innum = 1;
	vn[9].data = 9; vn[9].innum = 2;
	
	arcs[0][0] = 0; arcs[1][0] = 1; weight[0] = 3;
	arcs[0][1] = 0; arcs[1][1] = 2; weight[1] = 4;
	arcs[0][2] = 1; arcs[1][2] = 3; weight[2] = 5;
	arcs[0][3] = 1; arcs[1][3] = 4; weight[3] = 6;
	arcs[0][4] = 2; arcs[1][4] = 3; weight[4] = 8;
	arcs[0][5] = 2; arcs[1][5] = 5; weight[5] = 7;
	arcs[0][6] = 3; arcs[1][6] = 4; weight[6] = 3;
	arcs[0][7] = 4; arcs[1][7] = 6; weight[7] = 9;
	arcs[0][8] = 4; arcs[1][8] = 7; weight[8] = 4;
	arcs[0][9] = 5; arcs[1][9] = 7; weight[9] = 6;
	arcs[0][10] = 6; arcs[1][10] = 9; weight[10] = 2;
	arcs[0][11] = 7; arcs[1][11] = 8; weight[11] = 5;
	arcs[0][12] = 8; arcs[1][12] = 9; weight[12] = 3;

	CreateGraphic(g, vn, arcs, weight);
	
	PrintGraph(g);
	
	printf("����������:\n");
	TopologicalSort(g, pEtv, stack);
	
	printf("\n��ӡ����pEtv(�����¼������緢��ʱ��):\n");
	for(i = 0; i < MAXVEX; ++i)
	{
		printf("%2d\t", pEtv[i]);
	}
	
	printf("\n�ؼ�·����\n");
	CriticalPath(g, pEtv, pLtv, stack);
	DestroyStack(stack);
	printf("\n");

#endif	
	return 0;
}
