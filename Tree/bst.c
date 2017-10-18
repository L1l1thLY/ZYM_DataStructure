#include "bst.h"
#include <stdio.h>

void InsertBST(BSTree * bst, KeyType key)
{ 
	BSTNode * p;
	if (*bst == NULL)                            // �ݹ��������
	{
		p=(BSTree)malloc(sizeof(BSTNode));       // �����µĽ��p
		p-> key=key;
		p->lchild=NULL; 
		p->rchild=NULL;
		*bst=p;
	}
	else 
	{
		if (key < (*bst)->key)
		{
			InsertBST(&((*bst)->lchild), key);    // ��p����������
		}	
		else 
		{
			if (key > (*bst)->key)
			{
				InsertBST(&((*bst)->rchild), key); // ��p����������
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
		printf("%4d\t",root->key);    // ������
		PreOrderBST(root->lchild);    // �������������
		PreOrderBST(root->rchild);    // �������������
	}
}

BSTNode * SearchBST(BSTree bst, KeyType key)
{ 
	BSTNode * p;
	p=bst;
	while(p)
	{
		if (p->key == key) 
			return p;     // ���ҳɹ�
		if (p->key > key)  
			p=p->lchild;  // ���������в���
		else  
			p=p->rchild;  // ���������в���
	}
	return NULL;          // ����ʧ��
}

void DeleteBST(BSTree t, KeyType  k)
{
	BSTNode	* p;
	BSTNode * q;
	BSTNode	* r;
	BSTNode * s;

	p=t; 
	r=NULL;
	while(p)           // ���ҹؼ���Ϊk�Ĵ�ɾ���p
	{ 
		if(p->key==k )  
			break;     // �ҵ�������ѭ��
		r=p;           // rָ��p����˫�׽��
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
		return ;       // ���Ҳ���������ԭ���Ķ���������
	}  
	
	if(p->lchild==NULL) // p��������
	{ 
		if(r==NULL) 
			t=p->rchild;  // p��ԭ�����������ĸ�
		else 
		{
			if(r->lchild==p)  // p��r������
			{
				r->lchild=p->rchild ;  // ��p������������r��������
			}	
			else                       // p��r���Һ���*/
			{
				r->rchild=p->rchild ;  // ��p������������r��������
			}	
		}
		free(p);
	}
	else  // p��������
	{ 
		q=p; 
		s=p->lchild;
		while(s->rchild)           // ��p���������в��������½��
		{
			q=s; 
			s=s->rchild;
		}
		if(q==p) 
		{
			q->lchild=s->lchild ;  // ��s������������q��
		}	
		else 
		{
			q->rchild=s->lchild;
		}	
		p->key=s->key;             // ��s��ֵ����p
		free(s);
	}
}
