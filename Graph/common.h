#ifndef COMMON_H
#define COMMON_H

#define N 			10
#define MAX         20
#define MAX_VERTEX_NUM 20
#define INFINITY  	32768
#define Error		-1
#define Ok 			1

typedef char 	VertexData;
typedef int 	LinkQueueDataType;
typedef char 	LinkListDataType;
typedef int 	StackDataType;
typedef int     Status;
typedef int 	boolean; 

// 用于标识节点是否被访问的全局变量 
int visited[N];

// 图类型定义
typedef enum GraphKind{
	DG, DN, UDG, UDN 
}GraphKind;

// 函数返回状态 
typedef enum Message{
	Success, Failure, Fatal, NullPointor, RangError, Uninitial, ImproperPositon
}Message;

// 判断类型 
typedef enum Boolean{
	False, True
}Boolean;

// 链式队列的定义
typedef struct LinkQueueNode
{
	LinkQueueDataType		data;
	struct LinkQueueNode *	next;
}LinkQueueNode;

typedef struct QueueNode
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
}QueueNode, Queue;


// 链表的定义
typedef struct LinkListNode
{
	LinkListDataType 		data;
	struct LinkListNode *	next;
}LinkListNode, *LinkList;

// 复杂的链表定义
typedef struct ComplexLinkListNode
{
	LinkListDataType				data[2];
	struct ComplexLinkListNode * 	next;
}ComplexLinkListNode, *ComplexLinkList;

// 栈的定义
typedef struct StackNode
{
	StackDataType 	data[MAX];
	int 			top;
}StackNode, Stack;


/******************************************************************************
 *     初始化栈                                                               * 
 ******************************************************************************/ 
Status InitialStack(Stack * S);

/******************************************************************************
 *     销毁栈                                                               * 
 ******************************************************************************/ 
Status DestroyStack(Stack * S);

/******************************************************************************
 *     压栈                                                                   * 
 ******************************************************************************/
Status StackPush(Stack * S, StackDataType e);

/******************************************************************************
 *     出栈                                                                   * 
 ******************************************************************************/
Status StackPop(Stack * S, StackDataType * e);

/******************************************************************************
 *     判断栈是否为空                                                         * 
 ******************************************************************************/
boolean IsStackEmpty(Stack * S);


/******************************************************************************
 *     初始化队列                                                             * 
 ******************************************************************************/
Status InitialQueue(Queue * Q);

/******************************************************************************
 *     销毁队列                                                               * 
 ******************************************************************************/
Status DestroyQueue(Queue * Q);

/******************************************************************************
 *     如队列                                                                 * 
 ******************************************************************************/
Status EnterQueue(Queue * Q, LinkQueueDataType x);

/******************************************************************************
 *     出队列                                                                 * 
 ******************************************************************************/
Status DeleteQueue(Queue * Q, LinkQueueDataType * x);

/******************************************************************************
 *     判断队列是否为空                                                       * 
 ******************************************************************************/
boolean IsQueueEmpty(Queue * Q);

#endif
