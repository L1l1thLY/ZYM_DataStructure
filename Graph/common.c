#include "common.h"
#include <malloc.h>

Status InitQueue(Queue * Q)
{
	Q->front = (LinkQueueNode *)malloc(sizeof(LinkQueueNode));
	if(Q->front != NULL)
	{
		Q->rear=Q->front;
		Q->front->next = NULL;
		return Success;
	}
	else  
	{
		return Failure;
	}
}

Status EnterQueue(Queue * Q,int x)
{
	LinkQueueNode * NewNode;
	
	NewNode=(LinkQueueNode * )malloc(sizeof(LinkQueueNode));
	
	if(NewNode!=NULL)
	{
		NewNode->data=x;
		NewNode->next=NULL;
		Q->rear->next=NewNode;
		Q->rear=NewNode;
		return Success;
	}
	else 
	{
		return Failure;
	}
}

Status DestroyQueue(Queue * Q)
{
	int x;
	while(Q->front != Q->rear)
	{
		DeleteQueue(Q, &x);
	}
	free(Q); 
} 

Status DeleteQueue(Queue * Q,int * x)
{
	LinkQueueNode * p;
	if(Q->front==Q->rear)
	{
		return Failure;
	}
	p=Q->front->next;
	Q->front->next=p->next;
    if(Q->rear==p)
	{
		Q->rear=Q->front;
	}
	*x=p->data;
	free(p);
	
	return Success;
}

boolean IsQueueEmpty(Queue * Q)
{
	if(Q->front==Q->rear)
	{
		return (True);
	}
	else 
	{
		return (False);
	}
}

Status InitialStack(Stack * S)
{
	S->top=0;
	return Success;
}

Status DestroyStack(Stack * S)
{
	StackDataType * e;
	while(S->top != 0)
	{
		StackPop(S, e);
	}
	free(S);
	return Success;
}

Status StackPush(Stack * S, StackDataType e)
{
	if(S->top >= MAX) 
	{
		return Failure;
	}
	else
	{
		S->data[S->top++]=e;
	} 
	return Success;
}

Status StackPop(Stack * S, StackDataType * e)
{
	if(S->top<=0)
	{
		return Failure;
	} 
	else
	{
		*e=S->data[--S->top];
	} 
	return Success;
}

boolean IsStackEmpty(Stack * S)
{
	if(S->top==0)
	{
		return True;
	}
	else
	{
		return False;
	} 
}
