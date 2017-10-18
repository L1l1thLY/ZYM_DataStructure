#include "seqsearch.h"

void CreateList(RecordList * L, int len, KeyType key[])
{
	int 	i;
    *L = (RecordListNode *)malloc(sizeof(RecordListNode));
	if( len < 0 || len > LISTSIZE + 1)     // 表的长度判断 
	{
		return ;
	}
	(*L)->length = len;
	(*L)->r[0].key = 0;
	(*L)->r[0].otherdata = 0;
	for(i=1; i<=len; i++)                  // 从链表的第二个位置插入，第一位置 
	{                                      // 可用做哨点 
		(*L)->r[i].key = key[i-1];
		(*L)->r[i].otherdata = 0;
	}
}

int SeqSearch(RecordList  L,  KeyType  k)
{
	int i;
	L->r[0].key=k;                          // 哨点 
	i = L->length;
	while (L->r[i].key!=k)
	{
		i--;
	}  
	
	return(i);                             // 返回为第i个位置或0(表示未找到) 
}


int SeqSearch2(RecordList L,  KeyType k)
{
	int i;
	i = L->length;
	while (i>=1 && L->r[i].key!=k)
	{
 		i--;
	} 
	if (i>=1) 
	{
		return(i);                        // 返回为第i个位置
	}	
	else
	{
		return (0);                       // 返回为0(表示未找到)
	}	
}

void TravelSeq(RecordList L)
{
	int i;
	for(i = 0; i < L->length; i ++)
	{
		printf("%4d\t", L->r[i].key);
	}
}
