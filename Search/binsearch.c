#include "binsearch.h"

void CreateBiList(RecordList *L, int len, KeyType key[])
{
	int 	i;
	*L = (BiRecordListNode *)malloc(sizeof(BiRecordListNode));
	if( len < 0 || len > LISTSIZE + 1) // 表的长度判断 
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
	high=L->length;               // 置区间初值
	while( low <= high)
	{
		mid=(low+high) / 2;
		if  (k==L->r[mid]. key)  
		{
			return (mid);       // 找到待查元素
		}	
		else  
		{
			if (k<L->r[mid]. key) 
			{
				high=mid-1;     // 未找到，则继续在前半区间进行查找
			}	
			else  
			{
				low=mid+1;      // 继续在后半区间进行查找
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
