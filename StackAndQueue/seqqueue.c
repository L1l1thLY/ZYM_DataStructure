#include "seqqueue.h"

void InitialSeqQueue(SeqQueue * Q)
{  
	Q->front=Q->rear=0;
}

int EnterSeqQueue(SeqQueue * Q, SeqQueueElementType x)
{  
	
	if((Q->rear+1)%MAXSIZE==Q->front) // ��������
		return 0;
	Q->element[Q->rear]=x;
	Q->rear=(Q->rear+1)%MAXSIZE;      // �������ö�βָ��
	return 1;                         // �����ɹ�
}

int DeleteSeqQueue(SeqQueue * Q, SeqQueueElementType * x)
{ 
	
	if(Q->front==Q->rear)             // ����Ϊ��
		return 0;
	*x=Q->element[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;    // �������ö�ͷָ��
	return 1;                         // �����ɹ�
}

int GetSeqQueueHead(SeqQueue * Q, SeqQueueElementType * x)
{ 
	if(Q->front==Q->rear)            //����Ϊ�� 
	{
		return 0;
	}	
	*x=Q->element[Q->front];
	
	return 1;  				         // �����ɹ�
}

int IsSeqQueueEmpty(SeqQueue * Q)
{ 
	if(Q->front==Q->rear)            // ����Ϊ��
	{
		return 1;
	}	
	else
	{
		return 0;                    // �����ɹ�
	}	
}

