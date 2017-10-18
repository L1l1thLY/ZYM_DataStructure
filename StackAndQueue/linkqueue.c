#include "linkqueue.h"
#include <malloc.h>

int InitialLinkQueue(LinkQueue * Q)
{ 
	Q->front=(LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;
		Q->front->next=NULL;
 		return 1;
	}
	else 
		return 0; 
}


int EnterLinkQueue(LinkQueue * Q, LinkQueueElementType x)
{  
	
	LinkQueueNode *NewNode; 
	NewNode=(LinkQueueNode * )malloc(sizeof(LinkQueueNode));
	if(NewNode!=NULL)
	{
		NewNode->data=x;
		NewNode->next=NULL;
		Q->rear->next=NewNode;
		Q->rear=NewNode;
		return 1;
	}
	else 
	{
		return 0;
	} 
}


int DeleteLinkQueue(LinkQueue * Q, LinkQueueElementType * x)
{  
	
	LinkQueueNode * p;
	if(Q->front==Q->rear)
	{
		return 0;
	}	
	p=Q->front->next;
	Q->front->next=p->next;  // ��ͷԪ��p����
	if(Q->rear==p)           // �������ֻ��һ��Ԫ��p����p���Ӻ��Ϊ�ն�
	{
		Q->rear=Q->front;  
	}	
	*x=p->data;
	free(p); 
	
	return 1;	
}

int GetLinkQueueHead(LinkQueue * Q, LinkQueueElementType * x)
{ 	
	if(Q->front==Q->rear)    // ����Ϊ��
	{
		return 0;
	}	
	*x=Q->front->next->data;
	
	return 1;
}

int IsLinkQueueEmpty(LinkQueue * Q)
{
	return Q->front==Q->rear ? 1 : 0; 
} 

