#ifndef RADIXSORT_H
#define RADIXSORT_H

#define RADIX 		10
#define KEYSIZE 	6
#define LISTSIZE 	20

typedef int KeyType;
typedef int OtherType;

typedef struct RadixRecordTypeNode
{
	KeyType 	key[KEYSIZE];      // 子关键字数组  
	OtherType 	otherdata;         // 其它数据项  
	int  		next;              // 静态链域  
} RadixRecordTypeNode, RadixRecordType;

typedef struct RadixRecordListNode
{
	RadixRecordType	r[LISTSIZE+1];     // r[0]为头结点 
	int 		length;
	int 		keynum;
}RadixRecordListNode, RadixRecordList; 

typedef int PVector[RADIX];

/****************************************************************************** 
 * 记录数组r中记录已按低位关键字key[i+1]，…，key[d]进行过"低位优先"排序。    * 
 * 本算法按第i位关键字key[i]建立RADIX个队列，同一个队列中记录的key[i]相同。   *
 * head[j]和tail[j]分别指向各队列中第一个和最后一个记录                       *
 * (j=0，1，2，…，RADIX-1) head[j]=0表示相应队列为空队列                     *
 ******************************************************************************/
void Distribute(RadixRecordType r[], int i, PVector head, PVector tail);

/****************************************************************************** 
 *  本算法从0到RADIX-1 扫描各队列，将所有非空队列首尾相接，重新链接成一个链表 *
 ******************************************************************************/
void Collect(RadixRecordType r[], PVector head, PVector tail);

/****************************************************************************** 
 *  length个记录存放在数组r中，执行本算法进行基数排序后，                     *
 *  链表中的记录将按关键字从小到大的顺序相链接。                              *
 ******************************************************************************/
void RadixSort(RadixRecordType r[],int length );

#endif // END RADIXSORT_H 
