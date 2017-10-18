#include "threadtree.h"
#include <stdio.h>
#include <malloc.h>
#include <conio.h>

void CreateThreadTree(ThreadTree * bt, DataType datas[], int * pos)
{  
    if(ENDIDENTIFIER == datas[*pos]) 
	{
		(*pos)++;
		*bt = NULL;
	}
    else 
	{
		*bt = (ThreadTreeNode *)malloc(sizeof(ThreadTreeNode));// 生成一个新结点
		(*bt)->data = datas[*pos];
		(*bt)->ltag = 0;
		(*bt)->rtag = 0;
		(*pos)++;
		CreateThreadTree(&((*bt)->lchild), datas, pos);   // 生成左子树
		CreateThreadTree(&((*bt)->rchild), datas, pos);   // 生成右子树
	}
}

void InThread(ThreadTree root)
{
	if (root!=NULL)
	{ 
		InThread(root->lchild);             // 线索化左子树 
		if (root->lchild==NULL)
		{
			root->ltag=1; 
			root->lchild=pre;               // 置前驱线索 
		}
		if (pre!=NULL&& pre->rchild==NULL)  // 置后继线索 
		{
			pre->rchild=root;
			pre->rtag=1;
		}
		pre=root;
		InThread(root->rchild);             // 线索化右子树
	}
}	

ThreadTreeNode * InPre(ThreadTreeNode *p)
{  
	ThreadTreeNode * q;
	if(p->ltag==1)
		pre = p->lchild;  // 直接利用线索
	else 
	{                     // 在p的左子树中查找"最右下端"结点 
		for(q = p->lchild;q->rtag==0;q=q->rchild);
		pre=q;
	}
	return(pre);
}

ThreadTreeNode * InNext(ThreadTreeNode * p) 
{ 
	ThreadTreeNode * Next;
	ThreadTreeNode * q;
	
	if (p->rtag==1)  
		Next = p->rchild;  // 直接利用线索
	else
	{                      // 在p的右子树中查找"最左下端"结点
		if(p->rchild!=NULL)
		{
			for(q=p->rchild; q->ltag==0 ;q=q->lchild);
			Next=q; 
		}
		else
			Next = NULL;
		
	} 
	return(Next);
}

ThreadTreeNode* InFirst(ThreadTree root)
{
	ThreadTreeNode * p;
	
	p = root;
	
	if(p)
	{
		while(p->lchild!=NULL)
		{
			p=p->lchild;
		}	
	}	
	return p;
}

void InOrder(ThreadTree root)
{
	ThreadTreeNode * p;
	
	p = InFirst(root);
	
	while(p!=NULL)
	{
		printf("%d\t",p->data);
		p=InNext(p);
	}
}

void InsertNode(ThreadTreeNode * p , ThreadTreeNode * q)
{
	ThreadTreeNode *s;
	if(p->rtag==1)            // p无右孩子 
	{
		q->rchild=p->rchild;  // p的后继变为q的后继 
		q->rtag=1;
		p->rchild=q;          // q成为p的右孩子 
		q->lchild=p;          // p变为q的前驱 
		q->ltag=1;
	}
	else                      // p有右孩子 
	{ 
		s=p->rchild;
		while(s->ltag==0)
			s=s->lchild;      // 查找p结点的右子树的"最左下端"结点 
		q->rchild=p->rchild;  // p的右孩子变为q的右孩子 
		q->rtag=0;
		q->lchild=p;          // p变为q的前驱 
		q->ltag=1;
		p->rchild=q;          // q变为p的右孩子 
		s->lchild=q;          // q变为p原来右子树的"最左下端"结点的前驱 
	}
}
