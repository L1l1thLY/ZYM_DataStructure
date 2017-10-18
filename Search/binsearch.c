#include "binsearch.h"

void CreateBiList(RecordList *L, int len, KeyType key[])
{
	int 	i;
	*L = (BiRecordListNode *)malloc(sizeof(BiRecordListNode));
	if( len < 0 || len > LISTSIZE + 1) // ��ĳ����ж� 
	{
		return ;
	}
	(*L)->length = len;
	for(i = 0; i < LISTSIZE; i++)
	{
		(*L)->r[i].key = 0;
		(*L)->r[i].otherdata = 0;
	}
	for(i=1; i<=len; i++)
	{
		(*L)->r[i].key = key[i-1];
	}
}

int BinarySearch(RecordList L, KeyType k)
{
	int low;
	int high;
	int mid;
	
	low=1;  
	high=L->length;               // �������ֵ
	while( low <= high)
	{
		mid=(low+high) / 2;
		if  (k==L->r[mid]. key)  
		{
			return (mid);       // �ҵ�����Ԫ��
		}	
		else  
		{
			if (k<L->r[mid]. key) 
			{
				high=mid-1;     // δ�ҵ����������ǰ��������в���
			}	
			else  
			{
				low=mid+1;      // �����ں��������в���
			}	
		}	
	}

	return (0);
}

void TravelBiList(RecordList L)
{
	int i;
	for( i = 1; i <= L->length; i++)
	{
		printf("%d\t", L->r[i].key);
	}
	printf("\n");
}
