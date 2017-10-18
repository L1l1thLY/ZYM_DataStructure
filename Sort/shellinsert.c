#include "shellinsert.h"

void ShellInsert(RecordType r[], int length,  int  delta)
{
	int i;
	int j;
	for(i=1+delta;i<= length; i++)      //  1+deltaΪ��һ�������еĵڶ���Ԫ�ص��±� 
	{
		if(r[i].key < r[i-delta].key)
		{
			r[0]= r[i];                 //   ����r[i]  (����������) 
			for(j=i-delta; j>0 &&r[0].key < r[j].key; j-=delta)
			{
				r[j+delta]= r[j];
			}
			r[j+delta]= r[0];
		}
	}	
}

void  ShellSort(RecordType r[], int length, int delt[], int n)
{ 
	int i;
	for(i = 0; i <= n-1; ++i)
	{
		ShellInsert(r, length, delt[i]);
	}	
}