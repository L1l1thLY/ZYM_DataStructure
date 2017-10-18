#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "common.h"

#define X 			10000
#define VertexNum 	7  //ʵ���Ϲ����������㣨1--6��
#define EdgeNum  	9

int Visited[VertexNum];
int Path[VertexNum];
int Distance[VertexNum];

/*****************************************************************************
 *          Dijkstra�㷨ʵ��                                                 *
 *****************************************************************************/
void Dijkstra(int begin);

#endif // DIJKSTRA_H
