#include "linklist.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define RANGE 50

int main()
{
    LinkList		L;
    LinkList		La;
	LinkList		Lb;
	LinkList		Lc;
 	DoubleLinkList	dl;
	ElemType		key;
	ElemType		elem; 
    ElemType		E;
    LinkListNode * 	e;
 	int				Length;
 	int 			i;
	ElemType    	arr[RANGE], arr2[RANGE];
	
	key = 2; 
	
	srand((unsigned) time(NULL));         // ��ʱ�����֣�ÿ�β����������һ��
	for(i=0; i< (int)RANGE; i++)
	{
		arr[i] = (ElemType)rand() % 129;  // ����0-128�������	
	}
	printf("---------------------------���������ݼ�---------------------");
	printf("--------------------\n");
	for(i=0; i< (int)RANGE; i++)
	{
		printf("%4d\t", arr[i]);
	}
	printf("------------------------------------------------------------");
	printf("--------------------\n");
	
	for(i = 0; i < (int)RANGE / 2; i++)
	{
		arr2[i] = arr[RANGE -i];
	}
	printf("\n");

/* ********************�������������**************************** */ 
//	// ��ʼ������
//    printf("��ʼ��ʼ������...\n");  
//    InitialLinkList(&L);
//
//    // ͷ���뷽ʽ�������� - ��ͷ�ڵ� 
//    CreateLinkListFromHead(L, arr, 50);
     
//    // �������� 
//    printf("������������\n");
//    TravelLinkList(L);
//
//   // ��������ʱ��������ڵ���2
//    e =  (LinkListNode *)malloc(sizeof(struct LinkListNode));
//    e =  GetLinkListNode(L, 2);/* ���ҵ�����L�в��ҵ�i����� */
//    printf("��2��Ԫ���ǣ�%d\n", e->data);
//    free(e);
    
//    // ���ұ�L�е�Ԫ��e 
//    e =  (LinkListNode *)malloc(sizeof(struct LinkListNode));
//    e = LocateLinkList(L, arr[1]);
//    if(e && e->data) 
//		printf("�ҵ�Ԫ��[ %4d ]\n", arr[1]);
//    else 
//		printf("δ�ҵ�Ԫ��[ %4d ]\n", arr[1]);
//    free(e);
    
//     Length = LinkListLength(L);
//     printf("������Ϊ��%d\n", Length);
//
//
//	  printf("�ڵ�����λ���ϲ���[%4d]��\n", key);
//	  InsertLinkList(L, 3, key);
//	  TravelLinkList(L);
    

//    DeleteLinkList(L, 2, &E);
//    printf("ɾ����2��Ԫ��[%4d]��\n", E);
//    TravelLinkList(L);
//	  free(e);
/* ********************END �������������************************ */ 
    
/* ********************�ϲ����������**************************** */    
//    InitialLinkList(&La);
//    InitialLinkList(&Lb);
//    CreateLinkListFromHead(La, arr, 10);
//    CreateLinkListFromHead(Lb, arr2, 9); 
//    Lc = MergeLinkList(La,Lb);
//    TravelLinkList(Lc);
/* ********************END �ϲ����������************************ */

/* ********************˫�������������**************************** */ 
//	dl = (DoubleLinkListNode *)malloc(sizeof(struct DoubleLinkListNode));
//	dl->next = dl;
//	dl->prior = dl; 
//	CreateDoubleLinkList(dl, arr, 10);
//	
//	InsertDoublelinkList(dl, 2, key);
//	DeleteDoubleLinkList(dl, 2, &elem);
//	printf("%d\n", elem); 
/* ********************END ˫�������������************************ */	    
    return 0;
}
