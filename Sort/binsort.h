#ifndef BINSORT_H
#define BINSORT_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int OtherType;

typedef struct RecordTypeNode
{
	KeyType 	key;
	OtherType 	otherdata;
}RecordTypeNode, RecordType;

/***************************************************************************** 
 *                折半排序                                                   *
 *****************************************************************************/
void BinarySort(RecordType r[], int length);

#endif // END BINSORT_H
