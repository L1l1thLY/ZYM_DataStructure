#include "seqsearch.h"

void CreateList(RecordList * L, int len, KeyType key[])
{
	int 	i;
    *L = (RecordListNode *)malloc(sizeof(RecordListNode));
	if( len < 0 || len > LISTSIZE + 1)     // ��ĳ����ж� 
	{
		return ;
	}
	(*L)->length = len;
	(*L)->r[0].key = 0;
	(*L)->r[0].otherdata = 0;
	for(i=1; i<=len; i++)                  // ������ĵڶ���λ�ò��룬��һλ�� 
	{                                      // �������ڵ� 
		(*L)->r[i].key = key[i-1];
		(*L)->r[i].otherdata = 0;
	}
}

int SeqSearch(RecordList  L,  KeyType  k)
{
	int i;
	L->r[0].key=k;                          // �ڵ� 
	i = L->length;
	while (L->r[i].key!=k)
	{
		i--;
	}  
	
	return(i);                             // ����Ϊ��i��λ�û�0(��ʾδ�ҵ�) 
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
		return(i);                        // ����Ϊ��i��λ��
	}	
	else
	{
		return (0);                       // ����Ϊ0(��ʾδ�ҵ�)
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
