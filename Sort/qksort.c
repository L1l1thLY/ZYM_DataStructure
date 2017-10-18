#include "qksort.h"

int QuickPass(RecordType r[],int left, int right)
{ 
	RecordType 	x;
	int 		low;
	int 		high;
	
	x= r[left];                      // 选择基准记录 
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
		
		while(low<high && r[low].key<x.key)// low从左到右找大于x.key的记录 
		{
			low++; 
		}	
		if(low<high)          
		{ 
			r[high]= r[low];
			high--; 
		} 
	}
	r[low]=x;                         // 将基准记录保存到low=high的位置
	return low;                       // 返回基准记录的位置
} 

void QuickSort(RecordType r[],int low, int high )
{
	int pos;
	if(low<high)
	{
		pos=QuickPass(r, low, high);  // 调用一趟快速排序，将枢轴元素为界划分两
		                              // 个子表
		QuickSort(r, low, pos-1);     // 对左部子表快速排序
		QuickSort(r, pos+1, high);    // 对右部子表快速排序	
	}
}
