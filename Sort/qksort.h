#ifndef QKSORT_H
#define QKSORT_H

typedef int KeyType;
typedef int OtherType;

typedef struct RecordTypeNode
{
	KeyType 	key;
	OtherType 	otherdata;
}RecordTypeNode, RecordType;

/***************************************************************************** 
 *   对记录数组r 中的r[left]至r[right]部分进行一趟排序，                     *
 *   并得到基准的位置，使得排序后的结果满足其之后（前）的记录的              *
 *   关键字均不小于（大于）于基准记录                                        *
 *****************************************************************************/
int QuickPass(RecordType r[], int left, int right);

/***************************************************************************** 
 *    对记录数组r[low..high]用快速排序算法进行排序                           *
 *****************************************************************************/
void QuickSort(RecordType r[],int low, int high );

#endif // END QKSORT_H
