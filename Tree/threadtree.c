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
		*bt = (ThreadTreeNode *)malloc(sizeof(ThreadTreeNode));// ����һ���½��
		(*bt)->data = datas[*pos];
		(*bt)->ltag = 0;
		(*bt)->rtag = 0;
		(*pos)++;
		CreateThreadTree(&((*bt)->lchild), datas, pos);   // ����������
		CreateThreadTree(&((*bt)->rchild), datas, pos);   // ����������
	}
}

void InThread(ThreadTree root)
{
	if (root!=NULL)
	{ 
		InThread(root->lchild);             // ������������ 
		if (root->lchild==NULL)
		{
			root->ltag=1; 
			root->lchild=pre;               // ��ǰ������ 
		}
		if (pre!=NULL&& pre->rchild==NULL)  // �ú������ 
		{
			pre->rchild=root;
			pre->rtag=1;
		}
		pre=root;
		InThread(root->rchild);             // ������������
	}
}	

ThreadTreeNode * InPre(ThreadTreeNode *p)
{  
	ThreadTreeNode * q;
	if(p->ltag==1)
		pre = p->lchild;  // ֱ����������
	else 
	{                     // ��p���������в���"�����¶�"��� 
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
		Next = p->rchild;  // ֱ����������
	else
	{                      // ��p���������в���"�����¶�"���
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
	if(p->rtag==1)            // p���Һ��� 
	{
		q->rchild=p->rchild;  // p�ĺ�̱�Ϊq�ĺ�� 
		q->rtag=1;
		p->rchild=q;          // q��Ϊp���Һ��� 
		q->lchild=p;          // p��Ϊq��ǰ�� 
		q->ltag=1;
	}
	else                      // p���Һ��� 
	{ 
		s=p->rchild;
		while(s->ltag==0)
			s=s->lchild;      // ����p������������"�����¶�"��� 
		q->rchild=p->rchild;  // p���Һ��ӱ�Ϊq���Һ��� 
		q->rtag=0;
		q->lchild=p;          // p��Ϊq��ǰ�� 
		q->ltag=1;
		p->rchild=q;          // q��Ϊp���Һ��� 
		s->lchild=q;          // q��Ϊpԭ����������"�����¶�"����ǰ�� 
	}
}
