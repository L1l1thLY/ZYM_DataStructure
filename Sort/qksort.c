#include "qksort.h"

int QuickPass(RecordType r[],int left, int right)
{ 
	RecordType 	x;
	int 		low;
	int 		high;
	
	x= r[left];                      // ѡ���׼��¼ 
	low=left;  
	high=right;
	
	while(low<high)
	{
		while(low< high && r[high].key>=x.key) 
		{
			high--;
		}	
		if(low <high) 
		{ 
			r[low]= r[high];
			low++;
		}  
		
		while(low<high && r[low].key<x.key)// low�������Ҵ���x.key�ļ�¼ 
		{
			low++; 
		}	
		if(low<high)          
		{ 
			r[high]= r[low];
			high--; 
		} 
	}
	r[low]=x;                         // ����׼��¼���浽low=high��λ��
	return low;                       // ���ػ�׼��¼��λ��
} 

void QuickSort(RecordType r[],int low, int high )
{
	int pos;
	if(low<high)
	{
		pos=QuickPass(r, low, high);  // ����һ�˿������򣬽�����Ԫ��Ϊ�绮����
		                              // ���ӱ�
		QuickSort(r, low, pos-1);     // �����ӱ��������
		QuickSort(r, pos+1, high);    // ���Ҳ��ӱ��������	
	}
}
