#include "shellinsert.h"

void ShellInsert(RecordType r[], int length,  int  delta)
{
	int i;
	int j;
	for(i=1+delta;i<= length; i++)      //  1+delta为第一个子序列的第二个元素的下标 
	{
		if(r[i].key < r[i-delta].key)
		{
			r[0]= r[i];                 //   备份r[i]  (不做监视哨) 
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
