#include "radixsort.h"

void Distribute(RadixRecordType r[], int i, PVector head, PVector tail)
{	int j;
	int p;
	for ( j=0 ; j<=RADIX-1 ; ++j)
	head[j]=0;                        //  将RADIX个队列初始化为空队列
	p= r[0].next;                     //  p指向链表中的第一个记录
	while( p!=0 )
	{
		j=r[p].key[i];                //  用记录中第i位关键字求相应队列号
		if  ( head[j]==0 )
		{
			head[j]=p;                //  将p所指向的结点加入第j个队列中	
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
	while (head[i]==0 )                 //  找第一个非空队列
	{
		++i;
	}	
	r[0].next =head[i];
	j=tail[i];
	while ( i<RADIX-1 )                 //  寻找并串接所有非空队列
	{
		++i;
		while ( (i<RADIX-1 ) && (head[i]==0 ) )     //  找下一个非空队列
		{
			++i;
		}	
		if ( head[i]!=0 )       //  链接非空队列
		{
			r[j].next =head[i];
			j=tail[i];
		}
	}
	r[j].next =0;              //  t指向最后一个非空队列中的最后一个结点
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
		r[i].next=i+1;              //  构造静态链表
	}	
	r[n].next =0;
	d= 3;
	for ( i =d-1; i>= 0; --i )      //  从最低位子关键字开始，进行d趟分配和收集
	{
		Distribute(r,i,head,tail);  //  第i趟分配
		Collect(r,head,tail);       //  第i趟收集
	}
}
