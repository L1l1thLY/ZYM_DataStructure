#ifndef HASH_H
#define HASH_H

#define  M   13

typedef int  	KeyType;    // ����ؼ���Ϊ����
typedef struct 	RecordTypeNode
{
	KeyType  key;
}RecordTypeNode, RecordType;

typedef RecordType HashTable[M];

/*****************************************************************************
 *        ����k��hashֵ 
 *****************************************************************************/
int hash(KeyType k);

/*****************************************************************************
 *        Hash����                                                           * 
 *****************************************************************************/ 
int HashSearch(HashTable ht, KeyType key);

/*****************************************************************************
 *        HashTable��ʼ��                                                    * 
 *****************************************************************************/ 
void InitialHashTable(HashTable ht, int len, KeyType key[]);

/*****************************************************************************
 *        HashTable����                                                      * 
 *****************************************************************************/
void TravelHashTable(HashTable ht);
#endif // END HASH_H