#include "heapsort.h"


void sift(RecordType r[], int k, int m)
{
	RecordType 	t;
	int 		i;
	int 		j;
	int 		x;
	int 		finished;
	
	t= r[k];                        // 暂存"根"记录r[k]  
	x=r[k].key;
	i=k;
	j=2*i;
	finished = 0;
	while(j<=m && !finished) 
	{     
		if (j<m  && r[j].key< r[j+1].key ) 
		{    
			j=j+1;
		}
		if ( x>= r[j].key)
		{
			finished = 1;          //  筛选完毕   
		}	
		else 
		{
			r[i] = r[j];
			i=j;
			j=2*i;
		} 
	}
	r[i] =t;                        // r[k]填入到恰当的位置  
}
  
void createheap(RecordType r[], int length )
{
	int i;
	int n;
	
    n= length;
	for ( i=n/2; i >= 1; --i)        // 自第[n/2]个记录开始进行筛选建堆  
	{
		sift(r,i,n);
	}	
}

void HeapSort(RecordType r[], int length)
{
	int 		i;
	int 		n;
	RecordType	b;
	
	createheap(r, length);
	n= length;
	for (  i=n ; i>= 2; --i) 
	{
		b=r[1];                     // 将堆顶记录和堆中的最后一个记录互换  
		r[1]= r[i];
		r[i]=b; 
		sift(r,1,i-1);              // 进行调整，使r[1..i-1]变成堆  
	}
}
