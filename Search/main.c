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
	srand((unsigned) time(NULL));         // 用时间做种，每次产生随机数不一样
	for(i=0; i< RANGE; i++)
	{
		key[i] = (KeyType)rand() % 256;  // 产生0-255的随机数
		printf("%4d\t", key[i]);
	} 
	
	printf("\n建立二叉排序树...\n");
    CreateAVLTree(&T, RANGE, key);
	printf("先序遍历输出序列为:\n");
	PreOrderAVLTree(T);
	printf("\n");
#endif

#ifdef BST_H
	BSTree 		T;
	BSTNode * 	result;
	KeyType 	key[RANGE];
	int 		i;
	int 		k;
		
	srand((unsigned) time(NULL));         // 用时间做种，每次产生随机数不一样
	for(i=0; i< RANGE; i++)
	{
		key[i] = (KeyType)rand() % 256;  // 产生0-255的随机数
		printf("%4d\t", key[i]);
	} 
	
	printf("\n建立二叉排序树...\n");
    CreateBST(&T, RANGE, key);
	printf("先序遍历输出序列为:");
	PreOrderBST(T);
	printf("\n请输入要查找的元素:");
	fflush(stdin);
	scanf("%d",&k);
	result = SearchBST(T,k);
	if (result != NULL)
	{
		printf("要查找的元素为%d\n",result->key);
	}	
	else
	{
		printf("未找到!\n");
	}
	printf("删除元素%d.\n", k);	
	DeleteBST(T,k);
	printf("先序遍历输出序列为:");
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
		printf("请输入哈希表的元素个数:");
		scanf("%d",&len);
		if(len > 0 && len < M)
		{
			break;
		}
		else
		{
			printf("输入哈希表的元素个数须大于0小于%d\n", M);
		}
	}

	
	for(i = 0; i < len; i++)
	{	
		printf("请输入HashTable初始化的第%d个元素:", i+1 );
		scanf("%d", &key[i]);
		fflush(stdin);
	}
	
    InitialHashTable(ht, len, key);
    printf("遍历结果为:"); 
	TravelHashTable(ht);
	printf("请输入要查找的元素:");	
	scanf("%d",&k);
	result = HashSearch(ht,k);
	
	if(result == -1)
	{
		printf("未找到!\n");
	}	
	else
	{
		printf("元素位置为%d\n",result);
	}	
#endif

#ifdef SEQSEARCH_H
	RecordList 	L;
	int 		locate1;
	int 		locate2;
	KeyType 	k;
	KeyType 	key[RANGE];
	int 		i;
		
	srand((unsigned) time(NULL));         // 用时间做种，每次产生随机数不一样
	for(i=0; i< RANGE; i++)
	{
		key[i] = (KeyType)rand() % 256;  // 产生0-255的随机数
		key[i] = abs(key[i]);
		printf("%4d\t", key[i]);
	} 
	
	CreateList(&L, RANGE, key);
	printf("\n遍历结果:");
	TravelSeq(L); 
	printf("\n请输入要查找的元素:");
	fflush(stdin);
	scanf("%d",&k);
	
	locate1 = SeqSearch(L,k);
	if(locate1 == 0)
	{
		printf("未找到!\n");
	}	
	else
	{
		printf("该元素在表中的位置为%d\n",locate1);
	}	
	locate2 = SeqSearch2(L,k);
	if(locate2 == 0)
	{
		printf("未找到!\n");
	}	
	else
	{
		printf("该元素在表中的位置为%d\n",locate2);
	}	
#endif

#ifdef BINSEARCH_H
	RecordList 	L;
	int 		locate;
	KeyType 	k;
	KeyType 	key[RANGE];
	int 		i;
		
	srand((unsigned) time(NULL));         // 用时间做种，每次产生随机数不一样
	for(i=0; i< RANGE; i++)
	{
		key[i] = (KeyType)rand() % 256;   // 产生0-255的随机数
		key[i] = abs(key[i]);
		printf("%4d\t", key[i]);
	} 
	
	CreateBiList(&L, RANGE, key);
	printf("\n遍历结果:");
	TravelBiList(L); 
	printf("请输入要查找的元素:");
	fflush(stdin);
	scanf("%d",&k);
	locate = BinarySearch(L,k);
	if(locate == 0)
	{
		printf("未找到!\n");
	}	
	else
	{
		printf("该元素在表中的位置为%d\n",locate);
	}	
#endif

#ifdef MBTREE_H
	MBTree *	mbt;
	MBTree * 	np;
	KeyType 	key[RANGE];
	KeyType 	k;
	int 		i;
	int 		pos;
		
	srand((unsigned) time(NULL));         // 用时间做种，每次产生随机数不一样
	for(i=0; i< RANGE; i++)
	{
		key[i] = (KeyType)rand() % 256;   // 产生0-255的随机数
		key[i] = abs(key[i]);
		printf("%4d\t", key[i]);
	} 
	
	CreateMBTree(mbt, RANGE, key);
	printf("\n创建成功ok!\n");
	
	printf("输入查找关键字:");
	scanf("%d", &k);
	printf("查找结果为：%d\n", SearchMBTree(*mbt, k, np, &pos));

#endif
	
	return 0;
}
