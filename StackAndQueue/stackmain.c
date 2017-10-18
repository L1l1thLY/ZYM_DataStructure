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
	printf("��ʼ��˳��ջ...\n");
    InitialSeqStack(&sstack);
    
	printf("isempty: %d\n", IsSeqStackEmpty(&sstack));
    printf("isfull: %d\n", IsSeqStackFull(&sstack));
    
	a = 'x';
	printf("��ջ��ѹ��Ԫ��x\n");
    SeqStackPush(&sstack, a);
    a = '\0';
    SeqStackPop(&sstack, &a);
    printf("������Ԫ��Ϊ: %c\n", a);
    
    printf("��ջ�зֱ�ѹ��Ԫ��1��2��3\n");
	SeqStackPush(&sstack, '1');
    SeqStackPush(&sstack, '2');
    SeqStackPush(&sstack, '3');
    GetSeqStackTop(&sstack, &a); 
    printf("ջ��Ԫ��Ϊ: %c\n", a);
    
    printf("Match('{','d'): %d\n",Match('{','d')); 
    printf("Match'{','}': %d\n", Match('{','}'));
#endif
   
#ifdef LINKSTACK_H
    printf("��ջ��ѹ��Ԫ��%c\n", 'a');
	LinkStackPush(&lstack, 'a');
	LinkStackPop(&lstack, &e);
	printf("����ջ��Ԫ���ǣ�%c\n", e);
#endif

#ifdef BISTACK_H
    InitialBidirectionalStack(&dstack);
    printf("��ջ��ѹ��Ԫ��%c %c\n", 'X', 'Y');
    BidirectionalStackPush(&dstack, 'X', 0);
    BidirectionalStackPush(&dstack, 'Y', 1);
    BidirectionalStackVisit(&dstack);
    BidirectionalStackPop(&dstack, &e, 0); 
    printf("0 - ����Ԫ��Ϊ%c\n", e);
    BidirectionalStackPop(&dstack, &e, 1); 
    printf("1 - ����Ԫ��Ϊ%c\n", e);
#endif

	return 0;
}
