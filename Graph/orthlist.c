#include "orthlist.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int OrthListLocateVertex(OrthList * G,VertexData v)    
{
	int	i;
	int	j;
	i = -1;
	for(j=0;j<G->vexnum;j++)
		if(G->vertex[j].data == v)
		{ 
			i = j; 
			break; 
		}
	return(i);
}

void CreateOrthList(OrthList * g,  int vexnum, int arcnum, VertexData vexs[],
			 VertexData arcs[][MAX])
{
	int				i;
	int				j;
	int				k;
	OrthArcNode * 	p;
	
	g->vexnum = vexnum;
	g->arcnum = arcnum;
	
	// ¶¥µã 
	for(i = 0; i < g->vexnum; i++) 
	{
		g->vertex[i].data = vexs[i];
		g->vertex[i].firstin=NULL;
		g->vertex[i].firstout=NULL;
	}
	
	// ±ß 
	for(k = 0; k < g->arcnum; k++) 
	{

		i = LocateVertex(g, arcs[0][k]);
		j = LocateVertex(g, arcs[0][k]);
		p=(OrthArcNode*)malloc(sizeof(OrthArcNode));
		p->tailvex=i;
		p->headvex=j;
		p->tlink=g->vertex[i].firstout;
		g->vertex[i].firstout=p;
		p->hlink=g->vertex[j].firstin;
		g->vertex[j].firstin=p;
    }
}
