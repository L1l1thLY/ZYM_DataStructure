#ifndef RADIXSORT_H
#define RADIXSORT_H

#define RADIX 		10
#define KEYSIZE 	6
#define LISTSIZE 	20

typedef int KeyType;
typedef int OtherType;

typedef struct RadixRecordTypeNode
{
	KeyType 	key[KEYSIZE];      // �ӹؼ�������  
	OtherType 	otherdata;         // ����������  
	int  		next;              // ��̬����  
} RadixRecordTypeNode, RadixRecordType;

typedef struct RadixRecordListNode
{
	RadixRecordType	r[LISTSIZE+1];     // r[0]Ϊͷ��� 
	int 		length;
	int 		keynum;
}RadixRecordListNode, RadixRecordList; 

typedef int PVector[RADIX];

/****************************************************************************** 
 * ��¼����r�м�¼�Ѱ���λ�ؼ���key[i+1]������key[d]���й�"��λ����"����    * 
 * ���㷨����iλ�ؼ���key[i]����RADIX�����У�ͬһ�������м�¼��key[i]��ͬ��   *
 * head[j]��tail[j]�ֱ�ָ��������е�һ�������һ����¼                       *
 * (j=0��1��2������RADIX-1) head[j]=0��ʾ��Ӧ����Ϊ�ն���                     *
 ******************************************************************************/
void Distribute(RadixRecordType r[], int i, PVector head, PVector tail);

/****************************************************************************** 
 *  ���㷨��0��RADIX-1 ɨ������У������зǿն�����β��ӣ��������ӳ�һ������ *
 ******************************************************************************/
void Collect(RadixRecordType r[], PVector head, PVector tail);

/****************************************************************************** 
 *  length����¼���������r�У�ִ�б��㷨���л��������                     *
 *  �����еļ�¼�����ؼ��ִ�С�����˳�������ӡ�                              *
 ******************************************************************************/
void RadixSort(RadixRecordType r[],int length );

#endif // END RADIXSORT_H 
