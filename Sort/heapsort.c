#include "heapsort.h"


void sift(RecordType r[], int k, int m)
{
	RecordType 	t;
	int 		i;
	int 		j;
	int 		x;
	int 		finished;
	
	t= r[k];                        // �ݴ�"��"��¼r[k]  
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
			finished = 1;          //  ɸѡ���   
		}	
		else 
		{
			r[i] = r[j];
			i=j;
			j=2*i;
		} 
	}
	r[i] =t;                        // r[k]���뵽ǡ����λ��  
}
  
void createheap(RecordType r[], int length )
{
	int i;
	int n;
	
    n= length;
	for ( i=n/2; i >= 1; --i)        // �Ե�[n/2]����¼��ʼ����ɸѡ����  
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
		b=r[1];                     // ���Ѷ���¼�Ͷ��е����һ����¼����  
		r[1]= r[i];
		r[i]=b; 
		sift(r,1,i-1);              // ���е�����ʹr[1..i-1]��ɶ�  
	}
}
