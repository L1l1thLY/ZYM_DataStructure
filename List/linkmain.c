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
	
	srand((unsigned) time(NULL));         // 用时间做种，每次产生随机数不一样
	for(i=0; i< (int)RANGE; i++)
	{
		arr[i] = (ElemType)rand() % 129;  // 产生0-128的随机数	
	}
	printf("---------------------------测试用数据集---------------------");
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

/* ********************单链表基本操作**************************** */ 
//	// 初始化链表
//    printf("开始初始化链表...\n");  
//    InitialLinkList(&L);
//
//    // 头出入方式创建链表 - 带头节点 
//    CreateLinkListFromHead(L, arr, 50);
     
//    // 遍历链表 
//    printf("输出遍历结果：\n");
//    TravelLinkList(L);
//
//   // 创建链表时长度需大于等于2
//    e =  (LinkListNode *)malloc(sizeof(struct LinkListNode));
//    e =  GetLinkListNode(L, 2);/* 查找单链表L中查找第i个结点 */
//    printf("第2个元素是：%d\n", e->data);
//    free(e);
    
//    // 查找表L中的元素e 
//    e =  (LinkListNode *)malloc(sizeof(struct LinkListNode));
//    e = LocateLinkList(L, arr[1]);
//    if(e && e->data) 
//		printf("找到元素[ %4d ]\n", arr[1]);
//    else 
//		printf("未找到元素[ %4d ]\n", arr[1]);
//    free(e);
    
//     Length = LinkListLength(L);
//     printf("链表长度为：%d\n", Length);
//
//
//	  printf("在第三个位置上插入[%4d]后：\n", key);
//	  InsertLinkList(L, 3, key);
//	  TravelLinkList(L);
    

//    DeleteLinkList(L, 2, &E);
//    printf("删除第2个元素[%4d]后：\n", E);
//    TravelLinkList(L);
//	  free(e);
/* ********************END 单链表基本操作************************ */ 
    
/* ********************合并单链表操作**************************** */    
//    InitialLinkList(&La);
//    InitialLinkList(&Lb);
//    CreateLinkListFromHead(La, arr, 10);
//    CreateLinkListFromHead(Lb, arr2, 9); 
//    Lc = MergeLinkList(La,Lb);
//    TravelLinkList(Lc);
/* ********************END 合并单链表操作************************ */

/* ********************双单链表基本操作**************************** */ 
//	dl = (DoubleLinkListNode *)malloc(sizeof(struct DoubleLinkListNode));
//	dl->next = dl;
//	dl->prior = dl; 
//	CreateDoubleLinkList(dl, arr, 10);
//	
//	InsertDoublelinkList(dl, 2, key);
//	DeleteDoubleLinkList(dl, 2, &elem);
//	printf("%d\n", elem); 
/* ********************END 双单链表基本操作************************ */	    
    return 0;
}
