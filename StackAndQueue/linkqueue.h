#ifndef LINKQUEUE_H
#define LINKQUEUE_H

typedef char LinkQueueElementType;
 
typedef struct LinkQueueNode
{
	LinkQueueElementType	data;     // 数据域
	struct LinkQueueNode * 	next;     // 指针域
}LinkQueueNode;

typedef struct LinkQueueTag
{
	LinkQueueNode * front;
	LinkQueueNode * rear;
}LinkQueue;

/***************************************************************************** 
 *                    链表队列初始化                                         * 
 *****************************************************************************/ 
int InitialLinkQueue(LinkQueue * Q);

/***************************************************************************** 
 *                    链表队列入队                                           * 
 *****************************************************************************/
int EnterLinkQueue(LinkQueue * Q, LinkQueueElementType x);

/***************************************************************************** 
 *                    链表队列出队                                           * 
 *****************************************************************************/
int DeleteLinkQueue(LinkQueue * Q, LinkQueueElementType * x);

/***************************************************************************** 
 *                    获取链表队列对头元素                                   * 
 *****************************************************************************/
int GetLinkQueueHead(LinkQueue * Q, LinkQueueElementType * x);

/***************************************************************************** 
 *                    判断链表队列是否为空                                   * 
 *****************************************************************************/
int IsLinkQueueEmpty(LinkQueue * Q);

#endif // end LINKQUEUE_H
