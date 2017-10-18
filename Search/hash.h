#ifndef HASH_H
#define HASH_H

#define  M   13

typedef int  	KeyType;    // 假设关键字为整型
typedef struct 	RecordTypeNode
{
	KeyType  key;
}RecordTypeNode, RecordType;

typedef RecordType HashTable[M];

/*****************************************************************************
 *        计算k的hash值 
 *****************************************************************************/
int hash(KeyType k);

/*****************************************************************************
 *        Hash查找                                                           * 
 *****************************************************************************/ 
int HashSearch(HashTable ht, KeyType key);

/*****************************************************************************
 *        HashTable初始化                                                    * 
 *****************************************************************************/ 
void InitialHashTable(HashTable ht, int len, KeyType key[]);

/*****************************************************************************
 *        HashTable遍历                                                      * 
 *****************************************************************************/
void TravelHashTable(HashTable ht);
#endif // END HASH_H
