#include "threadtree.h"
#include <time.h>
#include <stdio.h> 

int main(int argc, char *argv[])
{
	ThreadTree 			T;
	ThreadTree 			p;
	ThreadTree 			q;
	ThreadTreeNode * 	r;
	int					pos;
	int 				key[RANGE] = {1, 2, 4, ENDIDENTIFIER, ENDIDENTIFIER, 5, 
						   ENDIDENTIFIER, ENDIDENTIFIER, 3, 6, ENDIDENTIFIER,
						   ENDIDENTIFIER, ENDIDENTIFIER};
	pos = 0;                                  
	printf("��������������������:1, 2, 4, ENDIDENTIFIER, ENDIDENTIFIER, 5, \
ENDIDENTIFIER, ENDIDENTIFIER, 3, 6, ENDIDENTIFIER,\
ENDIDENTIFIER, ENDIDENTIFIER(ENDIDENTIFIER��ʾ�ڵ�ΪҶ�ӽڵ�)��\n");
    CreateThreadTree(&T, key, &pos);

	pre = NULL;
	InThread(T);

    p = T->lchild->rchild;
	q =InPre(p);
	printf("p��ǰ��Ϊ%d\n", q->data);
	q =InNext(p);
	printf("p�ĺ��Ϊ%d\n", q->data);

	q = InFirst(T);
	printf("��һ�����Ϊ%d\n", q->data);

	r = (ThreadTreeNode *)malloc(sizeof(ThreadTreeNode));
	r->data = 90;
	r->lchild = NULL;
	r->rchild = NULL;
	r->ltag = 0;
	r->rtag = 0;
	printf("P�����½������ֵΪ90.\n");
	InsertNode(p, r);

	printf("����������:\n");
    InOrder(T);
	printf("\n");
	return 0;
}
