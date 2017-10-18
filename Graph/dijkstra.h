#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "common.h"

#define X 			10000
#define VertexNum 	7  //实际上共有六个顶点（1--6）
#define EdgeNum  	9

int Visited[VertexNum];
int Path[VertexNum];
int Distance[VertexNum];

/*****************************************************************************
 *          Dijkstra算法实现                                                 *
 *****************************************************************************/
void Dijkstra(int begin);

#endif // DIJKSTRA_H
