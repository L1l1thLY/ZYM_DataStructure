#include "bst.h"
#include <stdio.h>

void InsertBST(BSTree * bst, KeyType key)
{ 
	BSTNode * p;
	if (*bst == NULL)                            // 递归结束条件
	{
		p=(BSTree)malloc(sizeof(BSTNode));       // 申请新的结点p
		p-> key=key;
		p->lchild=NULL; 
		p->rchild=NULL;
		*bst=p;
	}
	else 
	{
		if (key < (*bst)->key)
		{
			InsertBST(&((*bst)->lchild), key);    // 将p插入左子树
		}	
		else 
		{
			if (key > (*bst)->key)
			{
				InsertBST(&((*bst)->rchild), key); // 将p插入右子树
			}	
		}	
	} 
}

void CreateBST(BSTree * bst, int len, KeyType key[])
{ 
	int i;
	*bst=NULL;
	for(i = 0; i < len; i++)
	{
		InsertBST(bst, key[i]);
	}
}

void PreOrderBST(BSTree root) 
{
	if (root!=NULL)
	{
		printf("%4d\t",root->key);    // 输出结点
		PreOrderBST(root->lchild);    // 先序遍历左子树
		PreOrderBST(root->rchild);    // 先序遍历右子树
	}
}

BSTNode * SearchBST(BSTree bst, KeyType key)
{ 
	BSTNode * p;
	p=bst;
	while(p)
	{
		if (p->key == key) 
			return p;     // 查找成功
		if (p->key > key)  
			p=p->lchild;  // 在左子树中查找
		else  
			p=p->rchild;  // 在右子树中查找
	}
	return NULL;          // 查找失败
}

void DeleteBST(BSTree t, KeyType  k)
{
	BSTNode	* p;
	BSTNode * q;
	BSTNode	* r;
	BSTNode * s;

	p=t; 
	r=NULL;
	while(p)           // 查找关键字为k的待删结点p
	{ 
		if(p->key==k )  
			break;     // 找到则跳出循环
		r=p;           // r指向p结点的双亲结点
		if(p->key>k)  
		{
			p=p->lchild;
		}	
		else 
		{
			p=p->rchild;
		}	
	} 
	if(p==NULL)
	{
		return ;       // 若找不到，返回原来的二叉排序树
	}  
	
	if(p->lchild==NULL) // p无左子树
	{ 
		if(r==NULL) 
			t=p->rchild;  // p是原二叉排序树的根
		else 
		{
			if(r->lchild==p)  // p是r的左孩子
			{
				r->lchild=p->rchild ;  // 将p的右子树链到r的左链上
			}	
			else                       // p是r的右孩子*/
			{
				r->rchild=p->rchild ;  // 将p的右子树链到r的右链上
			}	
		}
		free(p);
	}
	else  // p有左子树
	{ 
		q=p; 
		s=p->lchild;
		while(s->rchild)           // 在p的左子树中查找最右下结点
		{
			q=s; 
			s=s->rchild;
		}
		if(q==p) 
		{
			q->lchild=s->lchild ;  // 将s的左子树链到q上
		}	
		else 
		{
			q->rchild=s->lchild;
		}	
		p->key=s->key;             // 将s的值赋给p
		free(s);
	}
}
