#include "linkqueue.h"
// #include "seqqueue.h" 
#include <stdio.h>
#include <stdlib.h>

int main()
{
#ifdef SEQQUEUE_H
	SeqQueue			sq;
	SeqQueueElementType	e; 
#endif 	

#ifdef LINKQUEUE_H
	LinkQueue				lq;
	LinkQueueElementType	e; 
#endif 

#ifdef SEQQUEUE_H
	printf("初始化顺序队列...\n");
    InitialSeqQueue(&sq);
    
	printf("向顺序队列中插入a,b,c\n");
    EnterSeqQueue(&sq, 'a');
    EnterSeqQueue(&sq, 'b');
    EnterSeqQueue(&sq, 'c');
    
    DeleteSeqQueue(&sq, &e);
    printf("删除顺序队列元素%c\n", e); 
    
	printf("向顺序队列中插入d\n");
    EnterSeqQueue(&sq, 'd');
    
    GetSeqQueueHead(&sq, &e); 
    printf("取出顺序队列的头元素%c\n", e);
    
    printf("判断列表是否为空:%d\n", IsSeqQueueEmpty(&sq));

#endif 	

#ifdef LINKQUEUE_H
    printf("初始化链式队列...\n");
    InitialLinkQueue(&lq);
    
	printf("向链式队列中插入a,b,c\n");
    EnterLinkQueue(&lq, 'a');
    EnterLinkQueue(&lq, 'b');
    EnterLinkQueue(&lq, 'c');
    
    DeleteLinkQueue(&lq, &e);
    printf("删除链式队列元素%c\n", e); 
    
	printf("向链式队列中插入d\n");
    EnterLinkQueue(&lq, 'd');
    
    GetLinkQueueHead(&lq, &e);
    printf("取出链式队列的头元素%c\n", e);
    
    printf("判断列表是否为空:%d\n", IsLinkQueueEmpty(&lq));
    
#endif // END LINKQUEUE_H　 
	return 0;
}
