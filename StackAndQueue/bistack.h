#ifndef BISTACK_H
#define BISTACK_H

#define M		100

typedef char StackElementType;
typedef struct BidirectionalStackNode 
{
	StackElementType Stack[M];  // ˳��ջ��ʽʵ�� 
	StackElementType top[2];    // top[0]��top[1]�ֱ�Ϊ����ջ��ָʾ��
}BidirectionalStackNode, BiStack;

/*****************************************************************************
 *        ˫��ջ�ĳ�ʼ��                                                     *
 *****************************************************************************/ 
void InitBidirectionalStack(BiStack * S);

/*****************************************************************************
 *        ˫��ջ��ѹջ                                                       *
 *****************************************************************************/
int BidirectionalStackPush(BiStack * S, StackElementType x, int pos);

/*****************************************************************************
 *        ˫��ջ�ĳ�ջ                                                       *
 *****************************************************************************/
int BidirectionalStackPop(BiStack * S, StackElementType * x, int pos);

/*****************************************************************************
 *        ˫��ջ�ı���                                                       *
 *****************************************************************************/
void BidirectionalStackVisit(BiStack * S);

#endif // END BISTACK_H
