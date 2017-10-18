#include "MBTree.h"
#include <stdio.h>
#include <math.h>

void insert(MBTNode * mbt, int ipos, KeyType key, MBTNode * rp)
{
	int i;
	for (i=mbt->keynum; i>= ipos +1; i--)
	{ 
		mbt->key[i+1]=mbt->key[i];
		mbt->ptr[i+1]=mbt->ptr[i];
	}
	mbt->key[ipos+1]=key;
	mbt->ptr[ipos+1]=rp;
	mbt->keynum++;
}

void split(MBTNode * oldp, MBTree * newp)
{
	int i;
	int j;
	int k;
	
	j=ceil((float)M/2);
	k=M-j;
	*newp=(MBTNode *)malloc(sizeof(MBTNode));
	(*newp)->keynum=k;
	(*newp)->parent=oldp->parent;
	(*newp)->ptr[0]=oldp->ptr[j];
	for (i=1 ; i<=k ; i++)
	{ 
		(*newp)->key[i]=oldp->key[j+i];
		(*newp)->ptr[i]=oldp->ptr[j+i];
	}
	oldp->keynum=j-1;
}

int search(MBTNode * mbt, KeyType key)
{
	int n;
	int i;
	n = mbt->keynum ;
	i = 1 ;
	while (i <= n && mbt->key[i] <= key )
	{
		i++;
	}  
	return (i - 1);    // ����С�ڵ���key�����ؼ������ ��Ϊ0 ʱ��ʾӦ��
					   // �����֧�ң�Խ��ʱ��ʾӦ�����ҷ�֧��
}

void insertmbtree(MBTree * mbt, KeyType k, MBTree q, int pos)
{ 
	MBTree	q1;
	MBTree	ap;
	MBTree	new_root;
	int 	s;
	int 	finished;
	int 	x;
	
	if (*mbt==NULL)
	{ 
		*mbt =(MBTree)malloc(sizeof(MBTNode));
		(*mbt)->keynum=1;
		(*mbt)->parent=NULL;
		(*mbt)->key[1]=k;
		(*mbt)->ptr[0]=NULL; 
		(*mbt)->ptr[1]=NULL;
	}
	else  
	{  
		x=k;                         // ��x�嵽q->key[pos+1] �� 
		ap=NULL;		             // ��ap�嵽q->ptr[pos+1] �� 
		finished=(int)NULL;
		while (q!=NULL && !finished) // q=NULL ��ʾ�Ѿ����ѵ��� 
		{ 
			insert(q, pos, x, ap);
			if (q->keynum<M) 
			{
				finished=1;  	     // ���ٷ���
			}	
			else
			{
				s=ceil((float)M/2); 
				split(q, &q1);       // ����
				x=q->key[s];	
				ap=q1;
				q=q->parent;
				if (q!=NULL) 
				{
					pos=search(q,x); 
				}	
			}
		}
		if (!finished)              // ��ʾ�����Ҫ���ѣ��������¸�
		{
			new_root=(MBTree)malloc(sizeof(MBTNode));
			new_root->keynum=1;  
			new_root->parent=NULL; 
			new_root->key[1]=x;	
			new_root->ptr[0]=*mbt; 
			new_root->ptr[1]=ap;
			*mbt=new_root;
		}
	}
}

void CreateMBTree(MBTree * mbt, int len, KeyType key[])
{
	MBTNode * 	p;
	int 		i;
	
	*mbt = (MBTNode *)malloc(sizeof(MBTNode));
	p = (MBTNode *)malloc(sizeof(MBTNode));
	i = 0;

	while(i < len)
	{
		insertmbtree(mbt, key[i], p, i++);
	}	
}

Boolean SearchMBTree(MBTree mbt, KeyType k, MBTree * np, int * pos)
{
	MBTNode * 	p;
	MBTNode * 	q;
	Boolean 	found;
	int 		i;
	
	p = mbt;
	q = NULL; 
	found = 0; 
	i = 0;
	while (p != NULL && !found)
	{ 
		i = search (p, k);
		if (i>0 && p->key[i] == k) 
		{
			found = 1;
		}	
		else 
		{ 
			q = p; 
			p = p->ptr[i]; 
		}
	}
	if (found) 
	{ 
		*np = p; 
		*pos = i; 
		return 1;
	}
	else 
	{
		*np = q; 
		*pos = i; 
		return 0;
	}
}
