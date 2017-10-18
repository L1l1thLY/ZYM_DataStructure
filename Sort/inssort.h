#ifndef INSSORT_H
#define INSSORT_H

typedef int KeyType;
typedef int OtherType;

typedef struct RecordTypeNode
{
	KeyType 	key;
	OtherType 	other_data;
}RecordTypeNode, RecordType;

/***************************************************************************** 
 *        插入排序                                                           *
 *****************************************************************************/
void InsertSort(RecordType r[], int length);

#endif // END INSSORT_H
