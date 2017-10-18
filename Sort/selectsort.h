#ifndef SELECTSORT_H
#define SELECTSORT_H

typedef int KeyType;
typedef int OtherType;

typedef struct RecordTypeNode
{
	KeyType 	key;
	OtherType 	otherdata;
}RecordTypeNode, RecordType;

/******************************************************************************
 *           选择排序                                                         *
 ******************************************************************************/
void  SelectSort(RecordType r[], int length);

#endif // END SELECTSORT_H
