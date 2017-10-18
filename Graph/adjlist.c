#include "adjlist.h" 
#include "common.h"
#include <stdio.h> 

int AdjListLocateVertex(AdjList * g,VertexData v)
{
	int i;
	int j;
	
	j = -1;
	
	for(i=0;i<g->vexnum;i++)
	{
		if(g->vertex[i].data==v)
		{
			j = i;
			break;
		}
	}
		
	return(j);
}

int CreateAdjListUDG(AdjList * g, int vexnum, int arcnum, VertexData vexs[],
			 VertexData arcs[][MAX])
{
	int 				i;
	int 				j;
	int 				k;
	AdjListArcNode * 	p;
	AdjListArcNode * 	r;
	
	g->vexnum = vexnum;
	g->arcnum = arcnum;
	
	// ∂•µ„
	for(i=0; i < g->vexnum; i++)
	{ 
		g->vertex[i].data= vexs[i];
		g->vertex[i].firstarc=NULL;
	}
	
	// ±ﬂ–≈œ¢ 
	for(k = 0; k< g->arcnum; k++)
	{

  		i = AdjListLocateVertex(g, arcs[0][k]);
		j = AdjListLocateVertex(g, arcs[1][k]);
  		
  		p = (AdjListArcNode *)malloc(sizeof(AdjListArcNode));
    	p->adjvex = j;
        p->nextarc = g->vertex[i].firstarc;
        g->vertex[i].firstarc = p;
        
        r = (AdjListArcNode *)malloc(sizeof(AdjListArcNode));
        r->adjvex = i;
        r->nextarc = g->vertex[j].firstarc;
        g->vertex[j].firstarc = r;
	}
}

void AdjListDFS(AdjList g,int vo)
{
	AdjListArcNode *	p;
	printf("%c", g.vertex[vo].data);
	visited[vo]=True;
	p=g.vertex[vo].firstarc;
	while(p!=NULL)
	{
		if(!visited[p->adjvex])
		{
			AdjListDFS(g,p->adjvex);
		}	
		p=p->nextarc;
	}
}

void AdjListBFS(AdjList g,int vo)
{
	AdjListArcNode 	*	p;
	int 				vi;
	Queue 				Q;
	
	InitQueue(&Q);
	visited[vo]=True;
	EnterQueue(&Q,vo);
	while(!IsQueueEmpty(&Q))
	{
		DeleteQueue(&Q,&vi);
		printf("%c",g.vertex[vi].data);
		p=g.vertex[vi].firstarc;
		while(p!=NULL)
		{
			if(!visited[p->adjvex])
			{
				visited[p->adjvex]=True;
				EnterQueue(&Q,p->adjvex);
			}
			p=p->nextarc;
		}
	}
}

void AdjListTraverse(AdjList g)
{
	int vi;
	for(vi=0;vi<g.vexnum;vi++)
	{
		visited[vi]=False;
	}	
	printf("\nThe order of g Depth\n");
	
	for(vi=0;vi<g.vexnum;vi++)
	{
		if(!visited[vi])
		{
			AdjListDFS(g,vi); 
			printf("\n");
		}
	}
	
	for(vi=0;vi<g.vexnum;vi++)
	{
		visited[vi]=False;
	}	
	
	printf("\nThe order of g Breadth\n");
	for(vi=0;vi<g.vexnum;vi++)
    {
		if(!visited[vi])
		{
			AdjListBFS(g,vi);   
			printf("\n");
		}
	}
}
