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
 *          �������ڶ��ֲ����õ�˳����¼(����)                              * 
 ******************************************************************************/ 
void CreateBiList(RecordList *l, int len, KeyType key[]);

/******************************************************************************
 *           ���ж��ֲ���                                                     * 
 ******************************************************************************/ 
int BinarySearch(RecordList l, KeyType  k);

/******************************************************************************
 *           ����                                                             * 
 ******************************************************************************/ 
void TravelBiList(RecordList L);

#endif // END BINSEARCH_H
