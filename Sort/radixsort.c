#include "radixsort.h"

void Distribute(RadixRecordType r[], int i, PVector head, PVector tail)
{	int j;
	int p;
	for ( j=0 ; j<=RADIX-1 ; ++j)
	head[j]=0;                        //  ��RADIX�����г�ʼ��Ϊ�ն���
	p= r[0].next;                     //  pָ�������еĵ�һ����¼
	while( p!=0 )
	{
		j=r[p].key[i];                //  �ü�¼�е�iλ�ؼ�������Ӧ���к�
		if  ( head[j]==0 )
		{
			head[j]=p;                //  ��p��ָ��Ľ������j��������	
		}
		else
		{
			r[tail[j]].next=p;
		}	
		tail[j]=p;
		p= r[p].next;
	}
}

void Collect(RadixRecordType r[], PVector head,  PVector tail)
{	int i;
	int j;
	i=0;
	while (head[i]==0 )                 //  �ҵ�һ���ǿն���
	{
		++i;
	}	
	r[0].next =head[i];
	j=tail[i];
	while ( i<RADIX-1 )                 //  Ѱ�Ҳ��������зǿն���
	{
		++i;
		while ( (i<RADIX-1 ) && (head[i]==0 ) )     //  ����һ���ǿն���
		{
			++i;
		}	
		if ( head[i]!=0 )       //  ���ӷǿն���
		{
			r[j].next =head[i];
			j=tail[i];
		}
	}
	r[j].next =0;              //  tָ�����һ���ǿն����е����һ�����
}

void RadixSort(RadixRecordType r[],int length )
{	int 	i;
	int 	n;
	int 	d;
	PVector head;
	PVector tail;
	
	n= length;
	for ( i=0 ; i<= n-1 ; ++i)
	{
		r[i].next=i+1;              //  ���쾲̬����
	}	
	r[n].next =0;
	d= 3;
	for ( i =d-1; i>= 0; --i )      //  �����λ�ӹؼ��ֿ�ʼ������d�˷�����ռ�
	{
		Distribute(r,i,head,tail);  //  ��i�˷���
		Collect(r,head,tail);       //  ��i���ռ�
	}
}
