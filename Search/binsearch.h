#ifndef BINSEARCH_H
#define BINSEARCH_H

#define LISTSIZE 20 

typedef int KeyType;
typedef int OtherType;

typedef struct RecordTypeNode
{
	KeyType 	key;
	OtherType 	otherdata;
}RecordTypeNode, RecordType;

typedef struct BiRecordListNode
{
	RecordType	r[LISTSIZE+1];
	int 		length;
}BiRecordListNode, *RecordList;

/******************************************************************************
 *          创建用于二分查找用的顺序表记录(有序)                              * 
 ******************************************************************************/ 
void CreateBiList(RecordList *l, int len, KeyType key[]);

/******************************************************************************
 *           进行二分查找                                                     * 
 ******************************************************************************/ 
int BinarySearch(RecordList l, KeyType  k);

/******************************************************************************
 *           遍历                                                             * 
 ******************************************************************************/ 
void TravelBiList(RecordList L);

#endif // END BINSEARCH_H
