 #include "seqstack.h"
// #include "linkstack.h"
// #include "bistack.h"
 
int main()
{
#ifdef SEQSTACK_H
    SeqStack			sstack;
    SeqStackElementType	a;
#endif
	
#ifdef LINKSTACK_H
    LinkStack				lstack;
	LinkStackElementType	e;
#endif

#ifdef BISTACK_H
    BiStack				dstack;
    StackElementType	e;
	e = 0;
#endif		
	
#ifdef SEQSTACK_H
	printf("初始化顺序栈...\n");
    InitialSeqStack(&sstack);
    
	printf("isempty: %d\n", IsSeqStackEmpty(&sstack));
    printf("isfull: %d\n", IsSeqStackFull(&sstack));
    
	a = 'x';
	printf("向栈中压入元素x\n");
    SeqStackPush(&sstack, a);
    a = '\0';
    SeqStackPop(&sstack, &a);
    printf("弹出的元素为: %c\n", a);
    
    printf("向栈中分别压入元素1，2，3\n");
	SeqStackPush(&sstack, '1');
    SeqStackPush(&sstack, '2');
    SeqStackPush(&sstack, '3');
    GetSeqStackTop(&sstack, &a); 
    printf("栈顶元素为: %c\n", a);
    
    printf("Match('{','d'): %d\n",Match('{','d')); 
    printf("Match'{','}': %d\n", Match('{','}'));
#endif
   
#ifdef LINKSTACK_H
    printf("向栈中压入元素%c\n", 'a');
	LinkStackPush(&lstack, 'a');
	LinkStackPop(&lstack, &e);
	printf("弹出栈的元素是：%c\n", e);
#endif

#ifdef BISTACK_H
    InitialBidirectionalStack(&dstack);
    printf("向栈中压入元素%c %c\n", 'X', 'Y');
    BidirectionalStackPush(&dstack, 'X', 0);
    BidirectionalStackPush(&dstack, 'Y', 1);
    BidirectionalStackVisit(&dstack);
    BidirectionalStackPop(&dstack, &e, 0); 
    printf("0 - 弹出元素为%c\n", e);
    BidirectionalStackPop(&dstack, &e, 1); 
    printf("1 - 弹出元素为%c\n", e);
#endif

	return 0;
}
