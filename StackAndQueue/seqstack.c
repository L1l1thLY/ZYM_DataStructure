#include "seqstack.h"

void InitialSeqStack(SeqStack * S)
{
  	S->top = -1;
}

int IsSeqStackEmpty(SeqStack * S) 
{
	return(S->top==-1? 1 : 0);
}


int IsSeqStackFull(SeqStack * S)	
{
	return(S->top==STACKSIZE-1? 1 : 0);
}

int SeqStackPush(SeqStack * S,SeqStackElementType x)
{
	if(S->top==STACKSIZE-1)  
		return 0; 
	S->top++;
	S->elem[S->top] = x;
	return 1;
}

int SeqStackPop(SeqStack * S,SeqStackElementType * x)
{  
	if(S->top == -1)  
		return 0;
	else
	{
  		*x = S->elem[S->top];
		S->top--;    
  		return 1;
	}
}


int GetSeqStackTop(SeqStack * S,SeqStackElementType * x)
{  
	if(S->top == -1)  
		return 0;
	else
	{
  		*x = S->elem[S->top];
  		
 		return 1;
	}	
}


int Match(char cstart,char cend)
{		
	if(cstart=='(' && cend ==')')
	{
		return 1;
	}
	else if(cstart=='[' && cend ==']')
	{
		return 1;
	}
	else if(cstart=='{' && cend=='}')
	{
		return 1;
	}
	else 
		return 0;
}
