#include "seqlist.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define RANGE 50

int main()
{	
	int         i;
	SeqList		L;
	ElemType	a;
	ElemType	b;
	ElemType * 	e;
	ElemType    arr[RANGE];
	
	srand((unsigned) time(NULL));         // 用时间做种，每次产生随机数不一样
	for(i=0; i< (int)RANGE; i++)
	{
		arr[i] = (ElemType)rand() % 129;  // 产生0-128的随机数
		printf("%4d\t", arr[i]);
	} 
	printf("\n");
	
	printf("开始初始化顺序表...\n"); 
	InitialSeqList(&L , arr, 50);

	printf("开始查找顺序表元素.\n");
	printf("请输入要查找的元素值:\n");
	scanf("%d",&b);
	a = LocateSeqList(L, b);
	if(a == -1)
		printf("在此线性表中没有该元素!\n");
	else
		printf("该元素在线性表中的位置为:%d\n",a); 
	
	
	printf("开始插入元素.\n"); 
	InsertSeqList(L, 2, 3);
	
	e = (ElemType*)malloc(sizeof(ElemType));
	printf("开始删除元素.\n"); 
	DeleteSeqList(L, 2, e);
	printf("%d\n", *e);
	free(e);
	
	DestroySeqList(L);	
	return 0;
}
