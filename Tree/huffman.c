#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void select(HuffmanTree *ht,int pos, int *s1, int *s2)
{
	int i;
	int min;
	for(i=1; i<=pos; i++)
	{
		if((*ht)[i].parent == 0)
		{
			min = i;
			i = pos+1;
		}
	}
	for(i=1; i<=pos; i++)
	{
		if((*ht)[i].parent == 0)
		{
			if((*ht)[i].weight < (*ht)[min].weight)
			{
				min = i;
			}	
		}
	}
	*s1 = min;
	for(i=1; i<=pos; i++)
	{
		if((*ht)[i].parent == 0 && i!=(*s1))
		{
			min = i;
			i = pos+1;
		}
	}
	for(i=1; i<=pos; i++)
	{
		if((*ht)[i].parent == 0 && i!=(*s1))
		{
			if((*ht)[i].weight < (*ht)[min].weight)
				min = i;
		}
	}
	*s2 = min;
}

void CreateHuffmanTree(HuffmanTree *ht , int *w, int n)
{ 
	int m;
	int i;
	int s1;
	int s2;
	
	m=2*n-1;
	*ht=(HuffmanNode *)malloc((m+1)*sizeof(HuffmanNode)); // 0号单元未使用
	for(i=1;i<=n;i++) 
	{
		(*ht)[i].weight = w[i];
		(*ht)[i].lchild = 0;
		(*ht)[i].parent = 0;
		(*ht)[i].rchild = 0;
	}
	for(i=n+1;i<=m;i++)     // 非叶子结点初始化
	{
		(*ht)[i].weight = 0;
		(*ht)[i].lchild = 0;
		(*ht)[i].parent = 0;
		(*ht)[i].rchild = 0;
	}    
	
	for(i=n+1;i<=m;i++)    // 创建非叶子结点,建哈夫曼树
	{
		select(ht,i-1,&s1,&s2);
		(*ht)[s1].parent=i;
		(*ht)[s2].parent=i;
		(*ht)[i].lchild=s1;
		(*ht)[i].rchild=s2;
		(*ht)[i].weight=(*ht)[s1].weight+(*ht)[s2].weight;
	} 
}

void OutputHuffman(HuffmanTree HT, int m)
{
	if(m!=0)
	{
		printf("%d\t", HT[m].weight);
		OutputHuffman(HT,HT[m].lchild);
		OutputHuffman(HT,HT[m].rchild);
	}
}

void CreateHuffmanCode(HuffmanTree *ht, HuffmanCode *hc, int n)
{
	char			*cd;
	int				i;
	unsigned int	c;
	int				start;
	int				p;
	
	hc=(HuffmanCode *)malloc((n+1)*sizeof(char *));  // 分配n个编码的头指针
	cd=(char * )malloc(n * sizeof(char ));  		 // 分配求当前编码的工作空间
	cd[n-1]='\0';         // 从右向左逐位存放编码，首先存放编码结束符
	
	for(i=1;i<=n;i++)     // 求n个叶子结点对应的哈夫曼编码
	{
		start=n-1;        // 初始化编码起始指针
		for(c=i,p=(*ht)[i].parent; p!=0; c=p,p=(*ht)[p].parent) // 从叶子到根结
		                                                        // 点求编码
			if( (*ht)[p].lchild == c) 
				cd[--start]='0';  // 左分支标0
			else 
				cd[--start]='1';  // 右分支标1
	hc[i]=(char *)malloc((n-start)*sizeof(char));  // 为第i个编码分配空间
	strcpy(hc[i],&cd[start]);
	}
	free(cd);
	for(i=1;i<=n;i++)
	{
		printf("%d编码为%s\n",(*ht)[i].weight,hc[i]);
	}
}
