#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef char LinkStackElementType;
typedef struct LinkStackNode
{
	LinkStackElementType	data;
	struct LinkStackNode * 	next;
}LinkStackNode, *LinkStack;


/*****************************************************************************
 *               Á´Õ»½øÕ»²Ù×÷                                                *
 *****************************************************************************/
int LinkStackPush(LinkStack s, LinkStackElementType x);

/*****************************************************************************
 *               Á´Õ»³öÕ»²Ù×÷                                                *
 *****************************************************************************/
int LinkStackPop(LinkStack s, LinkStackElementType * x);

#endif // END LINKSTACK_H 
