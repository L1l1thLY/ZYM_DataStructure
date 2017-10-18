#include "adjmatrix.h"
#include "common.h"
#include <stdio.h>

int LocateVertex(AdjMatrix * g, VertexData v)
{
	int i;
	int j;
	j = -1;
	for(i=0; i<g->vexnum; i++)
	{
		if(g->vexs[i]==v)
		{
			j = i;
			break;
		}
	}
		
	return(j);
}

int CreateUDG(AdjMatrix * g, int vexnum, int arcnum, VertexData vexs[],
			 VertexData arcs[][MAX])
{
	int i;
	int j;
    int k;

	g->vexnum = vexnum;
	g->arcnum = arcnum;
	
	for(i=0; i<g->vexnum; i++)
	{
		for(j=0; j<g->vexnum; j++)
		{
			g->arcs[i][j].adj = 0;
		}	
	}	
    
	// 存储顶点及其位置信息
	for(i = 0; i < vexnum; i++)
	{ 
	    g->vexs[i] = vexs[i];
	}
	
	// 建立顶点之间的弧关系 
	for(k=0; k<g->arcnum; k++)
	{ 
		
		i = LocateVertex(g,arcs[0][k]);
		j = LocateVertex(g,arcs[1][k]);
		g->arcs[i][j].adj = 1;
		g->arcs[j][i].adj = 1;
	}
	return(Ok);
}

void DFS(AdjMatrix g,int vo)
{
	int vj;
	printf("%c",g.vexs[vo]);
	visited[vo]=True;
	for(vj=0;vj<g.vexnum;vj++)
	{
		if((!visited[vj])&&(g.arcs[vo][vj].adj==1))
		{
			DFS(g,vj);
		}	
	}	
}

void BFS(AdjMatrix g,int vo)
{
	int 		vi;
	int 		vj;
	Queue 		Q;
	
	InitQueue(&Q);
	visited[vo]=True;
	EnterQueue(&Q,vo);
	while(!IsQueueEmpty(&Q))
	{
		DeleteQueue(&Q,&vi);
		printf("%c",g.vexs[vi]);
		for(vj=0;vj<g.vexnum;vj++)
		{
			if((!visited[vj])&&(g.arcs[vi][vj].adj==1))
			{
				visited[vj]=True;
				EnterQueue(&Q,vj);
			}
		}	
	}
}

void Traverse(AdjMatrix g)
{
	int vi;
	for(vi=0;vi<g.vexnum;vi++)
	{
		visited[vi]=False;
	}	
	printf("\nDFS:");
	for(vi=0;vi<g.vexnum;vi++)
	{
		if(!visited[vi])
		{
			DFS(g,vi);    
			printf("\n");
		}
	}
	for(vi=0;vi<g.vexnum;vi++)
	{
		visited[vi]=False;
	}	
	printf("BFS:");
	for(vi=0;vi<g.vexnum;vi++)
	{
		if(!visited[vi])
		{
			BFS(g,vi);    
			printf("\n");
		}
	}
}
