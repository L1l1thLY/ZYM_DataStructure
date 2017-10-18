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
	
	// 存储顶点及其位置信息 
	for(i=0; i< vexnum; i++)
	{
		fflush(stdin);
		printf("input vexs[%d](e.g. A):", i);
		scanf("%c",&vexs[i]);
	}
	
	// 建立顶点之间的弧关系 
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
	
	// 存储顶点及其位置信息 
	for(i=0; i< vexnum; i++)
	{
		fflush(stdin);
		printf("input vexs[%d](e.g. A):", i);
		scanf("%c",&vexs[i]);
	}
	
	// 建立顶点之间的弧关系 
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
	
	// 存储顶点及其位置信息 
	for(i=0; i< vexnum; i++)
	{
		fflush(stdin);
		printf("input vexs[%d](e.g. A):", i);
		scanf("%c",&vexs[i]);
	}
	
	// 建立顶点之间的弧关系 
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
	printf("本程序将演示构造图的最小代价生成树。\n"); 
	printf("首先输入图的顶点数和弧数.\n格式：顶点数，弧数；例如:4,4\n"); 
	printf("接着输入各条弧(弧尾,弧头)和弧的权值。\n"); 
	printf("格式:弧尾，弧头，权值；例如\n1,2,1\n1,3,2\n2,4,3\n3,4,4\n"); 
	printf("程序将会构造该图的最小代价生成树。\n"); 
	printf("并显示该最小生成树。\n1,2\n1,3\n2,4\n"); 

	while(j!='N'&&j!='n') 
	{
		DefaultCreateGraph(G);              // 生成邻接矩阵结构的图 
		printf("从哪一顶点开始:"); 
		fflush(stdin);
		scanf("%d",&u);                     // 输入普里姆算法中的起始顶点 
		PrimMST(G,T,u);                     // 普里姆算法求最小生成树 
		PrintMST(T);                        // 打印最小生成树 
		printf("最小代价生成树构造完毕，继续进行吗?(Y/N)"); 
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
	printf("输入图的顶点个数和边的条数:");
	scanf("%d,%d", &vexnum, &arcnum);
	
	for(i = 0; i < vexnum; i++)
	{
		printf("输入顶点[%d]的标识符:", i);
		fflush(stdin);
		scanf("%c", &vexs[i]);
	}
	
	printf("输入边信息(起始点,终点,权值 格式如:1,2,9<Enter>,且顶点序号从0开始)");
	printf("\n");
	for(i = 0; i < arcnum; i++)
	{
		printf("输入边[%d]的信息:", i);
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
	printf("创建图:\n");
    
	printf("输入%d个顶点信息(顶点,入度).\n", MAXVEX);
    for (i = 0; i < MAXVEX; ++i)
    {
    	printf("Vex[%d]信息:", i) ;
    	scanf("%d,%d", &vn[i].data, &vn[i].innum);
    }

	printf("输入%d条弧的信息(起点,终点,权值).\n", MAXEDGE);
    for (i = 0; i < MAXEDGE; ++i)
    {
        printf("Arc[%d]信息:", i) ;
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
	
	printf("求拓扑序列:\n");
	TopologicalSort(g, pEtv, stack);
	
	printf("\n打印数组pEtv(各个事件的最早发生时间):\n");
	for(i = 0; i < MAXVEX; ++i)
	{
		printf("%2d\t", pEtv[i]);
	}
	
	printf("\n关键路径：\n");
	CriticalPath(g, pEtv, pLtv, stack);
	DestroyStack(stack);
	printf("\n");

#endif	
	return 0;
}
