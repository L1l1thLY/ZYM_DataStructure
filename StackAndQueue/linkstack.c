#include "linkstack.h"
#include <malloc.h> 

int LinkStackPush(LinkStack s, LinkStackElementType x)
{
	LinkStackNode *temp;
	temp=(LinkStackNode *)malloc(sizeof(LinkStackNode));
 	if(temp==NULL)  
 		return 0;                  // ?????????
	temp->data=x;
	temp->next=s->next;
	s->next=temp;                 // ??????????? 

	return 1;
}


int LinkStackPop(LinkStack s, LinkStackElementType * x)
{  
	LinkStackNode * temp;
	temp=s->next;
	if(temp==NULL)                // ????
		return 0;
	s->next=temp->next;
	*x=temp->data;
	free(temp);                   // ???洢???
	
	return 1;
}
