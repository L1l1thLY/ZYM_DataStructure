#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef char LinkStackElementType;
typedef struct LinkStackNode
{
	LinkStackElementType	data;
	struct LinkStackNode * 	next;
}LinkStackNode, *LinkStack;


/*****************************************************************************
 *               ��ջ��ջ����                                                *
 *****************************************************************************/
int LinkStackPush(LinkStack s, LinkStackElementType x);

/*****************************************************************************
 *               ��ջ��ջ����                                                *
 *****************************************************************************/
int LinkStackPop(LinkStack s, LinkStackElementType * x);

#endif // END LINKSTACK_H 
