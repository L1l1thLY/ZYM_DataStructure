#include "floyd.h"
#include <stdio.h>

Status CreateFloydGraph(FloydNode * F, int vexnum, int arcnum, VexType vexs[], 
ArcType arcs[][MAX], int weight[])
{
	int i;
	int j;
	if(vexnum < 0 || vexnum > MAX)
		return 1;
	if(arcnum < 0 || arcnum > MAX * (MAX - 1))
		return 1;
	
	F->arcnum = arcnum;
	F->vexnum = vexnum;
	
	// 初始化顶点信息
	for(i = 0; i < vexnum; i++)
	{
		F->vexs[i] = vexs[i];
	}
	
	for(i = 0; i < vexnum; i++)
	{
		for(j = 0; j < vexnum; j++)
		{
			F->arcs[i][j] = INFINITY;
			if(i == j)
			{
				F->arcs[i][j] = 0;
			}
		}
	}
	
	// 初始化边信息
	for(i = 0; i < arcnum; i++)
	{
		F->arcs[arcs[0][i]][arcs[1][i]] = weight[i];
	}
	
	return 0;
}

Status Floyd(FloydNode * F)
{
	int pos; // 尝试顶点
	int i;
	int j;
	int vexnum = F->vexnum;
	
	printf("\n%s\t", "原始信息");
	for(i = 0; i < vexnum; i++)
	{
		printf("%4c\t", F->vexs[i]);
	}
	printf("\n");
	for(i = 0; i < vexnum; i++)
	{
		printf("%8c\t", F->vexs[i]);
		for(j = 0; j < vexnum; j++)
		{
			printf("%4d\t", F->arcs[i][j]);
		}
		printf("\n");
	}
	
	// 弗洛伊德算法核心 
	for(pos = 0; pos < vexnum; pos++) 
	{
		for(i = 0; i < vexnum; i++)
		{
			if(pos == i) continue;
			for(j = 0; j < vexnum; j++)
			{
				if(pos == j) continue;
				if(i == j) continue;
				F->arcs[i][j] = F->arcs[i][pos]+F->arcs[pos][j] > F->arcs[i][j] 
				            ? F->arcs[i][j] : F->arcs[i][pos] + F->arcs[pos][j];
			}
		}
	}
	printf("\n%s\t", "最终信息");
	for(i = 0; i < vexnum; i++)
	{
		printf("%4c\t", F->vexs[i]);
	}
	printf("\n");
	for(i = 0; i < vexnum; i++)
	{
		printf("%8c\t", F->vexs[i]);
		for(j = 0; j < vexnum; j++)
		{
			printf("%4d\t", F->arcs[i][j]);
		}
		printf("\n");
	}
}
