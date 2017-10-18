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
	printf("��ʼ��˳�����...\n");
    InitialSeqQueue(&sq);
    
	printf("��˳������в���a,b,c\n");
    EnterSeqQueue(&sq, 'a');
    EnterSeqQueue(&sq, 'b');
    EnterSeqQueue(&sq, 'c');
    
    DeleteSeqQueue(&sq, &e);
    printf("ɾ��˳�����Ԫ��%c\n", e); 
    
	printf("��˳������в���d\n");
    EnterSeqQueue(&sq, 'd');
    
    GetSeqQueueHead(&sq, &e); 
    printf("ȡ��˳����е�ͷԪ��%c\n", e);
    
    printf("�ж��б��Ƿ�Ϊ��:%d\n", IsSeqQueueEmpty(&sq));

#endif 	

#ifdef LINKQUEUE_H
    printf("��ʼ����ʽ����...\n");
    InitialLinkQueue(&lq);
    
	printf("����ʽ�����в���a,b,c\n");
    EnterLinkQueue(&lq, 'a');
    EnterLinkQueue(&lq, 'b');
    EnterLinkQueue(&lq, 'c');
    
    DeleteLinkQueue(&lq, &e);
    printf("ɾ����ʽ����Ԫ��%c\n", e); 
    
	printf("����ʽ�����в���d\n");
    EnterLinkQueue(&lq, 'd');
    
    GetLinkQueueHead(&lq, &e);
    printf("ȡ����ʽ���е�ͷԪ��%c\n", e);
    
    printf("�ж��б��Ƿ�Ϊ��:%d\n", IsLinkQueueEmpty(&lq));
    
#endif // END LINKQUEUE_H�� 
	return 0;
}
