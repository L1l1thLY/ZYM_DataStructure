#ifndef BUBBLESORT_H
#define BUBBLESORT_H

typedef int KeyType;
typedef int OtherType;

typedef struct RecordTypeNode
{
	KeyType 	key;
	OtherType 	otherdata;
}RecordTypeNode, RecordType;

/***************************************************************************** 
 *   对记录数组r做冒泡排序，length为数组的长度                               *
 *****************************************************************************/
void BubbleSort(RecordType r[], int length );

#endif // END BUBBLESORT_H 
