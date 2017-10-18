#include "seqqueue.h"

void InitialSeqQueue(SeqQueue * Q)
{  
	Q->front=Q->rear=0;
}

int EnterSeqQueue(SeqQueue * Q, SeqQueueElementType x)
{  
	
	if((Q->rear+1)%MAXSIZE==Q->front) // 队列已满
		return 0;
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;      // 重新设置队尾指针
	return 1;                         // 操作成功
}

int DeleteSeqQueue(SeqQueue * Q, SeqQueueElementType * x)
{ 
	
	if(Q->front==Q->rear)             // 队列为空
		return 0;
	*x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;    // 重新设置队头指针
	return 1;                         // 操作成功
}

int GetSeqQueueHead(SeqQueue * Q, SeqQueueElementType * x)
{ 
	if(Q->front==Q->rear)            //队列为空 
	{
		return 0;
	}	
	*x=Q->element[Q->front];
	
	return 1;  				         // 操作成功
}

int IsSeqQueueEmpty(SeqQueue * Q)
{ 
	if(Q->front==Q->rear)            // 队列为空
	{
		return 1;
	}	
	else
	{
		return 0;                    // 操作成功
	}	
}

