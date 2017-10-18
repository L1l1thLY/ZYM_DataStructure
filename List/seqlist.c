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
	pos = 0;                               // posΪ��������������ֵΪ0
	while ((pos<=L->last)&&(L->elem[pos]!=e))// �ҵ���һ����ֵ�����һԪ�ؽ��� 
	{
		pos++;
	}	 
	if(pos<=L->last)                       // �ж��Ƿ��ҵ����ҵ��򷵻�Ϊ��i��λ�� 
	{
		return (pos+1);
	}	                  
	else
	{
		return (-1);                       // ��û�ҵ����򷵻�-1
	}
}

int InsertSeqList(SeqList L, int pos, ElemType e)
{ 
	int		i;
	Message msgsuccess, msgrangeerror, msgfail;
	
	msgsuccess = Success;
	msgrangeerror = RangError;
	msgfail = Fail;
	
	if((pos<1) || (pos>L->last+2))       // �жϲ���λ���Ƿ�Ϸ�
	{
		return msgrangeerror;
	}
	if(L->last>= MAXSIZE-1)
	{
		return msgfail;
	}
	for(i=L->last;i>=pos-1;i--)         // Ϊ����Ԫ�ض��ƶ�λ��
	{
		L->elem[i+1]=L->elem[i];
	}	
	L->elem[pos-1]=e;                   // ��C���������У���i��Ԫ�ص��±�Ϊi-1
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
	*e = L->elem[pos-1];               // ��ɾ����Ԫ�ش�ŵ�e��ָ��ı�����
	for(i = pos; i <= L->last; i++)
	{
		L->elem[i-1] = L->elem[i];   // �������Ԫ������ǰ��
	}
	L->last--;
	
	return msgsuccess;
}
