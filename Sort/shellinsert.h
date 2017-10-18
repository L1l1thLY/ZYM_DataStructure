#ifndef SHELLINSERT_H
#define SHELLINSERT_H

typedef int KeyType;
typedef int OtherType;

typedef struct RecordTypeNode
{
	KeyType 	key;
	OtherType 	otherdata;
}RecordTypeNode, RecordType;

/***************************************************************************** 
 *    对记录数组r做一趟希尔插入排序，length为数组的长度,delta 为增量         *
 *****************************************************************************/
void ShellInsert(RecordType r[], int length, int delta);

/***************************************************************************** 
 *  对记录数组r做希尔排序                                                    * 
 *  length为数组r的长度，delta 为增量数组，n为delta[]的长度                  *
 *****************************************************************************/ 
void ShellSort(RecordType r[], int length, int delt[], int n);

#endif // END SHELLINSERT_H
