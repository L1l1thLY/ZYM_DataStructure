#ifndef HEAPSORT_H
#define HEAPSORT_H

typedef int KeyType;
typedef int OtherType;

typedef struct RecordTypeNode
{
	KeyType 	key;
	OtherType 	otherdata;
}RecordTypeNode, RecordType;

/*****************************************************************************
 *  假设ｒ[k..m]是以ｒ[k]为根的完全二叉树，且分别以ｒ[2k]和ｒ[2k+1]为根的    *
 *  左、右子树为大根堆，调整r[k]，使整个序列r[k..m]满足堆的性质              *
 *****************************************************************************/
void sift(RecordType r[], int k, int m);

/*****************************************************************************
 *   对记录数组r建堆，length为数组的长度                                     *
 *****************************************************************************/
void createheap(RecordType r[], int length);

/*****************************************************************************
 *    对r[1..n]进行堆排序，执行本算法后，r中记录按关键字由大到小有序排列     *
 *****************************************************************************/
void HeapSort(RecordType r[],int length);

#endif // END HEAPSORT_H
