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
	printf("按先序建立二叉树，输入:1, 2, 4, ENDIDENTIFIER, ENDIDENTIFIER, 5, \
ENDIDENTIFIER, ENDIDENTIFIER, 3, 6, ENDIDENTIFIER,\
ENDIDENTIFIER, ENDIDENTIFIER(ENDIDENTIFIER表示节点为叶子节点)。\n");
    CreateThreadTree(&T, key, &pos);

	pre = NULL;
	InThread(T);

    p = T->lchild->rchild;
	q =InPre(p);
	printf("p的前驱为%d\n", q->data);
	q =InNext(p);
	printf("p的后继为%d\n", q->data);

	q = InFirst(T);
	printf("第一个结点为%d\n", q->data);

	r = (ThreadTreeNode *)malloc(sizeof(ThreadTreeNode));
	r->data = 90;
	r->lchild = NULL;
	r->rchild = NULL;
	r->ltag = 0;
	r->rtag = 0;
	printf("P插入新结点数据值为90.\n");
	InsertNode(p, r);

	printf("遍历线索树:\n");
    InOrder(T);
	printf("\n");
	return 0;
}
