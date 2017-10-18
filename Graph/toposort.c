#include "toposort.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void Create(Graph * G, int edge[][MAX])
{
	int 		i;
	int 		start; 
	int 		end;
	ArcNode * 	p;
	for(i=0; i<=MAX; i++)
	{
		G->elem[i] = NULL;
	}	
	for(i = 0; i < G->arcnum; i++)
	{
		start = edge[0][i];
		end = edge[1][i];
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = end;
		p->nextarc = G->elem[start];
		G->elem[start] = p;
		if(G->kind == 0)
		{
			p=(AdjList)malloc(sizeof(ArcNode));
			p->adjvex=start;
			p->nextarc = G->elem[end];
			G->elem[end] = p;
		}
	}
}

int TopoSort(Graph * G)
{
	int 	i;
	int 	count;
	int 	indegree[MAX+1];
	AdjList p;
	Stack *	S;
	for(i = 1; i <= G->vexnum; i++)
	{
		indegree[i]=0;
	}	
	InitialStack(S);
	for(i=1;i<=G->vexnum;i++)
	{
		for(p=G->elem[i]; p; p = p->nextarc)
		{
			++indegree[p->adjvex];
		}	
	}	
	for(i = 1; i <= G->vexnum; i++)
	{
		if(!indegree[i])
		{
			StackPush(S,i);
		} 
	}	
	count=0;
	while(!IsStackEmpty(S))
	{
		StackPop(S,&i);
		printf("v%d\t",i);
		++count;
		for(p=G->elem[i]; p; p = p->nextarc)
		{
			if(!(--indegree[p->adjvex])) 
			{
				StackPush(S,p->adjvex);
			}
		}	
	}
	DestroyStack(S); 
	if(!count) 
	{
		return Failure;
	}
	return Success;
}
