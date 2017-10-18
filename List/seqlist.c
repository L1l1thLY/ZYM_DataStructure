#include <malloc.h>
#include <memory.h>
#include <string.h>
#include "seqlist.h"

int InitialSeqList(SeqList * L, ElemType e[], int len)
{
	int 	i;
	Message msgsuccess, msgfail;
	
	msgsuccess = Success;
	msgfail = Fail;

	if(len > MAXSIZE || len < 0)
	{
		return msgfail;
	}
	else
	{	
		(*L) = (SeqListNode *)malloc(sizeof(SeqListNode));
		memset((*L)->elem, 0, sizeof(ElemType)*MAXSIZE);
		for( i = 0; i < len; i++)
		{
			(*L)->elem[i] = e[i];
		}
		(*L)->last = len;
	}
	return msgsuccess;
}

int DestroySeqList(SeqList L)
{
	if(L)
	{
		free(L);
	}
	return 0; 
} 

int LocateSeqList(SeqList L, ElemType e)
{	
	int pos;
	pos = 0;                               // pos为遍历计数器，初值为0
	while ((pos<=L->last)&&(L->elem[pos]!=e))// 找到第一查找值或最后一元素结束 
	{
		pos++;
	}	 
	if(pos<=L->last)                       // 判断是否找到，找到则返回为第i个位置 
	{
		return (pos+1);
	}	                  
	else
	{
		return (-1);                       // 若没找到，则返回-1
	}
}

int InsertSeqList(SeqList L, int pos, ElemType e)
{ 
	int		i;
	Message msgsuccess, msgrangeerror, msgfail;
	
	msgsuccess = Success;
	msgrangeerror = RangError;
	msgfail = Fail;
	
	if((pos<1) || (pos>L->last+2))       // 判断插入位置是否合法
	{
		return msgrangeerror;
	}
	if(L->last>= MAXSIZE-1)
	{
		return msgfail;
	}
	for(i=L->last;i>=pos-1;i--)         // 为插入元素而移动位置
	{
		L->elem[i+1]=L->elem[i];
	}	
	L->elem[pos-1]=e;                   // 在C语言数组中，第i个元素的下标为i-1
	L->last++;
	
	return msgsuccess;
}

int DeleteSeqList(SeqList L, int pos, ElemType *e)
{ 
	int		i;
	Message msgsuccess, msgfail;
	
	msgsuccess = Success;
	msgfail = Fail;
	
	if((pos<1)||(pos>L->last+1))   
	{ 
		return msgfail;
	}
	*e = L->elem[pos-1];               // 将删除的元素存放到e所指向的变量中
	for(i = pos; i <= L->last; i++)
	{
		L->elem[i-1] = L->elem[i];   // 将后面的元素依次前移
	}
	L->last--;
	
	return msgsuccess;
}
