#ifndef SEQSEARCH_H
#define SEQSEARCH_H

#define LISTSIZE 20 

typedef char 	KeyType;
typedef int 	OtherType;

// 需要查找的节点的数据类型 
typedef struct RecordTypeNode
{
	KeyType 	key;
	OtherType 	otherdata;
}RecordTypeNode, RecordType;

// 节点数据链表结构体 
typedef struct RecordListNode
{
	RecordType	r[LISTSIZE+1]; 
	int			length;         // 当前表中数据节点的个数 
}RecordListNode, *RecordList;

/*****************************************************************************
 *            创建数据链表                                                   * 
 *****************************************************************************/ 
void CreateList(RecordList * L, int len, KeyType key[]);

/*****************************************************************************
 *            顺序查找(设数组0号位为哨点)                                    * 
 *****************************************************************************/ 
int SeqSearch(RecordList L, KeyType  k);

/*****************************************************************************
 *            顺序查找(不用哨点的方法实现)                                   * 
 *****************************************************************************/ 
int SeqSearch2(RecordList L, KeyType k);

/*****************************************************************************
 *            遍历                                                           * 
 *****************************************************************************/ 
void ravelSeq(RecordList L);

#endif // END SEQSEARCH_H
