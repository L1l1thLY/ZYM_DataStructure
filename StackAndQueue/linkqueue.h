#ifndef LINKQUEUE_H
#define LINKQUEUE_H

typedef char LinkQueueElementType;
 
typedef struct LinkQueueNode
{
	LinkQueueElementType	data;     // ������
	struct LinkQueueNode * 	next;     // ָ����
}LinkQueueNode;

typedef struct LinkQueueTag
{
	LinkQueueNode * front;
	LinkQueueNode * rear;
}LinkQueue;

/***************************************************************************** 
 *                    ������г�ʼ��                                         * 
 *****************************************************************************/ 
int InitialLinkQueue(LinkQueue * Q);

/***************************************************************************** 
 *                    ����������                                           * 
 *****************************************************************************/
int EnterLinkQueue(LinkQueue * Q, LinkQueueElementType x);

/***************************************************************************** 
 *                    ������г���                                           * 
 *****************************************************************************/
int DeleteLinkQueue(LinkQueue * Q, LinkQueueElementType * x);

/***************************************************************************** 
 *                    ��ȡ������ж�ͷԪ��                                   * 
 *****************************************************************************/
int GetLinkQueueHead(LinkQueue * Q, LinkQueueElementType * x);

/***************************************************************************** 
 *                    �ж���������Ƿ�Ϊ��                                   * 
 *****************************************************************************/
int IsLinkQueueEmpty(LinkQueue * Q);

#endif // end LINKQUEUE_H
