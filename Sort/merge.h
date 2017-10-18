#ifndef MERGE_H
#define MERGE_H

typedef int KeyType;
typedef int OtherType;

typedef struct RecordTypeNode
{
	KeyType 	key;
	OtherType 	otherdata;
}RecordTypeNode, RecordType;


/***************************************************************************
 *     已知r1[low..mid]和r1[mid+1..high]分别按关键字有序排列，             *
 *     将它们合并成一个有序序列，存放在r2[low..high]                       *
 ***************************************************************************/
void Merge(RecordType r1[], int low, int mid, int high, RecordType r2[]);

/***************************************************************************
 *      r1[low..high]经过排序后放在r3[low..high]中，r2[low..high]为辅助空间*
 ***************************************************************************/ 
void MSort(RecordType r1[], int low, int high, RecordType r3[]);

/***************************************************************************
 *      对记录数组r[1..n]做归并排序                                        *
 ***************************************************************************/ 
void MergeSort(RecordType r[], int n);

#endif // END MERGE_H
