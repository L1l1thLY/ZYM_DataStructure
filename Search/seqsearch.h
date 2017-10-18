#ifndef SEQSEARCH_H
#define SEQSEARCH_H

#define LISTSIZE 20 

typedef char 	KeyType;
typedef int 	OtherType;

// ��Ҫ���ҵĽڵ���������� 
typedef struct RecordTypeNode
{
	KeyType 	key;
	OtherType 	otherdata;
}RecordTypeNode, RecordType;

// �ڵ���������ṹ�� 
typedef struct RecordListNode
{
	RecordType	r[LISTSIZE+1]; 
	int			length;         // ��ǰ�������ݽڵ�ĸ��� 
}RecordListNode, *RecordList;

/*****************************************************************************
 *            ������������                                                   * 
 *****************************************************************************/ 
void CreateList(RecordList * L, int len, KeyType key[]);

/*****************************************************************************
 *            ˳�����(������0��λΪ�ڵ�)                                    * 
 *****************************************************************************/ 
int SeqSearch(RecordList L, KeyType  k);

/*****************************************************************************
 *            ˳�����(�����ڵ�ķ���ʵ��)                                   * 
 *****************************************************************************/ 
int SeqSearch2(RecordList L, KeyType k);

/*****************************************************************************
 *            ����                                                           * 
 *****************************************************************************/ 
void ravelSeq(RecordList L);

#endif // END SEQSEARCH_H
