#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
#include "linklist.h" 

void InitialLinkList(LinkList * L)
{
	(*L) = (LinkList)malloc(sizeof(LinkListNode));
	memset(&((*L)->data), '\0', sizeof(ElemType));
	(*L)->next = NULL;
}

int CreateLinkListFromHead(LinkList L, ElemType e[], int len)
{ 
	LinkListNode * 	pLinkListNode;
	LinkListNode * 	pLinkListHead;
	int 			i;
	Message 		msguninitial, msgsuccess;
	
	
	pLinkListHead = L;
	msguninitial = Uninitial;
	msgsuccess = Success;
	
    if('$' != (char)pLinkListHead->data){
        return msguninitial;
    }
    
	for(i = 0; i < len; i++)
	{	
		pLinkListNode = (LinkListNode *)malloc(sizeof(LinkListNode)); 
		pLinkListNode->data = e[i];
		pLinkListNode->next = pLinkListHead->next; 
		pLinkListHead->next = pLinkListNode;
	}
	
	return msgsuccess;
}

int CreateLinkListFromTail(LinkList L, ElemType e[], int len)
{ 
	Message 		msguninitial, msgsuccess;
	LinkListNode * 	pTailNode;
	LinkListNode * 	pLinkListNode;
	int				i;
	
	i = 0;
	msguninitial = Uninitial;
	msgsuccess = Success;
	
	if('$' != (char)L->data){
        return msguninitial;
    }
	
	pTailNode = L;    // pTailNode指针动态指向链表的当前表尾，以便于做尾插入，
                      // 其初值指向头结点
	for( ; i < len; i++)
	{
		pLinkListNode = (LinkListNode*)malloc(sizeof(LinkListNode));
		pLinkListNode->data = e[i];
		pTailNode->next = pLinkListNode;
		pTailNode = pLinkListNode;
	}
	pTailNode->next = NULL;   // 将最后一个结点的next链域置为空，表示链表的结束
	
	return msgsuccess;
} 

void TravelLinkList(LinkList L)
{
	LinkList p;
	p = L;
	if(!p)
	{
		return; 
	}
	while(p->next != NULL)
	{
		printf("%4d\t", p->data);
		p = p->next;
	}
	printf("%4d\t\n", p->data);
}


LinkListNode * GetLinkListNode(LinkList L, int pos)
{  
	int				i;
	LinkListNode * 	p;
	
	p = L;
	i = 0;             // 从头结点开始扫描
	
	while ((p->next!=NULL)&&(i<pos))
	{ 
		p=p->next;     // 扫描下一结点
		i++;           // 已扫描结点计数器
	}
	if(pos == i)
	{
		return p;      // 找到了第i个结点
	}
	else 
	{
		return NULL;   // 找不到
	}
}  

LinkListNode * LocateLinkList(LinkList L, ElemType e)
{ 
	LinkListNode * p;
	p = L->next;       // 从表中第一个结点开始 
	
	while (p != NULL)
	{
		if (p->data != e)
		{
			p = p->next;
		}
		else  
		{
			break;    // 找到结点
		}
	}
	return p;
} 

int LinkListLength(LinkList L)
{   
	LinkListNode * 	p;
	int				len;
	
	p = L->next;
	len = 0;
	
	while(p!=NULL)
	{
		p = p->next;
		len++;
	}
	return len;
}

int InsertLinkList(LinkList L, int pos, ElemType e)
{  
    Message 		msgsuccess, msgimproperpositon;
	LinkListNode * 	p;
	LinkListNode * 	q;
	int				i;
	msgimproperpositon = ImproperPositon;
	msgsuccess = Success;
	
	p = L;  
	i = 0;                     // 从"头"开始，查找第i-1个结点
	while(p != NULL && i < pos-1) // 表未查完且未查到第pos-1个时重复
	{ 
		p = p->next;
		i++; 
	}
	if(!p) 
	{ 
		return msgimproperpositon;
	}
	q = (LinkListNode*)malloc(sizeof(LinkListNode));
	q->data = e;               // 设置数据域的值为e 
	q->next = p->next;         // 修改指针，完成插入操作
	p->next = q;
	
	return msgsuccess;
}

int DeleteLinkList(LinkList L, int pos, ElemType *e)
{  
	Message 		msgsuccess, msgimproperpositon;
	LinkListNode * 	p;
	LinkListNode * 	q;
	int		i;
	
	msgimproperpositon = ImproperPositon;
	msgsuccess = Success;
	p = L;
	i = 0;
	
	while(p->next!=NULL && i<pos-1)
	{ 
		p = p->next; 
		i++;
	}
	if(!(p->next))
	{
		return msgimproperpositon;
	}
	q = p->next;
	p->next = p->next->next;    // 修改指针，删除结点q
	*e = q->data;
	free(q);                    // 释放被删除的结点所占的内存空间
	
	return msgsuccess;
}

LinkList MergeLinkList(LinkList LA, LinkList LB)
{  
	LinkListNode * 	pa;
	LinkListNode * 	pb;
	LinkListNode * 	pc;
	LinkList		LC; 
   
	pa = LA->next;
	pb = LB->next;
	LC = LA;
	LC->next = NULL;
	pc = LC;        
    
	while(pa!=NULL && pb!=NULL)
	{
		if(pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	if(pa)    // 若表LA未完，将表LA中后续元素链到新表LC表尾
	{
		pc->next = pa;
	}
	else	  // 否则将表LB中后续元素链到新表LC表尾
	{
		pc->next=pb;
	}
	free(LB);
	
	return(LC);
}

void CreateCircleLinkList(LinkList L, ElemType e[], int len)
{
	int				i;
	LinkListNode * 	p;
	
	L->data = -1;
	L->next = L;
	
	for(i = 0; i < len; i++)
	{
		p = (LinkListNode*)malloc(sizeof(struct LinkListNode));
		p->data = e[i];
		p->next = L->next;
		L->next = p;
	}
}

void CreateDoubleLinkList(DoubleLinkList L, ElemType e[], int len)
{ 
	DoubleLinkListNode * 	p;
	DoubleLinkListNode * 	q;
	int						i; 
	
	i = 0; 
	L->next = L;
	L->prior = L;
	p = L;              
	
	for( ; i < len; i++)        
	{
		q = (DoubleLinkListNode*)malloc(sizeof(DoubleLinkListNode));
		q->data = e[i];
		p->next = q;
		q->prior = p;
		p = q;
	}
	p->next = L;   
	L->prior = p;
}

int InsertDoublelinkList(DoubleLinkList L, int pos, ElemType e)
{
	Message 				msgsuccess, msgfail;
	DoubleLinkListNode * 	p;
	DoubleLinkListNode * 	q;
	int						i;
	
	msgsuccess = Success;
	msgfail = Fail;
	p = L;  
	i = 0;
	while(p->next!=L && i < pos) 
	{ 
		p = p->next;
		i++; 
	}					    
	if(p->next == L)        // 如当前位置p为空表已找完还未数到第i个，
	                        // 说明插入位置不合理
	{ 
		return msgfail;
	}
	q = (DoubleLinkListNode*)malloc(sizeof(DoubleLinkListNode));
 	if(q)
	{
		q->data = e;
		q->prior = p->prior;
		p->prior->next = q;
		q->next = p;
		p->prior = q;
		return msgsuccess;
	}
	else 
	{
		return msgfail;
	}
}

int DeleteDoubleLinkList(DoubleLinkList L, int pos, ElemType *e)
{
	Message 				msgsuccess, msgfail;
	DoubleLinkListNode * 	p;
	int					i;
	
	p = L;  
	i = 0;                      // 从"头"开始，查找第i个结点
	
	while(p->next!=L && i<pos)  // 表未查完且未查到第i个时重复，找到p指向第i个 
	{ 
		p=p->next;
		i++; 
	}
	if(p->next == L)       
	{ 
		return msgfail;
	}
	else
	{
		*e = p->data;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		free(p);
		
		return msgsuccess;
	}
}
