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
	
	pTailNode = L;    // pTailNodeָ�붯ָ̬������ĵ�ǰ��β���Ա�����β���룬
                      // ���ֵָ��ͷ���
	for( ; i < len; i++)
	{
		pLinkListNode = (LinkListNode*)malloc(sizeof(LinkListNode));
		pLinkListNode->data = e[i];
		pTailNode->next = pLinkListNode;
		pTailNode = pLinkListNode;
	}
	pTailNode->next = NULL;   // �����һ������next������Ϊ�գ���ʾ����Ľ���
	
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
	i = 0;             // ��ͷ��㿪ʼɨ��
	
	while ((p->next!=NULL)&&(i<pos))
	{ 
		p=p->next;     // ɨ����һ���
		i++;           // ��ɨ���������
	}
	if(pos == i)
	{
		return p;      // �ҵ��˵�i�����
	}
	else 
	{
		return NULL;   // �Ҳ���
	}
}  

LinkListNode * LocateLinkList(LinkList L, ElemType e)
{ 
	LinkListNode * p;
	p = L->next;       // �ӱ��е�һ����㿪ʼ 
	
	while (p != NULL)
	{
		if (p->data != e)
		{
			p = p->next;
		}
		else  
		{
			break;    // �ҵ����
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
	i = 0;                     // ��"ͷ"��ʼ�����ҵ�i-1�����
	while(p != NULL && i < pos-1) // ��δ������δ�鵽��pos-1��ʱ�ظ�
	{ 
		p = p->next;
		i++; 
	}
	if(!p) 
	{ 
		return msgimproperpositon;
	}
	q = (LinkListNode*)malloc(sizeof(LinkListNode));
	q->data = e;               // �����������ֵΪe 
	q->next = p->next;         // �޸�ָ�룬��ɲ������
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
	p->next = p->next->next;    // �޸�ָ�룬ɾ�����q
	*e = q->data;
	free(q);                    // �ͷű�ɾ���Ľ����ռ���ڴ�ռ�
	
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
	if(pa)    // ����LAδ�꣬����LA�к���Ԫ�������±�LC��β
	{
		pc->next = pa;
	}
	else	  // ���򽫱�LB�к���Ԫ�������±�LC��β
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
	if(p->next == L)        // �統ǰλ��pΪ�ձ������껹δ������i����
	                        // ˵������λ�ò�����
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
	i = 0;                      // ��"ͷ"��ʼ�����ҵ�i�����
	
	while(p->next!=L && i<pos)  // ��δ������δ�鵽��i��ʱ�ظ����ҵ�pָ���i�� 
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
