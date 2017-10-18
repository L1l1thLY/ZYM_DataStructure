#include "BiStack.h"
#include <stdio.h>
#include <memory.h>

void InitialBidirectionalStack(BiStack * S)
{
	S->top[0]=-1;
	S->top[1]=M;
	memset(S->Stack, '#', M*sizeof(StackElementType));
}


int BidirectionalStackPush(BiStack * S, StackElementType x, int pos)
{
	if(S->top[0]+1==S->top[1])   // Õ»ÒÑÂú
		return 0;
	switch(pos)
	{
	case 0:
		S->top[0]++;
		S->Stack[S->top[0]]=x;
		break;
	case 1:
		S->top[1]--;
		S->Stack[S->top[1]]=x;
		break;
	default:                     // ²ÎÊý´íÎó
        return 0;
 	}
 	
	return 1;
}

int BidirectionalStackPop(BiStack * S, StackElementType * x, int pos)
{
	switch(pos)
	{
	case 0:
		if(S->top[0]==-1)  
			return 0;
		*x=S->Stack[S->top[0]];
		S->top[0]--;
		break;
	case 1:
		if(S->top[1]==M)  
			return 0;
		*x=S->Stack[S->top[1]];
		S->top[1]++;
		break;
	default:
		return 0;
	}
	return 1;
}

void BidirectionalStackVisit(BiStack * S)
{
	int flag;
	flag = 0;
	while(flag < M)
	{
		printf("%2c", S->Stack[flag]);
		flag ++;
		if(flag % 10 == 0)
		{
			printf("\n");	
		} 
	}
}
