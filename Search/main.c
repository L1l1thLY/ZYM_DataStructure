// #include "avltree.h"
// #include "bst.h"
// #include "hash.h"
// #include "seqsearch.h"
// #include "binsearch.h"
 #include "mbtree.h"

#include <time.h>
#include <stdio.h>

#define RANGE  5

int main(int argc, char *argv[])
{

#ifdef AVLTREE_H
	AVLTree T;
	KeyType key[RANGE];
	int 	i;
	srand((unsigned) time(NULL));         // ��ʱ�����֣�ÿ�β����������һ��
	for(i=0; i< RANGE; i++)
	{
		key[i] = (KeyType)rand() % 256;  // ����0-255�������
		printf("%4d\t", key[i]);
	} 
	
	printf("\n��������������...\n");
    CreateAVLTree(&T, RANGE, key);
	printf("��������������Ϊ:\n");
	PreOrderAVLTree(T);
	printf("\n");
#endif

#ifdef BST_H
	BSTree 		T;
	BSTNode * 	result;
	KeyType 	key[RANGE];
	int 		i;
	int 		k;
		
	srand((unsigned) time(NULL));         // ��ʱ�����֣�ÿ�β����������һ��
	for(i=0; i< RANGE; i++)
	{
		key[i] = (KeyType)rand() % 256;  // ����0-255�������
		printf("%4d\t", key[i]);
	} 
	
	printf("\n��������������...\n");
    CreateBST(&T, RANGE, key);
	printf("��������������Ϊ:");
	PreOrderBST(T);
	printf("\n������Ҫ���ҵ�Ԫ��:");
	fflush(stdin);
	scanf("%d",&k);
	result = SearchBST(T,k);
	if (result != NULL)
	{
		printf("Ҫ���ҵ�Ԫ��Ϊ%d\n",result->key);
	}	
	else
	{
		printf("δ�ҵ�!\n");
	}
	printf("ɾ��Ԫ��%d.\n", k);	
	DeleteBST(T,k);
	printf("��������������Ϊ:");
	PreOrderBST(T);
	printf("\n");
#endif

#ifdef HASH_H
	int 		i;
	int 		len;
	KeyType		k;
	KeyType		result;
	KeyType   	key[M]; 
	HashTable 	ht;
	
	for(i=0; i<M; i++)
	{
		ht[i].key = 0;
	} 
	
	while(1)
	{
		fflush(stdin);
		printf("�������ϣ���Ԫ�ظ���:");
		scanf("%d",&len);
		if(len > 0 && len < M)
		{
			break;
		}
		else
		{
			printf("�����ϣ���Ԫ�ظ��������0С��%d\n", M);
		}
	}

	
	for(i = 0; i < len; i++)
	{	
		printf("������HashTable��ʼ���ĵ�%d��Ԫ��:", i+1 );
		scanf("%d", &key[i]);
		fflush(stdin);
	}
	
    InitialHashTable(ht, len, key);
    printf("�������Ϊ:"); 
	TravelHashTable(ht);
	printf("������Ҫ���ҵ�Ԫ��:");	
	scanf("%d",&k);
	result = HashSearch(ht,k);
	
	if(result == -1)
	{
		printf("δ�ҵ�!\n");
	}	
	else
	{
		printf("Ԫ��λ��Ϊ%d\n",result);
	}	
#endif

#ifdef SEQSEARCH_H
	RecordList 	L;
	int 		locate1;
	int 		locate2;
	KeyType 	k;
	KeyType 	key[RANGE];
	int 		i;
		
	srand((unsigned) time(NULL));         // ��ʱ�����֣�ÿ�β����������һ��
	for(i=0; i< RANGE; i++)
	{
		key[i] = (KeyType)rand() % 256;  // ����0-255�������
		key[i] = abs(key[i]);
		printf("%4d\t", key[i]);
	} 
	
	CreateList(&L, RANGE, key);
	printf("\n�������:");
	TravelSeq(L); 
	printf("\n������Ҫ���ҵ�Ԫ��:");
	fflush(stdin);
	scanf("%d",&k);
	
	locate1 = SeqSearch(L,k);
	if(locate1 == 0)
	{
		printf("δ�ҵ�!\n");
	}	
	else
	{
		printf("��Ԫ���ڱ��е�λ��Ϊ%d\n",locate1);
	}	
	locate2 = SeqSearch2(L,k);
	if(locate2 == 0)
	{
		printf("δ�ҵ�!\n");
	}	
	else
	{
		printf("��Ԫ���ڱ��е�λ��Ϊ%d\n",locate2);
	}	
#endif

#ifdef BINSEARCH_H
	RecordList 	L;
	int 		locate;
	KeyType 	k;
	KeyType 	key[RANGE];
	int 		i;
		
	srand((unsigned) time(NULL));         // ��ʱ�����֣�ÿ�β����������һ��
	for(i=0; i< RANGE; i++)
	{
		key[i] = (KeyType)rand() % 256;   // ����0-255�������
		key[i] = abs(key[i]);
		printf("%4d\t", key[i]);
	} 
	
	CreateBiList(&L, RANGE, key);
	printf("\n�������:");
	TravelBiList(L); 
	printf("������Ҫ���ҵ�Ԫ��:");
	fflush(stdin);
	scanf("%d",&k);
	locate = BinarySearch(L,k);
	if(locate == 0)
	{
		printf("δ�ҵ�!\n");
	}	
	else
	{
		printf("��Ԫ���ڱ��е�λ��Ϊ%d\n",locate);
	}	
#endif

#ifdef MBTREE_H
	MBTree *	mbt;
	MBTree * 	np;
	KeyType 	key[RANGE];
	KeyType 	k;
	int 		i;
	int 		pos;
		
	srand((unsigned) time(NULL));         // ��ʱ�����֣�ÿ�β����������һ��
	for(i=0; i< RANGE; i++)
	{
		key[i] = (KeyType)rand() % 256;   // ����0-255�������
		key[i] = abs(key[i]);
		printf("%4d\t", key[i]);
	} 
	
	CreateMBTree(mbt, RANGE, key);
	printf("\n�����ɹ�ok!\n");
	
	printf("������ҹؼ���:");
	scanf("%d", &k);
	printf("���ҽ��Ϊ��%d\n", SearchMBTree(*mbt, k, np, &pos));

#endif
	
	return 0;
}
