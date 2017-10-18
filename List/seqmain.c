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
	
	srand((unsigned) time(NULL));         // ��ʱ�����֣�ÿ�β����������һ��
	for(i=0; i< (int)RANGE; i++)
	{
		arr[i] = (ElemType)rand() % 129;  // ����0-128�������
		printf("%4d\t", arr[i]);
	} 
	printf("\n");
	
	printf("��ʼ��ʼ��˳���...\n"); 
	InitialSeqList(&L , arr, 50);

	printf("��ʼ����˳���Ԫ��.\n");
	printf("������Ҫ���ҵ�Ԫ��ֵ:\n");
	scanf("%d",&b);
	a = LocateSeqList(L, b);
	if(a == -1)
		printf("�ڴ����Ա���û�и�Ԫ��!\n");
	else
		printf("��Ԫ�������Ա��е�λ��Ϊ:%d\n",a); 
	
	
	printf("��ʼ����Ԫ��.\n"); 
	InsertSeqList(L, 2, 3);
	
	e = (ElemType*)malloc(sizeof(ElemType));
	printf("��ʼɾ��Ԫ��.\n"); 
	DeleteSeqList(L, 2, e);
	printf("%d\n", *e);
	free(e);
	
	DestroySeqList(L);	
	return 0;
}
