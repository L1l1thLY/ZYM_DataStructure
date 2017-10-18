#ifndef BISTACK_H
#define BISTACK_H

#define M		100

typedef char StackElementType;
typedef struct BidirectionalStackNode 
{
	StackElementType Stack[M];  // 顺序栈方式实现 
	StackElementType top[2];    // top[0]和top[1]分别为两个栈顶指示器
}BidirectionalStackNode, BiStack;

/*****************************************************************************
 *        双向栈的初始化                                                     *
 *****************************************************************************/ 
void InitBidirectionalStack(BiStack * S);

/*****************************************************************************
 *        双向栈的压栈                                                       *
 *****************************************************************************/
int BidirectionalStackPush(BiStack * S, StackElementType x, int pos);

/*****************************************************************************
 *        双向栈的出栈                                                       *
 *****************************************************************************/
int BidirectionalStackPop(BiStack * S, StackElementType * x, int pos);

/*****************************************************************************
 *        双向栈的遍历                                                       *
 *****************************************************************************/
void BidirectionalStackVisit(BiStack * S);

#endif // END BISTACK_H
